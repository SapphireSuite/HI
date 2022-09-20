# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Executable

## Add executable target.
add_executable(SA_HIProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_HIProto PRIVATE SA_HI)



# Tests

add_test(NAME CSA_HIProto COMMAND SA_HIProto)
