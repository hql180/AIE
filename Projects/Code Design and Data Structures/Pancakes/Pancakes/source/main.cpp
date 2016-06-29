//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include "HStack.h"
#include "glfw.h"

struct Pancake {
	unsigned int texture;
	int y;
};

// callback function to draw the pancake in the stack
void drawPancake(const Pancake* pPancake) {
	MoveSprite(pPancake->texture, 500, pPancake->y);
	DrawSprite(pPancake->texture);
}

int main( int arc, char* argv[] )
{	
	// First we need to create our Game Framework
	Initialise( 1280, 720, false );

	HStack<Pancake> pancakeStack;

	// Now load some sprites
	for(int i=0; i<6; i++){
		Pancake p;
		p.texture = CreateSprite( "./images/pancake.png", 230, 220, false );
		p.y = 500 - (i*50);
		pancakeStack.Push(p);
	}
		
	int waitTimer = 0;	
	do {
		ClearScreen();

			// eat the pancake - get the item on the top of the stack, destroy the item, then pop the stack
		if(IsKeyDown(GLFW_KEY_DOWN) && waitTimer <= 0 && pancakeStack.IsEmpty() == false) {
			const Pancake* p = pancakeStack.Top();
			DestroySprite(p->texture);	
			pancakeStack.Pop();
			waitTimer = 50;
		}
			// mum made a new pancake, add it to the top of the stack
		if(IsKeyDown(GLFW_KEY_UP) && waitTimer <= 0) {
			Pancake p;
			p.texture = CreateSprite( "./images/pancake.png", 230, 220, false );
			p.y = 500 - (pancakeStack.Size()*50);
			pancakeStack.Push(p);
			waitTimer = 50;
		}

		if(pancakeStack.IsEmpty() == false) {
			pancakeStack.Draw(drawPancake);
		}

		if(waitTimer > 0)
			waitTimer--;
	} while ( FrameworkUpdate() == false );

	while(pancakeStack.IsEmpty() == false) {
		const Pancake* p = pancakeStack.Top();
		DestroySprite(p->texture);	
		pancakeStack.Pop();
	}

	Shutdown();
	return 0;
}
