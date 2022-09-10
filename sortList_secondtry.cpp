#include<iostream>
#include<vector>
#include<unordered_map>

 struct ListNode {
     public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  struct ListNode node4(3);
  struct ListNode node3(1, &node4);
  struct ListNode node2(2, &node3);
  struct ListNode node1(4, &node2);
 
class Solution {
public:
    
    void quicksort(std::vector<int> &nums)
    {
        std::vector<int> left;//nums = 4, 2, 1, 3 // nums`=2, 1, 3//nums``=1
        std::vector<int> right;
        std::vector<int>::iterator it;
        int pivot;
        if(nums.size()==0)
        {
            
        }else if(nums.size()==1)
        {
            left.push_back(nums[0]);
        }else if(nums.size()>1)
        {
            
            pivot=nums[0];//pivot=4//pivot`=2
            nums.erase(nums.begin());//nums = 2, 1, 3//nums`=1, 3
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]<pivot)
                {
                    left.push_back(nums[i]);
                }else if(nums[i]>=pivot)
                {
                    right.push_back(nums[i]);
                }
            }//  left = 2, 1, 3; right = [] //left = 1 right=3

            std::cout<<"left after pushing stuff in left and right(just before calling quicksort): ";
            for(int k=0; k<left.size(); k++)
            {
                std::cout<<left[k]<<", ";
            }
            std::cout<<std::endl;

            quicksort(left);//quicksort(2, 1, 3)//quicksort(1)DONE
            std::cout<<"left after quicksort(left): ";
            for(int k=0; k<left.size(); k++)
            {
                std::cout<<left[k]<<", ";
            }
            std::cout<<std::endl;

            quicksort(right);//quicksort(3)DONE

            std::cout<<"left after quicksort: ";
            for(int k=0; k<left.size(); k++)
            {
                std::cout<<left[k]<<", ";
            }
            std::cout<<std::endl;

            //since these are passed by reference, these will be changed permanently so I can refer to the quicksorted vectors simply as "left" and "right"
            left.push_back(pivot);//left = 1, 2
            it=left.end();
            left.insert(it, right.begin(), right.end());//left=1, 2, 3

            std::cout<<"left after pushing pivot and and right in it: ";
            for(int k=0; k<left.size(); k++)
            {
                std::cout<<left[k]<<", ";
            }
            std::cout<<std::endl;

        }

        nums.clear();

        std::cout<<"left after the main if function: ";
        for(int k=0; k<left.size(); k++)
        {
            std::cout<<left[k]<<", ";
        }
        std::cout<<std::endl;
        
        for(int i=0; i<left.size(); i++) //I'm copying all the values from this local vector left(the memory corresponding to which will be freed as soon as that function is popped off of the call stack) into the input vector nums, which since was passed by reference, have the memory corresponding to it intact, even after the function is popped off of the call stack. And since it was passed by reference, the "original" nums has been permanently changed which means I can now refer to the quicksorted nums simply as "nums"(which is what I did with left and right above)
        {
            nums.push_back(left[i]);//nums1=1, 2, 3
        }//nums''=1 for left; nums``=3 for right

        std::cout<<"the last for loop result: ";
        for(int k=0; k<left.size(); k++)
            {
                std::cout<<nums[k]<<", ";
            }
        std::cout<<std::endl;

    }
    
    void bubblesort(std::vector<int> &nums)
    {
        int temp;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<(nums.size()-1); j++)
            {
                if((nums[j])>(nums[j+1]))
                {
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode * listiterator = head;
        ListNode * loopiterator = head;
        ListNode * previous = head;
        
        for(int i=0; (loopiterator->next)!=nullptr; i++)
        {
            std::cout<<"outer loop "<<i<<std::endl;
            for(int j=0; (listiterator->next)!=nullptr; j++)
            {
                std::cout<<"    inner loop "<<j<<std::endl;
                if(listiterator==head)
                {
                    if((listiterator->val)>(listiterator->next)->val)
                    {
                        previous=listiterator->next;
                        loopiterator = loopiterator->next;
                        head = listiterator->next;
                        listiterator->next = (listiterator->next)->next;
                        head->next = listiterator;
                    }else if((listiterator->val)<=(listiterator->next)->val)
                    {
                        listiterator=listiterator->next;
                    }
                }else if(listiterator!=head)
                {
                    if((listiterator->val)>(listiterator->next)->val)
                    {
                        previous->next = listiterator->next;
                        listiterator->next = (listiterator->next)->next;
                        (previous->next)->next = listiterator;

                        previous = previous->next;
                    }else if((listiterator->val)<=(listiterator->next)->val)
                    {
                        listiterator=listiterator->next;
                    }
                }
            }
            listiterator = head;
            loopiterator = loopiterator->next;
        }
        return head;
    }
};

int main()
{
    Solution solution1;
    ListNode *head = &node1;
    ListNode *iterator1 = solution1.sortList(head);
    for(int i=0; i<4; i++)
    {
        std::cout<<"element "<<i+1<<" = "<<(iterator1->val)<<std::endl;
        iterator1=iterator1->next;
    }

}