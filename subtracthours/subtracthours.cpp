// subtracthours.cpp : Defines the exported functions for the DLL application.
//

#include <stdafx.h>
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, time, localtime, asctime */
#include <string.h>
#include <cstdlib>

extern "C" 
{ 
	__declspec (dllexport) void __stdcall RVExtension(char *output, int outputSize, const char *function); 
}

void __stdcall RVExtension(char *output, int outputSize, const char *function)
{ 

	/*datetimelocked="["date", 07, 11, 2013, 18, 50, 10]"*/


	time_t rawtime, _mktime_res;
	struct tm timeinfo;
	errno_t _err;
	int _year, _month, _day, _hour, _minute, _seconds, _time_err;
	char outputBuff[40];
	int buffUsed = 0;
	int _numHours = 0;


	_time_err = 0;
	_year = 0;
	_month = 0;
	_day = 0;
	_hour = 0;
	_minute = 0;
	_seconds = 0;
	_numHours = atoi(function);

	_time64(&rawtime);
	_err = localtime_s(&timeinfo, &rawtime);
	if (_err)
	{
		_time_err = 1;
	}
	else
	{
		timeinfo.tm_hour = timeinfo.tm_hour - (_numHours);

		if ((_mktime_res = mktime(&timeinfo)) != (time_t)-1)
		{

			_year = timeinfo.tm_year + 1900;
			_month = timeinfo.tm_mon + 1;
			_day = timeinfo.tm_mday;
			_hour = timeinfo.tm_hour;
			_minute = timeinfo.tm_min;
			_seconds = timeinfo.tm_sec;

		}
		else
		{
			_time_err = 1;
		}
	}

	buffUsed = _snprintf_s(&outputBuff[0], 40, _TRUNCATE, "[ %i, %i, %i, %i, %i, %i, %i ];", _time_err, _day, _month, _year, _hour, _minute, _seconds);
	outputBuff[buffUsed] = 0;
	printf("Result is: %s\n", outputBuff);

	strncpy_s(output, outputSize, outputBuff, _TRUNCATE); 
}