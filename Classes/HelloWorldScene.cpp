#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "NOD_Idle.h"
#include "NOD_MoveTo.h"
#include "NOD_Breathe.h"
#include "NOD_TurnTo.h"
#include "CON_HasReachedTarget.h"
#include "CON_HasFacedToTarget.h"
#include "BevNodePreconditionNOT.h"
#include "BevNodePreconditionTRUE.h"

USING_NS_CC;


HelloWorld::HelloWorld()
    : m_BevTreeRoot(nullptr)
    , m_TimeToFindNewTargetPos(-1.f)
{
    
}

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    CCLOG("HelloWorld::init()");
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    m_BevTreeInputData.m_Ower = Sprite::create("bang.png");
    addChild(m_BevTreeInputData.m_Ower);
    m_BevTreeInputData.m_Ower->setPosition(Vec2(100,100));
    m_BevTreeInputData.m_TargetPosition = Vec2(450,300);
    m_BevTreeOutputData.m_BodyColor = Color3B(255,255,255);
//    BevNode& ret = BevNodeFactory::CreatePrioritySelectorNode(nullptr, "root");
//    BevNode& p = BevNodeFactory::CreateParalleNode(&ret, k_PFC_OR, "parallel")
//    .SetNodePrecondition(new BevNodePreconditionNOT(new CON_HasReachedTarget()));
//    BevNodeFactory::CreateTeminalNode<NOD_MoveTo>(&p, "move to").SetNodePrecondition(new BevNodePreconditionTRUE());
//    BevNodeFactory::CreateTeminalNode<NOD_Breathe>(&p, "breathing").SetNodePrecondition(new BevNodePreconditionTRUE());
//    BevNode& p2 = BevNodeFactory::CreateParalleNode(&ret, k_PFC_OR, "parallel2")
//    .SetNodePrecondition(new BevNodePreconditionTRUE());
//    BevNodeFactory::CreateTeminalNode<NOD_Idle>(&p2, "idle").SetNodePrecondition(new BevNodePreconditionTRUE());
//    BevNodeFactory::CreateTeminalNode<NOD_Breathe>(&p2, "breathing").SetNodePrecondition(new BevNodePreconditionTRUE());

    BevNode& ret = BevNodeFactory::CreatePrioritySelectorNode(nullptr, "root");
    BevNode& p = BevNodeFactory::CreateParalleNode(&ret, k_PFC_OR, "parallel");
    BevNodeFactory::CreateTeminalNode<NOD_Idle>(&ret, "idle").SetNodePrecondition(new CON_HasReachedTarget());
    BevNode& sq = BevNodeFactory::CreateSequenceNode(&p, "sequence");
    BevNodeFactory::CreateTeminalNode<NOD_Breathe>(&p, "breathing").SetNodePrecondition(new BevNodePreconditionTRUE());
    BevNodeFactory::CreateTeminalNode<NOD_TurnTo>(&sq , "turn to").SetNodePrecondition(new BevNodePreconditionTRUE());
    BevNodeFactory::CreateTeminalNode<NOD_MoveTo>(&sq, "move to").SetNodePrecondition(new CON_HasFacedToTarget());
    
    
    m_BevTreeRoot = &ret;
    return true;
}

void HelloWorld::GameLoop(float _fDeltaTime) {
//    游戏主循环
    m_BevTreeInputData.m_TimeStep = _fDeltaTime;
    m_BevTreeOutputData.m_NextPosition = m_BevTreeInputData.m_Ower->getPosition();
    BevNodeInputParam input(&m_BevTreeInputData);
    BevNodeOutputParam output(&m_BevTreeOutputData);
    if (m_BevTreeRoot->Evaluate(input)) {
        m_BevTreeRoot->Tick(input, output);
    }
    m_BevTreeInputData.m_Ower->setPosition(m_BevTreeOutputData.m_NextPosition);
    m_BevTreeInputData.m_Ower->setColor(m_BevTreeOutputData.m_BodyColor);
    m_BevTreeInputData.m_Ower->setScale(m_BevTreeOutputData.m_BodySize.width);
}

void HelloWorld::onEnter() {
    Layer::onEnter();
    schedule(CC_SCHEDULE_SELECTOR(HelloWorld::GameLoop));
}

void HelloWorld::onExit() {
    Layer::onExit();
    unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::GameLoop));
}

