#include <vector>
#include <algorithm>
#include <climits>

class Solution {
private:
    // Helper function to calculate the best finish time for a specific ride sequence
    int findFinishTime(const std::vector<int>& start1, const std::vector<int>& duration1, 
                       const std::vector<int>& start2, const std::vector<int>& duration2) {
        
        int finish1 = INT_MAX;
        // Step 1: Find the absolute earliest time we can finish any ride of the first category
        for (size_t i = 0; i < start1.size(); ++i) {
            finish1 = std::min(finish1, start1[i] + duration1[i]);
        }
        
        int final_finish = INT_MAX;
        // Step 2: Evaluate the earliest finish time for all rides in the second category
        for (size_t j = 0; j < start2.size(); ++j) {
            int actual_start2 = std::max(finish1, start2[j]);
            final_finish = std::min(final_finish, actual_start2 + duration2[j]);
        }
        
        return final_finish;
    }

public:
    int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, 
                           std::vector<int>& waterStartTime, std::vector<int>& waterDuration) {
        
        // Scenario 1: Land Ride First, followed by Water Ride
        int landThenWater = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        
        // Scenario 2: Water Ride First, followed by Land Ride
        int waterThenLand = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);
        
        // Return the absolute minimum of both pathways
        return std::min(landThenWater, waterThenLand);
    }
};