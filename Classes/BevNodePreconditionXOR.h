//
//  BevNodePreconditionXOR.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePreconditionXOR_h
#define BevNodePreconditionXOR_h

#include <stdio.h>
#include "BevNodePrecondition.h"
#include "CoreTypes.h"
class BevNodePreconditionXOR : public BevNodePrecondition
{
public:
    BevNodePreconditionXOR(BevNodePrecondition* lhs, BevNodePrecondition* rhs): m_lhs(lhs), m_rhs(rhs) {}
    ~BevNodePreconditionXOR(){
        D_SafeDelete(m_lhs);
        D_SafeDelete(m_rhs);
    }
    virtual bool ExternalCondition(const BevNodeInputParam& input) override {
        return m_lhs->ExternalCondition(input) ^ m_rhs->ExternalCondition(input);
    }
private:
    BevNodePrecondition* m_lhs;
    BevNodePrecondition* m_rhs;
};

#endif /* BevNodePreconditionXOR_h */
