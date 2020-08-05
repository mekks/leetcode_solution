/*
Question:
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2
*/

//Sol:1 100ms
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>a;
        for(int i = 0; i<matrix.size(); ++i){
            for(int j = 0; j<matrix[0].size(); ++j){
                a.push_back(matrix[i][j]);
            }
        }
        sort(a.begin(), a.end());
        return a[k-1];
    }
};
*/

//Sol:2 88ms
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int ,vector<int>> pq;
        
        for(int i=0; i<matrix.size();i++)
        {
            for(int j=0; j<matrix.size();j++)
            {
                if(pq.size() < k)pq.push(matrix[i][j]);
                else if(matrix[i][j] < pq.top())
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};
*/

//Sol:3 68ms 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<long long> oneDimmArr;
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			oneDimmArr.push_back(matrix[i][j]);

	nth_element(oneDimmArr.begin(), oneDimmArr.begin() + k - 1, oneDimmArr.end());
	return oneDimmArr[k - 1];
    }
};
