#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        vector<int> stack;
        stack.push_back(0);
        
        while(!stack.empty()){
            int current = stack.back();
            stack.pop_back();
            
            for(int key : rooms[current]){
                if(!visited[key]){
                    visited[key] = true;
                    stack.push_back(key);
                }
            }
        }
        
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};
