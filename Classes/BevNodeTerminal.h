//
//  BevNodeTerminal.h
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#ifndef BevNodeTerminal_h
#define BevNodeTerminal_h

#include <stdio.h>
#include "BevNode.h"

class BevNodeTerminal : public BevNode
{
public:
    BevNodeTerminal(BevNode* _o_Parent,BevNodePrecondition* _o_NodePrecondition = nullptr)
        : BevNode(_o_Parent,_o_NodePrecondition)
        , me_Status(k_TNS_Ready)
        , mb_NeedExit(false)
    {}
    
    virtual void _DoTransition(const BevNodeInputParam& input) override;
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) override;
    
protected:
    virtual void				_DoEnter(const BevNodeInputParam& input)								{}
    virtual BevRunningStatus	_DoExecute(const BevNodeInputParam& input, BevNodeOutputParam& output)	{ return k_BRS_Finish;}
    virtual void				_DoExit(const BevNodeInputParam& input, BevRunningStatus _ui_ExitID)	{}
    
private:
    E_TerminalNodeStaus me_Status;
    bool mb_NeedExit;
};


#endif /* BevNodeTerminal_h */
