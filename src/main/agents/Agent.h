#ifndef AGENT_H
#define AGENT_H

#include "../data_structures/List.h"
#include "..actions/Action.h"

class Agent {
	
	private:
		
		bool is_alive;
		ListNode<Action> action_sequence;
	
	public:

	Agent();
	~Agent();
	virtual void executeAction(Action action) = 0;
	virtual ListNode<Action> perceiveEnvironment() = 0;
	bool isAlive();

};

#endif
