/*
Question:
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//Sol:1 8ms
/*
class Solution {
public:
    void swap(vector<int> &v, int i,int j)
    {
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        return; 
    }
    void permutation(vector<vector<int>> &v,vector<int> &nums,int l, int r)
    {
        if(l==r)
           { v.push_back(nums);}
        else
            for(int i=l;i<=r;i++)
            {
                swap(nums,l,i);
                permutation(v,nums,l+1,r);
                swap(nums,l,i);
            }
        return;       
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> v;
        int l=nums.size();
        permutation(v,nums,0,l-1);
        return v;
    }
    
};
*/

//Sol:2 4ms
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> v;
        v.push_back(nums);
         next_permutation(nums.begin(),nums.end());
        while(nums!=v[0])
        {
            v.push_back(nums);
             next_permutation(nums.begin(),nums.end());
        }
        return v;
    }
};
