class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        //Overall algorithm is to have dp vector of vector of set. Think of it as 3-dim array except the 3rd dim is a set
        //Row is node num, col is the edge num and the set elements are weights of edges leading to this node
        vector<vector<set<int>>> dp(n, vector<set<int>>(k + 1));
        
        //Initial values for each node with no edge (edge = 0) has only one total weight 0 leading to it 
        for (int i = 0; i < n; i++) {
            dp[i][0].insert(0);
        }

        //Loop through the required num of edges
        for (int j = 1; j <= k; j++) {
            //Loop through the number of edges
            for (const auto& edge : edges) {
                //For each edge, we have source (u), destination (v), and weight (w)
                int u = edge[0], v = edge[1], w = edge[2];
                //Loop through all total weights that lead to this node from previous edge number
                for (int s : dp[u][j - 1]) {
                    //For each weight, we will add the current weight to lead us to destination node
                    int new_sum = s + w;
                    //Check if it is leass than t
                    if (new_sum < t) {
                        //Update (add) dp for the destiantion node with current total weight
                        dp[v][j].insert(new_sum);
                    }
                }
            }
        }
        
        int ans = -1;
        //Now we will loop through all nodes
        for (int i = 0; i < n; i++) {
            //If set corresponding to this node and edge k is empty, it means this node has no k edge lead to it
            if (!dp[i][k].empty()) {
                //Else, since the result is set and set by default is sorted ascendingly, max weight will be last element
                int max_in_set = *dp[i][k].rbegin();
                //Check if this is the max we have seen so far
                ans = max(ans, max_in_set);
            }
        }
        return ans;
    }    
};