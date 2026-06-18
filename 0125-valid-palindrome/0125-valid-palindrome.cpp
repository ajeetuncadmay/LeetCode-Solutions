#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Move the left pointer forward if the character is not alphanumeric
            while (left < right && !std::isalnum(s[left])) {
                left++;
            }
            // Move the right pointer backward if the character is not alphanumeric
            while (left < right && !std::isalnum(s[right])) {
                right--;
            }
            
            // Compare characters after converting them to lowercase
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false; // Characters don't match, not a palindrome
            }
            
            // Move both pointers closer to the center
            left++;
            right--;
        }
        
        return true; // All valid characters matched perfectly
    }
};