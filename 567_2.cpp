class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
        //对代码2的优化
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2)
        {
            return false;
        }
        //两个数组arr1&arr2 -> 一个数组arr
        //arr1存储s1中所有字母出现次数
        //arr2存储当前遍历到的所有字母出现次数
        //使用滑动窗口维护数组arr2
        //当arr1 == arr2，代表找到子串 -> arr == 0，代表找到字串 
        //又vector已经重载了==，故使用vector而不是int[]
        vector<int> arr1(26);
        vector<int> arr2(26);
        for(int i = 0 ; i < n1 ; i++)
        {
            arr1[s1[i] - 'a']++;
            arr2[s2[i] - 'a']++;
        }
        if(arr1 == arr2)
        {
            return true;
        }
        //上个for循环到n1-1结束，因此这里从n1开始
        for(int i = n1 ; i < n2 ; i++)
        {
            arr2[s2[i] - 'a']++;
            arr2[s2[i-n1] - 'a']--;
            if(arr1 == arr2)
            {
                return true;
            }
        }
        return false;
    }
};