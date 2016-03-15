//
//  NOD_Idle.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#include "NOD_Idle.h"


void NOD_Idle::_DoEnter(const BevNodeInputParam& input) {
    m_WaitingTime = 0.5f;
}
BevRunningStatus NOD_Idle::_DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    const BevInputData& inputData = input.GetRealDataType<BevInputData>();
//    BevOutputData& outputData = output.GetRealDataType<BevOutputData>();
    f32 timeStep = inputData.m_TimeStep;
    m_WaitingTime -= timeStep;
    if (m_WaitingTime < 0) {
        return k_BRS_Finish;
    }
    return k_BRS_Executing;
}
void NOD_Idle::_DoExit(const BevNodeInputParam& input, BevRunningStatus _ui_ExitID) {
    m_WaitingTime = 0.f;
}