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
		return false;
	}

	WeaponManager * cWeaponManager = *(WeaponManager **)(this->Base + WEAP_OFFSET);

	if (!(cWeaponManager->pWeaponOffset))
	{
		return false;
	}
	
	if (!(cWeaponManager->pWeaponOffset->pWeaponComponent))
	{
		return false;
	}
	if (!(cWeaponManager->pWeaponOffset->pWeaponComponent->dMagAmmo));
	{
		return false;
	}

	pWeap = cWeaponManager->pWeaponOffset->pWeaponComponent;

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

		}
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
	for (int i=0; i = cGameManager->NumEntities; i ++)
	{
		Entity * curEntity = *(Entity **)(cGameManager->pEntityList + (0x08 * i));

		if (!(curEntity->pEntityRef))
		{
			continue;
		}
		if (!(curEntity->pEntityRef->pEntityInfo))
		{
			continue;
		}
		if (!(curEntity->pEntityRef->pEntityInfo->pEntityComponent))
		{
			continue;
		}
		if (!(curEntity->pEntityRef->pEntityInfo->pEntityComponent->pChildComponent	))
		{
			continue;
		}
		//check if entity alive
		if (!(curEntity->pEntityRef->pEntityInfo->pEntityComponent->pChildComponent->dEntityHealth >= 0))
		{
			continue;
		}	
		if (!(curEntity->pEntityRef->pRef))
		{
			continue;
		}	
		if (!(curEntity->pEntityRef->pRef->pPlayerInfo))
		{
			continue;
		}	
		if (!(curEntity->pEntityRef->pRef->pPlayerInfo->pPlayerName))
		{
			continue;
		}
		if (!(curEntity->pEntityRef->pRef->pPlayerInfo->pPlayerName ))
		{
			continue;
		}
		printf("Entity Name: %s\n", (char *) *curEntity->pEntityRef->pRef->pPlayerInfo->pPlayerName);
		printf("Entity Name: %c\n", curEntity->pEntityRef->pRef->pPlayerInfo->pPlayerName);



	}

}

void Hacks::Hack()
{
//if (this->Init())
//	{
	HookConsole();
	while (true)
	{

	this->Base = (DWORD_PTR)GetModuleHandleA("RainbowSix.exe");


	if (!*(WeaponManager **)(Base + WEAP_OFFSET))
	{
		printf("[!] Weapon Manager Not Found!\n");
		Sleep(1000);
		return ;
	}

	WeaponManager * cWeaponManager = *(WeaponManager **)(Base + WEAP_OFFSET);

	if (!(cWeaponManager->pWeaponOffset))
	{
		printf("[!] pWeaponOffset Not Found!\n");
		Sleep(1000);
		return ;
	}
	
	if (!(cWeaponManager->pWeaponOffset->pWeaponComponent))
	{
		printf("[!] pWeaponComponent Not Found\n!");
		Sleep(1000);
		return ;
	}

		WeaponComponent *pWeap;
		pWeap = cWeaponManager->pWeaponOffset->pWeaponComponent;


		this->Toggles(pWeap);

		pWeap->fMaxRecoil = 0;


		pWeap->fRecoil = 0;

		pWeap->fMaxSpread = 0.125;

		if (this->bFireRate)
		{
			pWeap->fFireRate = 0;
		}

		if (this->bNoReload )
		{
			pWeap->dMagAmmo = 25;
		}

		if (this->bInfiniteAmmo)
		{
			pWeap->dReserveAmmo = 250;
		}
		this->GetEntities();
		Hacks Chat;
		//this->GetMessageW();
		//this->NameManagerInit((char *) "test");
	}
}
