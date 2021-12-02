/*class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_s;
        stack<char> s_t;
        
        for (int i = 0; i < s.size(); ++i) {
            
            if ((s[i] == '#') and (s_s.size())) {
                
                s_s.pop();
                
            }
            else if (s[i] != '#') {
                
                s_s.push(s[i]);
                
            }
            
        }
        
        for (int i = 0; i < t.size(); ++i) {
            
            if ((t[i] == '#') and (s_t.size())) {
                
                s_t.pop();
                
            }
            else if (t[i] != '#') {
                
                s_t.push(t[i]);
                
            }
            
        }   
        
        if (s_s.size() != s_t.size()) {
        
            return false;
            
        }
        
        while ((s_s.size()) and (s_s.top() == s_t.top())) {
            s_s.pop();
            s_t.pop();
        
        }
        
        
        return not s_s.size();
        
    }
};*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int cmp_i = i;
        int cmp_j = i;
        
        while ((i >= 0) and (j >= 0)) {
            while ((i >= 0) and (s[i] == '#')) {
                --i;
                cmp_i -= 2;
            }
            while ((j >= 0) and (t[j] == '#')) {
                cmp_j -= 2;
                --j;
            }
            if ((cmp_i >= 0) and (cmp_j >= 0) and (s[cmp_i] != s[cmp_j])) { return false; }
            cmp_i -= 1;
            cmp_j -= 1;
            --i;
            --j;
        }
        return true;
        
            
    }

};