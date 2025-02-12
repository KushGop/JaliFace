#include "Engine.h"
int main() {
	Engine engine;

	//Game loop
	while (engine.getWindowIsOpen()) {
		engine.update();
		engine.render();
	}

	return 0;
}