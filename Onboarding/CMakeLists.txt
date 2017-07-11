set(CMAKE_CXX_STANDARD 11)

if (MSVC)
set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
endif ()

if (Clang)
	set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
endif()

MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID} )
MESSAGE(STATUS "CMAKE_CXX_COMPILER_VERSION: " ${CMAKE_CXX_COMPILER_VERSION} )

file(GLOB SOURCES src/*.cpp src/*.h)

add_executable(onboarding ${SOURCES})
