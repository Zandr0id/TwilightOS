#ifndef UNPACKED_PAGE_H_
#define UNPACKED_PAGE_H_

#include <basics.h>

class unpacked_page_table_ent
{
public:
    unpacked_page_table_ent(unsigned int * addr, unsigned char extra, bool global, bool pat, bool dirty, bool accessed, bool cache, bool write_through, bool priv, bool read_write, bool present);
    unpacked_page_table_ent(unsigned int int_form);
    unsigned int return_as_table_entry();
private:
    unsigned int * physical_page_address_; //12-31
    unsigned char extra_; //9-11
    bool global_;
    bool pat_;
    bool dirty_;
    bool accessed_;
    bool cache_disabled_;
    bool write_through_;
    bool priv_; //user\supervisor
    bool read_write_;
    bool present_;
};

#endif