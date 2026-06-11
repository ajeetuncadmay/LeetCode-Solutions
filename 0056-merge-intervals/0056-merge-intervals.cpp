#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Edge case: Agar koi interval na ho ya sirf ek ho
        if (intervals.size() <= 1) {
            return intervals;
        }

        // 1. Intervals ko unke 'start' time ke basis par sort karein
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedIntervals;
        
        // Pehle interval ko result me dalein shuruat ke liye
        mergedIntervals.push_back(intervals[0]);

        // 2. Baaki ke intervals ko check karein
        for (int i = 1; i < intervals.size(); i++) {
            // mergedIntervals ka aakhiri interval uthayein
            vector<int>& lastInterval = mergedIntervals.back();
            
            // Agar current interval ka 'start', pichle ke 'end' se chota ya barabar hai
            if (intervals[i][0] <= lastInterval[1]) {
                // Overlap hai! Pichle interval ka 'end' update karein
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                // Overlap nahi hai, toh ise naye interval ki tarah add karein
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }
};