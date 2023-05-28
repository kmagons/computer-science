#ifndef MAP_ENVIORNMENT_H
#define MAP_ENVIRONMENT_H

#include "Environment.h"
#include "../data_structures/Graph.h"

class MapEnvironment: public Environment {
	
	private:
	
		Graph map;

	public: 

		MapEnvironment(Graph map);
		~MapEnvironment();
		int getCost(int from, int to);
		int getLocation(MapAgent agent);
		void travel(MapAgent, int to);
		void activateAgentIn(MapAgent agent, int location);
};

#endif
