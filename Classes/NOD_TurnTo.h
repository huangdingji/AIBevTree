//
//  NOD_TurnTo.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/17.
//
//

#ifndef NOD_TurnTo_h
#define NOD_TurnTo_h

#include <stdio.h>
#include "BevNodeTerminal.h"


class NOD_TurnTo : public BevNodeTerminal
{
public:
    NOD_TurnTo(BevNode* _o_ParentNode)
        : BevNodeTerminal(_o_ParentNode)
    {}
    virtual BevRunningStatus _DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
};


#endif /* NOD_TurnTo_h */
