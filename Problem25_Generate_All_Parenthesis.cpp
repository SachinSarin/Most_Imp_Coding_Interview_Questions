/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

PROBLEM APPROACH :

Complete solution in hints.
*/
int Solution::isValid(string s) {
    
         stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]=='}')
            {
                if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]==']')
            {
                if(st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else
                st.push(s[i]);
        }
        if(st.empty())
            return true;
        else
            return false;
    
}
