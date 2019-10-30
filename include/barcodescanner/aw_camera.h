#ifndef __AW_BARCODE_SCANNER_CAMERA_H__
#define __AW_BARCODE_SCANNER_CAMERA_H__

namespace BarcodeScanner {
	class ICameraListener;

	class ICamera
	{
	public:
		virtual ~ICamera() {}

		virtual void addListener(ICameraListener* listener) = 0;
		virtual void removeListener(ICameraListener* listener) = 0;
		virtual void removeAllListeners() = 0;
		virtual void scan() = 0;
	};
}

#endif
