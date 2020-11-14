#include <bits/stdc++.h>
#include<cstring>
#include<vector>
#include<bitset>
#include<iostream>
#include<string>
#include<list>
#include<map>
#define ll long long int
#define f(i, a, b) 		for(ll i = a ; i < b ; i++)

using namespace std;






template<typename T>
class GraphTopologicalSort {
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	void topohelper(T src, map<T, bool> &visited, list<T> &ordering) { // same to dfs helper
		//recursive function that will traverse the graph

		visited[src] = true; //When you visit a node, mark it as true
		//go to all neighbours of that node that are not visited
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				topohelper(nbr, visited, ordering);
			}
		}

		//at this point push the values to the front
		ordering.push_back(src);
		return;

	}

	void toposort() {
		map<T, bool> visited;
		list<T> ordering;

		//Mark all the Nodes as not visited in the beginning
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		//call the helper function
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				topohelper(node, visited, ordering);
			}
		}

		//Finally print them
		for (auto node : ordering) {
			cout << node << endl;
		}
	}
};


int main() {


	//For Topological Sort using DFS
	GraphTopologicalSort<string> p;
	p.addEdge("Python", "Data Preprocessing");
	p.addEdge("Python", "PyTorch");
	p.addEdge("Python", "ML");
	p.addEdge("Data Preprocessing", "ML");
	p.addEdge("PyTorch", "ML");
	p.addEdge("ML", "DL");
	p.addEdge("DL", "FaceRecognisation");
	p.addEdge("Dataset", "FaceRecognisation");
	p.toposort();

	return 0;
}