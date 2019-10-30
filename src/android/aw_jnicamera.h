#ifndef __BARCODE_SCANNER_JNI_CAMERA_H__
#define __BARCODE_SCANNER_JNI_CAMERA_H__

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_com_angelsware_barcodescanner_Camera_onBarcodeScanResult(JNIEnv* env, jclass clazz, jstring data, jlong listener);
#ifdef __cplusplus
}
#endif

#endif
