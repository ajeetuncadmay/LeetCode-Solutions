class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int m = lg[n] + 1;
        stMax.assign(m, vector<int>(n));
        stMin.assign(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int j = 1; j < m; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(stMax[j - 1][i],
                                  stMax[j - 1][i + (1 << (j - 1))]);

                stMin[j][i] = min(stMin[j - 1][i],
                                  stMin[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto getValue = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int j = lg[len];

            int mx = max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
            int mn = min(stMin[j][l], stMin[j][r - (1 << j) + 1]);

            return 1LL * mx - mn;
        };

        priority_queue<array<long long, 3>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({getValue(l, r - 1), l, r - 1});
            }
        }

        return ans;
    }
};