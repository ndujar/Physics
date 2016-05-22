#include <Ogre.h>
#include "BaseFrameListener.h"
#include "PhysicsFrameListener.h"
#include "PhysicsEntity.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace Ogre;

class BaseApp
{
public:
    void go();
    ~BaseApp();

private:
    Root *mRoot;
    BaseFrameListener *mListener;
    PhysicsFrameListener *PhListener;
    Ogre::String mResourcePath;
    SceneManager *mgr;
    RenderWindow *win;
    Camera *mCamera;
    std::vector<PhysicsEntity> PhysicsEntities;

    void createRoot();
    void defineResources();
    void loadResources();
    void setupRenderSystem();
    void createRenderWindow();
    void initializeResourceGroups();
    void setupScene();
    void setupInputSystem();
    void setupCEGUI();
    void createFrameListener();
    void createPhysicsFrameListener();
    void startRenderLoop();
};
