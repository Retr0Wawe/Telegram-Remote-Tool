#ifndef REQ_HPP
#define REQ_HPP

#include <string>
#include <windows.h>

#include "Debug.hpp"

typedef void* HINTERNET;

class Requests
{
private:
	HINTERNET hSocket;
	HINTERNET hConnection;
	bool SSL;
public:
	Requests(const char* useragent, const char* url, bool https);

	Requests();

	~Requests();

	std::string Send_Request_Get(const char* path, const char* content) const;
};

#endif