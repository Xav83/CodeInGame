set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")

MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID} )
MESSAGE(STATUS "CMAKE_CXX_COMPILER_VERSION: " ${CMAKE_CXX_COMPILER_VERSION} )

file(GLOB SOURCES src/*.cpp src/*.h)

add_executable(onboarding ${SOURCES})
