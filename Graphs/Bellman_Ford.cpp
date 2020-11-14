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





//Bellman-Ford Algorithm
vector<int> bellman_ford(int V, int src, vector<vector<int>>edges) {

	//create a vector and set distances to infinity
	vector<int>dist(V + 1, INT_MAX);
	dist[src] = 0;

	//relax all the edges V-1 Times
	for (int i = 0; i < V - 1; i++) {
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	//For Checking Negative Weight Cycles
	//relax all the edges V-1 Times
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];

		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
			cout << "Negative Weight Cycle Found!";
			exit(0);
		}
	}

	return dist;
}

int main() {



	//Edge List representation for Bellmnan Ford
	int n, m; //n is vertices and m is edges.
	cin >> n >> m;

	vector<vector<int>>edges; //(a,b,3),(c,d,5)
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		edges.push_back({u, v, wt});
	}
	//bellman algorithm
	vector<int>distances = bellman_ford(n, 1, edges);
	for (int i = 1; i <= n; i++) {
		cout << "Node " << i << " is at Distance " << distances[i] << endl;
	}


	return 0;
}