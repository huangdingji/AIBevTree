//
//  BevNodeFactory.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#ifndef BevNodeFactory_h
#define BevNodeFactory_h

#include <stdio.h>
#include "BevNode.h"

class BevNodeFactory {
public:
    static BevNode& CreateParalleNode(BevNode* _o_Parent,E_ParallelFinishCondition _e_Condition,const char* _debugName);
    static BevNode& CreatePrioritySelectorNode(BevNode* _o_Parent, const char* _debugName);
    static BevNode& CreateNonePrioritySelectorNode(BevNode* _o_Parent, const char* _debugName);
    static BevNode& CreateSequenceNode(BevNode* _o_Parent, const char* _debugName);
    static BevNode& CreateLoopNode(BevNode* _o_Parent, const char* _debugName, int _i_LoopCount);
//    template<typename T>
    static BevNode& oCreateTeminalNode(BevNode* _o_Parent, const char* _debugName);
//    {
//        BevNodeTerminal* pReturn = new T(_o_Parent);
//        oCreateNodeCommon(pReturn, _o_Parent, _debugName);
//        return (*pReturn);
//    }
private:
    static void CreateNodeCommon(BevNode* _o_Me,BevNode* _o_Parent,const char* _debugName);
    
    
};

#endif /* BevNodeFactory_h */
