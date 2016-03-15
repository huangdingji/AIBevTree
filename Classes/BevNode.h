//
//  BevNode.hpp
//  cocos2d_tests
//
//  Created by huangdingji on 16/3/9.
//
//
#ifndef BevNode_h
#define BevNode_h

#include <string>
#include "AppMacros.h"
#include "CoreTypes.h"
#include "BevNodePrecondition.h"

static bool printFasle() {
    CCLOG("false");
    return false;
}

static bool printTrue() {
    CCLOG("true");
    return true;
}

class BevNode {
public:
    BevNode(BevNode* _o_ParentNode,BevNodePrecondition* o_NodeScript = nullptr)
        : mul_ChildNodeCount(0)
        , mz_DebugName("UNNAMED")
        , mo_ActiveNode(nullptr)
        , mo_LastActiveNode(nullptr)
        , mo_NodePreconditon(nullptr)
    {
        for (int i = 0; i < k_BLimited_MaxChildNodeCnt; ++i) {
            mao_ChildNodeList[i] = nullptr;
        }
        _SetParentNode(_o_ParentNode);
        SetNodePrecondition(o_NodeScript);
    }
    
    virtual ~BevNode() {
        for (int i = 0; i < k_BLimited_MaxChildNodeCnt ; ++i) {
            D_SafeDelete(mao_ChildNodeList[i]);
        }
        D_SafeDelete(mo_NodePreconditon);
    }
    
    bool Evaluate(const BevNodeInputParam& input) {
        return (mo_NodePreconditon == nullptr || mo_NodePreconditon->ExternalCondition(input)) && _DoEvaluate(input);
    }
    
    void Transition(const BevNodeInputParam& input) {
        _DoTransition(input);
    }
    
    BevRunningStatus Tick(const BevNodeInputParam& input,BevNodeOutputParam& output) {
        return _DoTick(input, output);
    }
   
    
    BevNode& SetNodePrecondition(BevNodePrecondition* _o_NodePrecondition) {
        if (mo_NodePreconditon != _o_NodePrecondition) {
            if (mo_NodePreconditon) {
                delete mo_NodePreconditon;
            }
            mo_NodePreconditon = _o_NodePrecondition;
        }
        return (*this);
    }
    
    BevNode& AddChildNode(BevNode* _o_ChildNode) {
        if (mul_ChildNodeCount == k_BLimited_MaxChildNodeCnt) {
            return (*this);
        }
        mao_ChildNodeList[mul_ChildNodeCount] = _o_ChildNode;
        ++mul_ChildNodeCount;
        return (*this);
    }
    
    BevNode& SetDebugName(const char* _debugName) {
        mz_DebugName = _debugName;
        return (*this);
    }
    
    const BevNode* GetLastActiveNode() const {
        return mo_LastActiveNode;
    }
    
    void SetActiveNode(BevNode* _o_Node) {
        mo_LastActiveNode = mo_ActiveNode;
        mo_ActiveNode = _o_Node;
        if (mo_ParentNode != nullptr) {
            mo_ParentNode->SetActiveNode(_o_Node);
        }
    }
    
    const char* GetDebugName() const {
        return mz_DebugName.c_str();
    }
    
protected:
    virtual bool _DoEvaluate(const BevNodeInputParam& input) {
        return true;
    }
    
    virtual void _DoTransition(const BevNodeInputParam& input)
    {
    }
    virtual BevRunningStatus _DoTick(const BevNodeInputParam& input, BevNodeOutputParam& output)
    {
        return k_BRS_Finish;
    }
protected:
    void _SetParentNode(BevNode* _o_ParentNode) {
        mo_ParentNode = _o_ParentNode;
    }
    bool _bCheckIndex(u32 _ui_Index) const {
        return _ui_Index < mul_ChildNodeCount;
    }
protected:
    BevNode* mao_ChildNodeList[k_BLimited_MaxChildNodeCnt];
    u32 mul_ChildNodeCount;
    BevNode* mo_ParentNode;
    BevNode* mo_ActiveNode;
    BevNode* mo_LastActiveNode;
    BevNodePrecondition* mo_NodePreconditon;
    std::string mz_DebugName;
};


#endif /* BevNode_h */
