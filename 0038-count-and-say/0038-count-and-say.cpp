#include <iostream>
#include <string>

class Solution {
public:
    string countAndSay(int n) {
        // Base case: n = 1 ke liye output hamesha "1" hota hai
        if (n == 1) return "1";
        
        // n = 1 se shuru karte hain
        string res = "1";
        
        // loop 2 se lekar n tak chalega
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            
            // Pichli string (res) ko scan karte hain
            for (int j = 0; j < res.length(); j++) {
                // Agar agla character same hai, to count badhao
                if (j + 1 < res.length() && res[j] == res[j + 1]) {
                    count++;
                } 
                // Agar alag hai, to count aur wo number temp string mein add karo
                else {
                    temp += to_string(count) + res[j];
                    count = 1; // count ko wapas reset kar do
                }
            }
            res = temp; // Nayi string ko main result bana do
        }
        
        return res;
    }
};