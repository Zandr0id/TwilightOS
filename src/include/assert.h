#ifndef ASSERT_H_
#define ASSERT_H_

#include <libc/stdio.h>
//#include <debugger_device.h>

//junk to make __LINE__ print as a string
#define STRINGIFY(X) STRINGIFY2(X)
#define STRINGIFY2(X) #X

#define CHECK( expression ) \
                do { \
                    if(false == (expression)) \
                    { \
                      printf("CHECK: " #expression ", File: " __FILE__ ", Line: " STRINGIFY(__LINE__) "\n");\
                      while(true);\
                    }\
                }while(false)
                
#define ASSERT_NOT_REACHED() \
                        do { \
                            printf("ASSERT REACHED! File: " __FILE__ ", Line: " STRINGIFY(__LINE__) "\n");\
                            while(true);\
                        }while(false)
 
#endif //ASSERT_H_