#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        
        // Step 1: Saare pichle intervals jo newInterval se pehle khatam hote hain
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        
        // Step 2: Saare overlapping intervals ko newInterval ke sath merge karein
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Final merged newInterval ko result me dalein
        result.push_back(newInterval);
        
        // Step 3: Baaki bache hue saare aage ke intervals ko dalein
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};