#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Agar current index tak hum pahunch hi nahi sakte, toh aage nahi badh sakte
            if (i > max_reach) {
                return false;
            }
            
            // Update karein ki hum maximum kahan tak jaa sakte hain
            max_reach = max(max_reach, i + nums[i]);
            
            // Agar max_reach aakhiri index tak ya usse aage pahunch gaya hai
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};