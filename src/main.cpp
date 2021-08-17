#include "SDL_Objects.hpp"

int main(int argc, char* argv[]) {
    SDL_Manager::initialize();
    SDL_Manager::quit();
    return 0;
}