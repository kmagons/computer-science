#ifndef TESTAGENT_H
#define TESTAGENT_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../../main/agents/Agent.h"
#include "../../main/data_structures/Graph.h"
#include "../GraphFileReader.h"

using namespace std;

class testagent : public CPPUNIT_NS :: TestFixture
{
	CPPUNIT_TEST_SUITE (testagent);
	CPPUNIT_TEST (constructorAgentTest);
	CPPUNIT_TEST_SUITE_END ();

	public:
		void setUp (void);
		void tearDown (void);

	protected:
		void constructorAgentTest (void);	

	private:

		GraphFileReader * reader;
		Graph * world;
		std :: string const ROMANIA_MAP = "./src/test/data/Romania.txt";
		int const AGENT_ID = 0;
		Agent * agent;
};
#endif
