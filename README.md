# Cub3D

***Cub3D*** is a project that aims to create a realistic 3D graphical representation of the inside of a maze from a first-person perspective using the Ray-Casting principles.
(basically a recreation of the classic ***Wolfenstein 3D game***)
___
## Requirements
### Requirements for Linux:
* make
* gcc
* package xorg 
* package libxext-dev 
* package libbsd-dev

➜ Requirements installation for Debian Distributions:
```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

### Requirements for Mac:
* Xquartz

➜ Requirements installation:
```
Brew install Xquartz
reboot
xeyes
```

## Installation
``` shell
git clone https://github.com/irhesri/cub3D.git
cd cub3D
make
```

## Usage:

* Start The executable:
``` 
./cub3D [map name]
```
>Note:
>* If the map doesn't exist in the same directory you should provide the path along with name [path/map_name].
>* The map extension should always be **.cub**

### The map:
The map file should be a plain text file with the following elements:
* **NO**: `the path to the texture used for the north-facing walls`
* **SO**: `the path to the texture used for the south-facing walls.`
* **WE**: `the path to the texture used for the west-facing walls.`
* **EA**: `the path to the texture used for the east-facing walls.`
* **F**: `the color of the floor`
* **C**: `the color of the ceiling`
* **The map**: it must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.

>**The map rules**:
>* The map must be closed/surrounded by walls.
>* There should be only one player in the map.
>* Elements can be separated by one or more empty lines, and they can appear in any order in the file. 
>Additionally, each type of information within an element can be separated by one or more spaces.
>The map content itself is not subject to these rules
>* Spaces are a valid part of the map.
>* The colors of F and C written in R,G,B form.
>* The texture image should have **.xpm** extension.

## Controls:
* <kbd> ← </kbd> <kbd> → </kbd> : Allows you to rotate the view left and right
* <kbd> w </kbd> <kbd> s </kbd> : Allows you to move forward and backward
* <kbd> a </kbd> <kbd> d </kbd> : Allows you to move to the left and to the right
* [Only in Mac] The mouse mouvements : Allows you to rotate the view left and right
* <kbd> ESC </kbd> : Close the window


## Restrictions:
* Only the next functions are allowed:
>open, close, read, write, printf, malloc, free, perror, strerror, exit
>
>All functions of the math
>
>All functions of the MiniLibX
* You must use the MiniLibX.
* Global variables are forbidden.

## Credits
The mlx library used in the project was provided by [Minilibx](https://github.com/42Paris/minilibx-linux).
