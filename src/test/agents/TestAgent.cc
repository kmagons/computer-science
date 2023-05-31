#include "TestAgent.h"
#include <iostream>

#include "../../main/agents/Agent.h"
CPPUNIT_TEST_SUITE_REGISTRATION (testagent);

void testagent :: setUp (void)
{

	this->reader = new GraphFileReader(this->ROMANIA_MAP);
	this->world = this->reader->getGraph();
	this->agent = new Agent(this->AGENT_ID);
}

void testagent :: tearDown (void) 
{
	delete this->reader;
	this->world = NULL;
	delete this->agent;
}


void testagent :: constructorAgentTest (void)
{
	CPPUNIT_ASSERT_EQUAL (true, true);
}
