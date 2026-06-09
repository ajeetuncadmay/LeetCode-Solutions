class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        for(int num : nums1){
            merged.push_back(num);
        }
        for(int num : nums2){
            merged.push_back(num);
        }

        sort(merged.begin(),merged.end());
        int n = merged.size();
        if (n % 2 != 0){
            return merged[n/2];
        } else {
            return(merged[n/2]+ merged[(n/2)-1])/2.0;
        }
        
    }
};