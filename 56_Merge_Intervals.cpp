/*
Question:
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/

//Sol:1 104 ms
/*
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;  
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end()); 
        int f=intervals[0][0]; 
        int e=intervals[0][1];
        
        for(int i=0; i<intervals.size(); i++)
        {
            int f2=intervals[i][0];
            int e2=intervals[i][1];
            if(max(f,f2) <= min(e,e2))//overlapping occure
            {
                f=min(f,f2);
                e=max(e,e2);
            }
            else
            {
                ans.push_back({f,e});
                f=f2;
                e=e2;
            }
        }
        ans.push_back({f,e});
        return ans;
    }
};
*/
//Sol:2 84ms
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        
        if(intervals.empty())
            return merged_intervals;
        
        // sort the intervals 
        sort(intervals.begin(), intervals.end());
        
        vector<int> curr_interval = intervals[0];

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] > curr_interval[1])
            {
                merged_intervals.emplace_back(curr_interval);
                curr_interval = intervals[i];
            }
            else {
                // current interval overlaps, so update the end time
                curr_interval[1] = max(curr_interval[1], intervals[i][1]);
            }
        }
        // add the last interval
        merged_intervals.emplace_back(curr_interval);
        return merged_intervals;
    }
};

