#ifndef VMM_H_
#define VMM_H_
//#include <unpacked_page_dir_ent.h>
//#include <unpacked_page_table_ent.h>
#include <basics.h>

typedef uint32_t page_table_entry;

enum PAGE_TABLE_ENTRY_FLAGS
{
    PRESENT = 1,
    WRITEABLE = 2,
    USER = 4,
    WRITETHROUGH = 8,
    NOT_CACHABLE = 0x10,
    ACCESSED = 0x20,
    DIRTY = 0x40,
    PAT = 0x80,
    CPU_GLOBAL = 0x100,
    LV4_GLOBAL = 0x200,
    FRAME = 0x7FFFF0000
};

//PAGES_PER_TABLE * TABLES_PER_DIR * PAGE_SIZE = 4 gigs
constexpr int PAGES_PER_TABLE = 1024;
constexpr int TABLES_PER_DIR = 1024;
constexpr int PAGE_SIZE = 4096; //4k

typedef struct page_table
{
    page_table_entry page_table_entries[PAGES_PER_TABLE];
}page_table;

typedef struct page_directory
{
    page_table page_directory_entries[TABLES_PER_DIR];
}page_directory;

//these functions act on page table entries
void add_attribute_to_entry(page_table_entry *entry, uint32_t attributes);
void del_attribute_from_entry(page_table_entry *entry, uint32_t attributes);
void attach_frame(page_table_entry *entry, void * frame);
bool is_present(page_table_entry *entry);
bool is_writable(page_table_entry *entry);
void * get_frame(page_table_entry *entry);

bool allocate_page(page_table_entry *entry);
void free_page(page_table_entry *entry);
page_table_entry * look_up_in_page_table(page_table *table, uint32_t virtual_address);


#endif //VMM_H_