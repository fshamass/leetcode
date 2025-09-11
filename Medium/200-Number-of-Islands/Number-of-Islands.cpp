class Solution {
public:
    // This problem is a simple straight forward DFS algorithm. THe idea is to traverse through the 
    // graph and whenever we encounter a '1' we increment the count of islands by one and at the 
    // same time we do DFS on all adjacent cells (left, right, up, and down) and set them to '0'
    // if their value is 1.
    // It is very important that we pass the graph to DFS algorithm by reference so that when we
    // clear adjacent cell, this change will stick and will not be observed as '1' by the main
    // algorithm later on since it was an adjacent cell to previous cell

    void DFS(vector<vector<char>>& graph, int row, int col) {
        // Exit immediately if cell is out of range or it is already set to '0'
        if((row < 0) || row >= graph.size() || (col < 0) || (col >= graph[0].size()) || (graph[row][col] == '0')) 
            return;
        // Reset value to '0
        graph[row][col] = '0';
        // Iterate the process on all 4 directions
        DFS(graph,row+1,col);
        DFS(graph,row-1,col);
        DFS(graph,row,col+1);
        DFS(graph,row,col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j] == '1') {
                    num++;
                    DFS(grid,i,j);
                }
            }
        }
        return num;
    }
};