#include <barcodescanner/aw_camerafactory.h>
#include "aw_camera_ios.h"

namespace BarcodeScanner {
	ICamera* CCameraFactory::create() {
		return new CCamera_Ios();
	}

	void CCameraFactory::destroy(ICamera* camera) {
		delete camera;
	}
}
