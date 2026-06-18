#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // If s is shorter than t, t can't be a subsequence of s
        if (m < n) return 0;
        
        // dp[i][j] will store the count of subsequences of t[0...i-1] in s[0...j-1]
        // Using unsigned long long to handle large numbers and avoid overflow
        std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(m + 1, 0));
        
        // Base case: Empty t can be formed by any prefix of s in exactly 1 way
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (t[i-1] == s[j-1]) {
                    // Two choices: use the match + don't use the match
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                } else {
                    // Only one choice: skip the current character of s
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[n][m];
    }
};