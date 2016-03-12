//
//  BevNodeNonePrioritySelector.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#include "BevNodeNonePrioritySelector.h"
bool BevNodeNonePrioritySelector::_DoEvaluate(const BevNodeInputParam& input)
{
    if(_bCheckIndex(mui_CurrentSelectIndex))
    {
        BevNode* oBN = mao_ChildNodeList[mui_CurrentSelectIndex];
        if(oBN->Evaluate(input))
        {
            return true;
        }
    }
    return BevNodePrioritySelector::_DoEvaluate(input);
}