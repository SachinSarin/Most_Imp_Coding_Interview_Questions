/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.




Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
*/
string Solution::simplifyPath(string str) {

    vector<string> v;
    string ans = "";
    for(int i = 0; i < str.size(); i++)
    {
        string path = "";
        while(i < str.length() && str[i]!='/')
        {
            path += str[i++];
        }
        if(path=="" || path==".") continue;
        else if (path=="..")
        {
            if(v.size()>0)
            {
                v.pop_back();
            }
        }
        else v.push_back(path);
    }
    if(v.size()==0) return "/";
    for(int i = 0; i < v.size(); i++)
    {
        ans += "/" + v[i];
    }
    return ans;

}
