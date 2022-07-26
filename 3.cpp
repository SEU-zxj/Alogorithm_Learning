class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        //建立哈希函数，用于查询下一个将加入到字串中的字符是否已经出现在滑动窗口中
        unordered_set<char> Hashset;
        int right = -1;//滑动窗口右侧边界，假定最开始没出发
        int ans = 0;
        for(int left = 0 ; left < n ; left++)
        {
            //滑动窗口左边界每次移动后，要从哈希集合里删去上个值
            if(left != 0)
            {
                Hashset.erase(s[left-1]);
            }
            //尝试移动滑动窗口右边界
            //只有右边界下一个不在哈希集合里，才可以移动
            while(right + 1 < n && Hashset.count(s[right+1]) == 0)
            {
                Hashset.insert(s[++right]);
            }
            //当前为滑动窗口左边界在left时，子字符串的最大值
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};