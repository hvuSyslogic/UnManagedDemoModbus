#pragma once
#include <limits>
#include "Device.h"
enum ServiceState
{
	Idle,
	Start,
	PlugPlayMode,
	PlugPlayModeOld,
	ExpertMode,
	ExpertModeOld,
	AlarmStop,
	CreateConfiguration,
	StartDataTransfer,
	CompleteReadConfiguration,
	WritePlugPlayMode,
	WritePlugPlayModeOld,
	WriteExpertMode,
	WriteExpertModeOld,
	WriteProcessDataWatchdogTime,
	WriteProcessDataWatchdogTimeOld,
	Error,
	Disconnect,
};
enum VersionInfoType
{
	DDI_Info = 1,
	Driver_Info = 2,
};
enum DriverState
{
	DriverInactive,
	DriverIdle,
	DriverGoingToEnable,
	DriverStart,
	DriverActive,
	DriverErrorDetect,
	DriverError,
	DriverGoingToDisable,
	DriverDisable,
	DriverGoingToDispose,
};
//static byte* Int32ToByteArray(int Integer, int ByteArrayLength)
//{
//	//C# TO C++ CONVERTER WARNING: C# to C++ Converter has converted this array to a pointer. You will need to call 'delete[]' where appropriate:
//	//ORIGINAL LINE: byte[] numArray = new byte[0];
//	unsigned char *numArray = new unsigned char[0];
//	if (ByteArrayLength > 0 && ByteArrayLength <= 4)
//	{
//		numArray = new unsigned char[ByteArrayLength];
//		for (int index = 0; index < ByteArrayLength; ++index)
//		{
//			numArray[ByteArrayLength - 1 - index] = static_cast<unsigned char>(Integer >> index * 8 & static_cast<int>(std::numeric_limits<unsigned char>max()));
//		}
//	}
//	return numArray;
//}

class ModbusPhoenixService
{
private:
	unsigned int returnValue;
	ServiceState m_actualState;
	ServiceState m_lastState;
	DriverState m_currentDriverstate;

public:
	~ModbusPhoenixService();
	__declspec(dllexport) bool Enable();//constructor
	__declspec(dllexport) ModbusPhoenixService();//constructor
	__declspec(dllexport) void Setvar(int val);
	__declspec(dllexport) int Getvar();
};
