//
//  BevNodePrioritySelector.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#include "BevNodePrioritySelector.h"


bool BevNodePrioritySelector::_DoEvaluate(const BevNodeInputParam& input) {
    mui_CurrentSelectIndex = k_BLimited_InvalidChildNodeIndex;
    for (unsigned int i = 0; i < mul_ChildNodeCount; ++i) {
        BevNode* oBN = mao_ChildNodeList[i];
        if (oBN->Evaluate(input) {
            mui_CurrentSelectIndex = i;
            return true;
        }
    }
    return false
}
void BevNodePrioritySelector::_DoTransition(const BevNodeInputParam& input) {
    if (_bCheckIndex(mui_LastSelectIndex)) {
        BevNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
        oBN->Transition(input);
    }
    mui_LastSelectIndex = k_BLimited_InvalidChildNodeIndex;
}
BevRunningStatus BevNodePrioritySelector::_DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    BevRunningStatus bIsFinish = k_BRS_Finish;
    if (_bCheckIndex(mui_CurrentSelectIndex)) {
        if (mui_CurrentSelectIndex != mui_LastSelectIndex) {
            if (_bCheckIndex(mui_LastSelectIndex)) {
                BevNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
                oBN->Transition(input);
            }
            mui_LastSelectIndex = mui_CurrentSelectIndex;
        }
    }
    if (_bCheckIndex(mui_LastSelectIndex)) {
        BevNode* oBN = mao_ChildNodeList[mui_LastSelectIndex];
        bIsFinish = oBN->Tick(input, output);
        if (bIsFinish) {
            mui_LastSelectIndex = k_BLimited_InvalidChildNodeIndex;
        }
    }
    return bIsFinish;
}
