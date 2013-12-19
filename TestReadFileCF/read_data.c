#include "read_data.h"

#include <CoreFoundation/CoreFoundation.h>

char * CFStringCopyUTF8String(CFStringRef aString) {
    if (aString == NULL) {
        return NULL;
    }
    
    CFIndex length = CFStringGetLength(aString);
    CFIndex maxSize =
    CFStringGetMaximumSizeForEncoding(length,
                                      kCFStringEncodingUTF8);
    char *buffer = (char *)malloc(maxSize);
    if (CFStringGetCString(aString, buffer, maxSize,
                           kCFStringEncodingUTF8)) {
        return buffer;
    }
    return NULL;
}

FILE *data_file_pointer(void)
{
    FILE *fp = NULL;
    
    //  get a reference to the main bundle
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    if( mainBundle == NULL )
    {
        printf("unable to get main bundle\n");
        return NULL;
    }
    //  get the CFURL reference to the file we're interested in
    CFURLRef dataFileURL = CFBundleCopyResourceURL(mainBundle, CFSTR("data"), CFSTR("txt"), NULL);
    if( dataFileURL == NULL )
    {
        printf("unable to locate data file\n");
        return NULL;
    }
    //  since fopen works with paths, we need to convert CFURL reference to path
    CFStringRef path;
    if( !CFURLCopyResourcePropertyForKey(dataFileURL, kCFURLPathKey, &path, NULL))
    {
        printf("unable to get file path\n");
        return NULL;
    }
    char *pathBuffer = CFStringCopyUTF8String(path);
    fp = fopen(pathBuffer, "rb");
    free(pathBuffer);
    
    return fp;
}