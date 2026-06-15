class Solution {
public:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> res;

        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = solve(start, i - 1);
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};