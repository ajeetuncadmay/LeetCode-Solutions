#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        
        // Start from the second-to-last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                // Add the minimum of the two adjacent numbers from the row below
                triangle[row][col] += std::min(triangle[row + 1][col], triangle[row + 1][col + 1]);
            }
        }
        
        // The top element now contains the minimum path sum
        return triangle[0][0];
    }
};