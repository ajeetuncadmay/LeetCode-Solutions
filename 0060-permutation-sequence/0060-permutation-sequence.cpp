#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        // 1. (n-1)! factorial calculate karein aur numbers ki list [1, 2, ..., n] banayein
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n); // numbers array ab [1, 2, 3, ..., n] hai
        
        string ans = "";
        k = k - 1; // 0-based indexing ke liye k ko 1 kam kiya
        
        // 2. Ek-ek karke saare positions ke liye sahi digit dhoondein
        while (true) {
            // Sahi digit ka index nikallein
            int index = k / fact;
            ans += to_string(numbers[index]);
            
            // Jo digit use ho gaya use list se hata dein
            numbers.erase(numbers.begin() + index);
            
            // Agar saare numbers khatam ho gaye toh loop tod dein
            if (numbers.empty()) {
                break;
            }
            
            // Agle round ke liye k aur factorial ko update karein
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    }
};