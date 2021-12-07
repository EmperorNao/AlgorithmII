#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;
    vector<bool> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();
        visited.resize(n, false);
        int cur = 0;

        for (int i = 0; i < n; ++i) {

            if (search(isConnected, i)) {

                cur += 1;

            }

        }
        return cur;


    }

    bool search(vector<vector<int>>& isConnected, int i) {

        if ((i < 0) or (i >= n)) {

            return false;

        } 

        if (visited[i]) {

            return false;

        }

        visited[i] = true;

        for (int j = 0; j < i; ++j) {

            if (isConnected[i][j]) {
                search(isConnected, j);
            }

        }
        for (int j = i + 1; j < n; ++j) {

            if (isConnected[i][j]) {
                search(isConnected, j);
            }

        }

        return true;

    }
};


int main () {



}