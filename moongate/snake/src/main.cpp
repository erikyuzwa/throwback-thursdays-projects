#include "moongate.h"

MoonCore engine;

int main(int argc, char* argv[]) {
	int result = 0;
	result = moon_core_startup(engine);
	if (result < 0) {
		goto CLEANUP_AND_EXIT;
	}

	moon_core_update(engine);

CLEANUP_AND_EXIT:
	moon_core_shutdown(engine);
	

	return 0;
}