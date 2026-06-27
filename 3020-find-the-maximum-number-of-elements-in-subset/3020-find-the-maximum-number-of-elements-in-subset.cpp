class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 1;

        // Handle 1 separately
        if (mp.count(1)) {
            int c = mp[1];
            ans = max(ans, (c % 2) ? c : c - 1);
        }

        for (auto &it : mp) {
            long long x = it.first;
            if (x == 1) continue;

            int len = 0;
            long long cur = x;

            while (true) {
                if (!mp.count(cur)) break;

                if (mp[cur] == 1) {
                    len++;
                    break;
                }

                len += 2;

                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                long long nxt = cur * cur;

                if (!mp.count(nxt)) {
                    len--;
                    break;
                }

                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};