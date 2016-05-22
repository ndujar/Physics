#include "BaseApp.h"

using namespace Ogre;
using namespace std;

 ///This code is adapted from the Ogre tutorials webpage for my own purposes
 ///http://www.ogre3d.org/wiki/index.php/Basic_Tutorial_6#Creating_the_RenderSystem

 ///Main function, calling all the private settings to make the application run in proper order:
 ///The basic Ogre life cycle looks like this:

 ///   1. Create the Root object.
 ///   2. Define the resources that Ogre will use.
 ///   3. Choose and set up the RenderSystem (that is, DirectX, OpenGL, etc).
 ///   4. Create the RenderWindow (the window which Ogre resides in).
 ///   5. Initialize the resources that you are going to use.
 ///   6. Create a scene using those resources.
 ///   7. Set up any third party libraries and plugins.
 ///   8. Create any number of frame listeners.
 ///   9. Start the render loop.
    void BaseApp::go()
    {
        createRoot();
        defineResources();
        loadResources();
        setupRenderSystem();
        createRenderWindow();
        initializeResourceGroups();
        setupScene();
        createFrameListener();
        createPhysicsFrameListener();
        startRenderLoop();
    }

    ///Destructor releases the FrameListener and the Root object from memory
    BaseApp::~BaseApp()
    {
        delete mListener;
        delete mRoot;
    }

 ///-createRoot sets the Ogre Root object from where all others derive.
    ///The Root object is the core of the Ogre library,
    ///and must be created before you can do almost anything with the engine.
    void BaseApp::createRoot()
    {
        mRoot = new Root();
    }

 ///-defineResources sets all the Ogre engine requirements by iterating the configuration file.
    ///The next thing we have to do is define the resources that the application uses.
    ///This includes the textures, models, scripts, and so on.
    ///Everything is set up in the resources.cfg file.
    void BaseApp::defineResources()
    // Method which will define the source of resources (other than current folder)
    {
        // Load resource paths from config file
        ConfigFile cf;
        mResourcePath = "";
        cf.load(mResourcePath + "resources.cfg");

        // Go through all sections & settings in the file
        ConfigFile::SectionIterator seci = cf.getSectionIterator();

        String secName, typeName, archName;
        while (seci.hasMoreElements())
        {
            secName = seci.peekNextKey();
            ConfigFile::SettingsMultiMap *settings = seci.getNext();
            ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                typeName = i->first;
                archName = i->second;
                ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
            }
        }
    }

 ///-loadResources intializes the application ResourceGroupManager.
    ///The function defineResources adds all of the resources from the config file,
    ///but it only tells Ogre where they are.
    ///Before you can use any of them you have to either initialize the group that you want to use,
    ///or you must initialize them all.
    void BaseApp::loadResources()
    {
       // Initialise, parse scripts etc
       ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    }

 ///-setupRenderSystem checks wether the config file Ogre.cfg has already set things up and calls the
 /// Ogre render system setup dialog in case it isn't.
    ///In the first part of the if statement, we attempt to restore the config file.
    ///If that function returns false it means that the file does not exist so we should show the config dialog,
    ///which is the second portion of that if statement.
    ///If that also returns false it means the user canceled out of config dialog
    ///(meaning they want to exit the program).
    void BaseApp::setupRenderSystem()
    {
        if (!mRoot->restoreConfig() && !mRoot->showConfigDialog())
            throw Exception(52, "User canceled the config dialog!", "BaseApp::setupRenderSystem()");
    }

 ///-createRenderWindow sets the Ogre root window where everything is going to be displayed
    ///Now that we have chosen the RenderSystem, we need a window to render Ogre in.
    ///There are actually a lot of options for how to do this, but we will really only need this to
    ///keep thing simple.
    void BaseApp::createRenderWindow()
    {
        mRoot->initialise(true, "Physics World");
    }

    ///The only thing left to do is to initialize the resources we are about to use.
    ///In a very large game or application, we may have hundreds or even thousands of
    ///resources that our game uses - everything from meshes to textures to scripts.
    ///At any given time though, we probably will only be using a small subset of these resources.
    ///To keep down memory requirements, we can load only the resources that our application is using.
    ///We do this by dividing the resources into sections and only initializing them as we go.
    void BaseApp::initializeResourceGroups()
    {
        TextureManager::getSingleton().setDefaultNumMipmaps(5);
        ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
    }

    ///There are at least three things that must be done before you start adding things to a scene:
    ///creating the SceneManager, creating the Camera, and creating the Viewport.
    ///I have added some lights and entities to give it some flesh.
    ///Entities are instances of PhysicsEntity, which is the class where all physics properties
    ///will be implemented
    void BaseApp::setupScene()
    {
        mgr = mRoot->createSceneManager(ST_GENERIC, "Default SceneManager");
        Viewport *vp;
        PhysicsEntity *PhysEnt(0);
        Light *light;

        mgr->setAmbientLight( ColourValue( 0, 0, 0 ) );
        mgr->setShadowTechnique( SHADOWTYPE_TEXTURE_MODULATIVE );

        mCamera = mgr->createCamera("PlayerCam");
        mCamera->setPosition(Vector3(300,300,200));
        mCamera->lookAt(Vector3(0,0,0));
        mCamera->setNearClipDistance(5);

        vp = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
        vp->setBackgroundColour(ColourValue(0,0,0));
        mCamera->setAspectRatio(Real(vp->getActualWidth()) / Real(vp->getActualHeight()));

        light = mgr->createLight("Light1");
        light->setType(Light::LT_POINT);
        light->setPosition(0, 15, 25);
        light->setDiffuseColour(.25, .25, 0);
        light->setSpecularColour(.25, .25, 0);

        light = mgr->createLight("Light3");
        light->setType(Light::LT_DIRECTIONAL);
        light->setPosition(10,10,10);
        light->setCastShadows(true);
        light->setDiffuseColour(.25, .25, 0);
        light->setSpecularColour(.25, .25, 0);
        light->setDirection(Vector3( 0, -1, 1 ));

        PhysEnt=new PhysicsEntity(mgr,PhysicsEntity::cube);
        PhysEnt->Geometry->scale(10,10,10);
        PhysicsEntities.push_back(*PhysEnt);
        PhysEnt=new PhysicsEntity(mgr,PhysicsEntity::plane);
        PhysEnt->Geometry->scale(1000,1000,1000);
        PhysicsEntities.push_back(*PhysEnt);
    }

    ///Every frame you must call the capture method on all Keyboard, Mouse, and Joystick objects you use.
    ///Our BaseFrameListener class manages all this for us.
    void BaseApp::createFrameListener()
    {
     mListener= new BaseFrameListener(mRoot->getAutoCreatedWindow(),mCamera);
        mRoot->addFrameListener(mListener);

    }

    ///Every frame you must also update all physics entities
    ///Our PhysicsFramelistener class manages all this for us.
    void BaseApp::createPhysicsFrameListener()
    {
     PhListener= new PhysicsFrameListener(PhysicsEntities);
        mRoot->addFrameListener(PhListener);
    }
    ///This will render the application until a FrameListener returns false.
    void BaseApp::startRenderLoop()
    {
        mRoot->startRendering();
    }

