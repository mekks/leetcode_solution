/*
Question:
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

*/

//Sol:1 36ms
/*
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans; 
        unordered_map<int,int> m;   
        priority_queue<pair<int,int>>q;
        for(int x: nums)m[x]++;
        for(auto p : m)
        {
            q.push({p.second,p.first});
        }
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
*/

//Sol:2 28ms
class Solution {
public:
    static bool cmp(const pair<int,int> &a , const pair<int,int> &b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<pair<int,int>> s; 
       vector<int> ans; 
       unordered_map<int,int> m;
        
        for(int i:nums)
        {
            m[i]++;
        }
        for(auto x:m)
        {
            s.push_back(x);
        }
        sort(s.begin(),s.end(),cmp);
        
        for(auto p: s)
        {
            if(!k)break;
            ans.push_back(p.first);
            k--;
        }
        return ans;
    }
};
