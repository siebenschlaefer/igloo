using namespace std;                                                
#include "assertionexception.hpp"
#include "testfixture.hpp"
#include "testrunner.hpp"                                           
#include "constraints/assertions.h"

int RegisterTestFixture(string name, TestFixtureBase* testFixture)
{        
	TestRunner::FixtureMap[name] = testFixture; 
	return 0;
}  

#define TestFixture(fixture) \
class fixture; \
int fixture##_dummy = RegisterTestFixture( #fixture , new TestFixture<fixture>()); \
class fixture : public TestFixture<fixture>            
                     
#define TestMethod(fixture, method) \
void BOOST_PP_CAT(GetTest, __COUNTER__)(vector< void (fixture::*)() >& tests) \
{ \
	tests.push_back(&fixture::method); \
} \
void method()
