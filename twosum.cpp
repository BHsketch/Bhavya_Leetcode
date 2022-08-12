#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        int least=nums[0];
        int max, max1;
        std::vector<int> half;
        std::vector<int> result;
        
        std::unordered_map<int, int> hashmap;
        
        for(int i=0; i<nums.size(); i++)
        {
            hashmap[nums[i]]=i;
            if(target%2==0 && nums[i]==target/2)
            {
                half.push_back(i+1);
                if(half.size()==2)
                {
                    result.push_back(half[0]-1);
                    result.push_back(half[1]-1);
                    break;
                }
            }else if(hashmap.find(target-nums[i])!=hashmap.end())
            {
                result.push_back(i);
                result.push_back(hashmap[target-nums[i]]);
                break;
            }
        }
        return result;
    }
};