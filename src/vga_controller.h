#ifndef VGACONTROLLER_H
#define VGACONTROLLER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void clear_screen();
void print(const char* data);
void print_good(const char* data);
void print_bad(const char* data);

#endif //VGACONTROLLER_H