#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumCost(std::vector<int>& cost) {
        // Step 1: Sort the candies in descending order
        std::sort(cost.begin(), cost.end(), std::greater<int>());
        
        int totalCost = 0;
        int n = cost.size();
        
        // Step 2: Loop through the sorted array and buy two, skip one
        for (int i = 0; i < n; i++) {
            // Every 3rd element (indices 2, 5, 8...) is free, so we skip adding it to totalCost
            if ((i + 1) % 3 == 0) {
                continue;
            }
            totalCost += cost[i];
        }
        
        return totalCost;
    }
};