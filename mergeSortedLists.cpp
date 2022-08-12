#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode list1e3(4);
// ListNode list1e2(2, &list1e3);
// ListNode list1e1(1, &list1e2);
// ListNode *tempptr1=&list1e1;

// ListNode list2e3(4);
// ListNode list2e2(3, &list2e3);
// ListNode list2e1(1, &list2e2);
// ListNode *tempptr2=&list2e1;

class Solution {
public:
    
    void createnode(int i, ListNode* &current3, ListNode* &answer)
    {
        if(i==0)
        {
            current3=new ListNode();
            answer=current3;
        }else{
            (current3->next)=new ListNode();
            current3=current3->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *current1=list1, *current2=list2;//, *current3=&list3;
        ListNode *answer=nullptr;// = new ListNode();
        ListNode *current3;//=answer;
        
        for(int i=0; (current1!=nullptr || current2!=nullptr); i++)
        {         
            if(current1==nullptr)
            {
                createnode(i, current3, answer);
                current3->val=current2->val;//add list1 value to the newly created node
                current2=current2->next;//current1 now points to the next value in list1
                
            }else if(current2==nullptr)
            {
                createnode(i, current3, answer);
                current3->val=current1->val;//add list1 value to the newly created node
                current1=current1->next;//current1 now points to the next value in list1
                
            }else if(current1->val<current2->val)
            {
                createnode(i, current3, answer);
                current3->val=current1->val;//add list1 value to the newly created node
                current1=current1->next;//current1 now points to the next value in list1
                
            }else if(current2->val<current1->val)
            {
                createnode(i, current3, answer);
                current3->val=current2->val;//add list1 value to the newly created node
                current2=current2->next;//current1 now points to the next value in list1

            }else if(current1->val==current2->val)
            {
                createnode(i, current3, answer);
                current3->val=current1->val;//add list1 value to the newly created node
                current1=current1->next;//current1 now points to the next value in list1
                
                (current3->next)=new ListNode();
                current3=current3->next;
                current3->val=current2->val;//add list1 value to the newly created node
                current2=current2->next;//current1 now points to the next value in list1
            }     
    }
        return answer;
    }
};
