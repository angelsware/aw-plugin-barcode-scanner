package com.angelsware.engine;

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

import android.util.Log;
import android.app.Activity;
import android.content.Intent;

import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;

public class Camera implements ActivityResultListener {
	public static native void onBarcodeScanResult(String data, long listener);

	private static String TAG = "aw";

	private List mListeners = new ArrayList();
	private IntentIntegrator mIntentIntegrator;

	public Camera() {
		Activity activity = AppActivity.getActivity();
		((AppActivity)activity).addActivityResultListener(this);
		mIntentIntegrator = new IntentIntegrator(AppActivity.getActivity());
		setText("");
	}

	public void onDestroy() {
		Activity activity = AppActivity.getActivity();
		((AppActivity)activity).removeActivityResultListener(this);
	}

	public void addListener(long listener) {
		mListeners.add(listener);
	}

	public void removeListener(long listener) {
		mListeners.remove(listener);
	}

	public void clearAllListeners() {
		mListeners.clear();
	}

	public void scan() {
		mIntentIntegrator.initiateScan();
	}

	@Override
	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		IntentResult result = IntentIntegrator.parseActivityResult(requestCode, resultCode, data);
		if (result != null) {
			String text = result.getContents() != null ? result.getContents() : null;
			for (Iterator<Long> i = mListeners.iterator(); i.hasNext();) {
				Long listener = i.next();
				onBarcodeScanResult(text, listener);
			}
		}
	}
}
