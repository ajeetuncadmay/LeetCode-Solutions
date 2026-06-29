#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        
        int leftSum = 0;
        int rightSum = 0;
        
        // Step 1: Calculate the total sum of all elements to initialize rightSum
        for (int num : nums) {
            rightSum += num;
        }
        
        // Step 2: Calculate differences and update running sums
        for (int i = 0; i < n; ++i) {
            // Remove the current element from rightSum
            rightSum -= nums[i];
            
            // Calculate the absolute difference
            answer[i] = std::abs(leftSum - rightSum);
            
            // Add the current element to leftSum for the next positions
            leftSum += nums[i];
        }
        
        return answer;
    }
};