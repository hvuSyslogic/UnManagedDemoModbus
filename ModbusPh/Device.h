#pragma once
#include <iostream>
using namespace std;
enum ControllerStartup
{
	PhysicalConfiguration = 1,
	LogicalConfiguration = 2,
	WithoutConfiguration = 3,
};
class Device
{
public:
	Device();
	Device(::string Name, ::string pstrIPaddress, bool ExpertModeSetting, bool PnPSetting);
	Device(char* pstrName, char* pstrIPaddress, bool ExpertModeSetting, bool PnPSetting);
	virtual ~Device();
	char* const GetIPAddress();
	::string GetconnectionDTI();
	::string GetconnectionMXI();
	 void SetConnect(bool isConnecting) ;
	inline bool IsConnecting() { return m_Isconnecting == true; };
	inline void SetError(bool IsError) { m_Error = IsError; };
	inline bool IsError() { return m_Error == true; };
	inline bool IsExpertMode() { return m_expertModeSetting == true; };
	inline bool IsPlugnPlayMode() { return m_PnPSetting == true; };
	inline int GetProcessDataWatchdogTime() { return m_processDataWatchdogTime; };

///should not be public, for the demo purpose, instead of creating get/setter just let them be public access.
	ControllerStartup DeviceControllerStartup = PhysicalConfiguration;
protected:
	char* m_Name = "FromQTAutotron";
	char* m_IPaddress = "192.168.0.1";
	bool m_expertModeSetting = false;
	bool m_PnPSetting = false;
	bool m_Isconnecting = false;
	bool m_Error = false;
	int m_processDataWatchdogTime = 0;// disable?
};
