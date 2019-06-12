// Source : https://leetcode.com/problems/course-schedule/
// Author : Hao Chen
// Date   : 2015-06-09

/********************************************************************************** 
 * 207. Course Schedule [Medium]
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to 
 * finish all courses?
 * 
 * Example 1:

 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0. So it is possible.

 * Example 2:

 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 *              To take course 1 you should have finished course 0, and to take course 0 you should
 *              also have finished course 1. So it is impossible.
 * 
 * Note:
 * 1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 *    Read more about how a graph is represented.
 * 2. You may assume that there are no duplicate edges in the input prerequisites.
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 *  - This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, 
 *    no topological ordering exists and therefore it will be impossible to take all courses.
 *
 *  - Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic 
 *    concepts of Topological Sort. (https://class.coursera.org/algo-003/lecture/52)
 *
 *  - Topological sort could also be done via BFS. (http://en.wikipedia.org/wiki/Topological_sorting#Algorithms)
 * 
 *               
 **********************************************************************************/


// 68 ms, faster than 14.61% of C++, 20 MB, less than 8.23% of C++
class Solution {
public:

    bool hasCycle(int n, vector<int>& explored, vector<int>& path, map<int, vector<int>>& graph) {
        
        for(int i=0; i<graph[n].size(); i++){
            
            //detect the cycle
            if ( path[graph[n][i]] ) return true;
            
            //set the marker
            path[graph[n][i]] = true;
            
            if (hasCycle(graph[n][i], explored, path, graph)) {
                return true;
            }
            //backtrace reset
            path[graph[n][i]] = false;
        }
        //no cycle found, mark this node can finished!
        explored[n] = true;
        return false;
        
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        //using map to stroe the graph, it's easy to search the edge for each node
        //the bool in pair means it is explored or not
        map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
        }
        
        //explored[] is used to record the node already checked!
        vector<int> explored(numCourses, false);
        
        //path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            
            if (explored[i]) continue;
            if (hasCycle(i, explored, path, graph)) return false;
            

        }
        return true;
    }
};







// BFS

// BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. 
// If we fail to do so, there must be a cycle in the graph and we return false. 
// Otherwise we set its indegree to be -1 to prevent from visiting it again and 
// reduce the indegrees of its neighbors by 1. This process will be repeated for n (number of nodes) times.

// 28 ms, faster than 48.19% of C++, 14.1 MB, less than 35.18% of C++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};