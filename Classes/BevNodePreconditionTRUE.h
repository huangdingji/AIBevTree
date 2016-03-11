//
//  BevNodePreconditionTRUE.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePreconditionTRUE_h
#define BevNodePreconditionTRUE_h

#include <stdio.h>
#include "BevNodePrecondition.h"

class BevNodePreconditionTRUE : public BevNodePrecondition
{
public:
    virtual bool ExternalCondition(const BevNodeInputParam& input) {
        return true;
    }
};


#endif /* BevNodePreconditionTRUE_h */
