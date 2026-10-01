class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        if (start < 0 || start >= n || arr[start] == -1)
            return false;

        if (arr[start] == 0)
            return true;

        int jump = arr[start];

        // Mark visited
        arr[start] = -1;

        return canReach(arr, start + jump) ||
               canReach(arr, start - jump);
    }
};