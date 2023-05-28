#include "MapEnvironment.h"

MapEnvironment :: MapEnvironment(Graph map){
	
	Environment();
	this->map = map;

};


MapEnvironment :: ~MapEnvironment(){

	~Environment();
	delete this->map;

};

int MapEnvironment :: getCost(int from, int to){
	return this->map->getCost(from, to);
};
