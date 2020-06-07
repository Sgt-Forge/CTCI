#include <iostream>
#include <vector>

void colorFill(std::vector< std::vector<int> >& screen, int row, int col, int newColor){
    const int MAX_COL = screen[0].size();
    const int MAX_ROW = screen.size();
    int currColor = screen[row][col];

    screen[row][col] = newColor;
    if(row-1 >= 0 && screen[row-1][col] == currColor){ colorFill(screen, row-1, col, newColor); }
    if(row+1 < MAX_ROW && screen[row+1][col] == currColor){ colorFill(screen, row+1, col, newColor); }
    if(col-1 >= 0 && screen[row][col-1] == currColor){ colorFill(screen, row, col-1, newColor); }
    if(col+1 < MAX_COL && screen[row][col+1] == currColor){ colorFill(screen, row, col+1, newColor); }
}

void printScreen(std::vector< std::vector<int> > screen){
    for(auto outter = screen.begin(); outter != screen.end(); ++outter){
        for(auto inner = (*outter).begin(); inner != (*outter).end(); ++inner){
            std::cout << *inner << ", " ;
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector< std::vector<int> > screen = {
        {0, 0, 0, 1, 2},
        {0, 0, 0, 1, 2},
        {0, 0, 0, 1, 2},
        {1, 1, 1, 1, 2},
        {1, 1, 1, 1, 2}
    };
    printScreen(screen);
    colorFill(screen, 2, 3, 3);
    std::cout << "=======================================\n";
    printScreen(screen);

    return 0;
}