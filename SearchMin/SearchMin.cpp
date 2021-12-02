#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int findMin(vector<int>& nums) {

        return nums[rotation_pos(nums)];
    }

    int rotation_pos(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int mid = (l + r) / 2;
        while ((l + 1 < r) and (nums[l] > nums[r])) {

            if (nums[l] > nums[mid]) {

                r = mid;

            }
            else {

                l = mid;

            }
            mid = (l + r) / 2;

        }
        if (nums[l] > nums[r]) {

            return r;

        }
        else {

            return l;

        }
    }

};