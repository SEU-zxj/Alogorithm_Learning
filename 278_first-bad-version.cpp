// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        //just like binary search
        int left = 1;
        int right = n;
        int mid = left + (right - left)/2;                 //<-优化

        if(isBadVersion(1))
        {
            return 1;
        }

        left++;

        while(left <= right)
        {
            // 0 0  | 0 1(impossible) | 1 0 | 1 1
            if(isBadVersion(mid) && !isBadVersion(mid-1))
            {
                return mid;
            }
            else if(!isBadVersion(mid) && !isBadVersion(mid-1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            mid = left + (right - left)/2;
        }    

        return -1;
    }
};