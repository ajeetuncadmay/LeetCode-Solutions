#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;
        
        // Initialize balances
        // buy variables are set to INT_MIN because we want to maximize a negative hit to our wallet
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        
        for (int price : prices) {
            // State 1: Max money left after buying the 1st stock
            buy1 = std::max(buy1, -price);
            
            // State 2: Max profit after selling the 1st stock
            sell1 = std::max(sell1, buy1 + price);
            
            // State 3: Max money left after buying the 2nd stock (using profit from sell1)
            buy2 = std::max(buy2, sell1 - price);
            
            // State 4: Max total profit after selling the 2nd stock
            sell2 = std::max(sell2, buy2 + price);
        }
        
        // sell2 will hold the maximum possible profit from up to 2 transactions
        return sell2;
    }
};