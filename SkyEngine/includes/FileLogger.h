#pragma once
#include <Engine.h>
class FileLogger final : public sky::ILogger {
public:
	FileLogger();
	virtual ~FileLogger() = default;
	virtual void OpenLog() override;
	virtual void CloseLog() override;
	virtual void Write(std::string message) override;

};
