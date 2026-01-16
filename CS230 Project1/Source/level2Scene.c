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
#include "Scene.h"
#include "SceneSystem.h"
#include "level2Scene.h"
#include "Stream.h"
#include "SandboxScene.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

typedef struct level2Scene
{
	// WARNING: The base class must always be included first.
	Scene	base;
	int numLives;
	int numHealth;

	// Add any scene-specific variables second.

} level2Scene;

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

static void level2SceneLoad(void);
static void level2SceneInit(void);
static void level2SceneUpdate(float dt);
static void level2SceneExit(void);
static void level2SceneUnload(void);
static void level2SceneRender(void);
static Stream streamFileLives;
static Stream streamFileHealth;

//------------------------------------------------------------------------------
// Instance Variable:
//------------------------------------------------------------------------------

static level2Scene instance =
{
	// Initialize the base structure:
	{ "Stub", level2SceneLoad, level2SceneInit, level2SceneUpdate, level2SceneRender, level2SceneExit, level2SceneUnload },0,0

	// Initialize any scene-specific variables:
};

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Get the instance of the Stub Scene.
// Returns:
//	 Pointer to the base Scene structure for this derived Scene.
const Scene* level2SceneGetInstance(void)
{
	return &(instance.base);
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

// Load any resources used by the scene.
static void level2SceneLoad(void)
{
	streamFileLives = StreamOpen("Data/Level2_Lives.txt");

	if (&streamFileLives)
	{

		instance.numLives = StreamReadInt(streamFileLives);
		StreamClose(&streamFileLives);

	}

}

// Initialize the entities and variables used by the scene.
static void level2SceneInit()
{
	streamFileHealth = StreamOpen("Data/Level2_Health.txt");
	instance.numHealth = StreamReadInt(streamFileLives);


}

// Update the the variables used by the scene.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
static void level2SceneUpdate(float dt)
{
	// Tell the compiler that the 'dt' variable is unused.
	UNREFERENCED_PARAMETER(dt);

	instance.numHealth -= 1;
	if (instance.numHealth <= 0)
	{
		instance.numLives -=1 ;

		if (instance.numLives > 0)
		{
			SceneSystemRestart();
		}
		else
		{
			SceneSystemSetNext(SandBoxSceneGetInstance());
		}
	}


	// NOTE: This call causes the engine to exit immediately.  Make sure to remove
	//   it when you are ready to test out a new scene.
	
}

// Render any objects associated with the scene.
void level2SceneRender(void)
{


}

// Free any objects associated with the scene.
static void level2SceneExit()
{

}

// Unload any resources used by the scene.
static void level2SceneUnload(void)
{

}

