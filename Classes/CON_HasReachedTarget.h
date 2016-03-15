//
//  CON_HasReachedTarget.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#ifndef CON_HasReachedTarget_h
#define CON_HasReachedTarget_h

#include <stdio.h>
#include "BevNodePrecondition.h"
#include "BTInit.h"
#include "cocos2d.h"
USING_NS_CC;

class CON_HasReachedTarget : public BevNodePrecondition
{
public:
    virtual bool ExternalCondition(const BevNodeInputParam& input) override;
};



#endif /* CON_HasReachedTarget_h */
