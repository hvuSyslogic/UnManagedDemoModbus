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