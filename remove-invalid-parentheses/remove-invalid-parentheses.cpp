class Solution
{
public:
    // Function to calculate how many invalid parenthesis are there in a string
    int getmin(string s)
    {
        int n=s.length();
        stack<char>stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(stk.empty())
                {
                    stk.push(s[i]);
                }
                else
                {
                    if(stk.top()=='(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.push(s[i]);
                    }
                }
            }
        }
        return stk.size();
    }
    void helper(unordered_set<string>&h,unordered_set<string>&dict,vector<string>&v,string s,int mra)
    {
        // If minimum removals allowed is 0 that means we can't remove anymore charcter
        if(mra==0)
        {
            //If no. of invalid parenthesis is 0 and it is not included in the
            // result then add it to the result cause it is a valid string
            if(getmin(s)==0 && h.find(s)==h.end())
            {
                h.insert(s);
                v.push_back(s);
            }
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            string tmp=s.substr(0,i)+s.substr(i+1); // Removing the ith character
            if(dict.find(tmp)==dict.end()) // Check whether we have already computed this string or not
            {
                dict.insert(tmp);
                helper(h,dict,v,tmp,mra-1);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int mra=getmin(s); // mra is the minimum no. of parentheis to be removed to make the string valid
        unordered_set<string>h,dict;
        // h is for removing duplicate results and dict is for storing computed strings
        vector<string>v;
        helper(h,dict,v,s,mra);
        return v;
    }
};