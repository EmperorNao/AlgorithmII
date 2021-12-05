#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};


class Solution {
public:
    
    struct coord {
        coord(int& _i, int& _j) : i(_i), j (_j) {};
        int i;
        int j;
    };


    vector<vector<int>> threeSum(vector<int>& nums) {
        
        map<int, unordered_set<int>> indexes;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {

            if (indexes.find(nums[i]) == indexes.end()) {
                indexes[nums[i]] = unordered_set<int>();
            }
            indexes[nums[i]].insert(i);

        }

        map<int, vector<coord>> sum;
        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {

                int s = nums[i] + nums[j];
                if (sum.find(s) == sum.end()) {

                    sum[s] = {};

                }
                sum[s].push_back(coord(i, j));

            }

        }

        vector<vector<int>> res;
        unordered_set<vector<int>, VectorHash> set_res;
        for (auto& pairs: sum) {

            if (indexes.find(-pairs.first) != indexes.end()) {

                for (auto& p: pairs.second) {

                    int num_in = (indexes[-pairs.first].find(p.i) != indexes[-pairs.first].end()) + (indexes[-pairs.first].find(p.j) != indexes[-pairs.first].end());
                    if (indexes[-pairs.first].size() > num_in) {

                        std::vector<int> v = { nums[p.i], nums[p.j], -pairs.first };
                        std::sort(v.begin(), v.end());

                        if (set_res.find(v) == set_res.end()) {

                            set_res.insert(v);
                            res.push_back(v);

                        }

                    }


                }

            }

        }

        return res;


    }
};

int main() {



}