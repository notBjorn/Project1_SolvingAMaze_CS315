#include "maze.h"

int main() {
    //std::cout << "START" << std::endl;
    maze aMaze;
    aMaze.importMaze("maze.txt"); //change this if you want it to run in clion
    //clion looks for the file in build, so to access the file we need to exit from build
    // ../maze.txt does that
    aMaze.printMaze();
    aMaze.solveMaze();
    aMaze.printSolution();
   // std::cout << "END" << std::endl;
}
