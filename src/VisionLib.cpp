/*
 * main.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Matthew
 */
#include <VisionLib.h>

namespace VisionLib {
	void VisionLib::AddCamera() {
		this->cameras.emplace_back(cameras.size());
	}

	void VisionLib::AddCamera(int camera) {
		this->cameras.emplace_back(camera);
	}

	void VisionLib::operator ++() {
		AddCamera();
	}

	void VisionLib::operator ++(int) {
		AddCamera();
	}

	cv::VideoCapture* VisionLib::operator [](int index) {
		return &this->cameras[index];
	}

	void VisionLib::Update() {

	}
}

