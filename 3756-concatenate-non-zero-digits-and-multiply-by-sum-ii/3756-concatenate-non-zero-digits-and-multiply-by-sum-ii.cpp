#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long MOD = 1e9 + 7;
        int n = s.length();
        
        // 1. Prefix arrays initialization
        vector<long long> pow10(n + 1, 1);       // 10 ki powers store karne ke liye
        vector<long long> nonZeroCount(n + 1, 0); // Non-zero digits ka count (Prefix)
        vector<long long> prefixX(n + 1, 0);      // Concatenated value ka prefix modulo MOD
        vector<long long> prefixSum(n + 1, 0);   // Digits ke sum ka prefix
        
        // Precompute powers of 10 modulo MOD
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // 2. Linear Scan se Prefix Arrays populate karna (Preprocessing)
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            
            nonZeroCount[i + 1] = nonZeroCount[i] + (d != 0 ? 1 : 0);
            prefixSum[i + 1] = prefixSum[i] + d;
            
            if (d != 0) {
                prefixX[i + 1] = (prefixX[i] * 10 + d) % MOD;
            } else {
                prefixX[i + 1] = prefixX[i];
            }
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        // 3. O(1) time me har query ka answer process karna
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Substring me non-zero digits ka total sum
            long long sum_val = prefixSum[r + 1] - prefixSum[l];
            
            // Substring [l..r] me total kitne non-zero digits hain
            long long nz_in_window = nonZeroCount[r + 1] - nonZeroCount[l];
            
            // Math Formula to extract substring value out of global prefix:
            // x_val = (prefixX[r+1] - prefixX[l] * 10^(nz_in_window)) % MOD
            long long x_val = (prefixX[r + 1] - (prefixX[l] * pow10[nz_in_window]) % MOD + MOD) % MOD;
            
            // Final Multiplication modulo MOD
            long long current_ans = (x_val * sum_val) % MOD;
            answer.push_back(current_ans);
        }
        
        return answer;
    }
};