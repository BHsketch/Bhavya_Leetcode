#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    
    int hash(int element, int least) 
        {
            int element2;
            if(least<0)
            {
                element2=element-least;
            }else if(least>0)
            {
                element2=element;
            }
            return element2;
        }
    
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        int least=nums[0];
        int max, max1;
        std::vector<int> half;
        std::vector<int> result;
        
        for(int i=0; i<nums.size(); i++) 
        {
            if(nums[i]<least)
            {
                least=nums[i];
            }
            if(target-nums[i]<least)
            {
                least=target-nums[i];
            }
        }
        max=target-least;
        
        if(least<0)
        {
            max1=max-least+1;
        }else if(least>=0)
        {
            max1=max+1;
        }
        //max1=22
        std::vector<int> hashmap(max1,0);
        
        for(int i=0; i<nums.size(); i++)
        {
            hashmap[hash(nums[i],least)]=i+1;
            if(target%2==0 && nums[i]==target/2)
            {
                half.push_back(i+1);
                if(half.size()==2)
                {
                    result.push_back(half[0]-1);
                    result.push_back(half[1]-1);
                }
            }else if(hashmap[hash(target-nums[i], least)]>0)
            {
                result.push_back(i);
                result.push_back(hashmap[hash(target-nums[i], least)]-1);
            }
        }
        return result;
    }
};