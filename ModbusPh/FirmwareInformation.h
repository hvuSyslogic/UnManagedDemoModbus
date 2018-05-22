#pragma once
#include <string>
#include <vector>
class FirmwareInformation
{
	
	private:
		std::string privateVersion;
		std::string privateState;
		std::string privateDate;
		std::string privateTime;

	public:
		std::string getVersion() const;
		void setVersion(const std::string &value);

		std::string getState() const;
		void setState(const std::string &value);

		std::string getDate() const;
		void setDate(const std::string &value);

		std::string getTime() const;
		void setTime(const std::string &value);

		void SetData(char* data);

		void Delete();

		std::string ToString() ;
	};


