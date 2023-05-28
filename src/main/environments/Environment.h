#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "../data_structures/List.h"
#include "../agents/Agent.h"

class Environment {

	private:

		ListNode<Agent> agent_list;

	public:
		Environment();
		~Environment();
		void addAgent(Agent agent);
		void removeAgent(Agent agent);
		ListNode<Agent> getAgents();

};

#endif
