//There is an integer array nums sorted in ascending order(with distinct values).
//
//Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k(1 <= k < nums.length) such that the resulting array is[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](0 - indexed).For example, [0, 1, 2, 4, 5, 6, 7] might be rotated at pivot index 3 and become[4, 5, 6, 7, 0, 1, 2].
//
//	Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//
//	You must write an algorithm with O(log n) runtime complexity.

// [4,5,6,7,0,1,2]

#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (not nums.size()) {

            return -1;

        }

        if (nums.size() == 1) {

            return -1 * (nums[0] != target);

        }

        int pos = rotation_pos(nums);
        int left = 0;
        int right = nums.size() - 1;
        if (pos != -1) {

            if ((nums[left] <= target) and (nums[pos - 1] >= target )) {

                return bin_search(nums, target, left, pos - 1);

            }
            return bin_search(nums, target, pos, right);

        }
        return bin_search(nums, target, left, right);

    }

    int bin_search(vector<int>& nums, int target, int l, int r) {

        int mid;
        while (l <= r) {

            mid = (l + r) / 2;
            if (nums[mid] < target) {

                l = mid + 1;

            }
            else if (nums[mid] > target) {

                r = mid - 1;

            }
            else {

                return mid;

            }

        }
        return -1;

    }

    int rotation_pos(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] < nums[r]) {

            return -1;

        }

        int mid = (l + r) / 2;
        while ((l + 1 < r)) {

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
        /*if (mid == r) {

            return mid;

        }
        return mid + 1;*/

    }

};


int main() {



}