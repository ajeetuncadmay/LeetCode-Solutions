#include <unordered_set>

using namespace std;

class Solution {
private:
    int count = 0;
    unordered_set<int> cols;
    unordered_set<int> posDiag; // (r + c)
    unordered_set<int> negDiag; // (r - c)

    void backtrack(int r, int n) {
        // Base Case: Agar saari rows (0 se n-1) me queens baith gayi hain
        if (r == n) {
            count++;
            return;
        }

        // Har column me check karein
        for (int c = 0; c < n; c++) {
            // Agar yeh position unsafe hai, toh skip karein
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            // 1. Queen ko place karein (Sets me entries daalein)
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            // 2. Agli row par jayein
            backtrack(r + 1, n);

            // 3. Backtrack (Sets se entries hatayein)
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }

public:
    int totalNQueens(int n) {
        count = 0; // Har test case ke liye reset karein
        cols.clear();
        posDiag.clear();
        negDiag.clear();
        
        backtrack(0, n);
        return count;
    }
};