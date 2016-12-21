#ifndef VALVE_H
#define VALVE_H

#include <string.h>
#include <sstream>      // std::stringstream, std::stringbuf
#include "network.h"
class Valve
{
private:
	std::string get;
	std::string setOpen;
	std::string setClose;
	Network* network;

public:
Valve(std::string LR,int number, Network* network);
bool isOpen();
bool Open();
bool Close();
};

#endif
