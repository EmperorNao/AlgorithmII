class Solution {
public:
    vector<vector<int>> visited;
    int m;
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();

        visited.resize(m);
        for (int i = 0; i < m; ++i) {

            visited[i].resize(n, -1);

        }

        int p = path(grid, 0, 0, 1);
        if (p == INT_MAX) {
            
            p = -2;
            
        }
        ++p;
        return p;


    }

    int min(int a, int b) {

        return a > b ? b : a;

    }

    void change_coord(int&i, int& j, int dir) {

        switch(dir) {
            case 1: 
                --i;
                --j;
                break;
            case 2: 
                --j;
                break;
            case 3: 
                --i;
                ++j;
                break;
            case 4:
                --j;
                break;
            case 5: 
                ++j;
                break;
            case 6: 
                ++i;
                --j;
                break;
            case 7: 
                ++i;
                break;
            case 8:
                ++i;
                ++j;
                break;
        }
        return;

    }


    // dir = 
    /*     

        123
        4 5
        678

    */
    int path(vector<vector<int>>& grid, int i, int j, int dir) {
        
        std::cout << i << " " << j << " " << dir << std::endl;


        if ((i < 0 or i >= m) or (j < 0 or j >= n)) {

            return INT_MAX;

        }
        if (grid[i][j] == 1) {

            return INT_MAX;

        }
        if ((i == m - 1) and (j == n - 1)) {

            return 0;

        }
        if (visited[i][j] != -1) {

            return visited[i][j];

        }

        visited[i][j] = INT_MAX;
        int m = INT_MAX;
        int c = INT_MAX;

        int t_i;
        int t_j;
        for (int d = 1; d < dir; ++d) {

            t_i = i;
            t_j = j;
            change_coord(t_i, t_j, d);
            c = path(grid, t_i, t_j, d);
            if (c != INT_MAX) {

                m = min(c, m);

            }

        }
        for (int d = dir + 1; d <= 9; ++d) {

            t_i = i;
            t_j = j;
            change_coord(t_i, t_j, d);
            c = path(grid, t_i, t_j, d);
            if (c != INT_MAX) {

                m = min(c, m);

            }

        }

        if (m != INT_MAX) {

            ++m;

        }
        visited[i][j] = m;
        return visited[i][j];
        
    }
};