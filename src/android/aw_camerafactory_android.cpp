#include <barcodescanner/aw_camerafactory.h>
#include "aw_camera_android.h"

namespace BarcodeScanner {
	ICamera* CCameraFactory::create() {
		return new CCamera_Android();
	}

	void CCameraFactory::destroy(ICamera* camera) {
		delete camera;
	}
}
