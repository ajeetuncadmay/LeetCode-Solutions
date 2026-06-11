#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: Key -> Sorted String, Value -> List of original anagram strings
        unordered_map<string, vector<string>> anagramMap;
        
        // 1. Har string ko process karein
        for (string s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // E.g., "eat" becomes "aet"
            
            // 2. Sorted string ko key banakar original string ko map me daalein
            anagramMap[sorted_s].push_back(s);
        }
        
        // 3. Map se saare grouped vectors ko nikal kar result me daalein
        vector<vector<string>> result;
        for (auto pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};