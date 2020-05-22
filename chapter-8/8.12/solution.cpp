#include <iostream>
#include <vector>

void printBoard(std::vector< std::vector<int> > );

void invalidRow(std::vector< std::vector<int> >&, int);
void invalidCol(std::vector< std::vector<int> >&, int);
void invalidDiag(std::vector< std::vector<int> >&, int, int);

void queens();
void queensHelper();


void printBoard(std::vector< std::vector<int> > board){
    std::cout << "========================================\n" ;
    for(auto row = board.begin(); row != board.end(); ++row){
        for(auto col = (*row).begin(); col != (*row).end(); ++col){
            std::cout << *col << ", " ;
        }
        std::cout << std::endl;
    }
}

void invalidRow(std::vector < std::vector<int> >& board, int row){
    for (int col = 0; col < board[row].size(); ++col){
        board[row][col] = -1;
    }
}

void invalidCol(std::vector < std::vector<int> >& board, int col){
    for (auto row = board.begin(); row != board.end() ; ++row){
        (*row)[col] = -1;
    }
}

void invalidDiag(std::vector< std::vector<int> >& board, int row, int col){
    const int MAX_ROW = board.size();
    const int MAX_COL = board[0].size();
    // Going to the up and left
    int tRow = row-1;
    int tCol = col-1;
    while (tRow >=0 && tCol >= 0){
        board[tRow--][tCol--] = -1;
    }
    // Going up and right 
    tRow = row-1;
    tCol = col+1;
    while( tRow >=0 && tCol < MAX_COL){
        board[tRow--][tCol++] = -1;
    }

    // Going down and right 
    tRow = row+1;
    tCol = col+1;
    while( tRow < MAX_ROW && tCol < MAX_COL){
        board[tRow++][tCol++] = -1;
    }

    // Going down and left
    tRow = row+1;
    tCol = col-1;
    while( tRow < MAX_ROW && tCol >= 0){
        board[tRow++][tCol--] = -1;
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
    invalidDiag(board8, 0, 0);
    printBoard(board8);
    invalidDiag(board8, 0, 7);
    printBoard(board8);
    invalidDiag(board8, 4, 2);
    printBoard(board8);

    return 0;
}