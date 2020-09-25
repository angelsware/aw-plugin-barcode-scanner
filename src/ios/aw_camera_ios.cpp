#include "aw_camera_ios.h"

extern "C" {
	void* BarcodeScanner_create();
	void BarcodeScanner_destroy(void* ptr);
	void BarcodeScanner_addListener(void* ptr, long long listener);
	void BarcodeScanner_removeListener(void* ptr, long long listener);
	void BarcodeScanner_clearAllListeners(void* ptr);
	void BarcodeScanner_scan(void* ptr);
}

namespace BarcodeScanner {
	CCamera_Ios::CCamera_Ios() {
		mBarcodeScanner = BarcodeScanner_create();
	}

	CCamera_Ios::~CCamera_Ios() {
		BarcodeScanner_destroy(mBarcodeScanner);
	}

	void CCamera_Ios::addListener(ICameraListener* listener) {
		BarcodeScanner_addListener(mBarcodeScanner, reinterpret_cast<long long>(listener));
	}

	void CCamera_Ios::removeListener(ICameraListener* listener) {
		BarcodeScanner_removeListener(mBarcodeScanner, reinterpret_cast<long long>(listener));
	}

	void CCamera_Ios::clearAllListeners() {
		BarcodeScanner_clearAllListeners(mBarcodeScanner);
	}

	void CCamera_Ios::scan() {
		BarcodeScanner_scan(mBarcodeScanner);
	}
}
//https://www.hackingwithswift.com/example-code/media/how-to-scan-a-qr-code
