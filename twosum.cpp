#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int least=nums[0];
        //int max=nums[0];
        int target2;
        int max2;
        std::vector<int> nums2((nums.size()), 0);
        int num1;
        int num2;
        std::vector<int> result;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<least)
            {
                least=nums[i];
            }
            if((target-nums[i])<least)
            {
                least=target-nums[i];
            } 
    
            //max=target-least; 
        }
        
    
        if(least<0)
        {
            target2=target-(2*least);
            max2=target-(2*least)+1;
        }else if(least>=0)
        {
            target2=target;
            max2=target-least+1;
        }
        
        std::vector<int> hash(max2, 0);
        
        if(least<0)
        {
            for(int i=0; i<nums.size(); i++)
            {
                nums2[i]=nums[i]-least; 
                (hash[(nums2[i])])++;
                if((target2%2)==0 && nums2[i]==(target2/2) && hash[(target2-nums2[i])]==1)
                {
                    
                }else if(hash[(target2-nums2[i])]>0)
                {
                    num1=nums2[i];
                    num2=target2-nums2[i];
                }
            }
        }else if(least>=0)
        {
            for(int i=0; i<nums.size(); i++)
            {
                nums2[i]=nums[i];
                (hash[nums2[i]])++;
                if((target2%2)==0 && nums2[i]==(target2/2) && hash[(target2-nums2[i])]==1)
                {
                   
                }else if(hash[(target2-nums2[i])]>0)
                {
                    num1=nums2[i];
                    num2=target2-nums2[i];
                }
            }
        }
        
        for(int i=0; i<nums2.size(); i++)
        {
            if((nums2[i]==num1)||(nums2[i]==num2))
            {
                result.push_back(i);
            }
                
        }
        return result;
    }
};