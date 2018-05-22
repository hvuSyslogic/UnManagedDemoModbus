#pragma once

#ifndef QTGLOBALINFO_H
#define QTGLOBALINFO_H
#endif
#include <stdio.h>
#include <windows.h>
#include "Device.h"
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
