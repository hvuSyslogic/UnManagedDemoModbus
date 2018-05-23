#include "Device.h"

Device::Device()
{
}

Device::Device(string Name, string pstrIPaddress, bool ExpertModeSetting, bool PnPSetting)
{
}

Device::Device(char * pstrName, char * pstrIPaddress, bool ExpertModeSetting, bool PnPSetting)
{
}

Device::~Device()
{
}

char * const Device::GetIPAddress()
{
	return m_IPaddress;
}

string Device::GetconnectionDTI()
{
	string connectionDTI("IBETHIP[");
	string ipAddress(m_IPaddress);
	connectionDTI += ipAddress;
	connectionDTI += "]N1_D";

	return connectionDTI;
}

string Device::GetconnectionMXI()
{
	string connectionDTI("IBETHIP[");
	string ipAddress(m_IPaddress);
	connectionDTI += ipAddress;
	connectionDTI += "]N1_M";

	return connectionDTI;
}
void Device::SetConnect(bool isConnecting)
{
	m_Isconnecting = isConnecting;
}
