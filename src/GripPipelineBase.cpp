/*
 * GripPipelineBase.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Matthew
 */
#include "GripPipelineBase.h"

namespace grip {
	GripPipelineBase::GripPipelineBase() {}
	void GripPipelineBase::Process(cv::Mat & source0) {}
	std::vector<std::vector<cv::Point> >* GripPipelineBase::GetFilterContoursOutput() {} // @suppress("No return")
}

