#include <iostream>
using namespace std;

void Swap1(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ShowNums(int nums[], int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        cout << nums[i];
    }
    cout << '\n';
}
//choose pivot from nums[left], nums[right] and nums[center]
//and return the value of the pivot
int Median3(int nums[], int left, int right)
{
    int center = (left + right) / 2;
    if(nums[left] > nums[center])
    {
        Swap1(nums[left], nums[right]);
    }
    if(nums[left] > nums[right])
    {
        Swap1(nums[left], nums[right]);
    }
    //now nums[left] is the smallest num among the three
    if(nums[center] > nums[right])
    {
        Swap1(nums[center], nums[right]);
    }
    //pivot = nums[center]
    //but we can hide pivot to nums[right-1]
    //in that case, we only need to consider nums[left+1 : right-2]
    Swap1(nums[center], nums[right-1]);
    return nums[right-1];
}
void Quicksort(int nums[], int left, int right)
{
    //recursion termination
    //at least three elements, can use fuction Median3
    if(right - left >= 2)
    {
        //at first, choose the pivot
        int pivot = Median3(nums, left, right);
        int i = left;
        int j = right - 1;
        //Subset partition
        while(true)
        {
            while(nums[++i] < pivot);//stop when nums[i++] >= pivot
            while(nums[--j] > pivot);//stop when nums[j--] <= pivot
            if(i >= j)
            {
                //pivot = nums[right-1]
                //so we should swap it with number >= than pivot
                //which points to nums[i], as the first "while"'s stop condition
                Swap2(&nums[i], &nums[right-1]); 
                break;
            }
            else
            {
                Swap2(&nums[i], &nums[j]);
            }
        }
        //recursion
        Quicksort(nums, left, i-1);
        Quicksort(nums, i+1, right);
    }
    else
    {
        if(right == left)
        {
            return;
        }
        if(right - left == 1)
        {
            if(nums[left]>nums[right])
            {
                Swap1(nums[left], nums[right]);
            }
        }
    }
}

int main()
{
    int N = 10;
    int* nums = new int[N];
    for(int i = N ; i > 0 ; i--)
    {
        nums[N-i] = i;
    }
    Quicksort(nums, 0 , N-1);
    ShowNums(nums, N);
    delete[] nums;
    return 0;
}