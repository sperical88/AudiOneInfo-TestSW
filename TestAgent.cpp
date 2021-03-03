#include "TestAgent.h"
#include <stdio.h>
#include <stdlib.h>
 
TestAgentServer::TestAgentServer(DBus::Connection * conn)
: DBus::ObjectAdaptor(*conn, "/org/freedesktop/DBus/lge/testSW")	//node name in xml
{
 
}
 
TestAgentServer::~TestAgentServer()
{
 
}
 
std::string TestAgentServer::HelloString(const std::string& name)
{
    printf("Input string : %s\n", name.c_str() );
    std::string ret = name + " world!!";
    //::DBus::Variant vari(std::string ret, std::string);
    //::DBus::Variant vari;
    //::DBus::MessageIter m2 = vari.writer();
    //m2.append_string("Test String");
    return ret;
}


::DBus::Variant TestAgentServer::reqTestFromClient(const ::DBus::Variant& requestMsg)
{
    ::DBus::Variant retMsg = requestMsg;
    ::DBus::MessageIter iter = requestMsg.reader();
    std::cout << iter.array_type();
    //std::variant<unsigned char> requestMsg;
    //std::array<unsigned char, 7> arr;
    //arr = std::get<std::array<unsigned char, 7>>(requestMsg);
    //reqTestFromClient.getValue
    printf("reqTestFromClient\n");
    //arr[0] = 1;
    return retMsg;
}
