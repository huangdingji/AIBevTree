//
//  NOD_Idle.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/14.
//
//

#ifndef NOD_Idle_h
#define NOD_Idle_h

#include <stdio.h>
#include "BevNodeTerminal.h"
#include "BTInit.h"

class NOD_Idle : public BevNodeTerminal
{
public:
    NOD_Idle(BevNode* _o_ParentNode)
        : BevNodeTerminal(_o_ParentNode)
        , m_WaitingTime(0.f)
    {}
    
protected:
    virtual void				_DoEnter(const BevNodeInputParam& input) override;
    virtual BevRunningStatus	_DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
    virtual void				_DoExit(const BevNodeInputParam& input, BevRunningStatus _ui_ExitID) override;
    
private:
    float m_WaitingTime;
};


#endif /* NOD_Idle_h */
