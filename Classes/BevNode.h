//
//  BevNode.hpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/9.
//
//
#ifndef BevNode_h
#define BevNode_h

#include <string>
#include "AppMacros.h"
#include "CoreTypes.h"
#include "BevNodePrecondition.h"
class BevNode {
public:
//    BevNode(BevNode*)
    
    
private:
    BevNode* mao_ChildNodeList[k_BLimited_MaxChildNodeCnt];
    u32 mul_ChildNodeCount;
    BevNode* mo_ParentNode;
    BevNode* mo_ActiveNode;
    BevNode* mo_LastActiveNode;
    BevNodePrecondition* mo_NodePreconditon;
    std::string mz_DebugName;
};


#endif /* BevNode_h */
