#include <stdio.h>
#include <windows.h>
#include "ModbusPhoenixService.h"
#include "QTGlobalInfo.h"
typedef void(*MYPROC)(PSZ, int);
int main()
{
	//HINSTANCE hinstLib;
	MYPROC ProcAdd;
	BOOL  fRunTimeLinkSuccess = FALSE;
	int bufferSize = 100;
	PSZ p_buffer = new char[bufferSize];
	// Get a handle to the DLL module.

	QTGlobalInfo::Instance().Initialize("dn2ddi");

	// If the handle is valid, try to get the function address.

	if (QTGlobalInfo::Instance().GetHandler() != NULL)
	{
		ProcAdd = (MYPROC)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DN_DDI_GetVersion");

		// If the function address is valid, call the function.

		if (fRunTimeLinkSuccess = (ProcAdd != NULL))
			(ProcAdd) (p_buffer, bufferSize);

		// Free the DLL module

		//fFreeResult = FreeLibrary(QTGlobalInfo::Instance().hinstLib);
	} 	return 0;
}

ModbusPhoenixService::ModbusPhoenixService()
{
	m_actualState = Idle;
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