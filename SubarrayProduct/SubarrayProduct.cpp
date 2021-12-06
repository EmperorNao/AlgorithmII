#include <iostream>
#include <vector>



// Given an array of integers nums and an integer k, 
// return the number of contiguous subarrays where the product of all
// the elements in the subarray is strictly less than k

using namespace std;

class Solution {
public:
    
    vector<vector<bool>> visited;
    int cur = 0;
    int m;
    int n;
    
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        cur = 0;
        
        visited.resize(m);
        
        for (int i = 0; i < m; ++i) {
            
            visited[i] = vector<bool>(n, false);
            
        }
        
        for (int i = 0; i < m; ++i) {
            
            for (int j = 0; j < n; ++j) {
                
                if (search(grid, i, j) == true) {
                    
                    cur += 1;
                    
                }
                
            }
            
            
        }     
        return cur;
        
    }
    
    bool search(vector<vector<char>>& grid, int i, int j) {
        
        if ((i < 0) or (i >= m)) {
            
            return false;
            
        }
        if ((j < 0) or (j >= n)) {
            
            return false;
            
        }
        
        if (visited[i][j]) {
        
            return false;
            
        }
        visited[i][j] = true;
        if (grid[i][j] == '0') {
            
            return false;
            
        }
        
        
        search(grid, i - 1, j);
        search(grid, i + 1, j);
        search(grid, i, j - 1);
        search(grid, i, j + 1);
        return true;        
        
    }
    
};


int main () {



}