#include "stdafx.h"
#include "Hacks.h"
#include "Structs.h"
#include "Vector3.h"
#include "Hacks.h"
#include <Windows.h>
#include <tlhelp32.h>
#include <string>
#include <iostream>       // used for std::cout, std::endl
#include <thread>         // used for std::this_thread::sleep_for
#include <chrono>         // used for std::chrono::seconds
#include <stdlib.h>
#include <cstring>
#include <vector>

void HookConsole()
{
	AllocConsole();
	FILE* file;
	freopen_s(&file, "CONOUT$", "w", stdout);
}
bool Hacks::Init()
{
	this->Base = (DWORD_PTR)GetModuleHandleA("RainbowSix.exe");

	if (!*(WeaponManager **)(this->Base + WEAP_OFFSET))
	{
		printf("[!] cWeaponManager Failed!\n");
		return false;
	}

	this->cWeaponManager = *(WeaponManager **)(this->Base + WEAP_OFFSET);

	if (!(this->cWeaponManager->pWeaponOffset))
	{
		printf("[!] pWeaponOffset Failed\n");
		return false;
	}
	
	if (!(this->cWeaponManager->pWeaponOffset->pWeaponComponent))
	{
		printf("[!] pWeaponComponent Failed!\n");
		return false;
	}

	this->pWeap = cWeaponManager->pWeaponOffset->pWeaponComponent;

	return true;
}

void Hacks::Toggles(WeaponComponent *pWeap)
{
	if (GetAsyncKeyState(VK_NUMPAD1))
	{
		printf_s("[+] Infinite Ammo Activated\n");
		this->bInfiniteAmmo = !bInfiniteAmmo;


		Sleep(200);
	}

	if (GetAsyncKeyState(VK_NUMPAD2))
	{
		printf_s("[+] No Reload Activated\n");
		this->bNoReload = !bNoReload;
		
		Sleep(200);
	}

	if (GetAsyncKeyState(VK_NUMPAD3))
	{
		printf_s("[+] Fast Fire Rate Activated\n");
		this->bFireRate = !bFireRate;

		Sleep(200);
	}
	if (GetAsyncKeyState(VK_NUMPAD4))
	{
		printf("NUMPAD 4 Pressed\n");
		switch (this->dFireMode)
		{
		case 0:
			pWeap->bFireMode = 1;


		case 1:
			pWeap->bFireMode = 2;

		case 2:
			pWeap->bFireMode = 3;

		case 3:
			pWeap->bFireMode = 0;
			Sleep(200);

		}
	}
				if (GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_SHIFT))
				{
					printf("Up Pressed\n");
					this->sMagAmmo = this->sMagAmmo + 10;

					Sleep(100);

					return;
				}
				if (GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_SHIFT))
				{
					this->sMagAmmo = sMagAmmo - 10;
					printf("Down Pressed\n");

					Sleep(100);

					return;
				}
				if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_SHIFT) )
				{
					this->fFov = this->fFov + 5;

					printf("Right Pressed\n");
					this->SetFOV();

					Sleep(100);

					return;
				}
				if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_SHIFT))
				{
					printf("Left Pressed\n");
					this->fFov = this->fFov - 5;

					this->SetFOV();

					Sleep(100);

					return;
				}
			
			if (GetAsyncKeyState(VK_UP))
			{
				printf("Up Pressed\n");
				this->fSpreadVal = this->fSpreadVal + .10;

				Sleep(100);

				return;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				printf("Down Pressed\n");
				this->fSpreadVal= 0.2;

				Sleep(100);

				return;
			}

}
void Hacks::NameManagerInit(char * name)
{

	if (!*(NameEngine**)(this->Base + NAME_OFFSET))
	{
		return;
	}
	NameEngine * cNameEngine = *(NameEngine **)(this->Base + NAME_OFFSET);
	if (!(cNameEngine->pRef->pRef->pRef->pNameChange))
	{
		return;
	}
	this->cNameManager = cNameEngine->pRef->pRef->pRef->pNameChange;
	
	//*cNameEngine->pRef->pRef->pRef->pNameChange->cName = (CHAR*)"test\0";
}

void Hacks::GetMessage()
{
	this->Base = (DWORD_PTR)GetModuleHandleA("RainbowSix.exe");
	if (!*(ChatEngine**)(Base + CHAT_OFFSET))
	{
		return;
	}
	ChatEngine *cChatEngine = *(ChatEngine **)(Base + CHAT_OFFSET);

	if (! (cChatEngine->pChatManager))
	{
		return;
	}

	//printf("[+] Chat: %s\n", cChatEngine->pChatManager->cMessage);
	char isCommand[] = "/";
	int next = 0;
	if ( *cChatEngine->pChatManager->cMessage == *isCommand)
	{
		ChatCommand sCommand;
		char * pch;
		printf("[+] Chat Command Received: %c\n",*cChatEngine->pChatManager->cMessage);
		char *sMessage = cChatEngine->pChatManager->cMessage;
		std::string delimeter = " ";
		printf("Message: %s\n", sMessage);
		size_t pos = 0;
		std::string token;
		int count = 0;
		printf("[-] DEBUG - Processing Command:%s\n",sMessage );
		Sleep(1000);
		

		pch = strtok(sMessage, " ");
		while (pch != NULL)
		{
			count++;
			if (pch == "/set")
			{
				pch = strtok(NULL, " ");
				printf("Debug: /set");
			}
			if (pch == "name")
			{
				next = 1;
				printf("Debug: command = name");
				pch = strtok(NULL, " ");
			}
			if (count == 3)
			{
					printf("================ Chat Command Received ==============\n");
					printf("[+] Setting Name To: %c\n", *pch);
					printf("[+] Setting Name To: %c\n", pch);
					printf("[+] Setting Name To: %s\n", &pch);
					//this->NameManagerInit(pch);

			}
		}


	}
	return;
}

void Hacks::GetEntities()
{
	if (!*((GameManager **)(this->Base + OFFSET_GAMEMANAGER)))
	{
		return;
	}
	GameManager * cGameManager = *(GameManager **)(this->Base + OFFSET_GAMEMANAGER);
	if (!cGameManager->pEntityList)
	{
		return;
	}
	

}

void Hacks::SetFOV()
{
	if (!*(FovManager **)(this->Base + OFFSET_FOV))
	{
		return;
	}
	FovManager * cFovManager = *(FovManager **)(this->Base + OFFSET_FOV);

	cFovManager->fFOV_1 = this->fFov;

	cFovManager->fFOV_2 = this->fFov;
}

void Hacks::Hack()
{
//if (this->Init())
//	{
	HookConsole();
	while (true)
	{
		bool inGame;
		inGame = this->Init();
		while (inGame == false)
		{
			inGame = this->Init();
			printf("[-----------------] Not in Game or Dead!\n");
			Sleep(1000);
		}
		if (inGame == true)
		{

		this->Toggles(pWeap);

		this->SetFOV();
		pWeap->fMaxRecoil = 0;


		pWeap->fRecoil = 0;

		this->pWeap->fMaxSpread = fSpreadVal;
		this->pWeap->vSpread.x = fSpreadVal;
		this->pWeap->vSpread.y = fSpreadVal;
		this->pWeap->vSpread.z = fSpreadVal;

		if (this->bFireRate)
		{
			pWeap->fFireRate = 0;
		}

		if (this->bNoReload )
		{
			pWeap->dMagAmmo = this->sMagAmmo;
		}

		if (this->bInfiniteAmmo)
		{
			pWeap->dReserveAmmo = 250;
		}

		//this->GetEntities();
		//Hacks Chat;
		//this->GetMessageW();
		//this->NameManagerInit((char *) "test");
	}
	}
}
