#include "Environment.h"

Environment :: Environment(Graph * state_space) {

	this->agent_list = new List<int>();
	this->state_space = state_space;
};

Environment :: ~Environment() {
	delete this->agent_list;
	delete this->state_space;
};

void Environment :: addAgent(int agent_id){
	this->agent_list->insertBack(agent_id);
};

void Environment :: removeAgent(id agent_id){
	this->agent_list->deleteElem(agent_id);
};

List<int> * Environment :: getAgents() {
	return this->agent_list;
};

List<int> * Environment :: getLegalActions(int agent_id){
	return NULL;
};

void Environment :: executeAction(int agent_id, int go_to ){

};

int Environment :: getAgentLocation(int agent_id){
	return 0;
};
