#pragma once
#include "stdafx.h"
#include "Vector3.h"
/*    OFFSET_GAMEMANAGER : 0x4ddc468
    OFFSET_GAMERENDERER : 0x4d80c28
    OFFSET_NAMECHANGER : 0x4d93b48
    OFFSET_NETMANAGER : 0x4d73e90
	*/
/*
DWORD_PTR Entity = 0x8;
DWORD_PTR EntityRef = 0x20;

DWORD_PTR EntityInfo = 0x18;
DWORD_PTR MainComponent = 0xA8;
DWORD_PTR ChildComponent = 0x8;
DWORD_PTR Health = 0x138;

DWORD_PTR PlayerInfo = 0x2A0;
DWORD_PTR PlayerInfoDeref = 0x0;
DWORD_PTR PlayerTeamId = 0x148;
DWORD_PTR PlayerName = 0x170;

DWORD_PTR FeetPosition = 0x1C0;
DWORD_PTR HeadPosition = 0x170;
DWORD_PTR NeckPosition = 0x160;

*/
/* Originally Posted by V10 View Post
someone have new offsets for gadgets?

with new game manager ptr its not work for me, last ptrs is null, trying to change offsets around +-0x30 for search correct - not works also
Because its not game manager try

Code:

4D750E0->0x348->0x18->0x130

Sig: 48 8B 05 ? ? ? ? 48 85 C0 74 37

void TP(Vector3 Destination) {

uint64_t tmp;
abc.Rpm(MEMBaseAddress() + 0x4D53520, tmp);
abc.Rpm(tmp + 0xb0, tmp);
abc.Rpm(tmp + 0x8, tmp);
abc.Rpm(tmp + 0x118, tmp);

int t = getNetObjectIndex();
for (int i = 0; i <= 800; i++)
{
float x = Destination.x - 1.f;
float y = Destination.y - 1.f;
abc.Wpm(tmp + (t * 0x80), x);
abc.Wpm(tmp + (t * 0x80) + 0x4, y);
abc.Wpm(tmp + (t * 0x80) + 0x8, Destination.z);
Sleep(1);

}
}    DWORD_PTR MEM::TELE() {
     DWORD_PTR pNetworkManager = RPM<DWORD_PTR>(MEMBaseAddress() + MEMOFFs::NETWORKMANAGER);
       
         
        DWORD_PTR pNetworkPtr1 = RPM<DWORD_PTR>(pNetworkManager + 0xB0);
     
         
        DWORD_PTR pNetworkPtr2 = RPM<DWORD_PTR>(pNetworkPtr1 + 0x8);
     
         
        DWORD_PTR pNetworkPtr3 = RPM<DWORD_PTR>(pNetworkPtr2 + 0x118);
        
         
        for (DWORD t = 0; t < 1000; t++)
        {
            Vector3 net_pos = RPM<Vector3>(pNetworkPtr3 + (t * 0x80));
         
    		
        }
		class NetObject
		{
		public:
		float X; //0x0000
		float Y; //0x0004
		float Z; //0x0008
		float Unknown1; //0x000C
		float Unknown2; //0x0010
		float Unknown3; //0x0014
		float Unknown4; //0x0018
		float Unknown5; //0x001C
		float Unknown6; //0x0020
		float Unknown7; //0x0024
		char pad_0x0028[0x58]; //0x0028
		if ((Myx == p7[i].X) && (Myy == p7[i].Y) && (abs((Myz + 1.075f) - p7[i].Z)<0.1f))
		}; //Size=0x0080


		WeaponManager + 0x5C0 = LastBulletPosition


		class GadgetDetails
		{
		public:
		Vector3 N000006AA; //0x0000
		char pad_0x000C[0x4]; //0x000C
		Vector3 N000006AC; //0x0010
		char pad_0x001C[0x4]; //0x001C
		DWORD State1; //0x0020
		DWORD State2; //0x0024
		DWORD64 Type; //0x0028
		DWORD Memo; //0x0030
		}; //Size=0x01A8



		class Gadget
		{
		public:
		Vector3 Position1;
		char pad_0x000C[0x4]; //0x000C
		Vector3 Position2;
		char pad_0x001C[0x4]; //0x001C
		GadgetDetails* detail_data; //0x0020
		char pad_0x0028[0x8]; //0x0028
		WORD TypeWord; //0x0030
		unsigned char N00000811; //0x0032
		unsigned char Size; //0x0033
		unsigned char Index; //0x0034
		char pad_0x0035[0xB]; //0x0035


		}; //Size=0x0040
*/


DWORD_PTR Renderer = 0x4d80c28;
DWORD_PTR GameRenderer = 0x0;
DWORD_PTR EngineLink = 0x120;
DWORD_PTR Engine = 0x218;
DWORD_PTR Camera = 0x38;

DWORD_PTR ViewTranslastion = 0x1A0;
DWORD_PTR ViewRight = 0x170;
DWORD_PTR ViewUp = 0x180;
DWORD_PTR ViewForward = 0x190;
DWORD_PTR FOVX = 0x1B0;
DWORD_PTR FOVY = 0x1C4;

DWORD_PTR OFFSET_GAMEMANAGER = 0x4ddc468;
DWORD_PTR OFFSET_PLAYERMANAGER = 0x4ddc458;
DWORD Entity_Offset = 0x08;

DWORD_PTR WEAP_OFFSET = 0x0365AC08;
DWORD_PTR NAME_OFFSET = 0x4d93b48;
DWORD_PTR CHAT_OFFSET = 0x03E423C8;

// Generated using ReClass 2016
