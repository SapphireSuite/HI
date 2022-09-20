# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)

# Sapphire Suite's CMake tools.
add_subdirectory(CMake)



# Project

project(SA_HI)
SA_ConfigureProject(SA_HI)



# Library

add_library(SA_HI STATIC)
SA_ConfigureTarget(TARGET SA_HI)
SA_TargetSources(TARGET SA_HI)

### Link dependencies.
target_link_libraries(SA_HI PUBLIC SA_Logger)



# Options

## Add SA_HI's tests to build tree.
option(SA_HI_BUILD_TESTS_OPT "Should build SA_HI tests" OFF)



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_HI_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)

endif()
