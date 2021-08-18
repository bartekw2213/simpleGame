file(GLOB SDL_OBJECTS_SRC CONFIGURE_DEPENDS "SDL_Objects/*.cpp")
file(GLOB UTILS_SRC CONFIGURE_DEPENDS "Utils/*.cpp")

add_executable(main main.cpp ${SDL_OBJECTS_SRC} ${UTILS_SRC})
target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})