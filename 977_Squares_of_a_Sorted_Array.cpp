/*
QUESTION
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, 
also in sorted non-decreasing order.


Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 */
//QUICK_SORTING..
class Solution {
public:
    void swap(int* a, int* b) 
    { 
     int t = *a; 
     *a = *b; 
     *b = t; 
    } 
    int partition (vector<int> &A, int low, int high) 
    { 
     int pivot = A[high];   
     int i = (low - 1);  
  
     for (int j = low; j <= high- 1; j++) 
     { 
        if (A[j] <= pivot) 
        { 
            i++;  
            swap(&A[i], &A[j]); 
        } 
     } 
     swap(&A[i + 1], &A[high]); 
     return (i + 1); 
    } 
  
    void quickSort(vector<int> &A, int low, int high) 
    { 
     if (low < high) 
     { 
         int pi = partition(A, low, high); 
  
         quickSort(A, low, pi - 1); 
         quickSort(A, pi + 1, high); 
     } 
    }
    vector<int> sortedSquares(vector<int>& A) 
    {
        int arr_len= A.size();
        int i;
        for(i=0 ;i<arr_len ;i++)
        {
           A[i]=A[i]*A[i];  
        }
        quickSort(A ,0 , arr_len-1); 
        return A;
    }
    
    
};
