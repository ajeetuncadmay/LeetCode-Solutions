class Solution {
public:
    vector<string> ans;

    void solve(string digits, int index, string current,
               vector<string>& mapping) {

        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, current + ch, mapping);
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mapping = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",
            "pqrs", "tuv",  "wxyz"
        };

        solve(digits, 0, "", mapping);

        return ans;
    }
};