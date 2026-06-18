#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        // Initialize the vector with size (rowIndex + 1) filled with 1s
        std::vector<int> row(rowIndex + 1, 1);
        
        // Loop through each row up to rowIndex
        for (int i = 1; i <= rowIndex; ++i) {
            // Update the row values backward
            // This prevents overwriting data from the previous iteration that we still need
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        
        // Returns only the requested row
        return row;
    }
};