class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n = nums.size();
        int m = 1 << n;
        for (int v = 0; v < m; ++v) {
            
            res.push_back(get_perm(nums, v));
            
        }
        return res;
        
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
        return res;  
        
    }
};