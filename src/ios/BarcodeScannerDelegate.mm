#import "BarcodeScannerDelegate.h"
#import <barcodescanner/aw_cameralistener.h>

@implementation BarcodeScannerDelegate

+(void) onBarcodeScanResult:(int64_t) id code:(NSString*) code {
    reinterpret_cast<BarcodeScanner::ICameraListener*>(id)->onBarcodeScanResult([code UTF8String]);
}

@end
