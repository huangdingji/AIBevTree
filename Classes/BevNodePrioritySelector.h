//
//  BevNodePrioritySelector.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodePrioritySelector_h
#define BevNodePrioritySelector_h

#include <stdio.h>
#include "BevNode.h"



class BevNodePrioritySelector : public BevNode
{
public:
    BevNodePrioritySelector(BevNode* o_ParentNode,BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNode(o_ParentNode,_o_NodePrecondition)
        , mui_LastSelectIndex(k_BLimited_InvalidChildNodeIndex)
        , mui_CurrentSelectIndex(k_BLimited_InvalidChildNodeIndex)
    {}
    
    virtual bool _DoEvaluate(const BevNodeInputParam& input) override;
    virtual void _DoTransition(const BevNodeInputParam& input) override;
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
protected:
    u32 mui_CurrentSelectIndex;
    u32 mui_LastSelectIndex;
    
};

#endif /* BevNodePrioritySelector_h */
