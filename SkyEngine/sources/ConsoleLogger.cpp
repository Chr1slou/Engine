#include "ConsoleLogger.h"
#include "SDL.h"
#include <Windows.h>
#include <iostream>

using namespace std;

ConsoleLogger::ConsoleLogger()
{
	OpenLog(); 
}

/// <summary>
/// open the console
/// </summary>
void ConsoleLogger::OpenLog()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}


/// <summary>
/// close the console
/// </summary>
void ConsoleLogger::CloseLog()
{
	FreeConsole();
}

/// <summary>
/// display a message in the console
/// </summary>
/// <param name="message"> message to display </param>
void ConsoleLogger::Write(string message)
{
	cout << message;
}
