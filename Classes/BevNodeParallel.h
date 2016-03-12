//
//  BevNodeParallel.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeParallel_h
#define BevNodeParallel_h

#include <stdio.h>
#include "BevNode.h"


class BevNodeParallel : public BevNode
{
public:
    BevNodeParallel(BevNode* _o_ParentNode, BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNode(_o_ParentNode, _o_NodePrecondition)
        , me_FinishCondition(k_PFC_OR)
    {
        for(unsigned int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i)
            mab_ChildNodeStatus[i] = k_BRS_Executing;
    }
    virtual bool _DoEvaluate(const BevNodeInputParam& input) override;
    virtual void _DoTransition(const BevNodeInputParam& input) override;
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
    
    BevNodeParallel& SetFinishCondition(E_ParallelFinishCondition _e_Condition);
private:
    E_ParallelFinishCondition me_FinishCondition;
    BevRunningStatus		  mab_ChildNodeStatus[k_BLimited_MaxChildNodeCnt];
};

#endif /* BevNodeParallel_h */
