// ModbusPhoenix.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ModbusPhoenix.h"


// This is an example of an exported variable
MODBUSPHOENIX_API int nModbusPhoenix=0;

// This is an example of an exported function.
MODBUSPHOENIX_API int fnModbusPhoenix(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ModbusPhoenix.h for the class definition
CModbusPhoenix::CModbusPhoenix()
{
    return;
}
