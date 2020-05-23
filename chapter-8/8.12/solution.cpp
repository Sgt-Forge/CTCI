#include <iostream>
#include <vector>

void printBoard(std::vector< std::vector<int> > board){
    std::cout << "========================================\n" ;
    for(auto row = board.begin(); row != board.end(); ++row){
        for(auto col = (*row).begin(); col != (*row).end(); ++col){
            if (*col != -1){
                std::cout << "|  " << *col << "\t" ;
            } else {
                std::cout << "| " << *col << "\t" ;
            }
        }
        std::cout << std::endl;
    }
}
void printSolution(std::vector< std::vector<int> > board){
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "|                      NEW SOLUTION                             |\n";
    std::cout << "-----------------------------------------------------------------\n";
    for(auto row = board.begin(); row != board.end(); ++row){
        for(auto col = (*row).begin(); col != (*row).end(); ++col){
            if (*col != -1){
                std::cout << "|  " << *col << "\t" ;
            } else {
                std::cout << "| " << *col << "\t" ;
            }
        }
        std::cout << std::endl;
    }
}

void invalidRow(std::vector < std::vector<int> >& board, int row){
    for (int col = 0; col < board[row].size(); ++col){
        if( board[row][col] != 9){
            board[row][col] = -1;
        }
    }
}

void invalidCol(std::vector < std::vector<int> >& board, int col){
    for (auto row = board.begin(); row != board.end() ; ++row){
        if( (*row)[col] != 9){
            (*row)[col] = -1;
        }
    }
}

void invalidDiag(std::vector< std::vector<int> >& board, int row, int col){
    const int MAX_ROW = board.size();
    const int MAX_COL = board[0].size();
    // Going to the up and left
    int tRow = row-1;
    int tCol = col-1;
    while (tRow >=0 && tCol >= 0){
        if( board[tRow][tCol] != 9){
            board[tRow][tCol] = -1;
        }
        --tRow;
        --tCol;
    }
    // Going up and right 
    tRow = row-1;
    tCol = col+1;
    while( tRow >=0 && tCol < MAX_COL){
        if( board[tRow][tCol] != 9){
            board[tRow][tCol] = -1;
        }
        --tRow;
        ++tCol;
    }

    // Going down and right 
    tRow = row+1;
    tCol = col+1;
    while( tRow < MAX_ROW && tCol < MAX_COL){
        if( board[tRow][tCol] != 9){
            board[tRow][tCol] = -1;
        }
        ++tRow;
        ++tCol;
    }

    // Going down and left
    tRow = row+1;
    tCol = col-1;
    while( tRow < MAX_ROW && tCol >= 0){
        if( board[tRow][tCol] != 9){
            board[tRow][tCol] = -1;
        }
        ++tRow;
        --tCol;
    }
}

void queensHelper(std::vector< std::vector<int> > board, int row, int col){
    for(int newRow = row; newRow < board.size(); ++newRow){
        auto newBoard = board;
        if(newBoard[newRow][col] == 0){ // Found valid position, emplace new queen and recurse
            newBoard[newRow][col] = 9;
            invalidRow(newBoard, newRow);
            invalidCol(newBoard, col);
            invalidDiag(newBoard, newRow, col);
            if(col == board[row].size()-1){ // In the last col, assume we can print the board
                printSolution(newBoard);
            } else {
                queensHelper(newBoard, 0, col+1);
            }
        }
    }
}

void queens(std::vector< std::vector<int> > board){
    // Iterate through the rows to explore placing the FIRST queen in different rows
    for(int row = 0; row != board.size(); ++row){
        auto newBoard = board; // This is bad.  We should avoid copy constructors
        newBoard[row][0] = 9;
        invalidRow(newBoard, row);
        invalidCol(newBoard, 0);
        invalidDiag(newBoard, row, 0);
        queensHelper(newBoard, 0, 1);
    }
}

int main(){
    std::vector< std::vector<int> > board4 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    std::vector< std::vector<int> > board5 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    std::vector< std::vector<int> > board8 = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    /*
    invalidDiag(board8, 0, 0);
    printBoard(board8);
    invalidDiag(board8, 0, 7);
    printBoard(board8);
    invalidDiag(board8, 4, 2);
    printBoard(board8);
    */
    queens(board5);

    return 0;
}