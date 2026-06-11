class Solution {
public:
    double myPow(double x, int n) {
        // 1. Integer overflow se bachne ke liye long long use karein
        long long nn = n;
        
        // 2. Agar power negative hai toh usko handle karein
        if (nn < 0) {
            x = 1 / x;
            nn = -nn;
        }
        
        double ans = 1.0;
        
        // 3. Binary Exponentiation Loop
        while (nn > 0) {
            if (nn % 2 == 1) { // Agar power odd hai
                ans = ans * x;
                nn = nn - 1;
            } else { // Agar power even hai
                x = x * x;
                nn = nn / 2;
            }
        }
        
        return ans;
    }
};