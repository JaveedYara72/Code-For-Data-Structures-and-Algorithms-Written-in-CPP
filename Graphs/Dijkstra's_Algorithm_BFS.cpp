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
class DijkstraGraph {
	unordered_map<T, list<pair<T, int>>> vvd;
public:
	void addEdge(T u, T v, int dist, bool bidir = true) {
		vvd[u].push_back(make_pair(v, dist));
		//if birectional is true
		if (bidir) {
			vvd[v].push_back(make_pair(u, dist));
		}
	}
	void printadjlist() {
		//Try to Print the adjacency list
		//Iterate over the rows(key,value pairs)
		for (auto j : vvd) {
			//j.first means the key here, ie amritsar and j.second means the list
			cout << j.first << " " << "->";
			for (auto l : j.second) {
				cout << "(" << l.first << "->" << l.second << ")";
			}
			cout << endl;
		}
	}

	void dijkstraSSSP(T src) {
		unordered_map<T, int>dist;

		//Set all distances to infinity in the first
		for (auto i : vvd) {
			dist[i.first] = INT_MAX;
		}

		//make a set now to find out node with the minimum distance
		set<pair<int, T>> s;
		//set sorts according to the first parameter.
		dist[src] = 0;
		s.insert(make_pair(0, src));

		while (!s.empty()) { //While loop will terminate if the set becomes empty
			//Find the pair which is at front
			auto p = *(s.begin());
			T node = p.second; // First parameter denotes the distance here in the set, but the second is the name

			int nodeDist = p.first;
			s.erase(s.begin());

			//Iterate over Neighbours/Children of current node
			for (auto childPair : vvd[node]) {
				if (nodeDist + childPair.second < dist[childPair.first] ) {
					//In the set updation of a particular node is not possible,
					//remove the old one and insert the new one to simulate updation
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest], dest)); //FInd the Old pair
					// if such pair exists then remove it
					if (f != s.end()) {
						s.erase(f);
					}
					//Insert the new pair
					//distance of destinationn is going to be updated
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}
		for (auto d : dist) {
			cout << d.first << " and " << d.second;
			cout << endl;
		}

	}
};


int main() {
	DijkstraGraph<string> India;
	India.addEdge("Amritsar", "Delhi", 1);
	India.addEdge("Amritsar", "Jaipur", 4);
	India.addEdge("Jaipur", "Delhi", 2);
	India.addEdge("Jaipur", "Mumbai", 8);
	India.addEdge("Bhopal", "Agra", 2);
	India.addEdge("Mumbai", "Bhopal", 3);
	India.addEdge("Agra", "Delhi", 1);
	India.printadjlist();
	India.dijkstraSSSP("Amritsar");



	return 0;
}