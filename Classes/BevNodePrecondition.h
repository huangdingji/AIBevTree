//
//  BevNodePrecondition.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePrecondition_h
#define BevNodePrecondition_h

#include <stdio.h>
#include "AppMacros.h"

class BevNodePrecondition {
public:
    virtual bool ExternalCondition(const BevNodeInputParam& input) = 0;
};



#endif /* BevNodePrecondition_h */
