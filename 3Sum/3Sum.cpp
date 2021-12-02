#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    
    struct coord {
        coord(int _i, int _j) : i(_i), j (_j) {};
        int i;
        int j;
    };
    
    vector<vector<int>> threeSum(vector<int>& nums) {
         
        vector<vector<int>> res = {};
        
        if (nums.size() < 3) {
            
            return {};
            
        }
        
        map<int, vector<coord>> map_sum;
        int n = nums.size();
        int sum;
        
        for (int i = 0; i < n; ++i) {
            
            for (int j = i + 1; j < n; ++j) {
                
                if (map_sum.find(sum) == map_sum.end()) {
                    map_sum[sum] = {};
                }
                map_sum[sum].push_back(coord(i, j));
                
            }
            
        }
        
        for (int k = 0; k < n; ++k) {
            
            if ((map_sum.find(-nums[k]) != map_sum.end())) {
                
                auto pairs = map_sum[-nums[k]];
                for (auto& p: pairs) {
                    
                    if (k > p.j) {
                        res.push_back({nums[k], nums[p.i], nums[p.j]});
                    }
                    
                }
                
            }
            
        }
        return res;
        
    }
};

int main() {


    
}