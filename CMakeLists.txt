cmake_minimum_required (VERSION 3.10)
project ("NotSoCivilised")

include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.0
)
FetchContent_MakeAvailable(SDL3)

add_executable(
        NotSoCivilised
        "src/Main.cpp"
        "src/Logger.cpp"
 "src/Renderer.cpp")
target_compile_features(NotSoCivilised PRIVATE cxx_std_20)
target_link_libraries(NotSoCivilised PRIVATE SDL3::SDL3)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
