
// compile with: cl /EHsc Vector3.h /link MathLib.lib


#include "Application2D.h"
#include <iostream>


int main() {
	
	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	

	return 0;

}