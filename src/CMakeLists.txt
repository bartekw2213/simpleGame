add_subdirectory(SDL_Objects)
add_subdirectory(Utils)
add_subdirectory(Game)

add_executable(main main.cpp)
target_link_libraries(main GAME_LIB)