//
//  BevNodeLoop.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeLoop_h
#define BevNodeLoop_h

#include <stdio.h>
#include "BevNode.h"

class BevNodeLoop : public BevNode
{
public:
    static const int kInfiniteLoop = -1;
public:
    BevNodeLoop(BevNode* _o_ParentNode,BevNodePrecondition* _o_NodePrecondition = nullptr)
//        : BevNode(_o_ParentNode,)
    {}
    
    virtual bool _DoEvaluate(const BevNodeInputParam& input);
    virtual void _DoTransition(const BevNodeInputParam& input);
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output);
    
private:
    int mi_LoopCount;
    int mi_CurrentCount;
};

#endif /* BevNodeLoop_h */
