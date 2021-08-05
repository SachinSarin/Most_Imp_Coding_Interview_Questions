/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

If n is greater than the size of the list, remove the first node of the list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int k) {
    int count = 0;
    ListNode* current = head;
 if((head==NULL || head->next==NULL) &&k ==1 )
    {
        return NULL;
    }
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
     int newsize = count-k;
    if(newsize<=0)
    {
        return head->next;
    }

   
    ListNode* ptr = head;
    while(newsize!=1&&newsize>0)
    {
            ptr = ptr->next;
            newsize--;
    }
    ListNode* ptr2 = ptr->next;
    ptr->next = ptr2->next;
    ptr2->next=NULL;
    return head;   
}
