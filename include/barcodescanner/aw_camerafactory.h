#ifndef __AW_BARCODE_SCANNER_CAMERA_FACTORY_H__
#define __AW_BARCODE_SCANNER_CAMERA_FACTORY_H__

namespace BarcodeScanner {
	class ICamera;

	class CCameraFactory
	{
	public:
		static ICamera* create();
		static void destroy(ICamera* camera);
	};
}

#endif
