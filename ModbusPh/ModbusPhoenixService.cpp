#include <stdio.h>
#include <windows.h>

#include "ModbusPhoenixService.h"
#include "QTGlobalInfo.h"
typedef void(*DN_DDI_GETVERSION)(char*, int);
typedef int(*DN_DDI_DEVOPENNODE)(char[], int, int*);
typedef void(*DN_DDI_DEVCLOSENODE)(int);


int main()
{
	HINSTANCE hinstLib;
	DN_DDI_GETVERSION ProcAdd;
	DN_DDI_DEVOPENNODE ProcOPen;
	DN_DDI_DEVCLOSENODE ProcClose;
	BOOL  fRunTimeLinkSuccess = FALSE;
	int bufferSize = 100;
	int handlerValue = 0;
	int returnValue = 0;
	char tab2[1024]; // holder for str pass in parameter
	char		  hex[9]; //Used for char to Hex conversion
	BOOL fFreeResult;
	// Get a handle to the DLL module.

	hinstLib = LoadLibrary("Ibddiwnt");
	QTGlobalInfo::Instance().Initialize("dn2ddi"); //("dn2ddi");
	// If the handle is valid, try to get the function address.

	if (QTGlobalInfo::Instance().GetHandler() != NULL)
	{
		PSZ p_buffer = new char[bufferSize];
		ProcAdd = (DN_DDI_GETVERSION)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DN_DDI_GetVersion");
		ProcOPen = (DN_DDI_DEVOPENNODE)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DN_DDI_DevOpenNode");
		ProcClose = (DN_DDI_DEVCLOSENODE)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DN_DDI_DevCloseNode");
		// If the function address is valid, call the function.
		if (QTGlobalInfo::Instance().TheDevicePtr == NULL)
			QTGlobalInfo::Instance().TheDevicePtr = new Device();
	   strncpy_s(tab2, QTGlobalInfo::Instance().TheDevicePtr->GetconnectionDTI().c_str(), sizeof(tab2));
		tab2[sizeof(tab2) - 1] = 0;
		if (fRunTimeLinkSuccess = (ProcOPen != NULL))
		{
			(ProcAdd)(p_buffer, bufferSize);
			Sleep(2000);
			returnValue= (ProcOPen)(tab2,3, &handlerValue);
			_itoa_s(returnValue, hex, 16);
			Sleep(2000);
			(ProcClose)(handlerValue);

		}
		// Free the DLL module

		fFreeResult = FreeLibrary(hinstLib);
		delete[] p_buffer;
	} 	return 0;
}

ModbusPhoenixService::ModbusPhoenixService()
{
	m_actualState = Idle;
	m_currentDriverstate = DriverInactive;
}

void ModbusPhoenixService::Setvar(int val)
{
}

int ModbusPhoenixService::Getvar()
{
	return 0;
}

ModbusPhoenixService::~ModbusPhoenixService()
{
}

bool ModbusPhoenixService::Enable()
{
	return false;
}
