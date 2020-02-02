#include <vmm.h>
#include <pmm.h>
#include <assert.h>


#define PAGE_DIRECTORY_INDEX(x) (((x)>>22)&0x3FF)
#define PAGE_TABLE_INDEX(x) (((x) >> 12)&0x3FF)
#define PAGE_GET_PHYSICAL_ADDRESS(x) (*x & ~0xfff)

void add_attribute_to_entry(page_table_entry *entry, uint32_t attributes)
{
    *entry = (*entry | attributes);
}

void del_attribute_from_entry(page_table_entry *entry, uint32_t attributes)
{
    *entry = ~(*entry & attributes);
}

void attach_frame(page_table_entry *entry, void * frame)
{
    entry = (page_table_entry *)(*entry | (page_table_entry)frame);
}

bool is_present(page_table_entry *entry)
{
    return (*entry & 1);
}

bool is_writable(page_table_entry *entry)
{
    return (*entry & 2);
}

void * get_frame(page_table_entry *entry)
{
    unsigned int temp = (*entry & (uint32_t)FRAME);
    return (void *)temp;
}

bool allocate_page(page_table_entry *entry)
{
    auto * new_frame = find_new_frame();
    CHECK(new_frame != NULL); //make sure it came back with something

    attach_frame(entry,new_frame);
    add_attribute_to_entry(entry, PRESENT);

    return true;
}

void free_page(page_table_entry *entry)
{
    void * frame = get_frame(entry);
    if (frame)
    {
        free_frame(frame);
    }
    del_attribute_from_entry(entry,PRESENT);
}

page_table_entry * look_up_in_page_table(page_table *table, uint32_t virtual_address)
{
    return &table->page_table_entries[PAGE_TABLE_INDEX(virtual_address)];
}