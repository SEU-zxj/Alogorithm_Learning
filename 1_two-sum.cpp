#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //对于当前在nums中遍历到的数nums[i]，需要寻找的和为target的另一个数
        int num = 0;
        //建立哈希表，key = 值， value = 下标
        unordered_map<int, int> hashtable;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            num = target - nums[i];
            //如果没找到，返回值=hashtable.end()
            auto itr = hashtable.find(num);
            if(itr == hashtable.end())
            {
                hashtable[nums[i]] = i;
            }
            else
            {//找到了对应的数，返回i和哈希表中的value（下标）即可
                return {i, itr->second};
            }
        }
        //遍历完之后还是没返回，不存在这样的一组数，返回空
        return {};
    }
}; 

//int main()
//  {
//     unordered_map<int, int> hashtable;
//     auto itr = hashtable.find(-1);
//     cout << ((itr == hashtable.end())? "Not found\n" : "Found it\n");
//     hashtable[-1] = -20;
//     itr = hashtable.find(-1);
//     cout << ((itr == hashtable.end())? "Not found\n" : "Found it\n");
//     cout << "key = " << itr->first << " value = " << itr->second;
//     return 0;
//  }