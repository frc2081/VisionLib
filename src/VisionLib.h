/*
 * main.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Matthew
 */
#ifndef SRC_VISIONLIB_H_
#define SRC_VISIONLIB_H_

#include <GripPipelineBase.h>
#include <GripGroup.h>
#include <opencv2/videoio/videoio.hpp>
#include <vector>
#include <string>
#include <map>
#include <thread>
#include "WPILib.h"
#include "NetworkTables/NetworkTable.h"

namespace VisionLib
{
class VisionLib;
class GripGroup;

class VisionLib {
	public:
		VisionLib();
		/* Functions to add a new camera */
		void AddCamera();
		void AddCamera(int camera);

		void AddGripPipeline(std::string pipelinename,
							 grip::GripPipelineBase *GripPipeline);

		void AddGripGroup(std::string pipelinename,
				          grip::GripPipelineBase pipeline,
						  std::vector<int> cameras,
						  int outputtype);

		cv::VideoCapture* GetCamera(int index);

		std::vector<cv::VideoCapture> cameras;

/* Don't change anything in the file past this point */

		/* Overloads for convenience */
		void operator++();
		void operator++(int);
		cv::VideoCapture* operator[](int index);

	private:
		std::vector<GripGroup> _groups;
		std::map<std::string, grip::GripPipelineBase> _pipelines;
		void Update();
};
}
#endif /* SRC_MAIN_H_ */
