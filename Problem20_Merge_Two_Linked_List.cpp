/*
Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
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
ListNode* Solution::mergeTwoLists(ListNode* head1, ListNode* head2) {


    ListNode *final = new ListNode(0);
    ListNode * ptr = final;
    ListNode *l1 = head1;
    ListNode *l2 = head2;
    //find the starting of the linked list
    if(head1->val < head2->val)
    {
        ptr->next = new ListNode(head1->val);
        ptr = ptr->next;
        l1 = l1->next;
    }
    else
    {
        ptr->next = new ListNode(head2->val);
        ptr= ptr->next;
        l2 = l2->next;
    }


    //main logic to mergeTwoLists
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1->val < l2->val)
        {
            ptr->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        else{
            ptr->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        ptr = ptr->next;
    }

    //merge remaining linked list
    if(l1!=NULL)
    {
        ptr->next = l1;
    }
    else{
        ptr->next = l2;
    }
    return final->next;
}
