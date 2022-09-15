#include "FileLogger.h"
#include "SDL.h"
#include <Windows.h>

FileLogger::FileLogger() : FileLogger("default.txt")
{
	
}

FileLogger::FileLogger(const string filename) 
{
	
}

FileLogger::~FileLogger()
{
	
}

void FileLogger::OpenLog()
{
	m_MyFile.open("fileLogs.txt");
}

void FileLogger::CloseLog()
{
	if (m_MyFile.is_open())
	{
		m_MyFile.close();
	}
}

void FileLogger::Write(string message)
{
	if (m_MyFile.is_open())
	{
		m_MyFile << message << endl;
	}
	
}
