#include <barcodescanner/aw_camerafactory.h>
#include "aw_camera_default.h"

namespace BarcodeScanner {
	ICamera* CCameraFactory::create() {
		return new CCamera_Default();
	}

	void CCameraFactory::destroy(ICamera* camera) {
		delete camera;
	}
}
