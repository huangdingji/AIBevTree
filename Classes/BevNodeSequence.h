//
//  BevNodeSequence.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeSequence_h
#define BevNodeSequence_h

#include <stdio.h>
#include "BevNode.h"


class BevNodeSequence : public BevNode
{
    BevNodeSequence(BevNode* _o_ParentNode,BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNode(_o_ParentNode,_o_NodePrecondition)
        , mui_CurrentNodeIndex(k_BLimited_InvalidChildNodeIndex)
    {}
    
    virtual bool _DoEvaluate(const BevNodeInputParam& input) override;
    
    virtual void _DoTransition(const BevNodeInputParam& input) override;
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
    
private:
    u32 mui_CurrentNodeIndex;
};

#endif /* BevNodeSequence_h */
