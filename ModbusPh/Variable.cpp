#include "Variable.h"

Variable::Variable(int p_baseAddress, PD_Length* pSize, int pLength, int pBitOffset, const std::string &pName)
{
	if (p_baseAddress < 0 || pLength <= 0 || (pLength > static_cast<int>(*pSize) * 8 || pLength > this->_maxVariableLength) || (pBitOffset < 0 || pBitOffset > static_cast<int>(*pSize) * 8 - 1 || pBitOffset + pLength > static_cast<int>(*pSize) * 8))
	{
		this->_baseAddress = 0;
		this->_length = 0;
		this->_bitOffset = 0;
		*_varType = VarType::Unknown;
	}
	else
	{
		this->_baseAddress = p_baseAddress;
		this->_length = pLength;
		this->_bitOffset = pBitOffset;
		*_varType = this->_length != 1 ? VarType::UInt64 : VarType::Boolean;
		this->CalcMinMaxRange();
		this->_byteLength = static_cast<int>(*pSize);
		if (pName != "Input" && pName != "Output")
		{
			this->_name = pName;
		}
		else
		{
			this->_name = StringHelper::formatSimple("{0} {1}.{2}", pName, std::to_string(this->_baseAddress), std::to_string(this->_bitOffset));
		}
	}
}


void Variable::AssignController(const std::string &ControllerName)
{
	this->_controllerName = ControllerName;
}

void Variable::CalcMinMaxRange()
{
	this->_maxValue = this->_length > 63 ? std::numeric_limits<unsigned long long>::max() : static_cast<unsigned long long>(std::pow(2.0, static_cast<double>(this->_length)) - 1.0);
	this->_minValue = 0ULL;
}

void Variable::CallVarChangeEvent(void * Sender)
{
	if (this->_hdVarChange == nullptr)
	{
		return;
	}
	std::shared_ptr<void> newSender(Sender);
	this->_hdVarChange(newSender);
}

bool Variable::getOnChangeEventValid() const
{
	return this->_hdVarChange != nullptr;
}

int Variable::CompareTo(std::shared_ptr<Variable> obj)
{
	if (this->_baseAddress > obj->_baseAddress)
	{
		return 1;
	}
	if (this->_baseAddress < obj->_baseAddress)
	{
		return -1;
	}
	return this->CompareBitOffset(obj.get());
}

int Variable::CompareBitOffset(Variable* var)
{
	if (this->_bitOffset > var->_bitOffset)
	{
		return 1;
	}
	if (this->_bitOffset < var->_bitOffset)
	{
		return -1;
	}
	return this->CompareVarType(var);
}

int Variable::CompareVarType(Variable* var)
{
	int num = this->_varType == (var->_varType);
	if (num == 0)
	{
		return this->CompareByteLenght(var);
	}
	return num;
}

int Variable::CompareByteLenght(Variable* var)
{
	if (this->_byteLength > var->_byteLength)
	{
		return 1;
	}
	if (this->_byteLength < var->_byteLength)
	{
		return -1;
	}
	return this->CompareLenght(var);
}

int Variable::CompareLenght(Variable* var)
{
	if (this->_length > var->_length)
	{
		return 1;
	}
	return this->_length < var->_length ? -1 : 0;
}
