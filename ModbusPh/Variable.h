#pragma once
#include <string>
#include <cmath>
#include <limits>
#include <memory>
#include <functional>
#include "stringhelper.h"
//function handler return void and has one parameter as void*
using VarChangeHandler = std::function<void(std::shared_ptr<void> Sender)>;

enum VarType
{
	Unknown,
	Boolean,
	UInt64,
	ByteArray,
};
enum PD_Length
{
	Byte = 1,
	Word = 2,
	DWord = 4,
	LWord = 8,
};
class Variable
{
private:
	int _maxVariableLength = 64;
public:
	std::string _name;
	std::string _controllerName;
	int _baseAddress = 0;
	int _length = 0;
	int _byteLength = 0;
	int _bitOffset = 0;
	VarType *_varType = NULL;
private:
	unsigned long long _maxValue = 0;
	unsigned long long _minValue = 0;
	VarChangeHandler _hdVarChange = NULL;
public:
	virtual ~Variable()
	{
		if (_varType != NULL)
		{
			delete _varType;
		}
		_varType = NULL;
		if (&_hdVarChange != NULL)
		{
			delete &_hdVarChange;
		}
	}

	Variable(int p_baseAddress, PD_Length *pSize, int pLength, int pBitOffset, const std::string &pName);
	Variable();

	void AssignController(const std::string &ControllerName);
private:
	void CalcMinMaxRange();
public:
	void CallVarChangeEvent(void *Sender);
	bool getOnChangeEventValid() const;
	int CompareTo(std::shared_ptr<Variable> obj);
private:
	int CompareBitOffset(Variable *var);
	int CompareVarType(Variable *var);
	int CompareByteLenght(Variable *var);
	int CompareLenght(Variable *var);
};
