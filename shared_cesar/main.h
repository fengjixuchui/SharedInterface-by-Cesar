#pragma once
#pragma component(browser, off, references)
#include <ntdef.h>
#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <Ntstrsafe.h>
#pragma component(browser, on, references)

const WCHAR SharedSectionName[] = L"\\BaseNamedObjects\\SharedMem"; //Allocate buffer for name of shared memory

DRIVER_UNLOAD driverUnload1;

SECURITY_DESCRIPTOR SecDescriptor;
HANDLE sectionHandle;
PVOID	SharedSection = NULL;
PVOID	Sharedoutputvar = NULL;
ULONG DaclLength;
PACL Dacl; // this is the problem i guess PACL


// trigger loop
HANDLE  SharedEventHandle_trigger = NULL;
PKEVENT SharedEvent_trigger = NULL;
UNICODE_STRING EventName_trigger;


// ReadyRead
HANDLE  SharedEventHandle_ReadyRead = NULL;
PKEVENT SharedEvent_ReadyRead = NULL;
UNICODE_STRING EventName_ReadyRead;

// data arrived
HANDLE  SharedEventHandle_dt = NULL;
PKEVENT SharedEvent_dt = NULL;
UNICODE_STRING EventName_dt;

extern NTKERNELAPI ERESOURCE PsLoadedModuleResource;
