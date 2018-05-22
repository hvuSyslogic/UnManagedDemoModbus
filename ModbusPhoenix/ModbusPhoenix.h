// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MODBUSPHOENIX_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MODBUSPHOENIX_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MODBUSPHOENIX_EXPORTS
#define MODBUSPHOENIX_API __declspec(dllexport)
#else
#define MODBUSPHOENIX_API __declspec(dllimport)
#endif

// This class is exported from the ModbusPhoenix.dll
class MODBUSPHOENIX_API CModbusPhoenix {
public:
	CModbusPhoenix(void);
	// TODO: add your methods here.
};

extern MODBUSPHOENIX_API int nModbusPhoenix;

MODBUSPHOENIX_API int fnModbusPhoenix(void);
