/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/

int Solution::maxProduct(const vector<int> &nums) {

    int n = nums.size();
    int max_so_far = nums[0];
    int min_so_far = nums[0];
    int max_product = nums[0];

    for(int i = 1; i < n; i++)
    {
        if(nums[i]<0)
        {
            swap(max_so_far,min_so_far);
        }
        max_so_far = max(nums[i],nums[i]*max_so_far);
        min_so_far = min(nums[i],nums[i]*min_so_far);

        max_product = max(max_product,max_so_far);

       

    }
     return max_product;
}
