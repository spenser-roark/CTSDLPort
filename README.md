# installation
## Dependencies
   1. cmake
   2. csdl / csdl2
     * I used libsdl2-dev to get the dependencies for ubuntu then...
     * you may need to build this from source as the dev package from ubuntu has issues with sdl2_image
   3. SDL2_image
   4. libsdl2-mixer-2.0-0
   5. libsdl2-image-2.0-0
   6. any image libraries you want
     * libjpeg-dev
     * libpng-dev
	* I had to compile this from source in ubuntu 16.04 lts
     
## Commands
   Install dependencies
   
   run sudo ldconfig
   
   1. create a build directory if one doesn't already exist
   2. run cmake from the build directory with the project root as an argument
     * e.g. cmake ../
   3. run make
   4. Profit!

# Scope
For right now all I want to do is make Crono's house. Possibly more to follow afterwards, but initially I just want to do that.

## Collission detection
  * Walls
  * Objects
  * Characters - only if we do more than just Crono's room
    * Special case here as we should be able to walk through a character after pushing for so long
    * doorways - same character

## Sprites
  * Furniture in Crono's room
    * Deprecated? Idea, the furniture is part of the background so this will be dealt with with collission sheets
  * Backgrounds
    * Are these included in the background or separate objects?
  * Cat - must have since it's there when crono wakes up
  * Mother - She wakes him up
  * The man himself

## Cutscene
  * Mother waking crono up
## Text
  * Mother waking crono up
  * Lucca convo in the kitchen - if we decide to do more than just Crono's room

## Loading zones
  * If we do the first floor of the house

## character customization, naming, identification
  * When mother asks for Lucca's name
    * Default name of Lucca
    * Can change that once and only once

## Character portrait images
  * Only playable characters now

## Triangle menu
  * All submenus
    * Items
    * Character stats
    * Saving
      * this doesn't need to work right now
    * config
      * Include screen size in that among other things

...

So much more to come holy crap