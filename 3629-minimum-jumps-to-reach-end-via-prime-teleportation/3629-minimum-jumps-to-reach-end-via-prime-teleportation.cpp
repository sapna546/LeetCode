class Solution {
public:

    bool isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        // prime -> indices where nums[index] is divisible by prime
        unordered_map<int, vector<int>> mp;

        // Build prime factor lists
        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    mp[p].push_back(i);

                    while (x % p == 0)
                        x /= p;
                }
            }

            // Remaining x is a prime factor
            if (x > 1) {
                mp[x].push_back(i);
            }
        }

        queue<int> q;

        vector<int> dist(n, -1);

        vector<bool> usedPrime(1000001, false);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            // Reached destination
            if (i == n - 1)
                return dist[i];

            // --------------------
            // 1. Adjacent i - 1
            // --------------------

            if (i - 1 >= 0 && dist[i - 1] == -1) {

                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // --------------------
            // 2. Adjacent i + 1
            // --------------------

            if (i + 1 < n && dist[i + 1] == -1) {

                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // --------------------
            // 3. Prime teleport
            // --------------------

            int p = nums[i];

            if (isPrime(p) && !usedPrime[p]) {

                usedPrime[p] = true;

                for (int j : mp[p]) {

                    if (dist[j] == -1) {

                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
            }
        }

        return -1;
    }
};