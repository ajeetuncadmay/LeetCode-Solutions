#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // g vector har node ka component ID store karega
        vector<int> g(n, 0);
        int cnt = 0;

        // Kyunki nums sorted hai, hum consecutive elements ka gap check karenge
        for (int i = 1; i < n; ++i) {
            // Agar gap maxDiff se bada hai, toh ek naya connected component shuru hota hai
            if (nums[i] - nums[i - 1] > maxDiff) {
                cnt++;
            }
            g[i] = cnt;
        }

        vector<bool> ans;
        ans.reserve(queries.size()); // Performance optimize karne ke liye memory reserve karein

        // Har query ko O(1) mein answer karein
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            // Agar dono nodes ka component ID same hai, toh unke beech path hai
            ans.push_back(g[u] == g[v]);
        }

        return ans;
    }
};