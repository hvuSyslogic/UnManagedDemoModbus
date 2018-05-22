#include "FirmwareInformation.h"


std::string FirmwareInformation::getVersion() const
{
	return privateVersion;
}

void FirmwareInformation::setVersion(const std::string &value)
{
	privateVersion = value;
}

std::string FirmwareInformation::getState() const
{
	return privateState;
}

void FirmwareInformation::setState(const std::string &value)
{
	privateState = value;
}

std::string FirmwareInformation::getDate() const
{
	return privateDate;
}

void FirmwareInformation::setDate(const std::string &value)
{
	privateDate = value;
}

std::string FirmwareInformation::getTime() const
{
	return privateTime;
}

void FirmwareInformation::setTime(const std::string &value)
{
	privateTime = value;
}

void FirmwareInformation::SetData(char* data)
{
 
}

void FirmwareInformation::Delete()
{
	this->setVersion("");
	this->setState("");
	this->setDate("");
	this->setTime("");
}

std::string FirmwareInformation::ToString()
{
	return "Firmware:\r\n\tVersion: " + this->getVersion() + "\r\n\tState: " + this->getState() + "\r\n\tDate: " + this->getDate() + "\r\n\tTime: " + this->getTime();
}
