#include "Agent.h"

/**
 * Implementation of the generic Action class
 */

Action :: Action(int go_to, int cost) {
	this->go_to = go_to;
	this->cost = cost;
};

int Action :: getGoTo() {
	return this->go_to;
};

int Action :: getActionCost(){
	return this->cost;
};

/**
 * Implementation of the generic Perception class
 */

Perception :: Perception(int perceived_state, List<Action> * legal_actions) {
	this->perceived_state = perceived_state;
	this->legal_actions = legal_actions;
};

Perception :: ~Perception() {
	delete this->legal_actions;
};

int Perception :: getPerceivedState() {
	return this->perceived_state;
};

List<Action> * Perception :: getLegalActions() {
	return this->legal_actions;
};

/**
 *	Implementation of the generic Problem class
 */

Problem :: Problem() {

};

Problem :: Problem(int goal){
	this->goal = goal;
};

int Problem :: getGoal() {
	return this->goal;
};

/**
 * Implementation of the generic search Agent class
 */ 

Agent :: Agent(int id){
	
	this->agent_id = id;
	this->action_sequence = new List<Action>;
};

Agent :: ~Agent(){
	delete this->action_sequence;
};

bool Agent :: isAlive(){
	return this->is_alive;
};

void Agent :: executeAction(Environment env, Action action) {
	int go_to = action.getGoTo();
	env.executeAction(this->agent_id, go_to);
};

Perception Agent :: perceiveEnvironment (Environment env) {
	
	int agent_location = env.getAgentLocation(this->agent_id);
	List<int> * legal_actions = env.getLegalActions(this->agent_id);
	Perception p(agent_location, NULL);
	return p;
};

void Agent :: formulateProblem (Problem problem) {
	this->problem = problem;
};


