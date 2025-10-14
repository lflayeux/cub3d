# :notebook_with_decorative_cover: CUBE3D DOCUMENTATIONS


__Introduction__

Cube3D is a graphical project where you have to create your own version of the historical game **Wolfenstein 3D**, the very first FPS.  
To achieve this, you will need to learn about **raycasting** and use some mathematics.

The project is divided into two main parts:  
1. **Map parsing**  
2. **Raycasting**

Here is the __original game__ to compare => [<u>**_Wolfenstein Game_**</u>](http://users.atw.hu/wolf3d/)

## :balance_scale: GENERAL RULES

__Parsing__:
- **.cub** extension
- The **.cub** contains
	- **Textures**:
		- ```NO ./path_to_north_texture```
		- ```SO ./path_to_south_texture```
		- ```WE ./path_to_west_texture```
		- ```EA ./path_to_east_texture```
	- **Colors**:
		- ```F R,G,B``` (__F for Floor__)
		- ```C R,G,B ```(__C for Ceiling__)
		:warning: _with RGB an integer between 0 and 255_
	- **Maps** (always last part in the file):
		- Only character allowed:
			- __0__ -> empty space
			- __1__ -> wall
			- __N, S, E, W__ -> player start position + orientation
		- __Map__ must be __closed__/surrounded by wall
		- __Space__ inside the map are __valid__, must be handled correctly.
		- Any number of __blank lines allowed__ between elements (__except inside the map__).
- **Formatting rules**:
	- Each __element__ (texture/color) __can have spaces separating__ identifier and values.
	- The __order of elements__ (_except the map_, which must be last) is __flexible__.
- **Error handling**
	- :warning: If __any problem__ occurs, the program should __exit and print__ ```Error\n``` followed by a descriptive error message.
	- If __map__ is __not closed / contains invalid characters__ → error.
	- If __RGB values__ are out of range or not integers → error.
	- If __the .cub__ file cannot be opened → error.
	- If a __texture path__ is invalid / file not found → error.
	- If there are __duplicate__ identifiers → error.

__Display and rendering__:
- Render the scene in a __window__ using __MiniLibX__.
- Use __different colors__ for the floor and the ceiling.
- Apply __wall textures__ correctly according to their direction (NO, SO, WE, EA).
- Implement a __simple raycasting engine__ to handle realistic wall collisions and camera rotation.
- Players controls:
	- __Arrow keys (Left/Right)__: rotate the camera.
	- __W, A, S, D__: move the player.
	- __ESC__ or clicking the window close button: exit the program cleanly.
- Using minilibx is strongly recommended:
	- You can use ```mlx_pixel_put``` for simple rendering or ```mlx_new_image``` for faster rendering.

## 