#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (not matrix.size()) {

            return false;

        }

        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        while ((i < m) and (matrix[i][n - 1] < target)) {
            ++i;
        }
        if (i == m) {
            return false;
        }
        else {
            return bin_search(matrix[i], target);
        }


    }
    bool bin_search(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
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

                return true;

            }
            

        }
        return false;

    }
};