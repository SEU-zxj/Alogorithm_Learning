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
        //当arr1 == arr2，代表找到子串 -> diff == 0，代表找到字串 
        //又vector已经重载了==，故使用vector而不是int[]

        //***优化思路***//
        //每次滑动窗口移动之后，只是进入了一个字符，出去了一个字符
        //但原方法还是比较了arr1与arr2所有地方，造成O(n1 * n2)的复杂度
        //不妨用一个变量diff表示当前滑动窗口中，s2与s1的arr有多少地方是不同的
        //于是判断arr1 == arr2就变成了 diff == 0
        vector<int> arr(26);
        int diff = 0;
        for(int i = 0 ; i < n1 ; i++)
        {
            arr[s1[i] - 'a']--;
            arr[s2[i] - 'a']++;
        }
        for(int item : arr)
        {
            if(item != 0)
            {
                diff++;
            }
        }
        if(diff == 0)
        {
            return true;
        }
        //上个for循环到n1-1结束，因此这里从n1开始
        //滑动窗口滑动时，如何更新diff?
        //假设移入滑动窗口的为x = s2[i],移出滑动窗口的为 y = s2[i-n1]
        //if x == y，diff无影响
        //if x != y，未更新arr[x]时，if arr[x] == 0，diff++  原来arr[x]没产生diff,改变之后arr[x]必!=0,一定会不同
        //            更新arr[x]后，if arr[x] == 0，diff--           
        //           未更新arr[y]时，if arr[y] == 0，diff++ 
        //            更新arr[y]后，if arr[y] == 0，diff--  
        for(int i = n1 ; i < n2 ; i++)
        {
            int x = s2[i] - 'a';//移入滑动窗口的字符下标
            int y = s2[i-n1] - 'a';//移出滑动窗口的字符下标
            if(x == y)
            {
                continue;
            }

            if(arr[x] == 0)
            {
                diff++;
            }
            arr[x]++;
            if(arr[x] == 0)
            {
                diff--;
            }

            if(arr[y] == 0)
            {
                diff++;
            }
            arr[y]--;
            if(arr[y] == 0)
            {
                diff--;
            }

            if(diff == 0)
            {
                return true;
            }
        }
        return false;
    }
};