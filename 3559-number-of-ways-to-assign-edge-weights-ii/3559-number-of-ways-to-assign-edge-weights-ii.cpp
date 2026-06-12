class Solution {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int LOG = 17;

    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;
    vector<vector<int>> g;

    void dfs(int u, int p) {
        up[u][0] = p;

        for (int i = 1; i < LOG; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (int v : g[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];

        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i))
                a = up[a][i];
        }

        if (a == b) return a;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        g.assign(n + 1, {});
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        dfs(1, 1);

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[w];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back((int)pow2[dist - 1]);
        }

        return ans;
    }
};