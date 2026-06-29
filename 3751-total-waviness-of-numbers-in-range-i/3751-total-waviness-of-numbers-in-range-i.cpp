#include <string>
#include <vector>

class Solution {
private:
    // Helper function to calculate waviness of a single number
    int getWaviness(int num) {
        std::string s = std::to_string(num);
        if (s.length() < 3) return 0;
        
        int count = 0;
        // Check only inner digits (skipping the first and last digit)
        for (size_t i = 1; i < s.length() - 1; ++i) {
            // Check for Peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                count++;
            }
            // Check for Valley
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                count++;
            }
        }
        return count;
    }

public:
    int totalWaviness(int num1, int num2) {
        int totalSum = 0;
        
        // Accumulate waviness for all numbers in the inclusive range
        for (int i = num1; i <= num2; ++i) {
            totalSum += getWaviness(i);
        }
        
        return totalSum;
    }
};