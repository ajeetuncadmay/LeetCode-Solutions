#include <vector>
#include <string>

class Solution {
public:
    int numOfStrings(std::vector<std::string>& patterns, std::string word) {
        int count = 0;
        
        for (const std::string& pattern : patterns) {
            // check if the pattern is a substring of word
            if (word.find(pattern) != std::string::npos) {
                count++;
            }
        }
        
        return count;
    }
};