#ifndef AGENT_H
#define AGENT_H

#include "../data_structures/List.h"
#include "../environments/Environment.h"

class Action {

	private:

		int go_to;
		int cost;

	public:

		Action(int go_to, int cost);
		int getGoTo();
		int getActionCost();

};

class Perception {

	private:
		int perceived_state;
		List<Action> * legal_actions;
	public:
		Perception(int perceived_state, List<Action> * legal_actions);
		~Perception();
		int getPerceivedState();
		List<Action> * getLegalActions();
};


class Problem {

	private:

		int goal;

	public:

		Problem();
		Problem(int goal);
		int getGoal();
};

class Agent {
	
	private:
		
		int agent_id;
		bool is_alive;
		List<Action> * action_sequence;
		bool isGoalState(Perception perception);
		Problem problem;

	public:

	Agent(int id);
	~Agent();
	void executeAction(Environment env, Action action);
	Perception perceiveEnvironment(Environment env);
	void formulateProblem(Problem problem);
	bool isAlive();

};

#endif
