---
date made: 2025-09-12
time made: 20:02
year: 2025
tags:
  - CS315
  - Fall 2025
description: "Readme file for the maze solution project"

## Categorizations.
isWork: true
isLearn: true
isCourse: true
---
> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/Project1_SolvingAMaze_CS315.git)


## **Implementation Details**
> [!abstract]-
> a description of your design, algorithms, and data structures used.


### `canTravel(int x, int y)`
This is a helper function that I am to going to design. The goal is to check whether we can transverse the coordinates being provided.
Three things need to be checked before we can move to a coordinate.
1. Is the cell a wall or is it path able
2. Is there a cell there or not i.e. is it out of bounds
3. Has the cell already been visited.

The function takes 2 integer coordinates and returns a bool.



## **Collaboration & Sources**
All of the code and logic is mine. I did use the backtracking algorithm provided in the project instructions file but made some slight modifications to even that. I only used chatGPT when I forgot something related to the syntax like how to access elements in vectors of vectors or when trying to figure out why an error was occurring even after I had figured out where the error was happening, I gave an example of this in the testing section.
I even disabled the inline suggestions provided by Clion as I find them to be too good. My main use of external resources was just for checking syntax and debugging any errors I had, the code and logic used in the code is entirely mine.

## **Testing & Status**
The program, to the best of my knowledge, is working perfectly. I did encounter some issues, such as the while loop in `solveMaze` giving an out-of-bounds error when the entire stack was popped. I tracked this by printing a success message after each step in the loop, it did help me in isolation where the issue was but in the end, I gave that piece of code to ChatGPT and asked why I was getting the error. It turned out the issue was in the loop condition, which I hadn’t noticed. My loop was checking whether the top of the stack was equal to the end and then if the stack was empty, but when the stack was empty, it caused the error. I also tested my code by changing the number of entry points, change the maze.
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

    
