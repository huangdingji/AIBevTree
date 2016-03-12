//
//  BevNodeNonePrioritySelector.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeNonePrioritySelector_h
#define BevNodeNonePrioritySelector_h

#include <stdio.h>
#include "BevNodePrioritySelector.h"

class BevNodeNonePrioritySelector : public BevNodePrioritySelector
{
public:
    BevNodeNonePrioritySelector(BevNode* _o_ParentNode, BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNodePrioritySelector(_o_ParentNode, _o_NodePrecondition)
    {}
    virtual bool _DoEvaluate(const BevNodeInputParam& input) override;
};

#endif /* BevNodeNonePrioritySelector_h */
