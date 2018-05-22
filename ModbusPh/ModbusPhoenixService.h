#pragma once
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
class ModbusPhoenixService
{
private:
	unsigned int returnValue;
	ServiceState m_actualState;
	ServiceState m_lastState;
public:
	~ModbusPhoenixService();
	__declspec(dllexport) ModbusPhoenixService();//constructor
	__declspec(dllexport) void Setvar(int val);
	__declspec(dllexport) int Getvar();
};
