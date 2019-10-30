# aw-plugin-gps

Barcode scanner plugin for Angels' Ware rendering engine.

### Getting Started

Add the **plugins** section to the **config.yaml** file of your project.

```
...

plugins:
	repo: https://github.com/angelsware/aw-plugin-barcode-scanner.git
```

```
BarcodeScanner::ICamera* camera = BarcodeScanner::CCameraFactory::create();
camera->addListener(this);
camera->scan();

```
