# Have the camera a certain rect with Crono in the middle
	* if the image is smaller than the camera then it doesn't move

# class Background needs to include the width and height of the viewable bg
	* Is this a good solution?
		* use the overlay/collision grid for each bg instead have a set w/h for it and if the camera hits the edge of that it should stop
		* Gonna need to have positions for that anyway might as well use it's edges for the map collision
	* This is necessary for determining whether the camera is larger than the image?
	* Necessary if the bg changes in some way
		* E.g. Crono's house when his mom opens window

# Character,h
	* Have a class just for movement spriting, done: Sprite.h
		* just contains a bunch of widths and heights for the position on the sprite sheet
		* Along with the appropriate names
			* running_left, running_right, walking_left, walking_right, surprised, standing_left, etc.