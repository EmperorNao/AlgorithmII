#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int min_size = n + 1;
        int i = 0;
        int j = 0;
        int sum = 0;
        while ((j < n) or (sum >= target)) {
            
            while ((j < n) and (sum < target)) {

                sum += nums[j];
                ++j;

            }

            while ((i < j) and (sum - nums[i] > target)) {

                sum -= nums[i];
                ++i;

            }
            std::cout << i << " " << j << " ";
            std::cout << sum << std::endl;
            if (sum >= target) {

                min_size = j - i > min_size ? min_size : j - i;

            }
            if (i < n) {
                
                sum -= nums[i];
                ++i;
                
            }

        }
        return min_size == (n + 1) ? 0 : min_size;
        
    }
};


int main() {


    
}