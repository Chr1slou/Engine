#pragma once
#include <Engine.h>
#include <fstream>
#include <iostream>
using namespace std;

/// <summary>
/// service provider for create and write logs  in a file
/// </summary>
class FileLogger final : public sky::ILogger {
public:
	FileLogger();
	FileLogger(const string filename);
	virtual ~FileLogger();
	virtual void Write(string message) override;
	virtual void CloseLog() override;
private:
	virtual void OpenLog() override;
	ofstream m_MyFile;

};
