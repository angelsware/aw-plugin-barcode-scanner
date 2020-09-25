class BarcodeScanner: NSObject {
	private var listeners: Set<Int64> = Set()

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
		// TODO: Implement magic.
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
