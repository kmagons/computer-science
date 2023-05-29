#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../data_structures/List.h"
#include "../data_structures/Graph.h"
#include "../agents/Agent.h"

class Environment {

	private:

		List<int> * agent_list;
		Graph * state_space;


	public:
		Environment(Graph state_space);
		~Environment();
		void addAgent(int agent_id);
		void removeAgent(int agent_id);
		List<int> * getAgents();
		List<int> * getLegalActions(int agent_id);
		void executeAction (int agent_id, int go_to);
		int getAgentLocation(int agent_id);
};

#endif
