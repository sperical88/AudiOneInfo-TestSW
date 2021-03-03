#include "ResponseInterfaceAdaptor.h"
 
class TestAgentServer : public org::freedesktop::DBus::TestAgent_adaptor,  //interface in xml
                   public DBus::IntrospectableAdaptor,
                   public DBus::ObjectAdaptor
{
public:
    TestAgentServer(DBus::Connection * conn);
    virtual ~TestAgentServer();
 
public:
    virtual std::string HelloString(const std::string& name);
    virtual ::DBus::Variant reqTestFromClient(const ::DBus::Variant& requestMsg);
};
