#include <unpacked_page_table_ent.h>
#include <assert.h>

unpacked_page_table_ent::unpacked_page_table_ent(unsigned int * addr, unsigned char extra, bool global, bool pat, bool dirty, bool accessed,
                                                 bool cache, bool write_through, bool priv, bool read_write, bool present)
{
    physical_page_address_ =  addr;
    extra_ = extra;
    global_ = global;
    pat_ = pat;
    dirty_ = dirty;
    accessed_ = accessed;
    cache_disabled_ = cache;
    write_through_ = write_through;
    priv_ = priv;
    read_write_ = read_write;
    present_ = present;

    CHECK(((unsigned int)physical_page_address_ & 0xFFF) == 0);
}

//break down the input into its bytes and fill in the members
unpacked_page_table_ent::unpacked_page_table_ent(unsigned int int_form )
{
    physical_page_address_ = (unsigned int *)(int_form & 0xFFFFF000); //align to 4KiB
    extra_ = (unsigned char)((int_form & 0x00000E00) >> 9);
    global_ = (bool)(int_form & 0x00000100);
    pat_ = (bool)(int_form & 0x00000080);
    dirty_ = (bool)(int_form & 0x00000040);
    accessed_ = (bool)(int_form & 0x00000020);
    cache_disabled_ = (bool)(int_form & 0x00000010);
    write_through_ = (bool)(int_form & 0x00000008);
    priv_ = (bool)(int_form & 0x00000004);
    read_write_ = (bool)(int_form & 0x00000002);
    present_ = (bool)(int_form & 0x00000001);
}

//OR everything together to make a single into table entry
unsigned int unpacked_page_table_ent::return_as_table_entry()
{
    int entry = ((int)physical_page_address_ | (((int)extra_) << 9) | (((int)global_) << 8) | (((int)pat_) << 7) | (((int)dirty_) << 6) | (((int)accessed_) << 5) | 
                (((int)cache_disabled_) << 4) | (((int)write_through_) << 3) | (((int)priv_) << 2) | (((int)read_write_) << 1) | (int)present_);
    return entry;
}