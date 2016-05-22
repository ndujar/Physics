/*
#ifndef PHYSICSENTITY_H_
#define PHYSICSENTITY_H_
#include <Ogre.h>

using namespace Ogre;

class PhysicsEntity
{
public:
 enum EntityType
 {
  cube,
  plane
 };

 PhysicsEntity(SceneManager *SceneMgr,EntityType ShapeType);
 ~PhysicsEntity();
 double mass;
 Vector3 position;
 Vector3 velocity;
 Vector3 acceleration;
 SceneNode *Geometry;
 EntityType GeomType;
private:
 ManualObject* createCubeMesh(Ogre::String, Ogre::String);
 ManualObject* createPlane(Ogre::String, Ogre::String);
};
#endif /*PHYSICSENTITY_H_*/
