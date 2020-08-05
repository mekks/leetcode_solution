/*
Question:
Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, 
             the order of elements returned by next should be: [1,4,6].
*/

//Sol:1 36ms

class NestedIterator {
public:
    int i=0;
    vector<int> nums;
    void help(vector<NestedInteger> &nestedList){
        for(NestedInteger i : nestedList){
            if(i.isInteger()){
                nums.push_back(i.getInteger());
            }
            else{
                help(i.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        help(nestedList);
    }
    
    int next() {
        return nums[i++];
    }
    
    bool hasNext() {
        return i<nums.size();
    }
};
