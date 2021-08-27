class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
           if(mp.find(target-nums[i])!=mp.end()){
               a.push_back(mp[target-nums[i]]);
               a.push_back(i);
               return a;
           }
            mp[nums[i]]=i;
        }
        return a;
    }
};