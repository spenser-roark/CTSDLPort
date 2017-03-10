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
set(CPP_FLAGS ${CPP_FLAGS} "-std=c++11")

# Non compilation directories we need to include
# headers, image files, etc
include_directories(include)

add_subdirectory(src)

set(INCLUDE_LIBS ${INCLUDE_LIBS} SDL2)
set(INCLUDE_LIBS ${INCLUDE_LIBS} SDL2_image)
set(INCLUDE_LIBS ${INCLUDE_LIBS} error_handlers)

add_executable(chronotrigger main.cpp)

target_link_libraries(chronotrigger ${INCLUDE_LIBS})
set_Target_properties(chronotrigger PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
