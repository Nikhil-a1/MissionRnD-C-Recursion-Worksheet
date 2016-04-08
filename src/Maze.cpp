/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int path_exists(int*, int , int , int , int , int, int);
int check_path(int*, int, int, int, int, int, int, int, int);

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int res = 0;
	res = check_path((int*)maze, rows, columns, x1, y1, x2, y2, x1, y1);
	return res;
}
int check_path(int* maze, int rows, int col, int i, int j, int target_x, int target_y, int prev_i, int prev_j)
{
	if (i < 0 || j >= col || i < 0 || j >= col || target_x < 0 || target_x >= rows || target_y < 0 || target_y >= col)
		return 0;
	else if (i == target_x &&j == target_y)
		return 1;
	else
	{
		//int prev_i = x1, prev_j = y1, i = x1, j = y1;
		if (*((maze + (i + 1)*col) + j) == 1 && i < rows - 1 && i + 1 != prev_i)
		{
			prev_i = i;
			prev_j = j;
			i++;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else if (*((maze + i*col) + (j + 1)) == 1 && j < col - 1 && j + 1 != prev_j)
		{
			prev_j = j;
			prev_i = i;
			j++;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else if (*((maze + (i - 1)*col) + j) == 1 && i > 0 && i - 1 != prev_i)
		{
			prev_i = i;
			prev_j = j;
			i--;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else if (*((maze + i*col) + (j - 1)) == 1 && j>0 && j - 1 != target_y)
		{
			prev_j = j;
			prev_i = i;
			j--;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else if (*((maze + (i - 1)*col + j)) == 1 && i > 0)
		{
			prev_i = i;
			prev_j = j;
			i--;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else if (*((maze + i*col) + (j - 1)) == 1 && j > 0)
		{
			prev_j = j;
			prev_i = i;
			j--;
			return check_path(maze, rows, col, i, j, target_x, target_y, prev_i, prev_j);
		}
		else
			return 0;
	}
}