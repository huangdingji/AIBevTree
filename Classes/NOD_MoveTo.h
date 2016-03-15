//
//  NOD_MoveTo.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#ifndef NOD_MoveTo_h
#define NOD_MoveTo_h

#include <stdio.h>
#include "BTInit.h"
#include "BevNodeTerminal.h"

class NOD_MoveTo : public BevNodeTerminal
{
public:
    NOD_MoveTo(BevNode* _o_ParentNode)
        :BevNodeTerminal(_o_ParentNode)
    {}
protected:
    virtual BevRunningStatus _DoExecute(const BevNodeInputParam& input,BevNodeOutputParam& output);
};

#endif /* NOD_MoveTo_h */
