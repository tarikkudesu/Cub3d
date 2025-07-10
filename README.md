## Overview

This project is inspired by the world-famous eponymous 90s game, which was the first FPS ever. The program has to implement a ray-casting algorithm in order to make a dynamic view inside a maze, in which you'll have to find your way.

## Description

-   This project is implemented in c and is compilable with a Makefile.
-   Memory leaks free, Memory leaks are not to be tolerated.
-   Error free, an error displayed in case something went wrong.
-   The program uses the 42 `minilibx` as a graphics library.
-   The management of the window remains smooth through the program lifespan.
-   Pressing ESC closes the window and quits the program in a clean way.
-   Clicking on the cross on the window’s frame also closes the window and quit the program in a clean way.
-   The program takes a configuration file containing a map, textures, and colors that are parsed and checked.
-   It does not take an open map.
-   It Displays different wall textures that vary depending on which side the wall the player is facing (North, South, East, West) and sets the floor and ceiling colors to two different ones.
-   The left and right arrow keys will allow you to look left and right in the maze.
-   The W, A, S, and D keys will allow you to move the point of view through the maze.
-   The player does not traverse walls.
-   As a bonus. The maze can have animated doors that open and close, animated sprites, mouse control and a minimap.
-   The program is able to transform a map like this :

## New Concepts

-	Recasting algorithm.
-   Pixel-Based Thinking.
-   Color Models: RGB, Hexadecimal color representation, alpha channel.
-   Rendering Loop.
-   Input Handling.
-   Graphics Libraries and APIs.
-   Working with Images and Textures.
-   Image buffering.
-   Frame Control.
-   Math for Graphics: Vector math and Trigonometry.


```bash
F 139,99,58
C 171,154,137

NO ./assets/north.xpm
SO ./assets/south.xpm
WE ./assets/west.xpm
EA ./assets/east.xpm

11111111111111
10000000000001
10303030303001
10303030303001
10000000000001
10333333333301
20000000000001
10100001000101
10100001000101
10100001000101
10000000000001
1000000N000001
11111111111111
```

into somthing like this :

![cub3dMap.png](/img/cub3d.png)

![Demo GIF](gif.gif)
