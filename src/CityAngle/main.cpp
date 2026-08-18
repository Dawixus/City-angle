#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
    bool init() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
            return false;

        window = SDL_CreateWindow(
            "Moje hra",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            800, 600,
            SDL_WINDOW_SHOWN
        );

        if (!window)
            return false;

        renderer = SDL_CreateRenderer(
            window, -1, SDL_RENDERER_ACCELERATED
        );

        return renderer != nullptr;
    }

    void run() {
        bool running = true;
        SDL_Event event;

        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    running = false;
            }

            update();
            render();
        }
    }

    void cleanup() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    void update() {
        // herní logika
    }

    void render() {
        SDL_SetRenderDrawColor(renderer, 20, 20, 30, 255);
        SDL_RenderClear(renderer);

        // vykreslování hry

        SDL_RenderPresent(renderer);
    }
};

int main() {
    Game game;

    if (!game.init()) {
        std::cerr << "Nepodarilo se inicializovat hru.\n";
        return 1;
    }

    game.run();
    game.cleanup();

    return 0;
}