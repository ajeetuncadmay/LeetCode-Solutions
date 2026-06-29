#include <vector>
#include <algorithm>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // Create a 2D DP table initialized with 0
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        // Base case: The health required after reaching the princess destination
        // The knight must have at least 1 HP remaining.
        dp[m - 1][n - 1] = std::max(1, 1 - dungeon[m - 1][n - 1]);
        
        // Fill the last column (can only move Down)
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = std::max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        
        // Fill the last row (can only move Right)
        for (int j = n - 2; j >= 0; --j) {
            dp[m - 1][j] = std::max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }
        
        // Fill the rest of the DP table bottom-up, right-to-left
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                int min_health_on_exit = std::min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = std::max(1, min_health_on_exit - dungeon[i][j]);
            }
        }
        
        // dp[0][0] holds the minimum initial health needed at the starting point
        return dp[0][0];
    }
};