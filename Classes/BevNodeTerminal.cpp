//
//  BevNodeTerminal.cpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/12.
//
//

#include "BevNodeTerminal.h"

void BevNodeTerminal::_DoTransition(const BevNodeInputParam& input) {
    if (mb_NeedExit) {
        _DoExit(input, k_BRS_ERROR_Transition);
    }
    SetActiveNode(nullptr);
    me_Status = k_TNS_Ready;
    mb_NeedExit = false;
}
BevRunningStatus BevNodeTerminal::_DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output) {
    BevRunningStatus bIsFinish = k_BRS_Finish;
    if (me_Status == k_TNS_Ready) {
        _DoEnter(input);
        mb_NeedExit = true;
        me_Status = k_TNS_Running;
        SetActiveNode(this);
    }
    if (me_Status == k_TNS_Running) {
        bIsFinish = _DoExecute(input, output);
        SetActiveNode(this);
        if (bIsFinish == k_BRS_Finish || bIsFinish < 0) {
            me_Status = k_TNS_Finish;
        }
    }
    
    if (me_Status == k_TNS_Finish) {
        if (mb_NeedExit) {
            _DoExit(input, bIsFinish);
        }
        me_Status = k_TNS_Ready;
        mb_NeedExit = false;
        SetActiveNode(nullptr);

        return bIsFinish;
    }
    
    return bIsFinish;
}

