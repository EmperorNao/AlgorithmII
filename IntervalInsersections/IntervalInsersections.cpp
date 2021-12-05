#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

    inline bool intersects(vector<int>& a, vector<int>& b) {

        return (b[0] <= a[0]) and (b[1] >= a[0]) or (b[0] <= a[1]) and (b[1] >= a[1]);

    }

    inline vector<int> intersection(vector<int>& a, vector<int>& b) {

        int right = a[1] > b[1] ? b[1] : a[1];
        int left = a[0] > b[0] ? a[0] : b[0];
        return {left, right};

    }


    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> res;
        while ((i < n) and (j < m)) {

            if (intersects(firstList[i], secondList[j]) or intersects(secondList[j], firstList[i])) {

                res.push_back(intersection(firstList[i], secondList[j]));

            }

            if (firstList[i][1] < secondList[j][1]) {

                ++i;

            }
            else {

                ++j;

            }


        }
        return res;
        
    }
};