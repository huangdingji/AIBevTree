//
//  BevNodePreconditionNOT.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePreconditionNOT_h
#define BevNodePreconditionNOT_h

#include <stdio.h>
#include "BevNodePrecondition.h"
#include "CoreTypes.h"


class BevNodePreconditionNOT : public BevNodePrecondition
{
public:
    BevNodePreconditionNOT(BevNodePrecondition* lhs) : m_lhs(lhs) {}
    virtual ~BevNodePreconditionNOT() {
        D_SafeDelete(m_lhs);
    }
    virtual bool ExternalCondition(const BevNodeInputParam& input) override {
        return !m_lhs->ExternalCondition(input);
    }
    
private:
    BevNodePrecondition* m_lhs;
};



#endif /* BevNodePreconditionNOT_h */
