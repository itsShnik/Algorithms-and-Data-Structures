#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V; //the number of the vertices in the graph

	list<int> *adj; // the adjacency list in the graph

public:
	Graph(int V); // the constructor method

	void addEdge(int v1, int v2); // method to add an edge to the graph

	void BFS(int s); //start the BFS travel from the vertex s

	void DFS(int s); // DFS travel from the vertex s

	void DFS_visit(bool* visited, vector<int> &parent, int s);

	void printGraph();

};

Graph::Graph(int V){
	this -> V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int v1, int v2){
	adj[v1].push_back(v2); // add v2 to v1's list
	adj[v2].push_back(v1); // add v1 to v2's list
}

void Graph::BFS(int s){
	vector<int> visited(V, 0); // to keep track of the nodes visited
	vector<int> dist(V, INT_MAX); // to calculate the distance
	vector<int> parent(V, -1); // to calculate the parent of the node

	queue<int> q; // initialize a queue and some details
	q.push(s);
	visited[s] = 1;
	dist[s] = 0;

	while(!q.empty()){
		int curr = q.front(); // remove the front element of the queue
		cout << curr << " ";
		q.pop();

		// check the adjacent unvisited nodes of the current node
		// add them to the queue
		// mark them visited
		list<int> :: iterator i;
		for(i = adj[curr].begin(); i != adj[curr].end(); i++){
			if(visited[*i] == 0){
				visited[*i] = 1;
				parent[*i] = curr;
				dist[*i] = dist[curr] + 1;
				q.push(*i);
			}
		}
	}
}

void Graph::DFS_visit(bool* visited, vector<int> &parent, int s){
	visited[s] = true; // mark that its now visited
	cout << s << " ";

	list<int> :: iterator i;
	for(i = adj[s].begin(); i != adj[s].end(); i++){
		if(!visited[*i]){
			cout << "s = " << s << ", next = " << *i << ", visited[s] = " << visited[s] << ", visited[next] = " << visited[*i] << endl;
			parent[*i] = s;
			DFS_visit(visited, parent, *i);
		}
	}
}

void Graph:: DFS(int s){
	bool* visited = new bool[V];
	for(int i = 0; i < V; i++){// initalize the visited array
		visited[i] = false;
	} 
	
	vector<int> parent(V, -1); // initalize the parent array

	DFS_visit(visited, parent, s); // call the recursive function from the start node
}

void Graph::printGraph(){
	for(int i = 0; i < V; i++){
		cout << i << " :: ";
		list<int>:: iterator j;
		for(j = adj[i].begin(); j != adj[i].end(); j++){
			cout << *j << " ";
		}
		cout << endl;
	}
}

int main(){
	int v, e;
	cin >> v; // scan the number of the vertices in the graph

	Graph g(v);

	cin >> e; // scan the number of the edges
	for(int i = 0; i < e; i++){
		int x, y;
		cin >> x >> y;

		g.addEdge(x, y);
	}
	g.printGraph();
	/*
	cout << "The BFS travel for the graph is : " << endl;
	g.BFS(2);
	cout << endl;
	*/
	cout << "The DFS travel for the graph is : " << endl;
	g.DFS(2);
	cout << endl;
} 