/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        
         int n = A.size();
    map<int,int> mp;

    for(int i = 0; i< A.size(); i++)
    {
        mp[A[i]]++;
    }

    for(auto x: mp)
    {
        if(x.second>1)
        {
            return x.first;
        }
    }
    return -1;
    }
};
