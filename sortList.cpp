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
        std::vector<int> left;
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
            pivot=nums[0];
            nums.erase(nums.begin());
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i]<pivot)
                {
                    left.push_back(nums[i]);
                }else if(nums[i]>=pivot)
                {
                    right.push_back(nums[i]);
                }
            }
            quicksort(left);
            quicksort(right);
            //since these are passed by reference, these will be changed permanently so I can refer to the quicksorted vectors simply as "left" and "right"
            left.push_back(pivot);
            it=left.end();
            left.insert(it, right.begin(), right.end());
        }
        
        for(int i=0; i<left.size(); i++) //I'm copying all the values from this local vector left(the memory corresponding to which will be freed as soon as that function is popped off of the call stack) into the input vector nums, which since was passed by reference, have the memory corresponding to it intact, even after the function is popped off of the call stack. And since it was passed by reference, the "original" nums has been permanently changed which means I can now refer to the quicksorted nums simply as "nums"(which is what I did with left and right above)
        {
            nums[0]=left[0];
        }

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
        
        std::unordered_map<int, ListNode*> hashmap;
        std::vector<int> nums;
        ListNode *listiterator=head;
        
        for(int i=0; listiterator!=nullptr; i++)
        {
            hashmap[listiterator->val]=listiterator;
            nums.push_back(listiterator->val);
            listiterator = (listiterator->next);
        }
        
        bubblesort(nums);
        //no need to return anything from the function since nums was passed by reference. Now nums has been sorted

        int i;
        
        for(i=0; i<(nums.size() - 1); i++)
        {
            ((hashmap[nums[i]])->next)=hashmap[nums[i+1]];
        }
        
        ((hashmap[nums[i]])->next)=nullptr;

        head = hashmap[nums[0]];
        
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