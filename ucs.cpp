// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;
 
// graph
vector<vector<int> > graph;
 
// map to store cost of edges from a current node to the target node
map<pair<int, int>, int> cost;
 
// returns the minimum cost in a vector
vector<int> uniform_cost_search(vector<int> goal, int start)
{    // minimum cost upto
    // goal state from starting
    // state
    vector<int> answer;
 
    // create a priority queue to store index's cost and index
    priority_queue<pair<int, int> > queue;
 
    // set the answer vector to max value
    for (int i = 0; i < goal.size(); i++)
        answer.push_back(INT_MAX);
 
    // insert the starting index's cost (0) and the starting index
    queue.push(make_pair(0, start));
 
    // map to store visited node
    map<int, int> visited;
 
    // count of number of goals reached
    int count = 0;
 
    // while the queue is not empty
    while (queue.size() > 0) {
 
        // get the top element of the
        // priority queue
        pair<int, int> p = queue.top();
 
        // pop the element
        queue.pop();
 		
        // revising orginal cost value of the popped element
        p.first *= -1;
 
        // check if the element is part of
        // the goal list
        if (find(goal.begin(), goal.end(), p.second) != goal.end()) {
 
            // get the position in the goal list
            int index = find(goal.begin(), goal.end(),
                             p.second) - goal.begin();
 
            // if a new goal is reached, count is increased by 1
            if (answer[index] == INT_MAX)
                count++;
 
            // if the cost is less than the cost at current element's index position in the answer vector, replace it
            if (answer[index] > p.first)
                answer[index] = p.first;
 
            // pop the element
            queue.pop();
 
            // if all goals are reached, return answer
            if (count == goal.size())
                return answer;
        }
 
        // check for the non visited nodes
        // which are adjacent to present node
        if (visited[p.second] == 0) //if present node hasn't been visited
            for (int i = 0; i < graph[p.second].size(); i++) { //while i is lesser than the number of child nodes of current node 
                // value is multiplied by -1 so that
                // least priority is at the top
                queue.push(make_pair((p.first +
                  cost[make_pair(p.second, graph[p.second][i])]) * -1,
                  graph[p.second][i]));
            }
 
        // mark as visited
        visited[p.second] = 1;
    }
 
    return answer;
}
 
// main function
int main()
{
    // create the graph
    cout<<"\n\n**********UNIFORM COST SEARCH**********\n\n";
 
    int m, n;
    cout <<"ENTER TOTAL NUMBER OF VERTICES: ";
    cin >> n;
    graph.resize(n);
    
    int m1, m2, c;
    cout<<"ENTER TOTAL NUMBER OF EDGES: ";
    cin>>m;
    cout <<"\nENTER THE VERTICES BETWEEN WHICH AN EDGE EXISTS AND THE EDGE'S COST:\n";
    while(m>0)
	    {
		cout<<"\nFIRST VERTEX: ";  
	    cin >> m1;
	    cout<<"SECOND VERTEX: ";
	    cin >> m2;
		cout<<"COST BETWEEN THE TWO VERTICES: ";
		cin >> c;
	    
	    graph[m1].push_back(m2); //adding edge
	    cost[make_pair(m1, m2)]=c; //adding cost
	    m--;
		}
		
	// start state
	int s;
	cout <<"\nENTER THE START STATE: ";
    cin >> s;
    
	// goal state
	int g;	
    vector<int> goal;
	cout <<"\nENTER THE GOAL STATE: ";
    cin >> g;
    goal.push_back(g);
 	
    // get the answer
    vector<int> answer = uniform_cost_search(goal, s);
 
    // print the answer
    cout << "\nMINIMUM COST FROM START STATE TO GOAL STATE IS= ";
    cout << answer[0] << endl;
 
    return 0;
}
