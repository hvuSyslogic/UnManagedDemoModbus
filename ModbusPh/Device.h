#pragma once
#include <iostream>
using namespace std;
class Device
{
public:
	Device();
	Device(string Name, string pstrIPaddress, bool ExpertModeSetting, bool PnPSetting);
	Device(char* pstrName, char* pstrIPaddress, bool ExpertModeSetting, bool PnPSetting);
	virtual ~Device();
	char* const GetIPAddress();
	inline bool IsExpertMode() { return m_expertModeSetting == true; }
	inline bool IsPlugnPlayMode() { return m_PnPSetting == true; }
	inline int GetProcessDataWatchdogTime() { return m_processDataWatchdogTime; }
protected:
	char* m_Name = "FromQTAutotron";
	char* m_IPaddress = "192.168.0.1";
	bool m_expertModeSetting = false;
	bool m_PnPSetting = false;
	int m_processDataWatchdogTime = 0;// disable?
};
