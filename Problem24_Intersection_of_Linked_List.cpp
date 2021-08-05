/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Problem approach completely explained :

Complete code in the hints section.
*/
ListNode* Solution::getIntersectionNode(ListNode* head1, ListNode* head2) {
        if(head1!=NULL&&head2==NULL)
    {
        return NULL;
    }
    if(head1==NULL&&head2!=NULL)
    {
        return NULL;
    }
    if(head1==NULL&&head2==NULL)
    {
        return NULL;
    }

    int counta = 0;
    int countb= 0;
    ListNode* current1 = head1;
    ListNode* current2 = head2;
    while(current1!=NULL)
    {   counta++;
        current1 =current1->next;
    }
    while(current2!=NULL)
    {
        countb++;
        current2 = current2->next;
    }
    int d = abs(counta-countb);
    ListNode* newcurrent1 = head1;
    ListNode* newcurrent2 = head2;
    while(d!=0)
    {   
        if(counta > countb)
        {
            newcurrent1 = newcurrent1->next;
            d--;
        }
        else if(counta < countb)
        {
            d--;
            newcurrent2 = newcurrent2->next;
        }
        else{
            break;
        }
    }
    while(newcurrent1!=newcurrent2)
    {   
        newcurrent1 = newcurrent1->next;
        newcurrent2 =  newcurrent2->next;
    }
    return newcurrent1;
        
    
}
