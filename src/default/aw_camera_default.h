#ifndef __AW_BARCODE_SCANNER_CAMERA_DEFAULT_H__
#define __AW_BARCODE_SCANNER_CAMERA_DEFAULT_H__

#include <barcodescanner/aw_camera.h>

namespace BarcodeScanner {
	class CCamera_Default
		: public ICamera
	{
	private:
		void addListener(ICameraListener* listener) override {}
		void removeListener(ICameraListener* listener) override {}
		void removeAllListeners() override {}
		void scan() override {}
	};
}

#endif
