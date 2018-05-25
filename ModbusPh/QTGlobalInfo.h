#pragma once

#ifndef QTGLOBALINFO_H
#define QTGLOBALINFO_H

#include <stdio.h>
#include <windows.h>
#include "Device.h"

typedef struct {
	unsigned short length;
	/* Amount of data to be read in bytes */
	unsigned short address;
	/* Address in the DTI area (byte address) */
	unsigned short dataCons;
	/* Desired data consistency area */
	unsigned char *data;
	/* Pointer to the data (read and
	write) */
} T_DDI_DTI_ACCESS;
typedef void(*QTDNDDIGETVERSION)(PSZ, int);
class QTGlobalInfo
{
public:
	~QTGlobalInfo();
	static QTGlobalInfo& Instance();
	Device* TheDevicePtr;
	BOOL Initialize(std::string DllName);
	inline HINSTANCE GetHandler() { return hinstLib; };
	std::string CopyConfToFwInfo(char* data, int fromWord, int toWord);

private:
	QTGlobalInfo() { hinstLib = NULL; TheDevicePtr = NULL; }; //prevent construction from outside this class' methods
	QTGlobalInfo& operator=(const QTGlobalInfo&) {}; //prevent assignment
	QTGlobalInfo(const QTGlobalInfo&) {}; //prevent copy construction
	HINSTANCE hinstLib;
};
#endif