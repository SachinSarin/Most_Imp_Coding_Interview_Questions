/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* swap(ListNode* next1 , ListNode* next2)
 {
     next1->next = next2->next;
     next2->next = next1;
     return next2;
 }
ListNode* Solution::swapPairs(ListNode* node) {
    ListNode* start = new ListNode(0);
    start->next = node;
    if(node == NULL)
    {
        return NULL;
    }
    ListNode * curr = start;
    while(curr->next!=NULL&&curr->next->next!=NULL)
    {
        curr->next = swap(curr->next,curr->next->next);
        curr = curr->next->next;
    }
    return start->next;
}
