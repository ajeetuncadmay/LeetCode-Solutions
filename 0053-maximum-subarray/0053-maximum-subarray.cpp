#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN; // Sabse choti possible value se shuru karein
        int current_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // 1. Current element ko sum me jodein
            current_sum += nums[i];
            
            // 2. Max sum ko update karein agar current_sum bada hai
            max_sum = max(max_sum, current_sum);
            
            // 3. Agar current_sum negative ho jaye, toh use reset (0) kar dein
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        return max_sum;
    }
};