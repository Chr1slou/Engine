#include "FileLogger.h"
#include "SDL.h"
#include <Windows.h>

FileLogger::FileLogger() : FileLogger("GameLogs.txt")
{
	
}

FileLogger::FileLogger(const string filename) : m_MyFile(filename)
{
	
}

FileLogger::~FileLogger()
{
	
}

/// <summary>
/// open a file for the logs
/// 
/// not used for now
/// </summary>
void FileLogger::OpenLog()
{
	m_MyFile.open("fileLogs.txt");
}


/// <summary>
/// close the stream for the filelogs
/// </summary>
void FileLogger::CloseLog()
{
	if (m_MyFile.is_open())
	{
		m_MyFile.close();
	}
}

/// <summary>
/// add text in the filelog
/// </summary>
/// <param name="message"> text to add in the file</param>
void FileLogger::Write(string message)
{
	if (m_MyFile.is_open())
	{
		m_MyFile << message << endl;
	}
	
}
