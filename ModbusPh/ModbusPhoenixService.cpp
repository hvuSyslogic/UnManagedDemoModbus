#include <stdio.h>
#include <windows.h>

#include "ModbusPhoenixService.h"
#include "QTGlobalInfo.h"
typedef void( *DN_DDI_GETVERSION)(char*, int);
typedef  int (*DNQT_DDI_DTI_READDATA)(unsigned int, int, int, int, byte*);
typedef  unsigned short (WINAPI *DN_DDI_DEVOPENNODE)(char[], unsigned short, unsigned int*);
typedef void(WINAPI *DN_DDI_DEVCLOSENODE)(unsigned int);
typedef  unsigned short (WINAPI *DN_DDI_DTI_READDATA)(unsigned int, T_DDI_DTI_ACCESS*);
typedef  unsigned short (WINAPI *DN_DDI_DTI_WRITEDATA)(unsigned int, T_DDI_DTI_ACCESS*);


int main()
{
	HINSTANCE hinstLib;
	DN_DDI_GETVERSION ProcAdd;
	DN_DDI_DEVOPENNODE ProcOPen;
	DN_DDI_DEVCLOSENODE ProcClose;
	DN_DDI_DTI_READDATA  ProcReadData;
	DN_DDI_DTI_WRITEDATA  ProcWriteData;
	DNQT_DDI_DTI_READDATA dnProcReadData;
	BOOL  fRunTimeLinkSuccess = FALSE;
	int bufferSize = 100, Result = 0;
	unsigned int handlerValue = 0;
	unsigned short returnValue = 0;
	const unsigned short MaxSize = 512;
	char tab2[MaxSize]{ 0 }; // holder for str pass in parameter
	char	hex[8]; //Used for char to Hex conversion
	T_DDI_DTI_ACCESS dtiAcc;
	unsigned char iBuf[8] ;
	dtiAcc.length = 8;
	dtiAcc.address = 2;
	dtiAcc.data = iBuf;
	dtiAcc.dataCons = 1;
	BOOL fFreeResult;
	byte* Buffer;
	// Get a handle to the DLL module.

	hinstLib = LoadLibrary("dn2ddi");
	QTGlobalInfo::Instance().Initialize("Ibddiwnt"); //("dn2ddi");
	// If the handle is valid, try to get the function address.

	if (QTGlobalInfo::Instance().GetHandler() != NULL)
	{
		PSZ p_buffer = new char[bufferSize];
		Buffer = new byte[9];
		ProcAdd = (DN_DDI_GETVERSION)GetProcAddress(hinstLib, "DN_DDI_GetVersion");
		ProcOPen = (DN_DDI_DEVOPENNODE)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DDI_DevOpenNode");
		ProcClose = (DN_DDI_DEVCLOSENODE)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DDI_DevCloseNode");
		ProcReadData = (DN_DDI_DTI_READDATA)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DDI_DTI_ReadData");
		ProcWriteData = (DN_DDI_DTI_WRITEDATA)GetProcAddress(QTGlobalInfo::Instance().GetHandler(), "DDI_DTI_WriteData");
		dnProcReadData = (DNQT_DDI_DTI_READDATA)GetProcAddress(hinstLib, "DN_DDI_DTI_ReadData");
		// If the function address is valid, call the function.
		if (QTGlobalInfo::Instance().TheDevicePtr == NULL)
			QTGlobalInfo::Instance().TheDevicePtr = new Device();
	   strncpy_s(tab2, QTGlobalInfo::Instance().TheDevicePtr->GetconnectionDTI().c_str(), sizeof(tab2));
		tab2[sizeof(tab2) - 1] = 0;
		if (fRunTimeLinkSuccess = (ProcOPen != NULL))
		{
			(ProcAdd)(p_buffer, bufferSize);
			Sleep(1000);
			returnValue= (ProcOPen)(tab2,3, &handlerValue);
			_itoa_s(returnValue, hex, 16);
			//Result = (dnProcReadData)(handlerValue, 8, 2, 1, Buffer);
			returnValue = (ProcReadData)(handlerValue, &dtiAcc);
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
