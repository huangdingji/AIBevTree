//
//  NOD_MoveTo.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#include "NOD_MoveTo.h"

BevRunningStatus NOD_MoveTo::_DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    const BevInputData& inputData = input.GetRealDataType<BevInputData>();
    BevOutputData& outputData = output.GetRealDataType<BevOutputData>();
    
    f32 timeStep = inputData.m_TimeStep;
    Vec2 targetPoint = inputData.m_TargetPosition;
    Vec2 curPosition = inputData.m_Ower->getPosition();
    
    Vec2 dir = targetPoint-curPosition;
    if (dir.lengthSquared() < 2.f) {
        outputData.m_NextPosition = targetPoint;
        return k_BRS_Finish;
    }
    else {
        dir.normalize();
        Vec2 nexPos = curPosition+dir*timeStep*100.f; // 沿着目标方向移动
        outputData.m_NextPosition = nexPos;
    }
    return k_BRS_Executing;
}
