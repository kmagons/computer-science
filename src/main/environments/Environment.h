#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../data_structures/List.h"
#include "../data_structures/Graph.h"
#include "../environments/Environment.h"

class MapEnvironment {

	private:

		List<int> * agent_list;
		Graph * state_space;


	public:
		MapEnvironment(Graph * state_space);
		~MapEnvironment();
		void addAgent(int agent_id);
		void removeAgent(int agent_id);
		List<int> * getAgents();
		List<int> * getLegalActions(int agent_id);
		void executeAction (int agent_id, int go_to);
		int getAgentLocation(int agent_id);
};

#endif
