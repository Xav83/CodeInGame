project(CodeInGame_HorseRacingDuals)

set(CMAKE_CXX_STANDARD 11)

if (MSVC)
set(CMAKE_CXX_FLAGS "/W4 /WX /EHsc")
endif ()

if (Clang)
	set(CMAKE_CXX_FLAGS "-Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic")
endif()

MESSAGE(STATUS "PROJECT NAME: " ${PROJECT_NAME} )
MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID} )
MESSAGE(STATUS "CMAKE_CXX_COMPILER_VERSION: " ${CMAKE_CXX_COMPILER_VERSION} )

file(GLOB SOURCES src/*.cpp src/*.h)

add_executable(horseRacingDuals ${SOURCES})

enable_testing()

if (BASH)
	add_test(
		NAME simpleTestCase
		COMMAND sh -c "$<TARGET_FILE:horseRacingDuals> ${CMAKE_CURRENT_SOURCE_DIR}/tst/simpleTestCaseInput.txt"
		CONFIGURATIONS ${CMAKE_BUILD_TYPE}
	)
else()
	add_test(
		NAME simpleTestCase
		COMMAND ${CMAKE_COMMAND} -E chdir $<TARGET_FILE:horseRacingDuals> $ENV{ComSpec} /c "$<TARGET_FILE:horseRacingDuals> < ${CMAKE_CURRENT_SOURCE_DIR}/tst/simpleTestCaseInput.txt"
		CONFIGURATIONS ${CMAKE_BUILD_TYPE}
	)
endif()
