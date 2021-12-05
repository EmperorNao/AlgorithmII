#include <vector>

using namespace std;


// This solution is OK but slow (5%)
/*class Solution {
public:

    int min(int a, int b) {

        return a > b ? b : a;

    }

    int max(int a, int b) {

        return a > b ? a : b;

    }


    int area(vector<int>& height, int l, int r) {

        return (r - l) * min(height[l], height[r]);

    }


    int maxArea(vector<int>& height) {

        int n = height.size();
        int lmax = INT_MIN;
        std::vector<int> left;
        for (int i = 0; i < n; ++i) {

            if (height[i] > lmax) {

                left.push_back(i);
                lmax = height[i];

            }

        }

        int rmax = INT_MIN;
        std::vector<int> right;
        for (int i = n - 1; i >= 0; --i) {

            if (height[i] > rmax) {

                right.push_back(i);
                rmax = height[i];

            }

        }

        
        int max_value = INT_MIN;
        for (auto i: left) {

            for (auto j: right) {

                max_value = max(max_value, area(height, i, j));

            }


        }
        
        return max_value;

    }
};*/


// This solution is OK but TL
class Solution {
public:

    int min(int a, int b) {

        return a > b ? b : a;

    }

    int max(int a, int b) {

        return a > b ? a : b;

    }


    int area(vector<int>& height, int l, int r) {

        return (r - l) * min(height[l], height[r]);

    }


    int maxArea(vector<int>& height) {

        int i = 0;
        int j = 1;
        int max_value = 0;
        int n = height.size();

        int last_greater;
        while (i < n) {

            last_greater = n;
            j = i + 1;
            while (j < n) {

                if (last_greater == n) {

                    last_greater = j;

                }

                int cur = area(height, i, j);
                max_value = max(cur, max_value);
                ++j;

            }
            i = last_greater;

        }
        return max_value;

    }
};