class Solution {
public:
    // Structure of 'Node' used in priority queue.
struct Node 
{
    int dist;
    int label;
    int color;
    bool operator<(const Node& a) const 
	{  
        return a.dist < dist;    
    }
};
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {

        vector<int> graph[2][n];

        for (int i = 0; i < redEdges.size(); i++)
        {
            graph[0][redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for (int i = 0; i < blueEdges.size(); i++)
        {
            // Add blue edges to 'graph[1]'.
            graph[1][blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        vector<vector<int>> dist(n, vector<int>(2, 2 * n));
        dist[0][0] = dist[0][1] = 0;

        priority_queue<Node> minDist;
        minDist.push({0, 0, 0});
        // Source node with red incoming edge.
        minDist.push({0, 0, 1});
        // Source node with blue incoming edge.

        while (!minDist.empty())
        {
            Node node = minDist.top();
            minDist.pop();

            int cur = node.label;
            int c = node.color;

            // If the path length of [cur, c] in 'node' is greater than 'dist[cur][c]' skip this node.
            if (dist[cur][c] < node.dist)
                continue;

            for (int i = 0; i < graph[1 - c][cur].size(); i++)
            {
                int next = graph[1 - c][cur][i];

                if (dist[next][1 - c] > dist[cur][c] + 1)
                {
                    dist[next][1 - c] = dist[cur][c] + 1;
                    minDist.push({dist[next][1 - c], next, 1 - c});
                }
            }
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            // Compute the array 'answer' from 'dist'.
            answer[i] = min(dist[i][0], dist[i][1]);
            if (answer[i] == 2 * n)
                answer[i] = -1;
        }

        return answer;
    }
};
    /*
    Time Complexity : O(N + (RLEN + BLEN) * log(RLEN + BLEN))
    Space Complexity : O(N + RLEN + BLEN)

    where 'RLEN' is the number of red edges, 
	'BLEN' is the number of blue Edges and 'N' is the number of nodes.
*/
    
// Modified Dijkstra’s algorithm
// Dijkstra’s algorithm is used for finding the shortest path between nodes in a weighted graph. As the given graph is unweighted, the path length is equal to the number of edges, so consider each edge’s weight to be ‘1’. The maximum shortest path length will be ‘2*n - 3’, which will be achieved when all edges from node ‘i’ to ‘j’ (where ‘i != j’) have the same color ‘red’ and each node has a self-loop of ‘blue’ color or vice-versa.

 

// For any node ‘x’ a valid path can be of two forms:

// 0 -> ... -’blue edge’-> x. (Ending with blue edge)
// 0 -> … -’red edge’-> x. (Ending with red edge)
 

// Create two graphs ‘graph[2][n]’, the first ‘graph[0]’ containing red edges and the second ‘graph[1]’ containing blue edges. Here, ‘graph[i][j][k]’ means an edge of color type ‘i’ (‘0’ is red and ‘1’ is blue) from node ‘j’ to node ‘k’. A node can be represented in the form ‘[x, c]’ where ‘x’ is the node’s label and ‘c’ is the color of the incoming edge. Use a 2-d array ‘dist[n][2]’, where ‘dist[i][0]’ will store the length of the shortest path to reach node ‘i’ from a red edge and ‘dist[i][1]’ is the length with a blue edge. Use a 2-d array ‘sptSet[n][2]’ to check if we have found the shortest path for a node of form ‘[x, c]’.

 

// Initialize the array ‘dist’ with value ‘2*n’ (i.e., unreachable from node ‘0’). Set ‘dist[0][0] = dist[0][1] = 0’ i.e., node ‘0’ is reachable from both blue and red edges with a path of zero length. Set ‘sptSet[0][0] = sptSet[0][1] = 0’, which means the length of shortest path to reach node ‘[0, 0]’ and ‘[0, 1]’ is zero.

 

// Now, use Dijkstra’s shortest path algorithm to find the shortest path length for each such node ‘[x, c]’ from node ‘0’ (i.e., from ‘[0, 0]’ and ‘[0, 1]’). Let ‘minDist’ be the set of nodes (with their path length) that are reachable from the nodes in ‘sptSet’. Initially, both ‘sptSet’ and ‘minDist’ contain two nodes, ‘[0, 0]’ and ‘[0, 1]’, the source nodes.

 

// According to Dijkstra’s algorithm: 

// In each iteration, remove the node (let’s say ‘[x, c]’)  having the smallest path length in ‘minDist’ (let’s say ‘len’). Then ‘len’ is the shortest path length for node ‘[x, c]’ from node ‘0’. Set ‘sptSet[x][c] = true’ and ‘dist[x][c] = len’ as we have found it’s shortest path length. For all the nodes that are reachable from ‘[x, c]’, if they have ‘sptSet’ as false (i.e., their shortest path is not known) and their ‘dist’ value is larger than ‘dist[x][c] + 1’ then, add them to the set ‘minDist’ and update their ‘dist’ value. Stop the iteration when the set ‘minDist’ becomes empty, i.e., when we have found the shortest path for all nodes reachable from node ‘0’ (the source node).

 

// Finally, for each node ‘i’ we have ‘answer[i] = min(dist[i][0], dist[i][1])’. If ‘answer[i]’ is still ‘2*n’ then no valid path exists to reach node ‘i’, set ‘answer[i] = -1’. Use a Priority Queue to implement ‘minDist’, so that we can extract the smallest element efficiently (in ‘O(log(n))’). Below is an implementation of Dijkstra’s algorithm using priority queue:

 

// Create an array of list ‘graph[2][n]’ to store the given graph.
// Run a loop where ‘i’ ranges from ‘0’ to ‘length(redEdges) - 1’:
// ‘graph[0][redEdges[i][0]].append(redEdges[i][1])’
// Run a loop where ‘i’ ranges from ‘0’ to ‘length(blueEdges) - 1’:
// ‘graph[1][blueEdges[i][0]].append(blueEdges[i][1])’
// Create a min priority queue ‘minDist’ that stores ‘Node’ objects and orders them by ‘Node->dist’. A ‘Node’ contains three values {‘dist’, ‘label’, ‘color’}.
// Insert {0, 0, 0} and {0, 0, 1} in ‘minDist’. These are the source nodes, [0, 0] and [0, 1] with ‘dist’ equal to zero.
// Initialize array ‘dist[n][2]’ with value ‘2*n’.
// Set ‘dist[0][0] = dist[0][1] = 0’ (for source nodes).
// Run a loop until ‘minDist’ is not empty:
// ‘node = minDist.pop()’. Get the node with the smallest known distance and remove it from ‘minDist’.
// ‘cur = node->label’. The current node label.
// ‘c = node->color’. The color of the incoming edge.
// If ‘dist[cur][c] < (node->dist)’ then, ignore this node as it doesn’t have the minimum distance:
// Continue the loop.
// Run a loop where ‘i’ ranges from ‘0’ to ‘length(graph[1 - c][cur]) - 1’
// ‘next = graph[1 - c][cur][i]’. Move to the neighboring node through an edge of color ‘1 - c’, i.e., alternate of color ‘c’.
// If  ‘dist[next][1 - c] > dist[next][c] + 1’, then:
// ‘dist[next][1 - c] = dist[next][c] + 1’
// ‘minDist.push({dist[next][1 - c], next, 1- c})’. Push an ‘Node’ object to ‘minDist’.
// Create an array ‘answer[n]’ to store the answer.
// Run a loop where ‘i’ ranges from ‘0’ to ‘n - 1’:
// ‘answer[i] = min(dist[i][0], dist[i][1])’
// If ‘answer[i] = 2*n’, then:
// ‘answer[i] = -1’
// Return the array ‘answer’ as the final answer.
// Time Complexity
// O(N + (RLEN + BLEN) * log(RLEN + BLEN)), where ‘RLEN’ is the number of red edges, ‘BLEN’ is the number of blue edges, and ‘N’ is the number of nodes.

 

// Whenever a node’s distance is reduced, we add that instance of the node in the priority queue. Therefore, there can be multiple instances, but we only consider the instance with the minimum distance and ignore others. So, there can be at most ‘O(E)’ vertices (one for each edge) in the priority queue, hence the time complexity ‘O(E * log(E))’. Creating the ‘DIST’ to store the shortest path for each node array takes ‘O(N)’ time. As the number of edges in the graph ‘E = RLEN+ BLEN’, total time complexity is ‘O(N + (RLEN+ BLEN) * log(RLEN + BLEN))'.

// Space Complexity
// O(RLEN + BLEN + N), where 'RLEN' is the number of red edges, 'BLEN' is the number of blue edges, and ‘N’ is the number of nodes.

 

// We create an adjacency list for the given graph, which takes ‘O(RLEN + BLEN)’ space. The array ‘DIST’ takes ‘O(N)’ space, and the priority queue stores ‘O(RLEN + BLEN)’ elements at most. Hence, the space complexity is ‘O(RLEN + BLEN + N)’.