#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        
        // 1. Duplicates handle karne ke liye aur next_permutation ke liye sorting zaroori hai
        sort(nums.begin(), nums.end());
        
        // 2. next_permutation automatically unique arrangements hi banata hai
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return result;
    }
};