/*
Question:
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

//Sol:1 4ms
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
          int n=nums.size();
        int low=0,mid=0,high=n-1;
        
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
*/

//Sol:2 0ms
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int indexZero= 0, indexTwo, n= nums.size();
		indexTwo= n-1;
        //Shift 0's left side and 2's right side of the array
        for(int i=0; i<n; i++ )
        {
            if(nums[i]==2 && i<indexTwo)
            {
                if(nums[indexTwo]==2)
                {
                    while(nums[indexTwo]==2 && indexTwo > i)
                        indexTwo--;//if more 2's are in rightside than just decrese the indexTwo
                }
                nums[i]=nums[indexTwo];
                nums[indexTwo]=2;
                indexTwo--;
            }
            if(nums[i]==0)
            {
                nums[i]=nums[indexZero];
                nums[indexZero]=0;
                indexZero++;
            }
            
        }
    }
};
