#ifndef __AW_BARCODE_SCANNER_CAMERA_ANDROID_H__
#define __AW_BARCODE_SCANNER_CAMERA_ANDROID_H__

#include <barcodescanner/aw_camera.h>
#include <platform/android/aw_jniclass.h>

namespace BarcodeScanner {
	class ICameraListener;

	class CCamera_Android
		: public ICamera
	{
	public:
		CCamera_Android();
		~CCamera_Android();

	private:
		void addListener(ICameraListener* listener) override;
		void removeListener(ICameraListener* listener) override;
		void removeAllListeners() override;
		void scan() override;

		Platform::CJniClass mObject;
	};
}

#endif
