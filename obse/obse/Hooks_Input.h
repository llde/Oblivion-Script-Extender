#pragma once
#include "GameOSDepend.h"
static const UInt32 kPollEndHook = 0x00403C81; 
static const UInt32 kPollEndRetn = 0x00403C85;
static const UInt32 kPollEndNoMouseHook = 0x0040483A;
static const UInt32 kPollEndNoMouseRetn = 0x0040483C;
static const UInt32 kLoc_403C40 = 0x00403C40;

static const UInt32 kInputGlobalAllocSize = 0x00404A77;
static const UInt32 kInputInitializeCallAddr = 0x00404A92;
static const UInt32 kInitializeInputGlobals = 0x00404150;

static UInt8 ControlsState[kControlsMapped] = {0};



class OSInputGlobalsEx : public OSInputGlobals {
public:
	UInt8	KeyMaskState[256];
	DIMOUSESTATE2 MouseMaskState;

	void SetMaskKey(UInt16 keycode);
	void SetUnmaskKey(UInt16 keycode);
	void SetMaskMouse(UInt8 keycode);
	void SetUnmaskMouse(UInt8 keycode);
	UInt8 GetMaskStatusKey(UInt16 keycode);
	UInt8 GetMaskStatusMouse(UInt8 keycode);
	UInt8 GetSignalStatusKey(UInt16 keycode);
	UInt8 GetSignalStatusMouse(UInt8 keycode);
	UInt8 GetPreSignalStatusKey(UInt16 keycode);
	UInt8 GetPreSignalStatusMouse(UInt8 keycode);

	void SetTapKey(UInt16 keycode);
	void SetTapMouse(UInt8 keycode);
	void SetHoldKey(UInt16 keycode);
	void SetHoldMouse(UInt8 keycode);
	void SetUnHoldKey(UInt16 keycode);
	void SetUnHoldMouse(UInt8 keycode);
	void SetHammerKey(UInt16 keycode, bool AHammer);
	void SetHammerMouse(UInt8 keycode, bool AHammer);
	void SetUnHammerKey(UInt16 keycode);
	void SetUnHammerMouse(UInt8 keycode);
	OSInputGlobalsEx* InitializeEx(IDirectInputDevice8* device);
	void InputPollFakeHandle();
};

STATIC_ASSERT(sizeof(OSInputGlobalsEx) == sizeof(OSInputGlobals) + sizeof(DIMOUSESTATE2) + sizeof(UInt8[256]));

enum  KeyControlState : UInt8 {
	kStateDisabled  = 1 << 0,
	kStateSignalled = 1 << 1,
	kStateTapped    = 1 << 2,
	kStateHolded    = 1 << 3,
	kStateHammered  = 1 << 4,
	kStateAHammered = 1 << 5,
	kStatePSignalled= 1 << 6
};

void Hook_Input_Init();



extern OSInputGlobalsEx* g_inputGlobal;