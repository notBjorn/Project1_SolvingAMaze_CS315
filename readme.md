---
date made: 2025-09-12
time made: 20:02
year: 2025
tags:
  - CS315
  - Fall 2025
description: "Maze project readme file"

## Categorizations.
isWork: true
isLearn: true
isCourse: true
---
> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/Project1_SolvingAMaze_CS315.git)

## **Collaboration & Sources**
All of the code and logic is mine. I did use the backtracking algorithm provided in the project instructions file but made some slight modifications to even that. I only used chatGPT when I forgot something related to the syntax like how to access elements in vectors of vectors or when trying to figure out why an error was occurring even after I had figured out where the error was happening, I gave an example of this in the testing section.
I even disabled the inline suggestions provided by Clion as I find them to be too good. My main use of external resources was just for checking syntax and debugging any errors I had, the code and logic used in the code are entirely mine.

## **Implementation Details**

### `void importMaze(string filename)`
This maze member function opens the file by the `filename`, reads the file line by line onto a string and then imports that value into a 2D vector.
- The 2D vector contains a pair which contains data regarding the cell
- The data about a cell being path or wall is denoted in the first value of the pair. where 1 is a wall and 0 is a path.
- The second value of the pair is defaulted to be true, it represents whether the cell can be visited or not.
  When the maze is finished importing into the vector, the program then runs a helper function `findKeyVariables` that helps find the entry, exit points as well as the bounds of the maze.

### `void findKeyVariables`
This helper function first assigns the bounds of the maze to `lastXIdx` and `lastYIdx` and finds any openings on the boundary by checking the top row and bottom row and then by checking the left column and right column.
If there are less than 2 openings it doesn't assign anything to the start and end variable.
If there are more than 2 openings than it assigns only two, one to start and another to end.


### `bool inBounds(int x, int y)`
This is a helper function I used throughout the code to check whether a given coordinate was in bounds or not

### `bool isPath(int x, int y)`
This helper function is also used a lot throughout the program to determine whether the given coordinates belong to a path or a wall

### `bool canVisit(int x, int y)`
This helper function checks whether a cell can be visited by checked whether it has already been visited or not. I think I used have named this `isExplored` as that makes more sense...

### `bool canTravel(int x, int y)`
This is a helper function that combines all the other checks to confirm whether the given coordinates are somewhere we can go .
Three things need to be checked before we can move to a coordinate.
1. Is there a cell there or not i.e. is it out of bounds
2. Is the cell a wall or is it path able
3. Has the cell already been visited.
   The function takes 2 integer coordinates and returns a bool.

### `void markVisited(int x, int y)`
changing values in a 2D vector is a bit unintuitive that's why I designed a function that helped me update the visitable status of a cell at a given coordinate.


### `void solveMaze`
This function uses the following steps solve the maze
- First the function checks whether we have an appropriate start value
- If we do then that value is pushed onto the `path` stack
- the coordinate is marked as visited using the `markVisited` function
- we then enter a loop which will continue to run until we have an empty loop or the coordinates reach the end of the maze
- we then check which adjacent cell we can move using the `canTravel` function in the following order, Right, Left, Up, Down.
- If we can move to any of these than we move that coordinate to the stack and set it to be visited.
- if none of the adjacent cells are traversable then we pop the stack and repeat until the stack is empty or another valid adjacent stack is present for transversal.
- if we reach the end then that means the path contains the solution to the maze in the reverse order. If the stack is empty that means that there is no solution to the maze.
- I then created a 2D vector with copied values from the `primeMaze` vector but with just char instead of int and bool.
- I then modified this vector with blank spots to highlight the solution

### `void printMaze`
This function prints the imported maze to the console

### `void printSolution`
This function prints the solved maze to the console




## **Testing & Status**
**The program, to the best of my knowledge, is working perfectly**. I did encounter some issues, such as the while loop in `solveMaze` giving an out-of-bounds error when the entire stack was popped. I tracked this by printing a success messages after each step in the loop, it did help me in isolating where the issue was but in the end I had to use ChatGPT.  I asked why I was getting the error. It turned out the issue was in the loop condition, which I hadn’t noticed. My loop was checking whether the top of the stack was equal to the end/target and then if the stack was empty, but when the stack was empty, it caused the error. I also tested my code by changing the number of entry points, and changing the maze itself.
When testing the code on the blue server, I had an issue where the program failed to access the `maze.txt` file. The error turned out to be because of the way I had to modify my code to make it work in clion. For some reason clion wants the input files in the build directory, that was an issue as git ignores the build directory so I had to modify the input to be `../maze.txt` this would make it so that clion would exit the build directory and then access the file. But in Linux this is an issue so I had to change it back to `maze.txt`

>demonstration of the while loop issue
```cpp
while (path.top() != end && !path.empty()) // path.top when empty is out of bounds
while (!path.empty() && path.top() != end)
```


> Final output
```cpp title:output fold:true
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1           0 0 1       0 0 1
1   1 1 1   1 0 1   1   1 1 1
    0 0 1   1 0 1   1       1
1 1 1 1 1   1 1 1   1 1 1   1
1 0 0 0 0           1       1
1 0 1 0 1 0 1 1 1 0 1   1 1 1
1 0 1 0 1 0 0 0 1 0 1       1
1 0 1 0 1 1 1 0 1 0 1 1 1   1
1 0 1 0 0 0 1 0 1 0 1 0 1   1
1 0 1 1 1 0 1 1 1 0 1 0 1   1
1 0 0 0 1 0 0 0 1 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

> Demonstration of how I tested code step by step
```cpp title:testing fold:true
curr: 0, 3
1, 3
check out of bounds
checked
pathable
checked
visited
checked
right
curr: 1, 3
2, 3
check out of bounds
checked
pathable
checked
visited
checked
right
curr: 2, 3
3, 3
check out of bounds
checked
pathable
checked
visited
checked
right
curr: 3, 3
4, 3
check out of bounds
checked
pathable
2, 3
check out of bounds
checked
pathable
checked
visited
3, 4
check out of bounds
checked
pathable
3, 2
check out of bounds
checked
pathable
popped
```

    
