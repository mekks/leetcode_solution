/*
Question:
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

//Sol_1: priority_queue
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>,greater<int>> pq;
        for(int num : nums)
        {
            pq.push(num);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

*/
//Sol_2:
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> min_heap(k, 0);
        for (int i = 0; i < k; i++)
            min_heap[i] = nums[i];
        intializeHeap(min_heap);
        for (int i = k; i < nums.size(); i++) {
            if (min_heap[0] < nums[i])
                min_heap[0] = nums[i];
            rebuildHeap(min_heap, 0);
        }
        return min_heap[0];
    }
    
    void intializeHeap(vector<int>& min_heap) {
        if (min_heap.size() <= 1) return;
        int pos = ( min_heap.size() - 2 ) / 2;
        while (pos >= 0) {
            rebuildHeap(min_heap, pos); pos--;
        }
    }
    
    void rebuildHeap(vector<int>& min_heap, int i) {
        int j = 2 * i + 1;
        int k = 2 * i + 2;
        if (j >= min_heap.size()) return;
        if (k == min_heap.size()) {
            if (min_heap[j] < min_heap[i])
                swap(min_heap[j], min_heap[i]);
            return;
        }
        int min_val = i;
        if (min_heap[j] < min_heap[i])
            min_val = j;
        if (min_heap[k] < min_heap[min_val])
            min_val = k;
        if (min_val != i) {
            swap(min_heap[min_val], min_heap[i]);
            rebuildHeap(min_heap, min_val);
        }
    }
    
    void swap(int& a, int& b) {
        int tmp = a; a = b; b = tmp;
    }
};
