class Solution {
public:

    class Fenwick {
    public:
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int i, int val) {
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        int query(int i) {
            int sum = 0;
            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }
            return sum;
        }
    };


    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        Fenwick fw(2 * n + 5);

        long long ans = 0;

        int prefix = n + 1;

        // initial prefix sum 0
        fw.update(prefix, 1);


        for (int x : nums) {

            if (x == target)
                prefix++;
            else
                prefix--;


            // count previous prefix sums smaller than current
            ans += fw.query(prefix - 1);


            fw.update(prefix, 1);
        }


        return ans;
    }
};