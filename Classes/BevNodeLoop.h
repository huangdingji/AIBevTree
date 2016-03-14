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
    BevNodeLoop(BevNode* _o_ParentNode,BevNodePrecondition* _o_NodePrecondition = nullptr,int _i_LoopCnt = kInfiniteLoop)
        : BevNode(_o_ParentNode,_o_NodePrecondition)
        , mi_LoopCount(_i_LoopCnt)
        , mi_CurrentCount(0)
    {}
    
    virtual bool _DoEvaluate(const BevNodeInputParam& input) override;
    virtual void _DoTransition(const BevNodeInputParam& input) override;
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
    
private:
    int mi_LoopCount;
    int mi_CurrentCount;
};

#endif /* BevNodeLoop_h */
