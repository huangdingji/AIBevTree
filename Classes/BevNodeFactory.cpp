//
//  ;
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#include "BevNodeFactory.h"
#include "BevNodeParallel.h"
#include "BevNodePrioritySelector.h"
#include "BevNodeNonePrioritySelector.h"
#include "BevNodeSequence.h"
#include "BevNodeLoop.h"
#include "BevNodeTerminal.h"

BevNode& BevNodeFactory::CreateParalleNode(BevNode* _o_Parent,E_ParallelFinishCondition _e_Condition,const char* _debugName) {
    BevNodeParallel* pReturn = new BevNodeParallel(_o_Parent);
    pReturn->SetFinishCondition(_e_Condition);
    CreateNodeCommon(pReturn, _o_Parent, _debugName);
    return (*pReturn);
}

BevNode& BevNodeFactory::CreatePrioritySelectorNode(BevNode* _o_Parent, const char* _debugName) {
    BevNodePrioritySelector* pReturn = new BevNodePrioritySelector(_o_Parent);
    CreateNodeCommon(pReturn, _o_Parent, _debugName);
    return (*pReturn);
}
BevNode& BevNodeFactory::CreateNonePrioritySelectorNode(BevNode* _o_Parent, const char* _debugName) {
    BevNodeNonePrioritySelector* pReturn = new BevNodeNonePrioritySelector(_o_Parent);
    CreateNodeCommon(pReturn, _o_Parent, _debugName);
    return (*pReturn);
}
BevNode& BevNodeFactory::CreateSequenceNode(BevNode* _o_Parent, const char* _debugName) {
    BevNodeSequence* pReturn = new BevNodeSequence(_o_Parent);
    CreateNodeCommon(pReturn, _o_Parent, _debugName);
    return (*pReturn);
}
BevNode& BevNodeFactory::CreateLoopNode(BevNode* _o_Parent, const char* _debugName, int _i_LoopCount) {
    BevNodeLoop* pReturn = new BevNodeLoop(_o_Parent, NULL, _i_LoopCount);
    CreateNodeCommon(pReturn, _o_Parent, _debugName);
    return (*pReturn);
}

//template<typename T>
//BevNode& BevNodeFactory::CreateTeminalNode(BevNode* _o_Parent, const char* _debugName)
//{
//    BevNodeTerminal* pReturn = new T(_o_Parent);
//    CreateNodeCommon(pReturn, _o_Parent, _debugName);
//    return (*pReturn);
//}


void BevNodeFactory::CreateNodeCommon(BevNode* _o_Me,BevNode* _o_Parent,const char* _debugName) {
    if (_o_Parent) {
        _o_Parent->AddChildNode(_o_Me);
    }
    _o_Me->SetDebugName(_debugName);
}
