class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& temp, vector<vector<int>>& ans) {
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size() || target < 0)
            return;

        // Include current element
        temp.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index, temp, ans);
        temp.pop_back();

        // Exclude current element
        solve(candidates, target, index + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};