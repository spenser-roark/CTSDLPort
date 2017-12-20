# Flags
set(CPP_FLAGS "-std=c++11")
set(CPP_FLAGS ${CPP_FLAGS} "")

# Utilities
add_library(error_handlers utilities/errorHandlers.cpp)
add_library(Setup utilities/setup.cpp)
add_library(utilities utilities/utilities.cpp)
add_library(VariableConstants constants/VariableConstants.cpp)
add_library(Run run/run.cpp)

# Classes
add_library(Background classes/Background.cpp)

# Structs
add_library(DisplayPlayableCharacter structs/DisplayPlayableCharacter.cpp)
add_library(CharacterSpriteActionIndex structs/CharacterSpriteActionIndex.cpp)

# global libraries
set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2)
set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2_image)

# Include libs explicitly just in case they aren't inherited from another component
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} error_handlers)
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} utilities)
set(BACKGROUND_INCLUDE_LIBS ${BACKGROUND_INCLUDE_LIBS} VariableConstants)

set(SETUP_INCLUDE_LIBS ${SETUP_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})

set(DISPLAY_PLAYABLE_CHARACTER_INCLUDE_LIBS ${DISPLAY_PLAYABLE_CHARACTER_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(DISPLAY_PLAYABLE_CHARACTER_INCLUDE_LIBS ${DISPLAY_PLAYABLE_CHARACTER_INCLUDE_LIBS} CharacterSpriteActionIndex)

set(RUN_INCLUDE_LIBS ${RUN_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(RUN_INCLUDE_LIBS ${RUN_INCLUDE_LIBS} DisplayPlayableCharacter)

set(VARIABLECONSTANTS_INCLUDE_LIBS ${VARIABLECONSTANTS_INCLUDE_LIBS} utilities)


set_target_properties(Background PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
set_target_properties(VariableConstants PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
set_target_properties(Run PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
set_target_properties(Setup PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})

target_link_libraries(Background ${BACKGROUND_INCLUDE_LIBS})
target_link_libraries(DisplayPlayableCharacter ${DISPLAY_PLAYABLE_CHARACTER_INCLUDE_LIBS})
target_link_libraries(VariableConstants ${VARIABLECONSTANTS_INCLUDE_LIBS})
target_link_libraries(Setup ${SETUP_INCLUDE_LIBS})
target_link_libraries(Run ${RUN_INCLUDE_LIBS})
# target_link_libraries(CharacterSpriteActionIndex ${GLOBAL_INCLUDE_LIBS})
