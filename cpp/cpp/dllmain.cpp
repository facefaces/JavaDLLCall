#include "pch.h"

#ifndef DLLEXPORT
#define DLLEXPORT extern "C" __declspec(dllexport)
#endif

using namespace System;
using namespace System::Runtime::InteropServices;

using namespace ClassLibrary1;


class Agent
{
private:
	IntPtr handle;
	char* str = NULL;
public:
	Agent()
	{
		Class1^ obj = gcnew Class1();
		handle = static_cast<IntPtr>(GCHandle::Alloc(obj));
	}
	~Agent()
	{
		if (str != NULL)
		{
			Marshal::FreeHGlobal(IntPtr(str));
		}
		static_cast<GCHandle>(handle).Free();
	}
	
	Class1^ GetInstance()
	{
		return safe_cast<Class1^>(static_cast<GCHandle>(handle).Target);
	}

	char* ConvertString(String^ input_string)
	{
		if (str != NULL)
		{
			Marshal::FreeHGlobal(IntPtr(str));
		}
		str = (char*)(void*)Marshal::StringToHGlobalAnsi(input_string);
		return str;
	}

	int AddBaudRate(int a)
	{
		return GetInstance()->AddBaudRate(a);
	}

	char* GetName()
	{
		String^ name = GetInstance()->GetName();
		return ConvertString(name);
	}

	char* SetName(char* name)
	{
		String^ str_name = gcnew String(name);
		String^ result = GetInstance()->SetName(str_name);
		return ConvertString(result);
	}
};


DLLEXPORT Agent* CreateObject()
{
	return new Agent();
}


DLLEXPORT int AddBaudRate(Agent *self, int a)
{
	return self->AddBaudRate(a);
}

DLLEXPORT char* GetName(Agent* self)
{
	return self->GetName();
}

DLLEXPORT char* SetName(Agent* self, char *name)
{
	return self->SetName(name);
}