//
//  CON_HasFacedToTarget.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/17.
//
//

#ifndef CON_HasFacedToTarget_h
#define CON_HasFacedToTarget_h

#include <stdio.h>
#include "BevNodePrecondition.h"
class CON_HasFacedToTarget : public BevNodePrecondition
{
public:
    virtual bool ExternalCondition(const BevNodeInputParam& input) override;
};

#endif /* CON_HasFacedToTarget_h */
