#ifndef Test_CF_read_data_h__
#define Test_CF_read_data_h__
#include <stdio.h>
#include <CoreFoundation/CFString.h>

/**
 *	File pointer to the file "data.txt"
 *
 *	@return	Returns a file pointer to the file "data.txt" if the file can be opened.  If the
 *          file cannot be opened, or an error occurs, returns \p NULL.
 */
extern FILE *data_file_pointer(void);

/**
 *	C string from a CFString
 *
 *	@param	aString	The CFString to convert
 *
 *	@return	Returns a C string from the contents of the CFString provided.
 */
extern char * CFStringCopyUTF8String(CFStringRef aString);

#endif
