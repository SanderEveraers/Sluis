#include "valve.h"

Valve::Valve(std::string LR,int number, Network * network): network(network)
{
	std::stringstream ss;
	ss.str(std::string());
	ss << "GetDoor" << LR << "Valve" << number << ";";
	get = ss.str();
	ss.str(std::string());
	ss << "SetDoor" << LR << "Valve" << number << ":open;";
	setOpen = ss.str();
	ss.str(std::string());
	ss << "SetDoor" << LR << "Valve" << number << ":close;";
	setClose = ss.str();
}
bool Valve::isOpen()
{
	if (network->Send(get).compare("open") == 0)
	{
		return true;
	} else 
	{
		return false;
	}
}
bool Valve::Open()
{
	if (network->Send(setOpen).compare("ack")==0)
	{
		return true;
	} else
	{
		return false;
	}
}
bool Valve::Close()
{
	if (network->Send(setClose).compare("ack")==0)
	{
		return true;
	} else
	{
		return false;
	}
}