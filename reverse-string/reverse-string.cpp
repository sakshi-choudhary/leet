class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=s.size();
        int j=l-1,i=0;
        while(i<j){
            int t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
    }
};