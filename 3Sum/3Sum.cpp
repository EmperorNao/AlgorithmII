#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    struct coord {
        coord(int _i, int _j) : i(_i), j (_j) {};
        int i;
        int j;
    };
    

    bool duplicate(int i, int j, int k) {

        return i == j or j == k or i == k;

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<int, int> num;

        int n = nums.size();

        for (int i = 0;i < n; ++i) {

            num[nums[i]] = i;

        }

        vector<vector<int>> res;
        set<vector<int>> set_res;
        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {

                if (num.find(-nums[i] - nums[j]) != num.end()) {

                    int k = num[-nums[i] - nums[j]];
                    std::vector<int> v = { nums[i], nums[j], nums[k] };
                    int min = v[std::distance(std::min_element(v.begin(), v.end()), v.begin())];
                    int max = v[std::distance(std::max_element(v.begin(), v.end()), v.begin())];
                    int avg = nums[i] + nums[j] + nums[k] - min - max;
                    v = {min, avg, max};
                    if ((not duplicate(i, j, k)) and (set_res.find(v) == set_res.end())) {

                        set_res.insert(v);
                        res.push_back(v);

                    }

                }


            }

        }

        return res;

    }
};

int main() {



}