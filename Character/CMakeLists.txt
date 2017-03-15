cmake_minimum_required(VERSION 3.0)
project(Character)

include_directories(${CMAKE_SOURCE_DIR}/Character/include)
include_directories(${CMAKE_SOURCE_DIR}/Character/resources)

add_library(Sprite src/Sprite.cpp)
add_library(Character src/Character.cpp)
add_library(BattlingCharacter src/BattlingCharacter.cpp)
add_library(PlayableCharacter src/PlayableCharacter.cpp)
add_library(PlayableCharacterList src/PlayableCharacterList.cpp)

set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2)
set(GLOBAL_INCLUDE_LIBS ${GLOBAL_INCLUDE_LIBS} SDL2_image)

set(CHARACTER_INCLUDE_LIBS ${CHARACTER_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(CHARACTER_INCLUDE_LIBS ${CHARACTER_INCLUDE_LIBS} Sprite)

set(SPRITE_INCLUDE_LIBS ${SPRITE_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})

set(PLAYABLECHARACTER_INCLUDE_LIBS ${PLAYABLECHARACTER_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})

set(PLAYABLECHARACTERLIST_INCLUDE_LIBS ${PLAYABLECHARACTERLIST_INCLUDE_LIBS} ${GLOBAL_INCLUDE_LIBS})
set(PLAYABLECHARACTERLIST_INCLUDE_LIBS ${PLAYABLECHARACTERLIST_INCLUDE_LIBS} Character)
set(PLAYABLECHARACTERLIST_INCLUDE_LIBS ${PLAYABLECHARACTERLIST_INCLUDE_LIBS} BattlingCharacter)
set(PLAYABLECHARACTERLIST_INCLUDE_LIBS ${PLAYABLECHARACTERLIST_INCLUDE_LIBS} PlayableCharacter)

target_link_libraries(Character ${CHARACTER_INCLUDE_LIBS})
target_link_libraries(Sprite ${SPRITE_INCLUDE_LIBS})
target_link_libraries(PlayableCharacter ${PLAYABLECHARACTER_INCLUDE_LIBS})
target_link_libraries(PlayableCharacterList ${PLAYABLECHARACTERLIST_INCLUDE_LIBS})
# set_target_properties(Character PROPERTIES COMPILE_FLAGS ${CPP_FLAGS})
