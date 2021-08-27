class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf=0,minm=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minm=min(minm,prices[i]);
            maxProf=max(maxProf,prices[i]-minm);
        }
        return maxProf; 
        
    }
};