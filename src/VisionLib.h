/*
 * main.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Matthew
 */
#ifndef SRC_VISIONLIB_H_
#define SRC_VISIONLIB_H_

#include <GripPipeline.h>
#include <vector>

namespace VisionLib
{
	class VisionLib {
	public:
		/* Functions to add a new camera */
		void AddCamera();
		void AddCamera(int camera);


	private:
		VisionLib() {}
		void Update();

	protected:
		std::vector<cv::VideoCapture> cameras;

	public:
		/* Overloads for singleton */
		VisionLib(VisionLib const&) = delete;
		void operator=(VisionLib const&) = delete;

		/* Overloads for convenience */
		void operator++();
		void operator++(int);
		cv::VideoCapture* operator[](int index);
	};
}
#endif /* SRC_MAIN_H_ */
