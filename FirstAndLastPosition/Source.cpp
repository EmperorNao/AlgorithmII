#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        return {left_bin_search(nums, target), right_bin_search(nums, target)};

    }

    int left_bin_search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l < r) {

            mid = floor(double(l + r) / 2);
            if (nums[mid] < target) {

                l = mid + 1;

            }
            else if (nums[mid] > target) {

                r = mid - 1;

            }
            else {

                r = mid;

            }

        }
        if ((l >= 0) and (l <= nums.size()) and (nums[l] == target)) {

            return l;

        }
        return -1;

    }

    int right_bin_search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l < r) {

            mid = ceil(double(l + r) / 2);
            if (nums[mid] < target) {

                l = mid + 1;

            }
            else if (nums[mid] > target) {

                r = mid - 1;

            }
            else {

                l = mid;

            }

        }
        if ((r >= 0) and (r <= nums.size()) and (nums[r] == target)) {

            return r;

        }
        return -1;

    };


};



int main() {

    vector<int> a = { 1, 2, 3, 4, 5, 5, 6};
    int target = 5;
    auto res = Solution().searchRange(a, target);
    std::cout << res[0] << " " << res[1] << std::endl;

}