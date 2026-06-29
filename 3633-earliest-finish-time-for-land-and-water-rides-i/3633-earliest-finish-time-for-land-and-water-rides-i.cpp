#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    // Helper function to calculate total finish time for a specific order
    int findFinishTime(const std::vector<int>& start1, const std::vector<int>& duration1, 
                       const std::vector<int>& start2, const std::vector<int>& duration2) {
        
        // Step 1: Find the absolute earliest time we can finish any ride of the first type
        int min_end1 = INT_MAX;
        for (size_t i = 0; i < start1.size(); ++i) {
            min_end1 = std::min(min_end1, start1[i] + duration1[i]);
        }
        
        // Step 2: Find the minimum time to finish the second type of ride after min_end1
        int final_finish = INT_MAX;
        for (size_t j = 0; j < start2.size(); ++j) {
            int actual_start2 = std::max(min_end1, start2[j]);
            final_finish = std::min(final_finish, actual_start2 + duration2[j]);
        }
        
        return final_finish;
    }

public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, 
                           std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        
        // Order 1: Land Ride First, then Water Ride
        int landThenWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Order 2: Water Ride First, then Land Ride
        int waterThenLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);
        
        // Return the best option out of both sequences
        return std::min(landThenWater, waterThenLand);
    }
};