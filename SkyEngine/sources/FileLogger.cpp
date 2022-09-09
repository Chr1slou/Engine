#include "FileLogger.h"
#include "SDL.h"
#include <Windows.h>

FileLogger::FileLogger()
{
	OpenLog();
}

void FileLogger::OpenLog()
{
	AllocConsole();
}

void FileLogger::CloseLog()
{
	FreeConsole();
}

void FileLogger::Write(std::string message)
{
}
