add_subdirectory(SDL_Objects)
add_subdirectory(Utils)

add_executable(main main.cpp)
target_link_libraries(main SDL_OBJECTS_LIB UTILS_LIB)