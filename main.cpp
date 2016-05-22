/*

#include "BaseApp.h"

///This is the top module for running any Ogre based application
///Is just simple an concise.
///Call the go method of the BaseApp class and everything just goes
int main(int argc, char **argv)
{
    // Create application object
    BaseApp app;

    //Just in case, catch any errors
    try
    {
     //Call the go method, where all the private settings
     //for running an Ogre app are called
        app.go();
    }
    catch(Exception& e)
    {
        printf( "An exception has occurred: %s\n",
            e.getFullDescription().c_str());
    }

    return 0;
}
