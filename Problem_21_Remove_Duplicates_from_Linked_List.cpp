/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.

Note:You only need to implement the given function. Do not read input, instead use the arguments to the function. Do not print the output, instead return values as specified. Still have a doubt? Checkout Sample Codes for more details.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {

    ListNode* final = new ListNode(0);
    ListNode* ptr = final;
    set<int> s;
    ListNode* current = head;
    while(current!=NULL)
    {
        s.insert(current->val);
        current =  current->next;
    }
    for(auto x: s)
    {
        ptr->next = new ListNode(x);
        ptr=ptr->next;
    }
    return final->next;
}
