#include "aw_camera_android.h"
#include <platform/android/aw_jnistring.h>

namespace BarcodeScanner {
	CCamera_Android::CCamera_Android()
		: mObject("com/angelsware/barcodescanner/Camera", "()V")
	{}

	CCamera_Android::~CCamera_Android() {
		mObject.callVoidMethod("onDestroy", "()V");
	}

	void CCamera_Android::addListener(ICameraListener* listener) {
		mObject.callVoidMethod("addListener", "(J)V", reinterpret_cast<jlong>(listener));
	}

	void CCamera_Android::removeListener(ICameraListener* listener) {
		mObject.callVoidMethod("removeListener", "(J)V", reinterpret_cast<jlong>(listener));
	}

	void CCamera_Android::removeAllListeners() {
		mObject.callVoidMethod("removeAllListeners", "()V");
	}

	void CCamera_Android::scan() {
		mObject.callVoidMethod("scan", "()V");
	}
}
