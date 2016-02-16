#pragma once

#include "Frame.h"

#include "ofxSquashBuddies/Sender.h"
#include "ofxKinectForWindows2.h"

namespace ofxMultiTrack {
	class Node {
	public:
		void init(string ipAddress, int port, bool useTexture = true);
		bool update(); // return false if dropped a frame

		ofxKinectForWindows2::Device & getKinect();

		void setTexturesEnabled(bool);
	protected:
		ofxKinectForWindows2::Device kinect;

		ofxSquashBuddies::Sender sender;
		ofxSquashBuddies::Message message;

		Frame frame;
		ofFloatPixels colorCoordInDepthFrameFloat;
		uint8_t * bodiesData;

		ofTexture yuyPreview;
	};
}