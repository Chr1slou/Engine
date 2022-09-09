#pragma once
#include <Engine.h>
class ConsoleLogger final : public sky::ILogger {
public:
	ConsoleLogger();
	virtual ~ConsoleLogger() = default;
	virtual void OpenLog() override;
	virtual void CloseLog() override;
	virtual void Write(std::string message) override;
};
