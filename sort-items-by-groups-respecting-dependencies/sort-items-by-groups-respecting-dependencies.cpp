class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_set<int> freeGroups;
        
        for (int i = 0; i < m; ++i) {
            freeGroups.insert(i);
        }
        
        for (int i = 0; i < n; ++i) {
            if (group[i] != -1) {  
                freeGroups.erase(group[i]);
            }
        }
        
        // 1. Build clusters using groups
        vector<vector<int>> cluster(m);
        
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                // Create dummy cluster for each unassigned node
                if (freeGroups.empty()) {
                    cluster.push_back(vector<int>());
                    cluster.back().push_back(i);
                    group[i] = cluster.size() - 1;
                    ++m;
                } else {
                    int g = *freeGroups.begin();
                    freeGroups.erase(g);
                    cluster[g].push_back(i);
                    group[i] = g;
                }
            } else {
                // Add to cluster group[i]
                freeGroups.erase(group[i]);
                cluster[group[i]].push_back(i);
            }
        }
        
        // 2. Order clusters using topological sort
        
        // Build cluster graph, find fanin count and schedule 0 fanin groups
        vector<vector<int>> clusterGraph(m);
        vector<int> clusterFanin(m, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int before: beforeItems[i]) {
                if (group[before] == group[i]) {
                    continue;
                }
                
                clusterGraph[group[before]].push_back(group[i]);
                ++clusterFanin[group[i]];
            }
        }
        
        // Topological sort cluster graph
        vector<int> clusterLevel = topologicalSort(clusterGraph, clusterFanin);
        
        if (clusterLevel.empty()) {
            return { };
        }
        
        // 3. Sort cluster ids based on level
        vector<int> clusterIndices(m, 0);
        iota(clusterIndices.begin(), clusterIndices.end(), 0);
        
        sort(clusterIndices.begin(), clusterIndices.end(), [&clusterLevel] (int i1, int i2) {
           return clusterLevel[i1] < clusterLevel[i2]; 
        });
        
        // 4. order items with-in a cluster 
        
        // Build item order graph
        vector<vector<int>> graph(n);
        vector<int> fanin(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int before: beforeItems[i]) {
                graph[before].push_back(i);
                ++fanin[i];
            }
        }
        
        // Topological sort item graph
        vector<int> level = topologicalSort(graph, fanin);
        
        if (level.empty()) {
            return { };
        }
        
        // 5. Sort items within a cluster
        for (int i = 0; i < m; ++i) {
            if (cluster[i].size() <= 1) {
                continue;
            }
            
            sort(cluster[i].begin(), cluster[i].end(), [&level] (int i1, int i2) {
               return level[i1] < level[i2]; 
            });
        }
        
        // 6. Output ordered items
        vector<int> result;
        result.reserve(n);
        
        for (int i = 0; i < m; ++i) {
            for (int j: cluster[clusterIndices[i]]) {
                result.push_back(j);
            }
        }
        
        return result;
    }
        
private:
    vector<int> topologicalSort(const vector<vector<int>>& graph, vector<int>& fanin) {
        int N = graph.size();
        queue<int> qu;
        
        for (int i = 0; i < N; ++i) {
            if (fanin[i] == 0) {
            //    cout << "schedule " << i << endl;
                qu.push(i);
            }
        }
        
        // Levelize clusters 
        vector<int> level(N, -1);
        int depth = -1;
        int marked = 0;
        
        while (!qu.empty()) {
            int count = qu.size();
                    
            ++depth;
            
            for (int i = 0; i < count; ++i) {
                int from = qu.front();
                qu.pop();
                level[from] = depth;
                ++marked;

                for (int to: graph[from]) {
                    --fanin[to];
                    
                    if (fanin[to] == 0) {
                        qu.push(to);
                    }
                }
            }
        }
        
        // Detect cycle
        if (marked != N) {
            return { };
        }
        
        return level;
    }
};