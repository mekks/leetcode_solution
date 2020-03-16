/*
QUESTION:
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)return; // if not nums2 than direct return
        if(!m)
        {
            nums1=std::move(nums2);
            return;
        }
        //mearge algo with decrement manner for less space complexity O(1)
        
        while(n)
        {
            if(!m || nums2[n-1] > nums1[m-1])
            {
                nums1[m+n-1]=nums2[n-1];
                n--;
            }
            else
            {
                nums1[m+n-1]=nums1[m-1];
                m--;
            }
        }
        return;
    }
};
