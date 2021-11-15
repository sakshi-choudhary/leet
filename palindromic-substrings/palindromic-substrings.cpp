class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        vector<vector<bool>>v(n,vector<bool>(n));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0) v[i][j]=true;
                else if(g==1) v[i][j]=s[i]==s[j];
                else v[i][j]=(s[i]==s[j]&&v[i+1][j-1]);
                v[i][j]?count++:count+0;
            }
        }
        return count; 
    }
};