class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Strategy is to take 2 passes, one pass to identify which cells are connected to Pacific Ocean
        // Second pass to to identify which cells are connected to Atlantic Ocean, then we will traverse
        // through the whole array and add cells that are connected to both oceans to the result

        //Vector that will mark all cells connected to Pacific ocean to be true
        vector<vector<bool>> isPacConnected(heights.size(),vector<bool>(heights[0].size(),false));
        //Vector that will mark all cells connected to Atlantic ocean to be true
        vector<vector<bool>> isAtlConnected(isPacConnected);
        // Two sets of queues to DFS each ocean
        queue<pair<int,int>> aq;
        queue<pair<int,int>> pq;
        // Result vector
        vector<vector<int>> results;
        if(heights.size() == 0) return results;

        int m = heights.size();
        int n = heights[0].size();

        for(int j=0;j<n;j++) {
            // Mark all top cells be connected to Pacific Ocean
            pq.push({0,j});
            isPacConnected[0][j] = true;
            // Mark all bottom cells be connected to Atlantic Ocean
            aq.push({m-1,j});
            isAtlConnected[m-1][j] = true;
        }
        for(int i=0;i<m;i++) {
            // Mark all cells from left column be connected to Pacific Ocean
            pq.push({i,0});
            isPacConnected[i][0] = true;
            // Mark all cells from right column be connected to Atlantic Ocean
            aq.push({i,n-1});
            isAtlConnected[i][n-1] = true;
        }

        // Do DFS on cells connected to Paciific Ocean
        dfs(heights, isPacConnected, pq);
        // Do DFS on cells connected to Atlantic Ocean
        dfs(heights, isAtlConnected, aq);

        // Add cells connected to both oceans to the result
        for(int i=0;i<heights.size();i++) {
            for(int j=0;j<heights[i].size();j++) {
                if((isPacConnected[i][j] == true) && (isAtlConnected[i][j] == true)) {
                    results.push_back({i,j});
                }
            }
        }
        return results;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, queue<pair<int,int>>& q) {
        vector<pair<int,int>> offsets = {{0,-1},{-1,0},{0,1},{1,0}};
        int m = heights.size();
        int n = heights[0].size();
        // For DFS, we will explore all adjacent cells in 4 direction, north, east, south and west
        // assumption is all cells in the queue are already connected to the specified ocean
        // so if an adjacent cell meets the criteria that its heigh is greater than or equal to
        // the current cell height, then the adjacent cell is also connected to the specified ocean
        // So we mark it as true and add it to the queue for exploring its neighboring cells later

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            for(auto [io,jo]:offsets) {
                int ni = i + io;
                int nj = j + jo;
                if((ni >= 0) && (ni <m) && (nj >= 0) && (nj <n)) {
                    if((heights[ni][nj] >= heights[i][j]) && (ocean[ni][nj] == false)) {
                        ocean[ni][nj] = true;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }

};