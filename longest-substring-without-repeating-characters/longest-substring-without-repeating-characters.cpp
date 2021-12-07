class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 1 ;
    
    int i = 0 ;
    int j = 0 ;
    int n = s.length() ;
    
    if(n==0) return 0;
    
    while( i < n && j < n && j+1 < n )
    {
        char ch = s[j+1] ;
        int start = i ;
        int end = j ;
        
        for ( ; start <= end ; start++ )
        {
            if( s[start] == ch )
            {
                i = start + 1 ;
                break ;
            }
        }
        
        j++ ;
        m = max(m,j-i+1) ;            
    }
    
    return m ;
    }
};