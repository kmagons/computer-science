#include <iostream>
#include <fstream>
#include <string>
#include <limits.h>
#include "list.h"
using namespace std;



class Graph {
 
	private:
		
		struct Vertice {
			
			int id;
			int cost;
		}	

		int V;

		List<Vertice> *adj;
		int ** weights;


		void initialize_graph_search_memory(int * distances,int * path, int number_of_nodes){
			for(int i = 0; i < number_of_nodes; i++){
				distances[i] = INT_MAX;
				path[i] = -1;
			}
		}

	public:

		Graph(int v){

			this->V = v;
			this->adj = new List<Vertice>[this->V];
			this->weights = new int * [v];
			
			for(int i = 0; i < v; i++){
				this->weights[i] = new int[v];
			}


		}
		
		~Graph(){


			for(int i = 0; i < this->V; i++){
				delete this->weights[i];
			}

			delete this->weights;
			//delete this->adj;
		}

		void addEdge(int v, int w, int weight){
			adj[v].insertAccordingToPriority(w);
			this->weights[v][w] = weight;
		}




	

		int uniform_cost_search(int initial_state, int goal_state, int * result, string * lookup){
			
			int node = initial_state;
			List<int> frontier; // priority queue sorted by the path cost

			int minimum_distance_costs[this->V]; //Dijkstra's approach to keep the shortest path and information on which vertices are yet to be explored
			this->initialize_graph_search_memory( minimum_distance_costs, result, this->V);
			minimum_distance_costs[node] = 0;


			frontier.insertAccordingToPriority(node); // the path cost for the initial state is 0
		
			while(!frontier.isEmpty()) {
				
				node = frontier.removeBack(); // select the neighbour vertice of the lowest path cost
				int number_of_neighbors = this->adj[node].getSize();
				int neighbors[number_of_neighbors];
				this->adj[node].copyListToArray(neighbors);

				
				for(int i = 0; i < number_of_neighbors; i++){
						
					int neighbor = neighbors[i];

						if(minimum_distance_costs[neighbor] > minimum_distance_costs[node] + this->weights[node][neighbor]){

							minimum_distance_costs[neighbor] = minimum_distance_costs[node] + this->weights[node][neighbor];
							result[neighbor] = node;
							//frontier.insertAccordingToPriority(neighbor, this->weights[node][neighbor]);
							frontier.insertAccordingPriority(neighbor);
						}
				}
			}

			return minimum_distance_costs[goal_state];

		}

		

};





	int main(int argc, char *argv[]) {
	

		char *filename = argv[1];
		int start =  9;
		int finish = 10;

		fstream file;
		string line;
		int v, w, distance;
		int number_of_vertices;
		int number_of_edges;
		int cityID;
		string cityName;

		file.open(filename);

		if(file.is_open()){

			file >> number_of_vertices >> number_of_edges;

			string cityNameLookup[number_of_vertices];

			for(int i = 0; i < number_of_vertices; i++){
				file >> cityID >> cityName;
				cityNameLookup[cityID] = cityName;

			}

			Graph graph(number_of_vertices);

			for(int i = 0; i < number_of_edges; i++){
				file >> v >> w >> distance;
				graph.addEdge(v, w, distance);
				graph.addEdge(w, v, distance);
			}

/*
			int path_in_reverse[number_of_vertices];
					int shortest_path =graph.uniform_cost_search(start, finish, path_in_reverse, cityNameLookup);
			int prev = finish;
			cout << "Shortest path between " << cityNameLookup[start] << " and " << cityNameLookup[finish] << " is " << shortest_path << '\n';

			cout << cityNameLookup[finish] << " <- ";

			while( prev !=start ){
				prev = path_in_reverse[prev];
				cout << cityNameLookup[prev] << " <- ";
			} 


			cout << cityNameLookup[start] << '\n';
*/

			file.close();
	}

	return 0;
}
