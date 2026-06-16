class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                ans.push_back(path);
            }
        }

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

        path.pop_back(); // Backtracking
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};