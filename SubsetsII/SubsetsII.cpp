class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> res;
        int n = nums.size();
        int m = 1 << n;
        for (int v = 0; v < m; ++v) {
            
            res.insert(get_perm(nums, v));
            
        }
        
        vector<vector<int>> real_res;
        for (auto& v: res) {
            
            real_res.push_back(v);
            
        }
        return real_res;
        
    }
    
    vector<int> get_perm(vector<int>& nums, int v) {
        
        vector<int> res;
        unsigned m = 1;
        for (int i = 0; i < nums.size(); ++i) {
        
            if (m & v) {
                
                res.push_back(nums[i]);
                
            }
            m <<= 1;
            
        }
        sort(res.begin(), res.end());
        return res;  
        
    }
};