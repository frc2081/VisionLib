/*
 * GripGroup.h
 *
 *  Created on: Jan 23, 2018
 *      Author: Matthew
 */

#ifndef SRC_GRIPGROUP_H_
#define SRC_GRIPGROUP_H_

#include <typeinfo>
#include <llvm/Twine.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include "NetworkTables/NetworkTableInstance.h"
#include <GripPipelineBase.h>
#include <VisionLib.h>

namespace VisionLib {

class GripGroup {
	public:
		GripGroup(grip::GripPipelineBase *base,
				  std::string pipelinename,
				  std::vector<cv::VideoCapture*> pcameras,
				  int outputtype);

		void Process();
	private:
		std::vector<cv::Mat> _mats;
		std::string _name;
		grip::GripPipelineBase *_Pipeline;
		std::vector<cv::VideoCapture*> _pcameras;
		std::shared_ptr<NetworkTable> _ntable;
		void PublishValues(int);
	};

} /* namespace VisionLib */

#endif /* SRC_GRIPGROUP_H_ */
