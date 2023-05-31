#include "Environment.h"

MapEnvironment :: MapEnvironment(Graph * state_space) {

	this->agent_list = new List<int>();
	this->state_space = state_space;
};

MapEnvironment :: ~MapEnvironment() {
	delete this->agent_list;
	delete this->state_space;
};

void MapEnvironment :: addAgent(int agent_id){
	this->agent_list->insertBack(agent_id);
};

void MapEnvironment :: removeAgent(int agent_id){
	this->agent_list->deleteElem(agent_id);
};

List<int> * MapEnvironment :: getAgents() {
	return this->agent_list;
};

List<int> * MapEnvironment :: getLegalActions(int agent_id){
	return NULL;
};

void MapEnvironment :: executeAction(int agent_id, int go_to ){

};

int MapEnvironment :: getAgentLocation(int agent_id){
	return 0;
};
