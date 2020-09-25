#import <Foundation/Foundation.h>

@interface BarcodeScannerDelegate : NSObject

+(void) onBarcodeScanResult:(int64_t) id code:(NSString*) code;

@end
