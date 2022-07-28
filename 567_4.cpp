class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        //思路：双指针（感觉也可以说成是两个边界都可以滑动的滑动窗口）
        //代码3的是寻找一个固定长度为n的子串，使arr所有值=0
        //换种思路：在一直满足arr=0的前提条件下，寻找一个长度为n的子串
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> arr(26);
        //只看s1,arr所有地方都是负的，而且和的绝对值为n1
        for(char x : s1)
        {
            arr[x-'a']--;
        }
        //双指针
        int p1 = 0;
        for(int p2 = 0 ; p2 < n2 ; p2++)
        {
            arr[s2[p2] - 'a']++;

            while(arr[s2[p2] - 'a'] > 0)
            {
                //通过移动左指针来使arr[p2]重新小于0
                arr[s2[p1] - 'a']--;
                p1++;
            }
            //保证arr所有元素的和小于等于0
            //[p2, p1]区间长度每增加1，arr所有元素的和就增加1
            //[p2, p1]区间长度为n1，arr所有元素的和为-n1+n1 = 0
            //又arr所有元素非正数 => arr所有元素为0 => 我们需要的子串
            if(p2 - p1 + 1 == n1)
            {
                return true;
            }
        }
        return false;
    }
};