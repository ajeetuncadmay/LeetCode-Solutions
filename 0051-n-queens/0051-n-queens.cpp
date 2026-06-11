#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    unordered_set<int> cols;          // Columns track karne ke liye
    unordered_set<int> posDiag;       // Positive diagonals (r + c) track karne ke liye
    unordered_set<int> negDiag;       // Negative diagonals (r - c) track karne ke liye
    vector<vector<string>> result;

    void backtrack(int r, int n, vector<string>& board) {
        // Base Case: Agar saari rows me queens baith gayi hain
        if (r == n) {
            result.push_back(board);
            return;
        }

        // Har column me rani bithane ki koshish karein
        for (int c = 0; c < n; c++) {
            // Agar column ya koi bhi diagonal pehle se occupied hai, toh skip karein
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            // 1. Queen ko place karein (Action)
            board[r][c] = 'Q';
            cols.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            // 2. Agli row par jayein (Recurse)
            backtrack(r + 1, n, board);

            // 3. Queen ko hatayein taaki dusra option check sakein (Backtrack)
            board[r][c] = '.';
            cols.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        // Khali board taiyar karein dots ('.') ke sath
        vector<string> board(n, string(n, '.'));
        
        // Row 0 se shuru karein
        backtrack(0, n, board);
        
        return result;
    }
};