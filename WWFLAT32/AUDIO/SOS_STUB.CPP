
#include "sos.h"

// Regular C Functions
WORD sosDIGILockMemory(VOID) { return 0; }
WORD sosDIGIUnLockMemory(VOID) { return 0; }
WORD sosDIGIInitSystem(LPSTR param, WORD val) { return 0; }
WORD sosDIGIUnInitSystem(VOID) { return 0; }
WORD sosDIGIInitDriver(WORD val1, _SOS_HARDWARE far *hw, _SOS_INIT_DRIVER far *init, WORD far *val2) { return 0; }
WORD sosDIGIUnInitDriver(WORD val, BOOL flag1, BOOL flag2) { return 0; }
WORD sosDIGILoadDriver(WORD a, WORD b, LPSTR far *c, LPSTR far *d, PSTR e, PSTR f, WORD *g) { return 0; }
WORD sosDIGIUnLoadDriver(WORD a) { return 0; }
WORD sosDIGIGetDeviceCaps(WORD a, LPSOSDEVICECAPS b) { return 0; }
LPSTR sosDIGIAllocateBuffer(WORD a, WORD *b, WORD *c) { return NULL; }
WORD sosDIGIStopSample(WORD a, WORD b) { return 0; }
WORD sosDIGISamplesPlaying(WORD a) { return 0; }
BOOL sosDIGISampleDone(WORD a, WORD b) { return 0; }
BOOL sosDIGISampleFilling(WORD a, WORD b) { return 0; }
WORD sosDIGIStartSample(WORD a, _SOS_START_SAMPLE far *b) { return 0; }
WORD sosDIGIContinueSample(WORD a, WORD b, _SOS_START_SAMPLE far *c) { return 0; }

WORD sosDIGIDetectInit(LPSTR a) { return 0; }
WORD sosDIGIDetectUnInit(VOID) { return 0; }
WORD sosDIGIDetectFindHardware(WORD a, _SOS_CAPABILITIES far *b, WORD far *c) { return 0; }
WORD sosDIGIDetectFindFirst(_SOS_CAPABILITIES far *a, WORD far *b) { return 0; }
WORD sosDIGIDetectFindNext(_SOS_CAPABILITIES far *a, WORD far *b) { return 0; }
WORD sosDIGIDetectGetSettings(_SOS_HARDWARE far *a) { return 0; }
WORD sosDIGIDetectGetCaps(WORD a, _SOS_CAPABILITIES far *b) { return 0; }
WORD sosDIGIDetectVerifySettings(_SOS_HARDWARE far *a) { return 0; }
PSTR sosGetErrorString(WORD a) { return NULL; }

WORD sosDIGILoadTimer(WORD a, LPSTR far *b, LPSTR far *c, PSTR d, PSTR e, WORD *f) { return 0; }
WORD sosDIGIUnLoadTimer(WORD a) { return 0; }

// Timer functions
WORD sosTIMERRegisterEvent(WORD a, VOID (far *b)(VOID), WORD far *c) { return 0; }
WORD sosTIMERInitSystem(WORD a, WORD b) { return 0; }
WORD sosTIMERUnInitSystem(WORD a) { return 0; }
WORD sosTIMERSetRate(WORD a) { return 0; }
WORD sosTIMERRemoveEvent(WORD a) { return 0; }
WORD sosTIMERAlterEventRate(WORD a, WORD b) { return 0; }
WORD sosTIMERGetEventRate(WORD a) { return 0; }
VOID far sosTIMEROldHandler(VOID) {}
VOID far sosTIMERHandler(VOID) {}

// Control functions
WORD sosDIGISetSampleVolume(WORD a, WORD b, WORD c) { return 0; }
WORD sosDIGIGetSampleVolume(WORD a, WORD b) { return 0; }
WORD sosDIGISetChannel(WORD a, WORD b, WORD c) { return 0; }
WORD sosDIGIGetChannel(WORD a, WORD b) { return 0; }
WORD sosDIGIGetBytesProcessed(WORD a, WORD b) { return 0; }
WORD sosDIGIGetLoopCount(WORD a, WORD b) { return 0; }
WORD sosDIGISetPanLocation(WORD a, WORD b, WORD c) { return 0; }
WORD sosDIGIGetPanLocation(WORD a, WORD b) { return 0; }
DWORD sosDIGISetPitch(WORD a, WORD b, DWORD c) { return 0; }
DWORD sosDIGIGetPitch(WORD a, WORD b) { return 0; }
WORD sosDIGIGetDMAPosition(WORD a) { return 0; }
WORD sosDIGISetPanSpeed(WORD a, WORD b, WORD c) { return 0; }
WORD sosDIGIGetPanSpeed(WORD a, WORD b) { return 0; }
WORD sosDIGIGetSampleID(WORD a, WORD b) { return 0; }
WORD sosDIGIGetSampleHandle(WORD a, WORD b) { return 0; }
WORD sosDIGISetMasterVolume(WORD a, WORD b) { return 0; }

// Memory allocation
WORD sosAllocVDSPage(LPSTR *a, WORD *b, WORD *c) { return 0; }
VOID sosFreeVDSPage(WORD a, WORD b, LONG c) {}

// External "C" functions for C++ compatibility
#ifdef __cplusplus
extern "C" {
#endif

WORD cdecl sosDRVLockMemory(DWORD a, DWORD b) { return 0; }
WORD cdecl sosDRVUnLockMemory(DWORD a, DWORD b) { return 0; }
void cdecl sosDRVGetCapsInfo(LPSTR a, LPSTR b, _SOS_CAPABILITIES far *c) {}
void cdecl sosDRVInit(LPSTR a, LPSTR b, int c, int d, int e, int f, int g, int h) {}
void cdecl sosDRVStart(LPSTR a, LPSTR b, int c, int d) {}
void cdecl sosDRVStop(LPSTR a, LPSTR b) {}
void cdecl sosDRVUnInit(LPSTR a, LPSTR b) {}
void cdecl sosDRVSetRate(LPSTR a, LPSTR b, int c) {}
void cdecl sosDRVSetAction(LPSTR a, LPSTR b) {}
WORD cdecl sosDRVMakeDMASelector(WORD a) { return 0; }
WORD cdecl sosDRVFreeDMASelector(WORD a) { return 0; }
void cdecl sosTIMERDRVInit(int wRate, void (far *func)(void)) {}
void cdecl sosTIMERDRVUnInit(void) {}
void cdecl sosTIMERDRVHandler(void) {}
void cdecl sosTIMERDRVFHandler(void) {}
void cdecl sosTIMERDRVEnable(void) {}
void cdecl sosTIMERDRVDisable(void) {}
void cdecl sosTIMERDRVCallOld(void) {}
void cdecl sosTIMERDRVSetRate(WORD a) {}
void cdecl sosDIGITimer_Start(void) {}
void cdecl sosDIGITimer_End(void) {}
void cdecl sosDIGIDrv_Start(void) {}
void cdecl sosDIGIDrv_End(void) {}

#ifdef __cplusplus
}
#endif



#pragma pack(4)
WORD     _sosDIGIData_Start;
WORD     _sosDIGIData_End;
WORD     _wSOSDriverLinear[256];
WORD     _wSOSTimerLinear[256];
LPSTR    _lpSOSDriver[256];
LPSTR    _lpSOSTimer[256];
LPSTR    _lpSOSDriverCS[256];
LPSTR    _lpSOSTimerCS[256];
BOOL     _wSOSDriverLoaded[256];
BOOL     _wSOSTimerLoaded[256];
BOOL     _wSOSDriverInitialized[256];
WORD     _wSOSOutputRate[256];
WORD     _wSOSDMABuffersize[256];
LONG     _dwSOSDMABufferPhysical[256];
LPSTR    _lpSOSDMABuffer[256];
BOOL     _wTimerUsed;
VOID ( far *_lpSOSFillHandler[256] )( VOID );
WORD     _wSOSTimerType[256];
WORD     _wSOSDriverType[256];
_SOS_SAMPLE far * _lpSOSSampleList[256][ _MAX_VOICES ];
LPWORD      _lpSOSDMAIrqCount[256];
LPWORD      _lpSOSDMAFillCount[256];
WORD        _wSOSTmrNextCount;
VOID ( interrupt far *_lpSOSOldTimer )( VOID );
WORD     _wSOSDriverID[256];
_SOS_CAPABILITIES _sSOSDriverCaps[256];
WORD        _wSOSDMAPortList[256];
BYTE        _bSOSDMAChannel[256];
_SOS_INIT_DRIVER     _sSOSDIGIInitDriver[256];
BYTE  _pSOSDriverPath[256];
BYTE  _pSOSTempDriverPath[256];
WORD  _wTIMERValue;
VOID ( far * _lpTIMEREvents[256] )( VOID );
WORD _wTIMEREventRate[256];
WORD _dwTIMEREventFraction[256];
WORD _dwTIMEREventFractionCurrent[256];
BYTE  _bSOSMIDITimerSongHandler[256];
BYTE  _bSOSMIDISongHandle;
WORD  _wSOSTimerMemHandle[256];
WORD  _wSOSDriverMemHandle[256];
WORD  _wSOSRealSeg[256];

_FILEHEADER    _sDETFileHeader;
_DRIVERHEADER  _sDETDriverHeader;
_FILEHEADER    sLOADFileHeader;
_DRIVERHEADER  sLOADDriverHeader;
BOOL           _wDETInitialized;
WORD           _wDETLinear;
LPSTR          _lpDETDriverBuffer;
LPSTR          _lpDETDriverBufferCS;
WORD           _hDETFile;
DWORD          _dwDETDriverIndex;
WORD           _wDETDriverIndexCur;
WORD           _wDETMemHandle;
LPSOSDEVICECAPS _lpDETDeviceCaps;
_SOS_CAPABILITIES _sDETCaps;
PSTR _pSOSErrorStrings[256];
BOOL _wSOSBufferAllocated[256];
BOOL _wSOSSystemInitialized;
VDS_STRUCT _sSOSVDSInfo;
_SOS_FILL_INFO _sSOSFillInfo;
WORD    _wSOSTimerEventIndex;
WORD  _wSOSTimerEntered;
WORD  _wSOSDriverSize[256];
WORD  _wSOSTimerSize[256];

#ifdef __cplusplus
extern "C" {
#endif
WORD  _sosDIGIData1_Start;
WORD  _sosDIGIData1_End;
WORD  _sosDIGIData2_Start;
WORD  _sosDIGIData2_End;
BYTE  _bTIMERInstalled;
BYTE  _bTIMERDPMI;
WORD  wDetectPort;
WORD  wDetectIRQ;
WORD  wDetectDMA;
WORD  wDetectParam;
#ifdef __cplusplus
}
#endif
