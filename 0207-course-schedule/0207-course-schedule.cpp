class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Step 1: Create adjacency list
        vector<vector<int>> adj(numCourses);

        // Step 2: Store indegree of every node
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Step 3: Push all nodes having indegree 0
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 4: BFS
        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int neighbor : adj[node]) {

                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 5: Check if all courses are completed
        return count == numCourses;
    }
};