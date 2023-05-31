#include "../main/data_structures/Graph.h"
#include <fstream>

class GraphFileReader {

	private:

		Graph * graph;
		int number_of_vertices;
		int number_of_edges;
		std :: string bfs_output;
		std :: string dfs_output;


	public:

		GraphFileReader(std :: string file_name);
		~GraphFileReader();
		Graph * getGraph();
		std :: string getBFSOutput();
		std :: string getDFSOutput();
		int getVerticeCount();
		int getEdgeCount();
};
