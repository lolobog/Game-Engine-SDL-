#pragma once
#include <iostream>
#include <debugapi.h>
#include <stdarg.h> 

extern int g_verbosity;

int VDebugPrintF(const char* format, va_list argList)
{
	const unsigned int MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];

	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, argList);
	OutputDebugStringA(s_buffer);

	return charsWritten;
	
}

int DebugPrintF(const char* format)
{
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;
}
enum Verbosity
{
	None,
	Error,
	Warning,
	Info,
	All
};

int VerboseDebugPrintF(int verbosity, const char* format)
{
	if (g_verbosity < verbosity)
	{
		return 0;
	}

	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);

	va_end(argList);

	return charsWritten;

}

