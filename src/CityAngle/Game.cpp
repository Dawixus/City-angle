#include <SDL2/SDL.h>

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
            window,
            -1,
            SDL_RENDERER_ACCELERATED
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

    void renderArrow() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // tělo šipky
        SDL_RenderDrawLine(
            renderer,
            300, 300,
            500, 300
        );

        // horní část hrotu
        SDL_RenderDrawLine(
            renderer,
            500, 300,
            470, 280
        );

        // spodní část hrotu
        SDL_RenderDrawLine(
            renderer,
            500, 300,
            470, 320
        );
    }

    void render() {
        // pozadí
        SDL_SetRenderDrawColor(
            renderer,
            20, 20, 30, 255
        );

        SDL_RenderClear(renderer);

        // šipka
        renderArrow();

        SDL_RenderPresent(renderer);
    }
};