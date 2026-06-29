class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        
        // Keep dividing n by powers of 5 and sum up the quotients
        while (n >= 5) {
            count += n / 5;
            n /= 5; // Efficiently moves to n/25, n/125, etc., in subsequent loops
        }
        
        return count;
    }
};