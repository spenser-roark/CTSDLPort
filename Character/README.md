# Character Class
* One of the biggest things here is some assumptions I've made
** One big one is that all character/enemy/playablecharacter spritesheets have the same layout
*** This is important because in order to abstract that from the user we deliberately set those values, e.g. Standing directions, walking directions, etc. In the corresponding constructors


# NOTES
* One note for myself, I definitely now need to make a npc character class, since the spritesheets are the way they are and to allow for the variance that exists it's a weakness I have to account for and something I can't do anything about
* Should I just have a set****(up down left right) in Character since I probably won't be setting those individually very often


# Character Children
* These include individual set actions that are specific to that sprite type