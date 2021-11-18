class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int i=0,j=1;
        // for(int i=0;i<(int)nums.size();i++){
        //     if(nums[i]==0&&nums[j]!=0) swap(nums[i],nums[j]);
        //     if(nums[i]==0&&nums[j]==0) j++;
        // }
        int cz=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cz++;
            else ans.push_back(nums[i]);
        }
        while(cz!=0){
            ans.push_back(0);
            cz--;
        }
        for(int p=0;p<nums.size();p++){
            nums[p]=ans[p];
        }
    }
};