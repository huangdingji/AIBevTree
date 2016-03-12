//
//  BevNodeSequence.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#include "BevNodeSequence.h"

bool BevNodeSequence::_DoEvaluate(const BevNodeInputParam& input) {
    if (_bCheckIndex(mui_CurrentNodeIndex)) {
        BevNode* oBN = mao_ChildNodeList[mui_CurrentNodeIndex];
        if (oBN->Evaluate(input)) {
            return true;
        }
    }
    return false;
}

void BevNodeSequence::_DoTransition(const BevNodeInputParam& input) {
    if (_bCheckIndex(mui_CurrentNodeIndex)) {
        BevNode* oBN = mao_ChildNodeList[mui_CurrentNodeIndex];
        oBN->Transition(input);
    }
    mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
}
BevRunningStatus BevNodeSequence::_DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    BevRunningStatus bIsFinish = k_BRS_Finish;
    if (mui_CurrentNodeIndex == k_BLimited_InvalidChildNodeIndex) {
        mui_CurrentNodeIndex = 0;
    }
    BevNode* oBN = mao_ChildNodeList[mui_CurrentNodeIndex];
    bIsFinish = oBN->Tick(input, output);
    if (bIsFinish == k_BRS_Finish) {
        ++mui_CurrentNodeIndex;
        if (mui_CurrentNodeIndex == mul_ChildNodeCount) {
            mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
        }
        else
        {
            bIsFinish = k_BRS_Executing;
        }
    }
    if (bIsFinish < 0) {
        mui_CurrentNodeIndex = k_BLimited_InvalidChildNodeIndex;
    }
    return bIsFinish;
}
