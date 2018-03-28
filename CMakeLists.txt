cmake_minimum_required(VERSION 3.6.2)

project(Xav_CodeInGame)

add_subdirectory(Onboarding)
add_subdirectory(HorseRacingDuals)

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
