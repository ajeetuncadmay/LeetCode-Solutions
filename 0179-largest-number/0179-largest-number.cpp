#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        
        // Step 1: Convert all integers to strings
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        // Step 2: Sort strings using a custom lambda comparator
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // Step 3: Handle edge case where all numbers are zeros (e.g., [0, 0])
        // If the largest element after sorting is "0", the entire result is "0".
        if (numStrings[0] == "0") {
            return "0";
        }
        
        // Step 4: Concatenate all sorted strings together
        string result = "";
        for (const string& str : numStrings) {
            result += str;
        }
        
        return result;
    }
};