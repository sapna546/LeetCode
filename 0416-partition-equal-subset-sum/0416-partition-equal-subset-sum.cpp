class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        // If total sum is odd, equal partition is impossible
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        // dp[j] = can we make sum j?
        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int num : nums) {

            // Traverse backwards
            for (int j = target; j >= num; j--) {

                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};