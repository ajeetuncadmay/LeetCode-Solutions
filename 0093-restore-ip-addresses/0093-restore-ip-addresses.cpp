class Solution {
public:
    vector<string> result;

    void backtrack(string &s, int index, int parts, string current) {
        if (parts == 4 && index == s.size()) {
            current.pop_back(); // remove last '.'
            result.push_back(current);
            return;
        }

        if (parts == 4 || index == s.size()) {
            return;
        }

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);

            if ((segment.size() > 1 && segment[0] == '0') ||
                stoi(segment) > 255) {
                continue;
            }

            backtrack(s, index + len, parts + 1,
                      current + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};