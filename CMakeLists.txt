cmake_minimum_required(VERSION 3.9.0-rc3)

project(Xav_CodeInGame)

add_subdirectory(Onboarding)

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
