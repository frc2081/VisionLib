/*
 * GripGroup.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Matthew
 */

#include <GripGroup.h>

namespace VisionLib {
	GripGroup::GripGroup(grip::GripPipelineBase *base, std::string name, std::vector<cv::VideoCapture*> pcameras, int outputtype = 0) {
		_pcameras = pcameras;
		_name = name;
		_Pipeline = base->MoveThis();
		delete base;
		_ntable = NetworkTable::GetTable(name);
		/*if(outputtype == 0)
		{
			_OutputFunction = _Pipeline->GetFilterContoursOutput;
		}*/
	}

	void GripGroup::Process() {
		for (uint x = 0; x < _pcameras.size(); ++x) {
			_pcameras[x]->read(_mats[x]);
			_Pipeline->Process(_mats[x]);
		}
	}

	void GripGroup::PublishValues(int camera) {
		for (std::vector<cv::Point> contour : *_Pipeline->GetFilterContoursOutput()) {
			cv::Rect bb = cv::boundingRect(cv::InputArray(contour));
			_ntable->PutNumber(llvm::StringRef((char)camera + "/height"), bb.height);
			_ntable->PutNumber(llvm::StringRef((char)camera + "/width"), bb.width);
		}
	}

} /* namespace VisionLib */
