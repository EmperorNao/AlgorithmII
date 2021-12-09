class Solution {
public:
    vector<string> letterCombinations(string digits) {
  
        if (not digits.size()) {
            
            return {};
            
        }
        map<char, string> num = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> res = {""};
        for (int i = 0; i < digits.size(); ++i) {

            string digs = num[digits[i]];
            vector<string> t;
            for (auto& r: res) {

                for (auto& d: digs) {

                    t.push_back(r + d);

                }

            }
            res = t;

        }
        return res;

    }
};