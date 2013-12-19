#ifndef Test_CF_read_data_h__
#define Test_CF_read_data_h__
#include <stdio.h>
#include <CoreFoundation/CFString.h>

extern FILE *data_file_pointer(void);
extern char * CFStringCopyUTF8String(CFStringRef aString);

#endif
