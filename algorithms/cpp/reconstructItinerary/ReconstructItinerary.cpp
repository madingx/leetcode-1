// Source : https://leetcode.com/problems/reconstruct-itinerary/
// Author : Hao Chen
// Date   : 2017-01-06

/*************************************************************************************** 
 * 332. Reconstruct Itinerary [Medium]
 * Given a list of airline tickets represented by pairs of departure and arrival 
 * airports [from, to], reconstruct the itinerary in order. All of the tickets belong 
 * to a man who departs from JFK. Thus, the itinerary must begin with JFK.
 * 
 * Note:
 * 
 * 1. If there are multiple valid itineraries, you should return the itinerary that has 
 * the smallest lexical order when read as a single string. For example, the itinerary 
 * ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * 2. All airports are represented by three capital letters (IATA code).
 * 3. You may assume all tickets form at least one valid itinerary.
 * 
 * Example 1:
 * tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
 * 
 * Example 2:
 * tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
 * Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it 
 * is larger in lexical order.
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

/*
 This problem's description really confuse me.
 
 for examples:
    1) [["JFK", "PEK"], ["JFK", "SHA"], ["SHA", "JFK"]], which has two itineraries: 
       a) JFK -> PEK, 
       b) JFK -> SHA -> JFK -> PEK
       The a) is smaller than b), because PEK < SHA, however the b) is correct answer.
       So, it means we need use all of tickets.
       
    2) [["JFK", "PEK"], ["JFK", "SHA"]], which also has two itineraries:
       a) JFK -> PEK
       b) JFK -> SHA
       for my understanding, the JFK -> SHA is the correct one, 
       however, the correct answer is JFK -> SHA -> PEK.
       I don't understand, why the correct answer is not JFK -> PEK -> SHA
       That really does not make sense to me.
       
 All right, we need assume all of the tickets can be connected in one itinerary.
 Then, it's easy to have a DFS algorithm.
*/

// 40 ms, faster than 30.08% of C++, 17.8 MB, less than 25.96% of C++
class Solution {
public:
    //DFS
    void travel(string& start, unordered_map<string, multiset<string>>& map, vector<string>& result) {
        while (map[start].size() > 0 ) {
            string next = *(map[start].begin());
            map[start].erase(map[start].begin());
            travel(next, map, result);
        }
        result.insert(result.begin(), start);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> map;
        for(auto t : tickets) {
            map[t.first].insert(t.second);
        }
        vector<string> result;
        string start = "JFK";
        travel(start, map, result);
        return result;
    }
};



// 32 ms, faster than 49.05% of C++, 19 MB, less than 11.25% of C++ 
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }

    map<string, multiset<string>> targets;
    vector<string> route;

    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
};