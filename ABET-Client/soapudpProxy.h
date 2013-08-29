/* soapudpProxy.h
   Generated by gSOAP 2.7.16 from udp.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapudpProxy_H
#define soapudpProxy_H
#include "soapH.h"
class udp
{   public:
	/// Runtime engine context allocated in constructor
	struct soap *soap;
	/// Endpoint URL of service 'udp' (change as needed)
	const char *endpoint;
	/// Constructor allocates soap engine context, sets default endpoint URL, and sets namespace mapping table
	udp()
	{ soap = soap_new(); endpoint = "soap.udp://localhost:10000"; if (soap && !soap->namespaces) { static const struct Namespace namespaces[] = 
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"wsa", "http://schemas.xmlsoap.org/ws/2004/08/addressing", NULL, NULL},
	{"ns", "urn:gsoap-udp-demo", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap->namespaces = namespaces; } };
	/// Destructor frees deserialized data and soap engine context
	virtual ~udp() { if (soap) { soap_destroy(soap); soap_end(soap); soap_free(soap); } };
	/// Invoke 'echoString' of service 'udp' and return error code (or SOAP_OK)
	virtual int ns__echoString(char *str, char **res) { return soap ? soap_call_ns__echoString(soap, endpoint, NULL, str, res) : SOAP_EOM; };
	/// Invoke 'sendString' of service 'udp' and return error code (or SOAP_OK)
	virtual int ns__sendString(char *str) { return soap ? soap_send_ns__sendString(soap, endpoint, NULL, str) : SOAP_EOM; };
};
#endif
