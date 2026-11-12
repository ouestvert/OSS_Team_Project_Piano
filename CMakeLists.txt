cmake_minimum_required(VERSION 3.22)
project(TeamPiano LANGUAGES C)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "Build raylib examples")

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 02566453880e06bec97f5b8160fa6fe1e98397ca # raylib 6.2
)
FetchContent_MakeAvailable(raylib)

add_executable(piano
    src/main.c
    src/ui.c
    src/recording.c
    src/note_io.c
)
target_compile_features(piano PRIVATE c_std_11)
target_link_libraries(piano PRIVATE raylib)