#include "SDL_Objects.hpp"

int main(int argc, char* argv[]) {
    SDL_Window_Wrapper window_wrapper;

    SDL_Manager::initialize();

    window_wrapper.initialize_window("Simple Game", 400, 400);

    SDL_Manager::quit();
    return 0;
}