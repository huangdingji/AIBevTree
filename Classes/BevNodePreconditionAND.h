//
//  BevNodePreconditionAND.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/11.
//
//

#ifndef BevNodePreconditionAND_h
#define BevNodePreconditionAND_h

#include <stdio.h>
#include "BevNodePrecondition.h"
#include "CoreTypes.h"

class BevNodePreconditionAND : public BevNodePrecondition
{
public:
    BevNodePreconditionAND(BevNodePrecondition* lhs,BevNodePrecondition* rhs) : m_lhs(lhs),m_rhs(rhs) {}
    virtual ~BevNodePreconditionAND() {
        D_SafeDelete(m_lhs);
        D_SafeDelete(m_rhs);
    }
    
     virtual bool ExternalCondition(const BevNodeInputParam& input) override {
        return m_lhs->ExternalCondition(input) && m_rhs->ExternalCondition(input);
    }
    
private:
    BevNodePrecondition* m_lhs;
    BevNodePrecondition* m_rhs;
};


#endif /* BevNodePreconditionAND_h */
