#import "AKDViewController.h"
#import "read_data.h"

#define MAX_FILE_SIZE 1024

@interface AKDViewController ()

@end

@implementation AKDViewController

- (void)viewDidLoad {
    [super viewDidLoad];
	
    FILE *dataFilePointer = data_file_pointer();
    if( dataFilePointer != NULL )
    {
        char *content = (char *)malloc(MAX_FILE_SIZE * sizeof(char));
        if( content == NULL )
        {
            printf("ERROR | unable to alloc memory for file content\n");
            return;
        }
        while( fgets(content, MAX_FILE_SIZE, dataFilePointer) ) {
            printf("%s\n",content);
        }
        CFStringRef contentString = CFStringCreateWithCString(kCFAllocatorDefault, content, kCFStringEncodingUTF8);
        NSLog(@"The contents are: %@",(__bridge NSString *)contentString);
        
        free(content);
    }
}


@end
