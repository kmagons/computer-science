#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"
#include "Queue.h"
#include "Stack.h"

class GraphEdge {

	private:

		int from;
		int to;
		int cost;
	
	public:

		GraphEdge(int from, int to, int cost );
		GraphEdge();
		int getCost();
		int getFrom();
		int getTo();


};


class GraphVertice {
		private:
		
		int id;
		std :: string name;
		List<GraphEdge> * adjacency_list;		

	public:

		GraphVertice(int id, std :: string name);
		~GraphVertice();
		std :: string getName();
		List<GraphEdge> * getNeighbors();
		void addNeighbor(GraphVertice * adj, int cost);
		int getId();
};

class GraphVerticeContainer {

	private:
		
		Queue<GraphVertice*> * queue;
		Stack<GraphVertice*> * stack;

	public:

		GraphVerticeContainer(Queue<GraphVertice*> * queue);
		GraphVerticeContainer(Stack<GraphVertice*> * stack);
		void insert(GraphVertice * vertice);
		GraphVertice * remove();
		bool isEmpty();

};

class Graph {

	private:

		int number_of_vertices;
		int number_of_edges;
		GraphVertice ** adjacency_list;
		static void initializeSearchMemory(int size, bool * visited, bool value);

	public:
		
		Graph(int number_of_vertices);
		~Graph();
		void addEdge(int v, int w, int cost);
		void addVertice(int v, std :: string name);
		std :: string getVerticeNamesBFS(int root);
		std :: string getVerticeNamesDFS(int root);
		std :: string getVerticeNames(int root,  GraphVerticeContainer frontier);
		void printDFS(int root);
		int getVerticeCount();
		int getEdgeCount();
};

#endif
