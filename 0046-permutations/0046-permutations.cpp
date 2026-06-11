#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        // 1. Pehle array ko sort karein
        sort(nums.begin(), nums.end());
        
        // 2. Saare permutations vector me store karein
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return result;
    }
};