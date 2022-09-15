#include "ConsoleLogger.h"
#include "SDL.h"
#include <Windows.h>
#include <iostream>

using namespace std;

ConsoleLogger::ConsoleLogger()
{
	OpenLog();
}

void ConsoleLogger::OpenLog()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}



void ConsoleLogger::CloseLog()
{
	FreeConsole();
}

void ConsoleLogger::Write(string message)
{
	cout << message;
}
