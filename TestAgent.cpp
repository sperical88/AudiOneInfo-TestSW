#include "TestAgent.h"
#include <stdio.h>
 
TestAgentServer::TestAgentServer(DBus::Connection * conn)
: DBus::ObjectAdaptor(*conn, "/lge/audioneinfo/DBus/testSW/TestAgent")	//node name in xml
{
 
}
 
TestAgentServer::~TestAgentServer()
{
 
}
 
std::string TestAgentServer::HelloString(const std::string& name)
{
    printf("Input string : %s\n", name.c_str() );
    std::string ret = name + " world!!";
    return ret;
}
