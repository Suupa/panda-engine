cmake_minimum_required(VERSION 3.10)

project(panda-engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#temptest
#message(STATUS ">>> ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}")


# Global output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")

# Panda-engine project directory
set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/panda-engine)

add_library(panda-engine SHARED
    "src/Panda.h"
    # "src/Panda.cpp"
	"src/Panda/Application.h"
	"src/Panda/Application.cpp"
	"src/Panda/Core.h"
	#"src/Panda/Core.cpp"
	"src/Panda/EntryPoint.h"
	"src/Panda/Log.cpp"
	"src/Panda/Log.h"
    # Add all your other source/header files here
)

target_include_directories(panda-engine PUBLIC "vendor/spdlog/include")

target_compile_definitions(panda-engine PUBLIC
    PANDA_PLATFORM_WINDOWS
    PANDA_BUILD_DLL
)

#${CMAKE_BUILD_TYPE}

set_target_properties(panda-engine PROPERTIES
	LINKER_LANGUAGE CXX
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/panda-engine"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/panda-engine"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/panda-engine"
)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sandbox/${CMAKE_BUILD_TYPE})

add_custom_command(TARGET panda-engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:panda-engine> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sandbox/Debug/panda-engine.dll
)
add_custom_command(TARGET panda-engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:panda-engine> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sandbox/Release/panda-engine.dll
)
add_custom_command(TARGET panda-engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:panda-engine> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sandbox/Dist/panda-engine.dll
)

# Configurations
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(panda-engine PUBLIC PANDA_DEBUG)
    target_compile_options(panda-engine PUBLIC -g)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(panda-engine PUBLIC PANDA_RELEASE)
    target_compile_options(panda-engine PUBLIC -O2)
elseif (CMAKE_BUILD_TYPE STREQUAL "Dist")
    target_compile_definitions(panda-engine PUBLIC PANDA_DIST)
    target_compile_options(panda-engine PUBLIC -O2)
endif()

