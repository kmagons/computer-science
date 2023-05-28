#include "Agent.h"

Agent :: Agent(){

	this->action_sequence = new List<Action>;
};

Agent :: ~Agent(){
	delete this->action_sequence;
};

bool Agent :: isAlive(){
	return this->is_alive;
};
