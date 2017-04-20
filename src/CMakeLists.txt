# Flags
set(CPP_FLAGS "-std=c++11")
set(CPP_FLAGS ${CPP_FLAGS} "")

# Utilities
add_library(error_handlers utilities/errorHandlers.cpp)
add_library(Setup utilities/setup.cpp)
add_library(utilities utilities/utilities.cpp)
add_library(VariableConstants constants/VariableConstants.cpp)

# Classes
add_library(Background classes/Background.cpp)

#structs
add_library(DisplayPlayableCharacter structs/DisplayPlayableCharacter.cpp)

set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2)
set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2_image)

# Include libs explicitly just in case they aren't inherited from another component
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} error_handlers)
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} utilities)
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} VariableConstants)

set(SETUP_INCLUDE_LIBS ${SETUP_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})

set(VARIABLECONSTANTS_INCLUDE_LIBS ${VARIABLECONSTANTS_INCLUDE_LIBS} utilities)


set_target_properties(Background PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
set_target_properties(VariableConstants PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
set_target_properties(Setup PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})

target_link_libraries(Background ${BACKGROUND_INCLUDE_LIBS})
target_link_libraries(DisplayPlayableCharacter ${GLOBAL_INCLUDE_LIBS})
target_link_libraries(VariableConstants ${VARIABLECONSTANTS_INCLUDE_LIBS})
target_link_libraries(Setup ${SETUP_INCLUDE_LIBS})
