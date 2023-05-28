#include "Environment.h"

Environment :: Environment() {

	this->agent_list = new List<Agent>();
};

Environment :: ~Environment() {
	delete this->agent_list;
};

void Environment :: addAgent(Agent agent){
	this->agent_list->insertBack(agent);
};

void removeAgent(Agent agent){
	this->agent_list->deleteElem(agent);
};
