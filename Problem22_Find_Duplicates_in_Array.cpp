/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/
int Solution::repeatedNumber(const vector<int> &A) {

    int n = A.size();
    unordered_map<int,int> mp;
    for(int i = 0;i < n; i++)
    {
        mp[A[i]]++;
    }

    //run for each loop
    for(auto x : mp)
    {
        if(x.second>1)
        {
            return x.first;
        }
    }
    return -1;
}


