// Source : https://oj.leetcode.com/problems/clone-graph/
// Author : Hao Chen
// Date   : 2014-10-12

/********************************************************************************** 
* 133. Clone Graph [Medium]
* Given a reference of a node in a connected undirected graph, return a 
* deep copy (clone) of the graph. Each node in the graph contains a 
* val (int) and a list (List[Node]) of its neighbors.

 

* Example:
*    1   ---   2
*
*    |         |
*    |         |
*
*    4   ---   3

* Input:
* {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":
* [{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],
* "val":2},{"$ref":"4"}],"val":1}

* Explanation:
* Node 1's value is 1, and it has two neighbors: Node 2 and 4.
* Node 2's value is 2, and it has two neighbors: Node 1 and 3.
* Node 3's value is 3, and it has two neighbors: Node 2 and 4.
* Node 4's value is 4, and it has two neighbors: Node 1 and 3.
 

* Note:

* The number of nodes will be between 1 and 100.
* The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
* Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
* You must return the copy of the given node as a reference to the cloned graph.
* 
*               
**********************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


// 28 ms, faster than 78.09 of C++, 16.5 MB, less than 64.87% of C++
class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == NULL) return NULL;
        
        //create a map, key is source node, value is clone node.
        map<Node*, Node*> cloneMap;
        
        //using queue for breadth first search
        queue<Node*> q;
        q.push(node);
        
        //clone the root
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode;
        
        //breadth first search
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            //for each neighbors
            for(int i=0; i<n->neighbors.size(); i++){
                Node* neighbor= n->neighbors[i];
                //not existed in cloneMap
                if (cloneMap.find(neighbor)==cloneMap.end()){
                    //clone a node
                    Node* newNode = new Node(neighbor->val);
                    cloneMap[n]->neighbors.push_back(newNode);
                    cloneMap[neighbor] = newNode;
                    
                    //put the neighbors into the queue
                    q.push(neighbor);
                }else{
                    cloneMap[n]->neighbors.push_back(cloneMap[neighbor]);
                }
            }
        }
        
        return cloneNode;
    }
};





// 36 ms, faster than 13.57% of C++, 16.6 MB, less than 45.65% of C++
class Solution {
    unordered_map<Node* ,Node*> mymap;
public:
    void cloneGraphResc(Node* node) {
        if(mymap.find(node) != mymap.end() && mymap[node])
            return;
        Node* newnode = new Node();
        newnode->val = node->val;
        newnode->neighbors = vector<Node*> (node->neighbors.size(),NULL);
        mymap[node] = newnode;
        for(int i=0;i<node->neighbors.size();i++){
            cloneGraphResc(node->neighbors[i]); 
            newnode->neighbors[i] = mymap[node->neighbors[i]];
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        cloneGraphResc(node);
        return mymap[node];
    }
};