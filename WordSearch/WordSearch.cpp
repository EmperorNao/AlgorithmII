class Solution {
public:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m);
        for (int i = 0; i < m; ++i) {

            visited[i].resize(n, false);

        }

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                if (check(board, visited, word, 0, i, j)) {

                    return true;

                }

            }

        }
        return false;


    };

    bool check(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int pos, int i, int j) {

        if (pos == word.size()) {

            return true;

        }
        if ((i < 0) or (i >= m) or (j < 0) or (j >= n)) {

            return false;

        }
        
        if (visited[i][j]) {

            return false;

        }

        visited[i][j] = true;
        if (board[i][j] != word[pos]) {

            visited[i][j] = false;
            return false;

        }
        ++pos;

        //std::cout << i << " " << j << " " << board[i][j] << std::endl;
        bool res = false;
        res = res or check(board, visited, word, pos, i + 1, j);
        res = res or check(board, visited, word, pos, i, j + 1);
        res = res or check(board, visited, word, pos, i - 1, j);
        res = res or check(board, visited, word, pos, i, j - 1);
        --pos;

        visited[i][j] = false;
        return res;

    }

};