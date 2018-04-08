project(CodeInGame_Defibrillators)

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

add_executable(defibrillators ${SOURCES})

enable_testing()

file (GLOB TEST_INPUTS ${CMAKE_CURRENT_SOURCE_DIR}/tst/*.txt)

foreach (_input_file ${TEST_INPUTS})
	get_filename_component(testName ${_input_file} NAME_WE)
	if (APPLE)
		add_test(
			NAME ${testName}
			COMMAND sh -c "$<TARGET_FILE:defibrillators> < ${_input_file}"
			CONFIGURATIONS ${CMAKE_BUILD_TYPE}
		)
	elseif(WIN32)
		add_test(
			NAME ${testName}
			COMMAND ${CMAKE_COMMAND} -E chdir $<TARGET_FILE:defibrillators> $ENV{ComSpec} /c "$<TARGET_FILE:defibrillators> < ${_input_file}"
			CONFIGURATIONS ${CMAKE_BUILD_TYPE}
		)
    else()
        message(FATAL_ERROR "Unknown shell command for ${CMAKE_HOST_SYSTEM_NAME}")
	endif()
endforeach()
