/*
elfreader.h
This is the header file to support the reading and extraction of ELF files.
Heavy use of this file was used. http://www.skyfree.org/linux/references/ELF_Format.pdf
This is the actual specs. http://sco.com/developers/gabi/latest/ch4.sheader.html

Written by Zane Youmans
10/18/19
*/

#ifndef ELF_TYPES_H_
#define ELF_TYPES_H_

//Rename some data types so it's easier to see what they do
/*
typedef unsigned int Elf32_Addr; // Program address, 4 bytes, aligned at 4 bytes
typedef unsigned short Elf32_Half; // Medium integer, 2 bytes, aligned at 2 bytes
typedef unsigned int Elf32_Offset; // File Offset, 4 bytes, aligned at 4 bytes
typedef int Elf32_Sword; //Signed int, 4 bytes, aligned at 4 bytes
typedef unsigned int ELF32_Word; // Unsigned int, 4 bytes, aligned at 4 bytes
*/

/*
ELF files are made of some combonation of these sections
Only the File_Header is garantueed to be present and at the top
The others can be in any order, or not present at all
*/

/////////////////////////////////////////////////////////////////////////////////////////////////  FILE HEADER

//Make a nice union for the Magic Number Header
struct Magic_numbers_struct
{
    unsigned char magic_1;
    unsigned char magic_2;
    unsigned char magic_3;
    unsigned char magic_4;
    unsigned char file_class; //how this file can be used
    unsigned char data_encoding; //how to read the file
    unsigned char file_version; //better be CURRENT
    unsigned char padding; //start of 0 padding 
    unsigned short size_of_ident; //should be 16?
};

typedef union
{
    Magic_numbers_struct fields;
    unsigned char bytes[16] ;
}Magic_numbers;

//Every ELF file needs one of these
typedef struct
{
    Magic_numbers     identity; //the magic ELF header number to identify itself. The union below
    unsigned short    type; // the type of file, selected from Object_file_type enum below
    unsigned short    machine; //what sort of processor was made on, from Machine_type enum below
    unsigned int      version; //Version of ELF, from Version_type enum below
    unsigned int      entry; //Location of program entry point, if there is one
    unsigned int      phoff; //program header offset (struct below), in bytes
    unsigned int      shoff; //section header offset (struct below), in bytes
    unsigned int      flags; //anything extra info about the Machine
    unsigned short    elf_header_size; //The size of this header, in bytes
    unsigned short    program_header_entry_size; //the size of one entry in the program header. They all have to match
    unsigned short    program_headar_entry_number; //how many entries in the program header. Can be zero
    unsigned short    section_header_entry_size; //the size of one entry in the section header. They all have to match
    unsigned short    section_header_entry_number; //how many entries in the program header. Can be zero
    unsigned short    section_header_str_index; //index of section header that that goes with the string table

}File_Header;

//These are the different types of objects the file can be
enum Object_file_type
{
    OFT_NONE, //none?
    OFT_RELOCATABLE, //static link
    OFT_EXECUTABLE, //run
    OFT_SHARED_OBJECT, //dynamic link
    OFT_CORE, //core dump
    OFT_LOPROC = 0xff00, //Processor specific, don't expect to use
    OFT_HIPROC = 0xffff, //Processor spepcific, don't expect to use.
    OFT_Object_file_type_CNT = 7
};

//These are the different machines the ELF file can originate from
enum Machine_type
{
    MT_NONE, //none?
    MT_M32, //AT&T WE 32100
    MT_SPARC, //SPARC
    MT_E_368, //Intel 80386
    MT_E_68k, //Motorola 68000
    MT_E_88k, //Motorola 88000
    MT_E_860, //Intel 80860
    MT_E_MIPS, //MIPS RS3000
    MT_Machine_type_CNT
};

//The type of ELF. There's only 1...
enum Version_type
{
    VT_NONE, //none?
    VT_CURRENT, //current
    VT_Version_type_CNT
};

//What sort of architecture was it made for?
enum Class_type
{
    CT_CLASS_NONE,
    CT_CLASS_32,
    CT_CLASS_64,
    CT_Class_type_CNT
};

//how to read the data
enum Data_type
{
    DT_DATA_NONE,
    DT_DATA_2LSB,
    DT_DATA_2MSB,
    DT_Data_type_CNT
};

///////////////////////////////////////////////////////////////////////////////////////////// SECTION HEADER

//only linkables require this   
//There are one of these for every section in the ELF File
typedef struct
{
    unsigned int    name; //the name of a section
    unsigned int    type; //Section type from the enum below
    unsigned int    flags; //special flags
    unsigned int    address; //if this section goes in a memory image, this is where to put it
    unsigned int    offset; //offset from the start of the ELF file to this section
    unsigned int    size;  //size of the section 
    unsigned int    link; // section header table index link, and is dependend on type
    unsigned int    info; //extra info about the type if needed
    unsigned int    addrelign; // alignment constraint for this section, 0 or 1 mean none
    unsigned int    entry_size;

}Section_Header;

//For that last part of the magic header
enum Special_section_indexes
{
    SSI_UNDEF,
    SSI_LORESERVE = 0xff00,
    SSI_LOPROC = 0xff00,
    SSI_HIPROC = 0xff1f,
    SSI_ABS = 0xfff1,
    SSI_COMMON = 0xfff2,
    SSI_HIRESERVE = 0xffff,
    SSI_Special_section_indexes_CNT = 7
};

// possible types this section coule be
enum Section_types
{
    ST_NULL, //invactive or invalid and makes all other fields in the Section header go to 0
    ST_PROGBITS, //This section is holding data for the program
    ST_SYMTAB, // Symbols table
    ST_STRTAB, //string table. ELF can have multiple of these
    ST_RELA, //relocation entries with addins
    ST_HASH, //symbol has table. Must be present for dynamic linking
    ST_DYNAMIC, //info for dynamic linking. Can only be one
    ST_NOTE, //Just random notes
    ST_NOBITS, //Treat like PROGBITS, but takes up no actual space?
    ST_REL, //Relcation entries without addins
    ST_SHLIB, //Extra crap
    ST_DYNDYM, //sybomls table
    ST_LOPROC = 0x70000000, //processor specific
    ST_HIPROC = 0x7fffffff, //processor specific
    ST_LOUSER = 0x80000000,
    ST_HIUSER = 0xffffffff,
    ST_Section_types_CNT = 16
};

enum Section_flags
{
    SF_WRITE = 0x1, //data here should be writable during execution
    SF_ALLOC = 0x2, //This section will need some memory to run
    SF_EXECINSTR = 0x3, //This section contains machine instructions
    SF_MASKPROC = 0xf0000000, //processor specific
    SF_Section_flags_CNT = 4
};

///////////////////////////////////////////////////////////////////////////////// SYMBOL TABLE ENTRY

#define ELF32_symbol_table_bind(i)  ((i)>>4)
#define ELF32_symbol_table_type(i)  ((i)&0xf)
#define ELF32_symbol_table_info(b,t)  ((b)<<4)+((t)&0xf)

typedef struct
{
    unsigned int    name; //index into a string table
    unsigned int    value; //can vary
    unsigned int    size; //size of associated data, or could be 0
    unsigned char   info; //the above macros will extract data out of this
    unsigned char   other; //always 0...
    unsigned short  section_header_index; //the index into section header table that his entry relates to

}Symbol_Table_Entry;


//Thes are the outputes of the Bind macro above
enum Symbol_table_bind
{
    STB_LOCAL = 0, //symbols are only visible inside this ELF file
    STB_GLOBAL = 1, //symbols will be seen by other files being linked
    STB_WEAK = 2, //Similar to global
    STB_LOPROC = 13, //processor specific
    STB_HIPROC = 15, //processor specific
    STB_Symbol_table_bind_CNT = 5
};

enum Symbol_table_type
{
    STT_NOTYPE, //No symbol type
    STT_OBJECT, //the symbol is for a data object (variable, array, etc.)
    STT_FUNC, // the symbol is for a function or executable code
    STT_SECTION, //the symbol is for a section
    STT_FILE, // name of the source file associated with this object file
    STT_LOPROC = 13, //processor specific
    STT_HIPROC = 15, //processor specific
    STT_Symbol_table_type_CNT = 7
};

///////////////////////////////////////////////////////////////////// RELOCATION ENTRY

//relocation is connecting symbolic referencees with symbolic definitions.
// like linking a function call to the definition of a function.

#define ELF32_R_SYM(i) ((i)>>8)
#define ELF32_R_TYPE(i) ((unsigned char)(i))
#define ELF32_R_INFO(s,t) (((s)<<8)+(unsigned char)(t))

typedef struct
{
    unsigned int offset; //
    unsigned int info;
}Relocation_Entry;

typedef struct
{
    unsigned int offset;
    unsigned int info;
    signed int addned; 

}Relocation_Entry_Addend;

enum Relocation_type
{
    RT_386_NONE,
    RT_386_32,
    RT_386_PC32,
    RT_386_GOT32,
    RT_386_PLT32,
    RT_386_COPY,
    RT_386_GLOB_DAT,
    RT_386_JMP_SLOT,
    RT_386_RELATIVE,
    RT_386_GOTOFF,
    RT_386_GOTPC,
    RT_Relocation_type_CNT
};

//////////////////////////////////////////////////////////// PROGRAM HEADER

//Only executables require this
typedef struct
{
    unsigned int type; //what kind of segment. Enum below
    unsigned int offset; //offset from start of file that this segment resides
    unsigned int virtual_address; //virtual address of where this segment resides
    unsigned int physical_address; //physical address, if needed
    unsigned int file_size; //number of bytes in segment. can be 0.
    unsigned int memory_size; //number of bytes in memory image of segment. can be 0.
    unsigned int flags; //relevent flags. Enum below
    unsigned int align; //how many bytes to align to
}Program_Header;

enum Segment_Types
{
    SGT_NULL, //nothing. Ignore this entry
    SGT_LOAD, // loadable segment
    SGT_DYNAMIC, //dynamic linking info
    SGT_INTERP, // path name to an interpreter
    SGT_NOTE, //extra info
    SGT_SHLIB, //Unused
    SGT_PHDR, //tells the location and size of the program header
    SGT_LOPROC = 0x70000000, //processor
    SGT_HIPROC = 0x7fffffff //processor
};

#endif //ELF_TYEPS_H_