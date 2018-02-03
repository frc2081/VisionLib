/*
 * main.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Matthew
 */
#include <VisionLib.h>

namespace VisionLib {
	VisionLib::VisionLib() {
		NetworkTable::SetClientMode();
		NetworkTable::SetIPAddress("10.20.81.2");
		NetworkTable::Initialize();
	}

	void VisionLib::AddCamera() {
		VisionLib::cameras.emplace_back(cameras.size());
	}

	void VisionLib::AddCamera(int camera) {
		VisionLib::cameras.emplace_back(camera);
	}

	void VisionLib::operator ++() {
		AddCamera();
	}

	void VisionLib::operator ++(int) {
		AddCamera();
	}

	cv::VideoCapture* VisionLib::operator [](int index) {
		cv::VideoCapture *_ = &cameras[index];
		return _;
	}

	void VisionLib::AddGripPipeline(std::string pipelinename, grip::GripPipelineBase *GripPipeline)
	{
		// Yes, this is slow, but I can't think of another way to make this work
		grip::GripPipelineBase _ = *GripPipeline->MoveThis();
		delete &GripPipeline;
		_pipelines.insert(std::pair<std::string, grip::GripPipelineBase>(pipelinename, _));
	}
	void AddGripGroup(VisionLib vslib, std::string pipelinename, std::vector<int> cameras, int outputtype) {

	}

	void VisionLib::Update() {
		// Update groups
		for (GripGroup group : _groups)
		{
			group.Process();
		}
	}
}

