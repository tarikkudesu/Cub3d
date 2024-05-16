#!/bin/sh

file=$(ls -R *.c */*.c)
if [ $# -gt 0 ]; then
	cc -Wall -Wextra -Werror $file -o cub3d -D D=1
	make clean
else
	cc -Wall -Wextra -Werror $file -o cub3d
	make clean
fi
