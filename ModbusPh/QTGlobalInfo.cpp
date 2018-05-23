#include "QTGlobalInfo.h"

QTGlobalInfo::~QTGlobalInfo()
{
	BOOL fFreeResult = FALSE;
	if (TheDevicePtr != NULL)
		delete TheDevicePtr;
	TheDevicePtr = NULL;
	if (hinstLib != NULL)
		fFreeResult = FreeLibrary(hinstLib);
	hinstLib = NULL;
}

QTGlobalInfo & QTGlobalInfo::Instance()
{
	// TODO: insert return statement here
	static QTGlobalInfo instance; //create as a static object, i.e. will only be created once.
	return instance;
}

BOOL QTGlobalInfo::Initialize(std::string DllName)
{
	hinstLib = LoadLibrary(DllName.c_str());
	return (hinstLib != NULL);
}

std::string QTGlobalInfo::CopyConfToFwInfo(char* data, int fromWord, int toWord)
{
	std::string SourceString(data);
	return SourceString.substr(fromWord, toWord - fromWord);
}