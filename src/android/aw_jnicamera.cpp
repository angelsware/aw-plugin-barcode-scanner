#include "aw_jnicamera.h"
#include <barcodescanner/aw_cameralistener.h>
#include <platform/android/aw_jninativestring.h>

JNIEXPORT void JNICALL Java_com_angelsware_barcodescanner_Camera_onBarcodeScanResult(JNIEnv* env, jclass clazz, jstring data, jlong listener) {
	if (BarcodeScanner::ICameraListener* ptr = reinterpret_cast<BarcodeScanner::ICameraListener*>(listener)) {
		Platform::CJniNativeString dataStr(data);
		ptr->onBarcodeScanResult(dataStr.getText());
	}
}
