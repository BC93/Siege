// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include "Vector3.h"
#include "guicon.h"
#include <crtdbg.h>
#include "Hacks.h"

#ifndef _USE_OLD_OSTREAMS
#pragma warning(suppress : 4996)
using namespace std;

#endif
#pragma warning(suppress : 4996)


#pragma warning(suppress : 4996)


void startdl();

extern "C" { int _afxForceUSRDLL; }  BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		AttachConsole(GetProcessId(hModule));
		FILE* file;
		freopen_s(&file, "CONOUT$", "w", stdout);

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&startdl, 0, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

void startdl()
{
	printf_s("[+] Successfully Injected\n");

	Hacks hack;
	while (true)
	{
		hack.Hack();
		//bool triggerBot = false;
		//bool FireRateActive = false;
		//bool tNoReload = false;

	}

}

