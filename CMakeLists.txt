cmake_minimum_required(VERSION 3.6.2)

project(Xav_CodeInGame)

if(APPLE)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmakeScripts)
    include(CodeCoverage)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif(APPLE)

add_subdirectory(Onboarding)
add_subdirectory(HorseRacingDuals)
add_subdirectory(Defibrillators)

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

enable_testing()
