//
//  NOD_Breathe.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/17.
//
//

#ifndef NOD_Breathe_h
#define NOD_Breathe_h

#include <stdio.h>
#include "BevNodeTerminal.h"

class NOD_Breathe : public BevNodeTerminal
{
public:
    NOD_Breathe(BevNode* _o_ParentNode)
        : BevNodeTerminal(_o_ParentNode)
    {}
    virtual BevRunningStatus _DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
private:
    bool m_IsIncreating;
};


#endif /* NOD_Breathe_h */
