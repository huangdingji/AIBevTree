//
//  BevNodeNodePrioritySelector.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeNodePrioritySelector_h
#define BevNodeNodePrioritySelector_h

#include <stdio.h>
#include "BevNodePrioritySelector.h"

class BevNodeNonePrioritySelector : public BevNodePrioritySelector
{
    BevNodeNodePrioritySelector(BevNOde* _o_ParentNode,BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNodePrioritySelector(_o_NodePrecondition,_o_NodePrecondition)
    {}
    
};

#endif /* BevNodeNodePrioritySelector_h */
