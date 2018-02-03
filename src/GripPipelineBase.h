/*
 * GripPipelineBase.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Matthew
 */

#ifndef SRC_GRIPPIPELINEBASE_H_
#define SRC_GRIPPIPELINEBASE_H_
#include <vector>
#include <opencv2/core/core.hpp>

namespace grip
{
	class GripPipelineBase {
	public:
		GripPipelineBase();

		GripPipelineBase* MoveThis() const { return new GripPipelineBase(*this); };

		/* So we can call the output function from anywhere */
		void Process(cv::Mat& source0);
		std::vector<std::vector<cv::Point> >* GetFilterContoursOutput();
	};
}




#endif /* SRC_GRIPPIPELINEBASE_H_ */
