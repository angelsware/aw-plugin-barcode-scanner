import AVFoundation
import UIKit

class BarcodeScanner: UIViewController, AVCaptureMetadataOutputObjectsDelegate {
	private var listeners: Set<Int64> = Set()
	private var captureSession: AVCaptureSession!
	private var previewLayer: AVCaptureVideoPreviewLayer!

	func addListener(listener: Int64) {
		listeners.insert(listener)
	}

	func removeListener(listener: Int64) {
		listeners.remove(listener)
	}

	func clearAllListeners() {
		listeners.removeAll()
	}

	func scan() {
		captureSession = AVCaptureSession()
		guard let videoCaptureDevice = AVCaptureDevice.default(for: .video) else {
			return
		}
		let videoInput: AVCaptureDeviceInput

		do {
			videoInput = try AVCaptureDeviceInput(device: videoCaptureDevice)
		} catch {
			return
		}

		if (captureSession.canAddInput(videoInput)) {
			captureSession.addInput(videoInput)
		} else {
			return
		}

		let metadataOutput = AVCaptureMetadataOutput()

		if (captureSession.canAddOutput(metadataOutput)) {
			captureSession.addOutput(metadataOutput)

			metadataOutput.setMetadataObjectsDelegate(self, queue: DispatchQueue.main)
			metadataOutput.metadataObjectTypes = [.qr]
		} else {
			return
		}
		
		previewLayer = AVCaptureVideoPreviewLayer(session: captureSession)
		previewLayer.frame = view.layer.bounds
		previewLayer.videoGravity = .resizeAspectFill
		view.layer.addSublayer(previewLayer)

		let appDelegate = UIApplication.shared.delegate as! AppDelegate
		appDelegate.window?.rootViewController?.present(self, animated: true)
		
		captureSession.startRunning()
	}
	
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)

		if (captureSession?.isRunning == false) {
			captureSession.startRunning()
		}
	}

	override func viewWillDisappear(_ animated: Bool) {
		super.viewWillDisappear(animated)

		if (captureSession?.isRunning == true) {
			captureSession.stopRunning()
		}
	}

	func metadataOutput(_ output: AVCaptureMetadataOutput, didOutput metadataObjects: [AVMetadataObject], from connection: AVCaptureConnection) {
		captureSession.stopRunning()

		if let metadataObject = metadataObjects.first {
			guard let readableObject = metadataObject as? AVMetadataMachineReadableCodeObject else { return }
			guard let stringValue = readableObject.stringValue else { return }
			AudioServicesPlaySystemSound(SystemSoundID(kSystemSoundID_Vibrate))
			found(code: stringValue)
		}

		dismiss(animated: true)
	}
	
	func found(code: String) {
		listeners.forEach { listener in
			BarcodeScannerDelegate.onBarcodeScanResult(listener, code: code)
		}
	}
	
	override var prefersStatusBarHidden: Bool {
		return true
	}

	override var supportedInterfaceOrientations: UIInterfaceOrientationMask {
		return .portrait
	}
}

@_cdecl("BarcodeScanner_create")
func BarcodeScanner_create() -> UnsafeMutablePointer<BarcodeScanner> {
	let barcodeScanner = UnsafeMutablePointer<BarcodeScanner>.allocate(capacity: 1)
	barcodeScanner.initialize(to: BarcodeScanner())
	return barcodeScanner
}

@_cdecl("BarcodeScanner_destroy")
func BarcodeScanner_destroy(ptr: UnsafeMutablePointer<BarcodeScanner>) {
	ptr.deallocate()
}

@_cdecl("BarcodeScanner_addListener")
func BarcodeScanner_addListener(ptr: UnsafeMutablePointer<BarcodeScanner>, listener: Int64) {
	ptr.pointee.addListener(listener: listener)
}

@_cdecl("BarcodeScanner_removeListener")
func BarcodeScanner_removeListener(ptr: UnsafeMutablePointer<BarcodeScanner>, listener: Int64) {
	ptr.pointee.removeListener(listener: listener)
}

@_cdecl("BarcodeScanner_clearAllListeners")
func BarcodeScanner_clearAllListeners(ptr: UnsafeMutablePointer<BarcodeScanner>) {
	ptr.pointee.clearAllListeners()
}

@_cdecl("BarcodeScanner_scan")
func BarcodeScanner_scan(ptr: UnsafeMutablePointer<BarcodeScanner>) {
	ptr.pointee.scan()
}
