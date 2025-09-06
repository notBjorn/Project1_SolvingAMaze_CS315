#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main() {
    std::ifstream file("./maze.txt");
    std::string line;
    std::vector<std::vector<int> > maze;

    if (!file.is_open()) {
        std::cout << "File not open" << std::endl;
    }
    int row = 0;
    while (std::getline(file, line)) {
        std::cout<<line<<std::endl; // remove later, this was to test if the reading of line works or not.
        //getting an extra 0 there for some reason, will diagnose that tomorrow.
        for (auto i = 0; i < line.length(); i++) {
            //need to create another vector that will store rows here
            //then I need to push that vector onto the 2d vector. I think...
        }
        row++;
    }

    file.close();
    return 0;
}
