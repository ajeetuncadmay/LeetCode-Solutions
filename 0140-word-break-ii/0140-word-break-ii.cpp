class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> memo;

    vector<string> solve(string s) {
        if (memo.count(s))
            return memo[s];

        vector<string> res;

        if (s.empty()) {
            res.push_back("");
            return res;
        }

        for (int i = 1; i <= s.size(); i++) {
            string prefix = s.substr(0, i);

            if (dict.count(prefix)) {
                vector<string> suffixWays = solve(s.substr(i));

                for (string &way : suffixWays) {
                    if (way.empty())
                        res.push_back(prefix);
                    else
                        res.push_back(prefix + " " + way);
                }
            }
        }

        return memo[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return solve(s);
    }
};