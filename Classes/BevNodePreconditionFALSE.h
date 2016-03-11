//
//  BevNodePreconditionFALSE.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePreconditionFALSE_h
#define BevNodePreconditionFALSE_h

#include <stdio.h>
#include "BevNodePrecondition.h"

class BevNodePreconditionFALSE : public BevNodePrecondition
{
public:
    virtual bool ExternalCondition(const BevNodeInputParam& input) {
        return false;
    }
    
};

#endif /* BevNodePreconditionFALSE_h */
