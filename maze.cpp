//
// Created by Rishav Sharma on 9/10/25.
//

#include "maze.h"

void maze::importMaze(const std::string &filename) {
    std::ifstream file(filename);
    std::string line; // used for reading file data
    std::vector<std::pair<int, bool> > aRow; // temp vector used to push data into the 2D vector

    // check whether the file is open or not
    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }

    while (std::getline(file, line)) {
        for (auto c: line) {
            int data = c - '0';
            aRow.push_back({data, true});
            // - '0' converts char to int, learned this from the first search result on google...
        }

        primeMaze.push_back(aRow); // push the temp vector and place it in the desired row of our 2D maze vector
        aRow.clear(); // This will empty the temp vector for future use
    }

    findKeyVariables();

    file.close();
}


void maze::printMaze() {
    for (std::vector<std::pair<int, bool> >
         &aRow: primeMaze) {
        for (const std::pair element: aRow) {
            std::cout << element.first << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// The following functions analyzes the maze vector to find all the key coordinates and variables like the start and end
// points of a maze, and what are the bounds of the maze.
void maze::findKeyVariables() {
    std::vector<std::pair<int, int> > openings; // temp vector with the openings

    if (primeMaze.empty()) return;

    lastXIdx = primeMaze[0].size() - 1;
    lastYIdx = primeMaze.size() - 1;

    // This loops checks if there is a pathable cell in the top or bottom row, if there is one then it pushes it onto the openings vector
    for (int i = 0; i <= lastXIdx; i++) {
        if (isPath(i, 0)) {
            openings.push_back({i, 0});
        }
        if (isPath(i, lastYIdx)) {
            openings.push_back({i, lastYIdx});
        }
    }

    // This loops checks if there is a pathable cell in the left or right column, if there is one then it pushes it onto the opening vector.
    for (int i = 0; i <= lastYIdx; i++) {
        if (isPath(0, i)) {
            openings.push_back({0, i});
        }
        if (isPath(lastXIdx, i)) {
            openings.push_back({lastXIdx, i});
        }
    }

    // The following statement checks whether we have enough data for start and end, if we do store the data into those variables.
    if (openings.size() >= 2) {
        start = openings.at(0);
        end = openings.at(1);
    } else {
        std::cout << "no valid start/end" << std::endl;
    }
}

// returns true if coordinates are not out of bound
bool maze::inBounds(int x, int y) const {
    return x >= 0 && x <= lastXIdx && y >= 0 && y <= lastYIdx;
}


// checks whether the coordinate is a path or not
bool maze::isPath(int x, int y) {
    if (!inBounds(x, y)) return false;
    if (primeMaze[y][x].first == 1) return false;
    return true;
}

// checks if cell can be visited or not by checking if it has been visited before.
bool maze::canVisit(int x, int y) {
    if (!inBounds(x, y)) return false;
    if (primeMaze[y][x].second) return true;
    return false;
}

// checks whether we can travel to the designated cell
bool maze::canTravel(int x, int y) {
    // Check whether the coordinates are inBounds or not
    if (!inBounds(x, y)) return false;
    // Check whether the coordinates are pathable or not
    if (!isPath(x, y)) return false;
    // Check if the cell has been visited before or not
    if (!canVisit(x, y)) return false;

    return true;
}

// marks the coordinates as visited
void maze::markVisited(int x, int y) {
    if (primeMaze[y][x].second) {
        primeMaze[y].at(x).second = false;
    }
}


void maze::solveMaze() {
    // Checks whether there is a proper start or not
    if (start.first == -1) {
        std::cout << "No defined Start or End" << std::endl;
        return;
    }

    path.push(start); // pushes the starting point onto the stack
    markVisited(start.first, start.second); // marks the starting point as visited

    //loops until the stack is empty or until the target/end is reached
    while (!path.empty() && path.top() != end) {
        int x = path.top().first;
        int y = path.top().second;

        // checks and travels to a valid cell. order of movement is Right, left, up and down
        if (canTravel(x + 1, y)) {
            markVisited(x + 1, y);
            path.push({x + 1, y});
        } else if (canTravel(x - 1, y)) {
            markVisited(x - 1, y);
            path.push({x - 1, y});
        } else if (canTravel(x, y + 1)) {
            markVisited(x, y + 1);
            path.push({x, y + 1});
        } else if (canTravel(x, y - 1)) {
            markVisited(x, y - 1);
            path.push({x, y - 1});
        } else {
            path.pop(); // if can't move pop from the stack
        }
    }

    // If the path is empty that means that there is no solution
    if (path.empty()) {
        std::cout << "The Maze has no solution" << std::endl;
        return;
    }
    std::cout << "The maze has been solved" << std::endl;

    // create a copy of the primeMaze to the solved maze with just chars
    for (const auto &row: primeMaze) {
        std::vector<char> aRow;
        for (const auto &cell: row) {
            if (cell.first == 0)
                aRow.push_back('0');
            else
                aRow.push_back('1');
        }
        solvedMaze.push_back(aRow);
    }

    // Edit the copied maze with the solution
    while (!path.empty()) {
        int x = path.top().first;
        int y = path.top().second;
        solvedMaze[y].at(x) = ' ';
        path.pop();
    }
}


void maze::printSolution() {
    if (solvedMaze.empty()) {
        std::cout << "No Solution to print, call the solveMaze function before calling print" << std::endl;
        return;
    }

    for (auto row: solvedMaze) {
        for (auto cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}
