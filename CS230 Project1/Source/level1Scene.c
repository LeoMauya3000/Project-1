//------------------------------------------------------------------------------
//
// File Name:	StubScene.c
// Author(s):	Leo Mauya  0069791
// Project:		Project 0
// Course:		CS230S26
//
// Copyright © 2026 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "level2Scene.h"
#include "Scene.h"
#include "SceneSystem.h"
#include "StubScene.h"
#include "stream.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

typedef struct Level1Scene
{
	// WARNING: The base class must always be included first.
	Scene	base;
	int numLives;

	// Add any scene-specific variables second.

} Level1Scene;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

static void Level1SceneLoad(void);
static void Level1SceneInit(void);
static void Level1SceneUpdate(float dt);
static void Level1SceneExit(void);
static void Level1SceneUnload(void);
static void Level1SceneRender(void);

//------------------------------------------------------------------------------
// Instance Variable:
//------------------------------------------------------------------------------

static Level1Scene instance =
{
	// Initialize the base structure:
	{ "Level1", Level1SceneLoad, Level1SceneInit, Level1SceneUpdate, Level1SceneRender, Level1SceneExit, Level1SceneUnload},0 
	
	// Initialize any scene-specific variables:
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Get the instance of the Level1 Scene.
// Returns:
//	 Pointer to the base Scene structure for this derived Scene.
const Scene* Level1SceneGetInstance(void)
{
	return &(instance.base);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Load any resources used by the scene.
static void Level1SceneLoad(void)
{
	Stream streamFile = StreamOpen("Data/Level1_Lives.txt");

	if (&streamFile)
	{
		instance.numLives = StreamReadInt(streamFile);
		StreamClose(&streamFile);
		
	}
}

// Initialize the entities and variables used by the scene.
static void Level1SceneInit(void)
{
}

// Update the the variables used by the scene.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
static void Level1SceneUpdate(float dt)
{
	// Tell the compiler that the 'dt' variable is unused.
	UNREFERENCED_PARAMETER(dt);
	instance.numLives -=1;
	if(instance.numLives <= 0)
	{
		SceneSystemSetNext(level2SceneGetInstance());
	    
	}
	// NOTE: This call causes the engine to exit immediately.  Make sure to remove
	//   it when you are ready to test out a new scene.
	
}

// Render any objects associated with the scene.
void Level1SceneRender(void)
{
}

// Free any objects associated with the scene.
static void Level1SceneExit(void)
{
}

// Unload any resources used by the scene.
static void Level1SceneUnload(void)
{

}

