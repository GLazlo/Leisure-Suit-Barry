
#include "stdafx.h"
#include "MyGameManager.h"

int main(int argc, char* argv[])
{
	// get things going
	//  optional parameters:
	//		int windowWidth			default: 1024
	//		int windowHeight		default: 768
	//		std::string windowName	default: "Angel Engine"
	//		bool antiAliasing		default: false
	//		bool fullScreen			default: false
	theWorld.Initialize();
	
	//adds the default grid so you can more easily place Actors
	theWorld.Add(new GridActor(), -1);
	
	theWorld.SetGameManager(&theGame);

	//MyGameManager test = MyGameManager::GetInstance();
		
	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();
	
	// any cleanup can go here
	theWorld.Destroy();
	
	return 0;
}
