// moongate.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "moongate.h"

MOONGATE_API int moon_core_startup(MoonCore& engine) {
    int result = 0;
    result = SDL_Init(SDL_INIT_EVERYTHING);
    if (result < 0) {
        SDL_Log("Failure in SDL_Init: %s", SDL_GetError());
        return -1;
    }

    engine.window = SDL_CreateWindow("moongate",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1024, 768,
        SDL_WINDOW_SHOWN);
    if (engine.window == NULL) {
        SDL_Log("Failure in SDL_CreateWindow: %s", SDL_GetError());
        return -2;
    }

    engine.renderer = SDL_CreateRenderer(engine.window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (engine.renderer == NULL) {
        SDL_Log("Failure in SDL_CreateRenderer: %s", SDL_GetError());
        return -3;
    }

    // set clear color to cornflower blue
    SDL_SetRenderDrawColor(engine.renderer, 100, 149, 237, 255);

    return 1;
}

MOONGATE_API void moon_core_shutdown(MoonCore& engine) {
    
    SDL_DestroyRenderer(engine.renderer);
    engine.renderer = nullptr;

    SDL_DestroyWindow(engine.window);
    engine.window = nullptr;

    SDL_Quit();
}

MOONGATE_API void moon_core_update(MoonCore& engine) {

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                    break;
                }
            }
        }

        // TODO: update world

        SDL_RenderClear(engine.renderer);
        
        // TODO: render world

        SDL_RenderPresent(engine.renderer);
        
        // small delay
        SDL_Delay(100);
    }

}


/*
// This is an example of an exported variable
MOONGATE_API int nmoongate=0;

// This is an example of an exported function.
MOONGATE_API int fnmoongate(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Cmoongate::Cmoongate()
{
    return;
}
*/