#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 1. Ek n x n ka empty matrix banayein jisme saare elements 0 hon
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        int num = 1; // Shuruat 1 se karenge
        
        // 2. Jab tak boundaries cross nahi hotin, tab tak fill karte rahein
        while (top <= bottom && left <= right) {
            
            // Left to Right (Top row)
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            top++; // Top boundary niche shift hui
            
            // Top to Bottom (Right column)
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            right--; // Right boundary left shift hui
            
            // Right to Left (Bottom row)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = num++;
                }
                bottom--; // Bottom boundary upar shift hui
            }
            
            // Bottom to Top (Left column)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++; // Left boundary right shift hui
            }
        }
        
        return matrix;
    }
};