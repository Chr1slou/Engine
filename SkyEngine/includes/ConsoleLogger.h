#pragma once
#include <Engine.h>


/// <summary>
/// service provider which creates a console and displays logs
/// </summary>
class ConsoleLogger final : public sky::ILogger {
public:
	ConsoleLogger();
	virtual ~ConsoleLogger() = default;
	virtual void OpenLog() override;
	virtual void CloseLog() override;
	virtual void Write(std::string message) override;
};
