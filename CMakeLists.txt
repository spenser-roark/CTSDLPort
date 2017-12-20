cmake_minimum_required(VERSION 3.0)
project(ChronoTriggerSDLPort)

# See CMP0003 for policy details
# No need for the backwards compatibility for now so setting to new
cmake_policy(SET CMP0003 NEW)

# Adding this just in case we want the old stuff at some future date
if (COMMAND old_policy_0003)
cmake_policy(SET CMP0003 OLD)
endif(COMMAND old_policy_0003)

# Set flags here
set(CPP_FLAGS "-std=c++11")
set(CPP_FLAGS ${CPP_FLAGS} "")

# Non compilation directories we need to include
# headers, image files, etc
include_directories(include/utilities)
include_directories(include/constants)
include_directories(include/classes)
include_directories(include/structs)
include_directories(include/run)

# Move to separate folder maybe ... + /external with only PlayableCharacerList in there that may do it
# Just want to abstract that since we don't need to see that functionality
include_directories(${CMAKE_SOURCE_DIR}/Character/include)

add_subdirectory(src)
add_subdirectory(Character)

set(INCLUDE_LIBS ${INCLUDE_LIBS} SDL2)
set(INCLUDE_LIBS ${INCLUDE_LIBS} SDL2_image)
set(INCLUDE_LIBS ${INCLUDE_LIBS} error_handlers)
set(INCLUDE_LIBS ${INCLUDE_LIBS} Background)
set(INCLUDE_LIBS ${INCLUDE_LIBS} PlayableCharacterList)
set(INCLUDE_LIBS ${INCLUDE_LIBS} Setup)
set(INCLUDE_LIBS ${INCLUDE_LIBS} DisplayPlayableCharacter)
set(INCLUDE_LIBS ${INCLUDE_LIBS} Run)

add_executable(chronoTrigger main.cpp)

target_link_libraries(chronoTrigger ${INCLUDE_LIBS})
set_Target_properties(chronoTrigger PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
