#include <string>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        long long result = 0; // Use long long to prevent potential overflow during calculation
        
        for (char c : columnTitle) {
            // Convert character to its corresponding 1-indexed value ('A' -> 1, 'B' -> 2, etc.)
            int d = c - 'A' + 1;
            
            // Shift the existing total to the left by one base-26 position and add the new digit
            result = result * 26 + d;
        }
        
        return result;
    }
};