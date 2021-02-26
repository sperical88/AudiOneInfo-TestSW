
/*
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!
 */

#ifndef __dbusxx__ResponseInterfaceAdaptor_h__ADAPTOR_MARSHAL_H
#define __dbusxx__ResponseInterfaceAdaptor_h__ADAPTOR_MARSHAL_H

#include <dbus-c++/dbus.h>
#include <cassert>

namespace lge {
namespace testSW {
namespace DBus {

class TestAgent_adaptor
: public ::DBus::InterfaceAdaptor
{
public:

    TestAgent_adaptor()
    : ::DBus::InterfaceAdaptor("lge.testSW.DBus.TestAgent")
    {
        register_method(TestAgent_adaptor, HelloString, _HelloString_stub);
        register_method(TestAgent_adaptor, reqTestFromClient, _reqTestFromClient_stub);
    }

    ::DBus::IntrospectedInterface *introspect() const 
    {
        static ::DBus::IntrospectedArgument HelloString_args[] = 
        {
            { "name", "s", true },
            { "greeting", "s", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument reqTestFromClient_args[] = 
        {
            { "name", "a", true },
            { "greeting", "a", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedArgument EchoCount_args[] = 
        {
            { "count", "y", false },
            { 0, 0, 0 }
        };
        static ::DBus::IntrospectedMethod TestAgent_adaptor_methods[] = 
        {
            { "HelloString", HelloString_args },
            { "reqTestFromClient", reqTestFromClient_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedMethod TestAgent_adaptor_signals[] = 
        {
            { "EchoCount", EchoCount_args },
            { 0, 0 }
        };
        static ::DBus::IntrospectedProperty TestAgent_adaptor_properties[] = 
        {
            { 0, 0, 0, 0 }
        };
        static ::DBus::IntrospectedInterface TestAgent_adaptor_interface = 
        {
            "lge.testSW.DBus.TestAgent",
            TestAgent_adaptor_methods,
            TestAgent_adaptor_signals,
            TestAgent_adaptor_properties
        };
        return &TestAgent_adaptor_interface;
    }

public:

    /* properties exposed by this interface, use
     * property() and property(value) to get and set a particular property
     */

public:

    /* methods exported by this interface,
     * you will have to implement them in your ObjectAdaptor
     */
    virtual std::string HelloString(const std::string& name) = 0;
    virtual std::vector<  > reqTestFromClient(const std::vector<  >& name) = 0;

public:

    /* signal emitters for this interface
     */
    void EchoCount(const uint8_t& arg1)
    {
        ::DBus::SignalMessage sig("EchoCount");
        ::DBus::MessageIter wi = sig.writer();
        wi << arg1;
        emit_signal(sig);
    }

private:

    /* unmarshalers (to unpack the DBus message before calling the actual interface method)
     */
    ::DBus::Message _HelloString_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::string argin1; ri >> argin1;
        std::string argout1 = HelloString(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
    ::DBus::Message _reqTestFromClient_stub(const ::DBus::CallMessage &call)
    {
        ::DBus::MessageIter ri = call.reader();

        std::vector<  > argin1; ri >> argin1;
        std::vector<  > argout1 = reqTestFromClient(argin1);
        ::DBus::ReturnMessage reply(call);
        ::DBus::MessageIter wi = reply.writer();
        wi << argout1;
        return reply;
    }
};

} } } 
#endif //__dbusxx__ResponseInterfaceAdaptor_h__ADAPTOR_MARSHAL_H
