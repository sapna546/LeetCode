class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> result(k, 0);

        // dp[r] = number of subarrays ending at previous
        // position having product % k == r
        vector<long long> dp(k, 0);

        for (int x : nums) {

            vector<long long> newdp(k, 0);

            // Start a new subarray [x]
            int single = x % k;
            newdp[single]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {

                if (dp[r] == 0)
                    continue;

                int newRemainder = (int)(((long long)r * x) % k);

                newdp[newRemainder] += dp[r];
            }

            // Add all subarrays ending at current position
            for (int r = 0; r < k; r++) {
                result[r] += newdp[r];
            }

            dp = newdp;
        }

        return result;
    }
};