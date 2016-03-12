//
//  BevNodeParallel.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#include "BevNodeParallel.h"

bool BevNodeParallel::_DoEvaluate(const BevNodeInputParam& input) {
    for (unsigned int i = 0; i < mul_ChildNodeCount; ++i) {
        BevNode* oBN = mao_ChildNodeList[i];
        if (!oBN->Evaluate(input)) {
            return false;
        }
    }
    return true;
}
void BevNodeParallel::_DoTransition(const BevNodeInputParam& input) {
    for (unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i) {
        mab_ChildNodeStatus[i] = k_BRS_Executing;
    }
    for (unsigned int i = 0; i < mul_ChildNodeCount; ++i) {
        BevNode* oBN = mao_ChildNodeList[i];
        oBN->Transition(input);
    }
}
BevRunningStatus BevNodeParallel::_DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    unsigned int finishedChildCount = 0;
    for(unsigned int i = 0; i < mul_ChildNodeCount; ++i)
    {
        BevNode* oBN = mao_ChildNodeList[i];
        if(me_FinishCondition == k_PFC_OR)
        {
            if(mab_ChildNodeStatus[i] == k_BRS_Executing)
            {
                mab_ChildNodeStatus[i] = oBN->Tick(input, output);
            }
            if(mab_ChildNodeStatus[i] != k_BRS_Executing)
            {
                for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
                    mab_ChildNodeStatus[i] = k_BRS_Executing;
                return k_BRS_Finish;
            }
        }
        else if(me_FinishCondition == k_PFC_AND)
        {
            if(mab_ChildNodeStatus[i] == k_BRS_Executing)
            {
                mab_ChildNodeStatus[i] = oBN->Tick(input, output);
            }
            if(mab_ChildNodeStatus[i] != k_BRS_Executing)
            {
                finishedChildCount++;
            }
        }
    }
    if(finishedChildCount == mul_ChildNodeCount)
    {
        for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
            mab_ChildNodeStatus[i] = k_BRS_Executing;
        return k_BRS_Finish;
    }
    return k_BRS_Executing;
}

BevNodeParallel& BevNodeParallel::SetFinishCondition(E_ParallelFinishCondition _e_Condition) {
    me_FinishCondition = _e_Condition;
    return (*this);
}
