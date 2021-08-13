class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPri=INT_MAX,maxPro=0;
        for(int i=0;i<prices.size();i++){
          minPri=min(minPri,prices[i]);
          maxPro=max(maxPro,prices[i]-minPri);
        }
        return maxPro;
    }
};