#ifndef __AW_BARCODE_SCANNER_CAMERA_LISTENER_H__
#define __AW_BARCODE_SCANNER_CAMERA_LISTENER_H__

namespace BarcodeScanner {
	class ICameraListener
	{
	public:
		virtual void onBarcodeScanResult(const char* data) = 0;

	protected:
		~ICameraListener() {}
	};
}

#endif
