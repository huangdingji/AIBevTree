//
//  NOD_Breathe.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/17.
//
//

#include "NOD_Breathe.h"
#include "BTInit.h"

BevRunningStatus NOD_Breathe::_DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    BevOutputData& outputData = output.GetRealDataType<BevOutputData>();
    if (m_IsIncreating) {
//        outputData.m_BodySize = outputData.m_BodySize + Size(1,1);
        outputData.m_BodySize.width = outputData.m_BodySize.width+0.1;
        if (outputData.m_BodySize.width >= 2) {
            outputData.m_BodySize.width = 1;
            m_IsIncreating = false;
        }
    } else {
        outputData.m_BodySize.width = outputData.m_BodySize.width-0.1;
        if (outputData.m_BodySize.width <= 0.5) {
           outputData.m_BodySize.width = 1;
            m_IsIncreating = true;
        }
    }
    return k_BRS_Executing;
}