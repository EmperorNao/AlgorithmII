class Solution {
public:
    
    struct parenthesis {
        
        int open;
        int closed;
        string str;
        
    };
    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;
        recursive_way(n, 0, 0, "", answer);
        return answer;
        
    }
    
    void recursive_way(int n, int o, int c, string s, vector<string>& answer) {
        
        if (o == n and c == n) {
            
            answer.push_back(s);
            
        }
        else if (o == n) {
            
            recursive_way(n, o, c + 1, s + ")", answer);
            
        }
        else if (o == c) {
            
            recursive_way(n, o + 1, c, s + "(", answer);
            
        }
        else {
            
            recursive_way(n, o + 1, c, s + "(", answer);
            recursive_way(n, o, c + 1, s + ")", answer);
            
        }
        
        
        
        
    }
    
};