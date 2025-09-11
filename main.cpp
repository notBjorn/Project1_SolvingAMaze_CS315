#include "maze.h"

int main() {
    maze aMaze;
    aMaze.importMaze("../maze.txt");
    aMaze.printMaze();
    aMaze.printOpen();
}

/*
 *
 * The data type needs to be a vector otherwise it will be hard to traverse the maze
 * Each cell of the maze grid will need 4 data points,
 * - The position data which will be provided by the vector position itself
 * - The type of cell it is will be defined by the data in the vector, if it is a 0 it means its pathable, if it is 1 it means it is a wall
 * - The history of the cell is also needed, meaning we need to know whether we have been to the cell or not.
 *
 * The problem right now is that I can't think of a way to dynamically insert all this data.
 * The only way I have in mind is to create a 2D vector with the contents of the maze and position
 * Then copy it over to a new maze, whose size we know because I know what the size of the 2D vector is.
 * Doing so will help me insert the default state of the cell which is that the cell has not been transversed
 */
/*
 * vector[0].at(i)==0
 * vector[size-1].at(i)==0
 * vector[i].at(0)==0
 * vector[i].at(size -1) ==0
 * if any of these is true, that element is entry/exit point
 */
