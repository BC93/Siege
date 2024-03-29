#pragma once
#include "Vector3.h"
#include <string>



class WeaponManager;
class WeaponOffset_0;
class WeaponOffset_1;
class WeaponOffset_2;
class WeaponComponent;
class GameStatus;
class TriggerManager;
class TriggerOffset_0;
class TriggerComponent;

class WeaponManager
{
public:
private:
	char pad_0x0000[0x20]; //0x0000
public:
	WeaponOffset_0 * pRef; //0x0020 

}; //Size=0x0028

class WeaponOffset_0
{
public:
private:
	char pad_0x0000[0xE0]; //0x0000
public:
	WeaponOffset_1 * pRef; //0x00E0 

}; //Size=0x00E8

class WeaponOffset_1
{
public:
private:
	char pad_0x0000[0x120]; //0x0000
public:
	WeaponOffset_2 * pRef; //0x0120 

}; //Size=0x0128

class WeaponOffset_2
{
public:
private:
	char pad_0x0000[0x110]; //0x0000
public:
	WeaponComponent * pWeaponComponent; //0x0110 

}; //Size=0x0118

class WeaponComponent
{
public:
private:
	char pad_0x0000[0x70]; //0x0000
public:
	float fSpread; //0x0070 
private:
	char pad_0x0074[0x34]; //0x0074
public:
	float fRecoil; //0x00A8 
private:
	char pad_0x00AC[0x10]; //0x00AC
public:
	Vector3 vRecoil; //0x00BC 
private:
	char pad_0x00C8[0x34C]; //0x00C8

}; //Size=0x0414
class GameStatus
{
public:
private:
	char pad_0x0000[0x38C]; //0x0000
public:
	DWORD bInGame; //0x038C 
private:
	char pad_0x0390[0x4B4]; //0x0390

}; //Size=0x0844


class TriggerManager
{
public:
private:
	char pad_0x0000[0x400]; //0x0000
public:
	TriggerOffset_0 * pRef; //0x0400 

}; //Size=0x0408

class TriggerOffset_0
{
public:
private:
	char pad_0x0000[0x398]; //0x0000
public:
	TriggerComponent * pTriggerComponent; //0x0398 

}; //Size=0x03A0

class TriggerComponent
{
public:
private:
	char pad_0x0000[0x1F4]; //0x0000
public:
	DWORD dTrigger; //0x01F4 
private:
	char pad_0x01F8[0x214]; //0x01F8

}; //Size=0x040C


class WeaponComponent;
class WeaponManager;
class WeaponOffset;
class Entity;
class EntityRef;
class EntityInfo;
class EntityComponent;
class ChildComponent;
class NameEngine;
class NameRef_1;
class NameRef_2;
class NameRef_3;
class NameChange;
class GameManager;
class EntityList;
class LocalPlayerManager;
class LocalPlayerRef_1;
class LocalPlayerRef_2;
class LocalPlayerRef_3;
class LocalPlayer;
class PlayerInfoRef;
class PlayerName;
class PlayerInfo;
class ChatEngine;
class ChatManager;
class NetManager;
class NetEntities_pRef_1;
class NetEntities_pRef_2;
class NetEntities;
class FovManager;

class Hacks
{
public:
	GameStatus * cGameStatus;
	TriggerManager * cTriggerManager;
	char cName[10];
	NameChange *cNameManager; 
	bool bFireRate = false;
	bool bNoReload = false;
	bool bInfiniteAmmo = false;
	bool bTriggerBot = false;
	float fFov = 100;
	float fSpreadVal = 0.5;
	DWORD sMagAmmo = 25;
	DWORD_PTR Base;
	WeaponManager *cWeaponManager;
	WeaponComponent *pWeap;
	Entity * EntityLocalPlayer;
	BYTE dFireMode;
	void SetFOV();
	bool Init();
	void NameManagerInit(char* name);
	void GetEntities();
	void GetNetEntities();
	void Toggles(WeaponComponent *pWeap);
	void Hack();
	char Message[20];
	void GetMessage();
	void Command();
	bool GetWeap();
	bool GetTrigger();
};

class FovManager
{
public:
private:
	char pad_0x0000[0x418]; //0x0000
public:
	float fFOV_1; //0x0418 
private:
	char pad_0x041C[0x48C]; //0x041C
public:
	float fFOV_2; //0x08A8 

}; //Size=0x08AC

class NetManager
{
public:
private:
	char pad_0x0000[0xB0]; //0x0000
public:
	NetEntities_pRef_1 * pRef; //0x00B0 
private:
	char pad_0x00B8[0x8]; //0x00B8

}; //Size=0x00C0

class NetEntities_pRef_1
{
public:
private:
	char pad_0x0000[0x8]; //0x0000
public:
	NetEntities_pRef_2 * pRef; //0x0008 

}; //Size=0x0010

class NetEntities_pRef_2
{
public:
private:
	char pad_0x0000[0x118]; //0x0000
public:
	NetEntities * pNetEntities; //0x0118 

}; //Size=0x0120

class NetEntities
{
public:
private:
	char pad_0x0000[0x3C08]; //0x0000

}; //Size=0x3C08

struct ChatCommand
{
	std::string Modifier;
	std::string Module; 
	CHAR Target[10];
};
/*
class WeaponComponent
{
public:
private:
	char pad_0x0000[0x148]; //0x0000
public:
	unsigned char bFireMode; //0x0148 
private:
	char pad_0x0149[0x27]; //0x0149
public:
	DWORD dMagAmmo; //0x0170 
	DWORD dReserveAmmo; //0x0174 
private:
	char pad_0x0178[0x108]; //0x0178
public:
	Vector3 vSpread; //0x0280 
private:
	char pad_0x028C[0x24]; //0x028C
public:
	float fMaxSpread; //0x02B0 
private:
	char pad_0x02B4[0x24]; //0x02B4
public:
	float fMaxRecoil; //0x02D8 
private:
	char pad_0x02DC[0xC]; //0x02DC
public:
	float fRecoil; //0x02E8 
private:
	char pad_0x02EC[0x37C]; //0x02EC
public:
	float fFireRate; //0x0668 
private:
	char pad_0x066C[0x1D4]; //0x066C


}; //Size=0x0840

 */
/*{
public:
private:
	char pad_0x0000[0x148]; //0x0000
public:
	unsigned char bFireMode; //0x0148 
private:
	char pad_0x0149[0x27]; //0x0149
public:
	DWORD dMagAmmo; //0x0170 
	DWORD dReserveAmmo; //0x0174 
private:
	char pad_0x0178[0x138]; //0x0178
public:
	float fMaxSpread; //0x02B0 
private:
	char pad_0x02B4[0x24]; //0x02B4
public:
	float fMaxRecoil; //0x02D8 
private:
	char pad_0x02DC[0xC]; //0x02DC
public:
	float fRecoil; //0x02E8 
private:
	char pad_0x02EC[0x37c]; //0x02EC
public:
	float fFireRate; //0x0664 

}; //Size=0x0668
*/
/*class WeaponManager
{
public:
private:
	char pad_0x0000[0x20]; //0x0000
public:
	WeaponOffset * pWeaponOffset; //0x0020 
private:
	char pad_0x0028[0x18]; //0x0028

}; //Size=0x0040

class WeaponOffset
{
public:
private:
	char pad_0x0000[0xC8]; //0x0000
public:
	WeaponComponent * pWeaponComponent; //0x00C8 

}; //Size=0x00D0
*/
class Entity
{
public:
private:
	char pad_0x0000[0x20]; //0x0000
public:
	EntityRef * pEntityRef; //0x0020 
private:
	char pad_0x0028[0x808]; //0x0028

}; //Size=0x0830

class EntityRef
{
public:
private:
	char pad_0x0000[0x18]; //0x0000
public:
	EntityInfo * pEntityInfo; //0x0018 
private:
	char pad_0x0020[0x140]; //0x0020
public:
	Vector3 vCoords; //0x0160 
private:
	char pad_0x016C[0x134]; //0x016C
public:
	PlayerInfoRef * pRef; //0x02A0 
private:
	char pad_0x02A8[0x568]; //0x02A8

}; //Size=0x0810

class EntityInfo
{
public:
private:
	char pad_0x0000[0xA8]; //0x0000
public:
	EntityComponent * pEntityComponent; //0x00A8 
private:
	char pad_0x00B0[0x358]; //0x00B0

}; //Size=0x0408

class EntityComponent
{
public:
private:
	char pad_0x0000[0x8]; //0x0000
public:
	ChildComponent * pChildComponent; //0x0008 
private:
	char pad_0x0010[0x3F8]; //0x0010

}; //Size=0x0408

class ChildComponent
{
public:
private:
	char pad_0x0000[0x138]; //0x0000
public:
	DWORD dEntityHealth; //0x0138 
private:
	char pad_0x013C[0x2FC]; //0x013C

}; //Size=0x0438

class NameEngine
{
public:
	NameRef_1 * pRef; //0x0000 
private:
	char pad_0x0008[0x38]; //0x0008

}; //Size=0x0040

class NameRef_1
{
public:
	NameRef_2 * pRef; //0x0000 

}; //Size=0x0008

class NameRef_2
{
public:
	NameRef_3 * pRef; //0x0000 

}; //Size=0x0008

class NameRef_3
{
public:
private:
	char pad_0x0000[0x60]; //0x0000
public:
	NameChange * pNameChange; //0x0060 

}; //Size=0x0068

class NameChange
{
public:
private:
	char pad_0x0000[0xC]; //0x0000
public:
	char cName[10]; //0xB43B49C0 

}; //Size=0x0016

class GameManager
{
public:
private:
	char pad_0x0000[0xB8]; //0x0000
public:
	EntityList * pEntityList; //0x00B8 
	DWORD NumEntities; //0x00C0 
private:
	char pad_0x00C4[0x44]; //0x00C4

}; //Size=0x0108

class EntityList
{
public:
	Entity * pEntity_1; //0x0000 
	Entity* pEntity_2; //0x0008 
	Entity* pEntity_3; //0x0010 
	Entity* pEntity_4; //0x0018 
private:
	char pad_0x0020[0x358]; //0x0020

}; //Size=0x0378

class LocalPlayerManager
{
public:
private:
	char pad_0x0000[0x48]; //0x0000
public:
	LocalPlayerRef_1 * pRef; //0x0048 

}; //Size=0x0050

class LocalPlayerRef_1
{
public:
private:
	char pad_0x0000[0x18]; //0x0000
public:
	LocalPlayerRef_2 * pRef; //0x0018 

}; //Size=0x0020

class LocalPlayerRef_2
{
public:
private:
	char pad_0x0000[0xC0]; //0x0000
public:
	LocalPlayerRef_3 * N0000097C; //0x00C0 

}; //Size=0x00C8

class LocalPlayerRef_3
{
public:
	LocalPlayer * pLocalPlayer; //0x0000 

}; //Size=0x0008

class LocalPlayer
{
public:
private:
	char pad_0x0000[0x408]; //0x0000

}; //Size=0x0408

class PlayerInfoRef
{
public:
	PlayerInfo * pPlayerInfo; //0x0000 
private:
	char pad_0x0008[0x3F8]; //0x0008

}; //Size=0x0400

class PlayerName
{
public:
	char cPlayerName[8]; //0xB43B49C0 

}; //Size=0x0008

class PlayerInfo
{
public:
private:
	char pad_0x0000[0x170]; //0x0000
public:
	char* pPlayerName; //0x0170 
private:
	char pad_0x0178[0x290]; //0x0178

}; //Size=0x0408

class ChatEngine
{
public:
private:
	char pad_0x0000[0x60]; //0x0000
public:
	ChatManager * pChatManager; //0x0060 
private:
	char pad_0x0068[0x18]; //0x0068

}; //Size=0x0080

class ChatManager
{
public:
private:
	char pad_0x0000[0x1E0]; //0x0000
public:
	char cMessage[20]; //0x536D49C0 
private:
	char pad_0x01F4[0x214]; //0x01F4

};


