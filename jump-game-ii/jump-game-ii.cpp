class Solution {
public:
    int jump(vector<int>& a) {
        int jump = 0, maxReach = 0, currReach = 0, n = a.size();
        for(int i=0;i<n-1;i++)
        {
            maxReach = max(maxReach, i+a[i]);
            if(i==currReach)
            {
                jump++;
                currReach = maxReach;
            }
        }
        return jump;
    }
};