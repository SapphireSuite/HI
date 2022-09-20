# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

SA_FetchGoogleTest()

# Executable

## Inputs

file(GLOB_RECURSE SA_HI_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_HIUT ${SA_HI_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_HIUT PRIVATE SA_HI)

### Google test module dependency.
target_link_libraries(SA_HIUT PRIVATE gtest)



# Tests

add_test(NAME CSA_HIUT COMMAND SA_HIUT)
