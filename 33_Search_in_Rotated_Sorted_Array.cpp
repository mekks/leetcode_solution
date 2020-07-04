/*
Question:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

//Sol:1 20ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0 , r=n-1;  // right and left var
        int m;
        if(n==0)
            return -1;
        
        while(l <= r)
        {
            m=(l+r)/2;
            if(nums[m]==target)
            {
                return m;
            }
            else if(nums[0] <= nums[m])
            {
                if(target>= nums[0] && target <= nums[m])
                    r=m-1;
                else
                    l=m+1;
            }
            else
            {
                if(target >= nums[m] && target<=nums[n-1])
                    l=m+1;
                else
                    r=m-1;
            }
        
        }
        return -1;
    }
};

//Sol:2 12ms 
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target)
                return mid;
            if ((nums[0] > target && nums[mid] >= nums[0]) || (nums[mid] < target && !(target >= nums[0] && nums[mid] < nums[0])))
                i = mid + 1;
            else
                j = mid - 1;
        }
        return -1;
    }
};
*/

//Sol:3 12ms
/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); 
        int rotationIndex = findRotationIndex (nums, n);
        
        int l = 0, r = n - 1;
        int mid, rotMid, rotL, rotR;
        while(l <= r){
            mid = l + (r-l) / 2;
            rotMid = (mid + rotationIndex) % n;
            if(nums[rotMid]> target){
                r = mid - 1;
            }
            else if(nums[rotMid] == target){
                return rotMid;
            }
            else{
                l = mid + 1;
            }
        }
        return -1; 
    }
    
    int findRotationIndex(vector<int> const &nums, int const &n){
        int l = 0, r = n-1; 
        int mid;
        while(l< r && nums[l] > nums[r]){
            mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }
            else {
                r = mid ; 
            }
        }
        return l;
    }
};
*/
