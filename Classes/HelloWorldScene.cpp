#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "NOD_Idle.h"
#include "NOD_MoveTo.h"
#include "CON_HasReachedTarget.h"
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
    
    BevNode& ret = BevNodeFactory::CreatePrioritySelectorNode(nullptr, "root");
    BevNodeFactory::CreateTeminalNode<NOD_MoveTo>(&ret, "move to").SetNodePrecondition(new BevNodePreconditionNOT(new CON_HasReachedTarget()));
    BevNodeFactory::CreateTeminalNode<NOD_Idle>(&ret, "idle").SetNodePrecondition(new BevNodePreconditionTRUE);
    
    m_BevTreeRoot = &ret;
    return true;
}

void HelloWorld::GameLoop(float _fDeltaTime) {
//    游戏主循环
    m_BevTreeInputData.m_TimeStep = _fDeltaTime;
    m_TimeToFindNewTargetPos -= _fDeltaTime;
    if (m_TimeToFindNewTargetPos <= 0) {
        m_BevTreeInputData.m_TargetPosition = Vec2(rand()%960,rand()%640);
        CCLOG("%f,%f",m_BevTreeInputData.m_TargetPosition.x,m_BevTreeInputData.m_TargetPosition.y);
        m_TimeToFindNewTargetPos = 5;
    }
    m_BevTreeOutputData.m_NextPosition = m_BevTreeInputData.m_Ower->getPosition();
    BevNodeInputParam input(&m_BevTreeInputData);
    BevNodeOutputParam output(&m_BevTreeOutputData);
    if (m_BevTreeRoot->Evaluate(input)) {
        m_BevTreeRoot->Tick(input, output);
    }
    m_BevTreeInputData.m_Ower->setPosition(m_BevTreeOutputData.m_NextPosition);

}

void HelloWorld::onEnter() {
    Layer::onEnter();
    schedule(CC_SCHEDULE_SELECTOR(HelloWorld::GameLoop));
}

void HelloWorld::onExit() {
    Layer::onExit();
    unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::GameLoop));
}

