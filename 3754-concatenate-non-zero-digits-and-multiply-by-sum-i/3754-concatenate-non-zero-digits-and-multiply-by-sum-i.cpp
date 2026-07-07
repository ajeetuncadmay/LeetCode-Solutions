#include <string>

class Solution {
public:
    long long sumAndMultiply(long long number) {
        // Negative numbers ko handle karne ke liye
        if (number < 0) {
            number = -number;
        }

        std::string numStr = std::to_string(number);
        std::string concatStr = "";
        long long sumOfDigits = 0;

        // Har ek digit ko check karein
        for (char ch : numStr) {
            if (ch != '0') {
                concatStr += ch;          // Non-zero digits ko concatenate karein
                sumOfDigits += (ch - '0'); // Digits ka sum nikaalein
            }
        }

        // Agar saare digits 0 the, toh output 0 hoga
        if (concatStr.empty()) {
            return 0;
        }

        // String ko wapas number mein convert karein
        long long concatenatedNumber = std::stoll(concatStr);

        // Final multiplication aur result return karna
        return concatenatedNumber * sumOfDigits;
    }
};