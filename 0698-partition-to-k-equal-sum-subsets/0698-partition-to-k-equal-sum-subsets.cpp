class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& bucket, int k, int target, int index) {
        
        if (index == nums.size()) {
            // Check if all buckets have target sum
            for (int i = 0; i < k; i++) {
                if (bucket[i] != target)
                    return false;
            }
            return true;
        }

        for (int i = 0; i < k; i++) {

            // Don't put in same bucket again
            if (i > 0 && bucket[i] == bucket[i - 1])
                continue;

            // Current number cannot exceed target
            if (bucket[i] + nums[index] > target)
                continue;

            bucket[i] += nums[index];

            if (solve(nums, bucket, k, target, index + 1))
                return true;

            bucket[i] -= nums[index];

            // If this bucket was empty, no need to try other empty buckets
            if (bucket[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int total = accumulate(nums.begin(), nums.end(), 0);

        // Total sum must be divisible by k
        if (total % k != 0)
            return false;

        int target = total / k;

        // If largest element > target, impossible
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> bucket(k, 0);

        return solve(nums, bucket, k, target, 0);
    }
};