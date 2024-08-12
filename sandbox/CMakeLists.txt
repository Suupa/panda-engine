cmake_minimum_required(VERSION 3.10)

project(panda-engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Global output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")


# Sandbox project directory
set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/sandbox)

add_executable(Sandbox
    # "src/Sandbox.h"
    "src/Sandbox.cpp"

    # Add all your other source/header files here
	#TODO try to remove these and see if works afterwards
	"../panda-engine/src/Panda.h"
    # "../panda-engine/src/Panda.cpp"
	"../panda-engine/src/Panda/Application.h"
	"../panda-engine/src/Panda/Core.h"
	"../panda-engine/src/Panda/EntryPoint.h"
	"../panda-engine/src/Panda/Log.h"
	"../panda-engine/src/Panda/Log.cpp"
)

target_include_directories(Sandbox PUBLIC
    "../panda-engine/vendor/spdlog/include"
    "../panda-engine/src"
)

target_link_libraries(Sandbox PUBLIC panda-engine)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/sandbox"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/sandbox"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}sandbox"
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Sandbox PUBLIC PANDA_DEBUG)
    target_compile_options(Sandbox PUBLIC -g)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(Sandbox PUBLIC PANDA_RELEASE)
    target_compile_options(Sandbox PUBLIC -O2)
elseif (CMAKE_BUILD_TYPE STREQUAL "Dist")
    target_compile_definitions(Sandbox PUBLIC PANDA_DIST)
    target_compile_options(Sandbox PUBLIC -O2)
endif()
