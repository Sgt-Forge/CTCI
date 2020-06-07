#include <iostream>
#include <queue>
#include <vector>

void printGrid(std::vector< std::vector<int> > grid){
    for(auto outter = grid.begin(); outter != grid.end(); ++outter){
        for(auto inner = (*outter).begin(); inner != (*outter).end(); ++inner){
            std::cout << (*inner) << ", " ;
        }
        std::cout << std::endl;
    }
}

int* BFS(int* grid, int rows, int cols){
    std::queue<int> m_queue;
    int goal = rows*cols-1;
    int* cameFrom = new int[goal+1];

    m_queue.push(0);
    while( !m_queue.empty() ){
        int current = m_queue.front();
        m_queue.pop();

        int right = current+1;
        int below = current+5;
        if (grid[right] && (current) % (rows-1) != 0){
            std::cout << "RIGHT COORD:\t" << right << std::endl;
            if (right == goal) {
                std::cout << "Found it" << std::endl;
                cameFrom[right] = current;
                break;
            } else if(right < goal && !cameFrom[right]){
                m_queue.push(right);
                cameFrom[right] = current;
            }
        }
        if (grid[below]){
            std::cout << "BELOW COORD:\t" << below << std::endl;
            if (below == goal){
                std::cout << "Found it" << std::endl;
                cameFrom[below] = current;
                break;
            } else if(below < goal && !cameFrom[below]){
                m_queue.push(below);
                cameFrom[below] = current;
            }
        }
    }

    return cameFrom;
}

int main(){
    int grid[25] = {1, 1, 1, 1, 1,
                 1, 0, 0, 0, 1,
                 1, 1, 0, 1, 0,
                 0, 1, 0, 0, 0,
                 1, 1, 1, 1, 1
                };
    int rows = 5;
    int cols = 5;
    int size =  rows*cols;
    
    int* cameFrom = BFS(grid, rows, cols);
    int coord = cameFrom[size-1];
    std::cout << "goal came from:\t" << cameFrom[size-1] << std::endl;
    while(coord){
        std::cout << "came from:\t" << coord << std::endl;
        coord = cameFrom[coord];
    }
    std::cout << "came from:\t0\n" ;
    
    delete cameFrom;

    return 0;
}