/*
#ifndef PHYSICSFRAMELISTENER_H_
#define PHYSICSFRAMELISTENER_H_

#include "PhysicsEntity.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <Ogre.h>

using namespace Ogre;
///This class is in charge to manage the physics before every
///render step on the Ogre window.
class PhysicsFrameListener : public FrameListener
{
public:
    ///The Ents vector contains the entities with physical properties attached to them
    ///In this example, no physics are used yet. Just an X-axis displacement is applied
    ///to perceive motion.
    PhysicsFrameListener(std::vector<PhysicsEntity> Ents):
     Entities(Ents)
    {
    }

    ///frameStarted is an overriden event from the Ogre FrameListener.
    ///Note that positions are updated before sending the information
    ///to the root object in the go loop.
    bool frameStarted(const FrameEvent& evt)
    {
     UpdatePositions();
     return true;
    }

    ///Update positions is in charge to reallocate the entities to their future locations
    void UpdatePositions()
    {
//     PhysicsEntity::EntityType TypeEnt;

     for (unsigned int i=0; i<Entities.size(); i++)
     {
      if (Entities[i].GeomType==PhysicsEntity::cube)
       Entities[i].Geometry->translate(0.1,0,0,Ogre::Node::TS_WORLD);
     }
    }
private:
    std::vector<PhysicsEntity> Entities;
};

#endif /*PHYSICSFRAMELISTENER_H_*/
