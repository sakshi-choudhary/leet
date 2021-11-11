class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,nz=0,nt=nums.size()-1;
        while(i<=nt){
            if(nums[i]==0){
                swap(nums[i],nums[nz]);
                i++;
                nz++;
            }else if(nums[i]==2){
                swap(nums[i],nums[nt]);
                nt--;
            }else{
                i++;
            }
        }
    }
};