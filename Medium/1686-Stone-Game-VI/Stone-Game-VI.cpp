class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<pair<int,int>> stones(n);
        int aliceScore = 0;
        int bobScore = 0;
        for(int i=0;i<n;i++) {
            stones.push_back({aliceValues[i]+bobValues[i],i});
        }
        sort(stones.rbegin(),stones.rend());
        for(int i=0;i<n;i++) {
            int index = stones[i].second;
            if(i%2==0) {
                aliceScore += aliceValues[index];
            }else {
                bobScore += bobValues[index];
            }
        }
        if(aliceScore > bobScore) return 1;
        else if(bobScore > aliceScore) return -1;
        else return 0;        
    }
};
