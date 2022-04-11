// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MOONGATE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MOONGATE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MOONGATE_EXPORTS
#define MOONGATE_API __declspec(dllexport)
#else
#define MOONGATE_API __declspec(dllimport)
#endif

#include <SDL.h>
#include <iostream>

typedef struct MOONGATE_API MoonCore {
	SDL_Window* window;
	SDL_Renderer* renderer;
} *MoonCorePtr;

MOONGATE_API int moon_core_startup(MoonCore& engine);
MOONGATE_API void moon_core_shutdown(MoonCore& engine);
MOONGATE_API void moon_core_update(MoonCore& engine);

/*
// This class is exported from the dll
class MOONGATE_API Cmoongate {
public:
	Cmoongate(void);
	// TODO: add your methods here.
};

extern MOONGATE_API int nmoongate;

MOONGATE_API int fnmoongate(void);
*/