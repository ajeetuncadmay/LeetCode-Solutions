#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;

    // Power function: (base^exp) % MOD nikalne ke liye
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1); // 1-based indexing ke liye n+1 size
        
        // 1. Adjacency list (Graph) banayein
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // 2. BFS ke jariye Node 1 se max depth (edges ki count) dhoondein
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        q.push(1); // Node 1 root hai
        dist[1] = 0; // Root ki depth 0 hai
        
        int max_edges = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            max_edges = max(max_edges, dist[curr]);
            
            for (int neighbor : adj[curr]) {
                if (dist[neighbor] == -1) { // Agar visit nahi hua hai
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // 3. Agar max depth par 0 edges hain (sirf 1 node hai) toh 0 ways
        if (max_edges == 0) return 0;
        
        // Math Trick: Answer hamesha 2^(max_edges - 1) % MOD hota hai
        return power(2, max_edges - 1);
    }
};