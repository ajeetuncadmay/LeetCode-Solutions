class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        
        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        vector<int> freq(26, 0);
        for (char c : s1) freq[c - 'a']++;
        for (char c : s2) freq[c - 'a']--;

        for (int x : freq) {
            if (x != 0)
                return memo[key] = false;
        }

        int n = s1.size();

        for (int i = 1; i < n; i++) {
            // Without swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // With swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};