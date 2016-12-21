//============================================================================
// Name       	: ui.cpp
// Author   	: Sander Everaers
// Date			: 2016
//=======================================================================

#include <iostream>
#include <stdexcept>
#include <string>
#include "network.h"
#include "valve.h"

static void showMenu( void )
{
    std::cout << ("\n\nSluis\n");
    std::cout << ("===============\n");
    std::cout << ("(1) Connect\n");
    std::cout << ("(2) Send\n");
    std::cout << ("(3) Close\n");
    std::cout << ("(4) Valve\n");
    std::cout << ("-----------------------\n");
    std::cout << ("(9) QUIT\n\n");
    std::cout << ("Choice : ");
}

static void valve(Network* network)
{
    std::cout << ("\n\nLeft/Right:\n");
    std::cout << ("===============\n");
    std::cout << ("Choice : ");
    std::string choice;
    std::cin >> choice;
    std::cin.ignore();
    std::cout << ("\n\nValve Number:\n");
    std::cout << ("===============\n");
    std::cout << ("Choice : ");
    int number = 0;
    std::cin >> number;
    std::cin.ignore();
    Valve valve(choice, number, network);
    valve.Open();
}

static void connect(Network* network)
{
	std::cout << ("\n\nPort Number:\n");
    std::cout << ("===============\n");
    std::cout << ("Choice : ");
    unsigned short choice = 0;
    std::cin >> choice;
    std::cin.ignore();
    network->Connect(choice);
}

static void send(Network* network)
{
	std::cout << ("\n\nMessage:\n");
    std::cout << ("===============\n");
    std::cout << ("Choice : ");
    std::string choice = "\0";
    std::cin >> choice;
    std::cin.ignore();
    std::cout << network->Send(choice) << std::endl;
}

int main( void )
{
    bool quit = false;
    Network* network = new Network();

    while (!quit)
    {
        char choice = '\0';
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case '1' :
            connect(network);
            break;
        case '2' :
            send(network);
            break;
        case '3' :
            network->Close();
            break;
        case '4' :
            valve(network);
            break;
        case '9' :
        	delete network;
            quit = true;
            break;
        default:
            std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
            break;
        }
    }

    return 0;
}