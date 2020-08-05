/*
Question:
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

//Sol:1 168ms
/*
class Solution {
public:
    vector<int>ans,a;
    Solution(vector<int>& nums) {
        ans=nums;
        a=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(!next_permutation(ans.begin(), ans.end()))
            sort(ans.begin(), ans.end());      //if its not possible to generate the next_permutation then sort the array, so again we can get next permutations
    
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 */
 
 //Sol:2 160ms
 class Solution {
public:
    vector<int>ans,a;
    Solution(vector<int>& nums) {
        ans=nums;
        a=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(ans.begin(),ans.end());
        return ans;
    }
};
