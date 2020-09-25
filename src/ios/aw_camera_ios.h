#ifndef __AW_BARCODE_SCANNER_CAMERA_IOS_H__
#define __AW_BARCODE_SCANNER_CAMERA_IOS_H__

#include <barcodescanner/aw_camera.h>

namespace BarcodeScanner {
	class CCamera_Ios
		: public ICamera
	{
	public:
		CCamera_Ios();
		~CCamera_Ios();

	private:
		void addListener(ICameraListener* listener) override;
		void removeListener(ICameraListener* listener) override;
		void clearAllListeners() override;
		void scan() override;

		void* mBarcodeScanner;
	};
}

#endif
