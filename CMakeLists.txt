cmake_minimum_required (VERSION 3.10)
project ("NotSoCivilised")

include(FetchContent)

# Fetch SDL
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.0
)
# Fetch SDL_ttf
FetchContent_Declare(
    SDL3_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG release-3.2.2
)
# Fetch and configure SDL_image
FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-3.4.0
)
set(SDLIMAGE_VENDORED ON)
set(SDLIMAGE_AVIF OFF)
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_JPEG OFF)
set(SDLIMAGE_WEBP OFF)
set(SDLIMAGE_PNG_LIBPNG OFF) 

# Compile the libraries
FetchContent_MakeAvailable(SDL3)
FetchContent_MakeAvailable(SDL3_ttf)
FetchContent_MakeAvailable(SDL3_image)

add_executable(
        NotSoCivilised
        "src/Main.cpp"
        "src/Logger.cpp"
        "src/Renderer.cpp"
)
target_compile_features(NotSoCivilised PRIVATE cxx_std_20)
target_link_libraries(
    NotSoCivilised 
    PRIVATE 
    SDL3::SDL3 
    SDL3_ttf::SDL3_ttf 
    SDL3_image::SDL3_image
)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
