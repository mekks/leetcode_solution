/*
Question:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/


//Sol:1 64ms
/*
class Solution {
public:
  
   bool dfsCycle(int curr, vector<bool>& visited, vector<bool>& rec_stack,vector<vector<int>>& g)
   {
       visited[curr]=true;
       rec_stack[curr]=true;
       
       for(int i=0;i<g[curr].size();i++)
       {
           //if neighbour are already visted ,cycle is there
           if(rec_stack[g[curr][i]])
               return true;
           if(dfsCycle(g[curr][i],visited,rec_stack,g))
               return true;
       }
    // make the current node as unvisited, because at a time we need
	// to keep track of nodes in the same branch only
	rec_stack[curr] = false;
	return false;
   }
   bool DFS(int numCourses, vector<vector<int>>& g)
   {
	// to keep track of visited courses
	vector<bool> visited(numCourses, false);
	// for keeping track of recursion stack in DFS branch
	vector<bool> rec_stack(numCourses, false);
       
       for(int i=0;i< numCourses ;i++)
       {
           if(!visited[i] && dfsCycle(i,visited , rec_stack , g))
               return false;
       }
       return true;
   }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	// make edges for each vertex
	vector<vector<int>> g(numCourses);
	for(auto& edge: prerequisites) 
		g[edge[0]].emplace_back(edge[1]);//[1,0] means edge form 1 to 0

	// using DFS
	return DFS(numCourses, g);
    }
};
*/


//Sol:2 56ms
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> zeroDegree;   
        
        //create graph in form of adjecenet list and find also indegree
        for(int i=0; i < prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        //push zero degree nodes into queue
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                zeroDegree.push(i);
                numCourses--;
            }
        }
        
        while(!zeroDegree.empty())
        {
            int node = zeroDegree.front();
            zeroDegree.pop();
            for(int i=0;i < graph[node].size();i++)
            {
                int connectedNode = graph[node][i];
                indegree[connectedNode]--;
                if(indegree[connectedNode] == 0)
                {
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;
    }
};
