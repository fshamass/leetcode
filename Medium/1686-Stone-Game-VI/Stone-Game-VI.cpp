class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> stones(n);
        int aliceScore = 0;
        int bobScore = 0;
        for(int i=0;i<n;i++) {
            // Store at each index the total value for both players
            stones.push_back({aliceValues[i]+bobValues[i],i});
        }
        // Sort the vector by total value decendingly.
        // The idea is every player will pick max value available to them when its their turn to play
        sort(stones.rbegin(),stones.rend());
        for(int i=0;i<n;i++) {
            //For every turn, find the value index corresponding to it
            int index = stones[i].second;
            // Since Alice starts first, all even turns belong to Alice so update her value
            if(i%2==0) {
                aliceScore += aliceValues[index];
            }else {
                bobScore += bobValues[index];
            }
        }
        //Find out who has the higher score and return values accordingly
        if(aliceScore > bobScore) return 1;
        else if(bobScore > aliceScore) return -1;
        else return 0;        
    }
};
