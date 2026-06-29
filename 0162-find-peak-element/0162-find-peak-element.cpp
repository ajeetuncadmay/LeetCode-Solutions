#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // Binary Search
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If the middle element is smaller than the next element,
            // then a peak must exist on the right half.
            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } 
            // If the middle element is greater or equal,
            // the peak is either at mid or on the left half.
            else {
                high = mid;
            }
        }
        
        // When low == high, they point to a peak element.
        return low;
    }
};