#include <iostream>
#include <vector>

std::vector< std::vector<int> > subSets(std::vector<int> set){
    std::vector<std::vector<int>> prevSubs = {{}}; 
    for (int i = 0; i < set.size(); ++i){
        std::vector< std::vector<int> > newSubs = prevSubs;
        for(auto it = newSubs.begin(); it != newSubs.end(); ++it){
            (*it).push_back(set.at(i));
        }
        for(auto it2 = newSubs.begin(); it2 != newSubs.end(); ++it2){
            prevSubs.push_back(*it2);
        }
    }
    return prevSubs;
}

int main() {
    std::vector<int> set = {1,2,3};
    std::vector< std::vector<int> > subsets = subSets(set);
    for(auto outter = subsets.begin(); outter != subsets.end(); ++outter){
        for(auto inner = (*outter).begin(); inner != (*outter).end(); ++inner){
            std::cout  << *inner ;
        }
        std::cout << std::endl;
    }

    return 0;
}