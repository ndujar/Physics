/*
#include "PhysicsEntity.h"

PhysicsEntity::PhysicsEntity(SceneManager *SceneMgr,EntityType ShapeType)
{
 Geometry = SceneMgr->getRootSceneNode()->createChildSceneNode();
 Geometry->setPosition(0,5,0);
 GeomType=ShapeType;
 switch (GeomType)
 {
 case cube:
        Geometry->attachObject(createCubeMesh("Cube","myMaterial"));
  break;
 case plane:
        Geometry->attachObject(createPlane("Plane","myMaterial"));
  break;
 };
}
PhysicsEntity::~PhysicsEntity()
{

}
ManualObject* PhysicsEntity::createCubeMesh(Ogre::String name, Ogre::String matName)
{
 ManualObject* cube = new ManualObject(name);
 cube->begin(matName);

 cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(1,0);
 cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(0,1);
 cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(1,1);
 cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(0,0);
 cube->position(0.5,0.5,1.0);cube->normal(0.666667,0.333333,0.666667);cube->textureCoord(1,0);
 cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(0,1);
 cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(1,1);
 cube->position(-0.5,0.5,1.0);cube->normal(-0.408248,0.816497,0.408248);cube->textureCoord(0,0);
 cube->position(-0.5,0.5,0.0);cube->normal(-0.666667,0.333333,-0.666667);cube->textureCoord(0,1);
 cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(1,1);
 cube->position(-0.5,-0.5,1.0);cube->normal(-0.666667,-0.333333,0.666667);cube->textureCoord(1,0);
 cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(0,1);
 cube->position(0.5,0.5,0.0);cube->normal(0.408248,0.816497,-0.408248);cube->textureCoord(1,1);
 cube->position(0.5,-0.5,1.0);cube->normal(0.408248,-0.816497,0.408248);cube->textureCoord(0,0);
 cube->position(0.5,-0.5,0.0);cube->normal(0.666667,-0.333333,-0.666667);cube->textureCoord(1,0);
 cube->position(-0.5,-0.5,0.0);cube->normal(-0.408248,-0.816497,-0.408248);cube->textureCoord(0,0);
 cube->position(-0.5,0.5,1.0);cube->normal(-0.408248,0.816497,0.408248);cube->textureCoord(1,0);
 cube->position(0.5,0.5,0.0);cube->normal(0.408248,0.816497,-0.408248);cube->textureCoord(0,1);
 cube->position(-0.5,0.5,0.0);cube->normal(-0.666667,0.333333,-0.666667);cube->textureCoord(1,1);
 cube->position(0.5,0.5,1.0);cube->normal(0.666667,0.333333,0.666667);cube->textureCoord(0,0);
 cube->triangle(0,1,2);      cube->triangle(3,1,0);
 cube->triangle(4,5,6);      cube->triangle(4,7,5);
 cube->triangle(8,9,10);      cube->triangle(10,7,8);
 cube->triangle(4,11,12);   cube->triangle(4,13,11);
 cube->triangle(14,8,12);   cube->triangle(14,15,8);
 cube->triangle(16,17,18);   cube->triangle(16,19,17);
 cube->end();

 return cube;
}
ManualObject* PhysicsEntity::createPlane(Ogre::String name, Ogre::String matName)
{
 ManualObject* plane = new ManualObject(name);
 plane->begin(matName);

 plane->position(-0.5,0,-0.5);plane->normal(0.408248,-0.816497,0.408248);plane->textureCoord(1,0);
 plane->position(-0.5,0.0,0.5);plane->normal(-0.408248,-0.816497,-0.408248);plane->textureCoord(0,1);
 plane->position(0.5,0.0,0.5);plane->normal(0.666667,-0.333333,-0.666667);plane->textureCoord(1,1);
 plane->position(0.5,0.0,-0.5);plane->normal(-0.666667,-0.333333,0.666667);plane->textureCoord(0,0);
 plane->triangle(0,1,2);      plane->triangle(0,2,3);
 plane->end();

 return plane;
}
