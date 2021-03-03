#include "TestAgent.h"
#include <unistd.h>
#include <future>
#include <stdio.h>
 
DBus::BusDispatcher dispatcher;
 
int main()
{
    // connect to sessino bus for TestAgent service and create object(conn)
    DBus::default_dispatcher = &dispatcher;
    DBus::_init_threading();
    DBus::Connection conn = DBus::Connection::SessionBus();
    //conn.request_name("lge.testSW.DBus.TestAgentService");	// input new service node name to conn object
    conn.request_name("org.freedesktop.DBus.tcClient");
 
    // create TestAgentServer object with session connection
    TestAgentServer server(&conn);
 
    uint8_t count = 0;
 
    std::future<void>fut = std::async(std::launch::async, [=] {
        dispatcher.enter();
    });
 
    printf("TestAgent Service is ready!!\n");

    // emit EchoSignal every seconds.
    while ( true )
    {
        //printf("emit signal 'EchoSignal' count : %d\n", count);
        //server.EchoCount(count++);	// it's signal function created through xml
        //sleep(5);
    }
    return 0;
}
