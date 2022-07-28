#include <iostream>
using namespace std;
void CopyArray(int* arr1, int* arr2, int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        arr2[i] = arr1[i];
    }
}
bool checkInclusion(string s1, string s2) 
{
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 > n2)
    {
        return false;
    }
    //本题中，滑动窗口的大小是固定的（n1)
    //用一个数组record存储s1中的各字母出现情况
    int record[26] = {0};
    for(int i = 0 ; i < n1 ; i++)
    {
        record[static_cast<int>(s1[i]) - 97]++;
    }
    //left, right are left bound and right bound of the slip window, respectively.
    int left = 0;
    int right = n1 - 1;
    //used to go through s2
    int p = 0;
    int judge[26] = {};
    CopyArray(record, judge, 26);
    //若右边界超界，跳出循环
    while(right < n2)
    {
        while((p < n2) && judge[static_cast<int>(s2[p]) - 97] != 0)
        {
            judge[static_cast<int>(s2[p]) - 97]--;
            p++;
        }
        //现在p指向的元素两种情况
        //1. 当前的滑动窗口满足，p == right+1
        //2. 当前滑动窗口不满足条件，p <= right
        if(p == right + 1)
        {
            return true;
        }
        else
        {
            //移动窗口，重新开始下一轮判断
            right += 1;
            left += 1;
            p = left;
            CopyArray(record, judge, 26);
        }
    }
    return false;
}
int main()
{
    checkInclusion("adc", "dcda");
    return 0;
}