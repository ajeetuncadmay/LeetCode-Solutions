class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 1), down(m + 1);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = m - v;   // next comparison must be down
            down[v] = v - 1; // next comparison must be up
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m + 1, 0);
            vector<long long> newDown(m + 1, 0);

            long long pref = 0;
            for (int v = 1; v <= m; v++) {
                newDown[v] = pref;
                pref = (pref + up[v]) % MOD;
            }

            long long suff = 0;
            for (int v = m; v >= 1; v--) {
                newUp[v] = suff;
                suff = (suff + down[v]) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};