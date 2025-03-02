#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "function.h"
#include "session.h"
#include "commLib.h"

// Stubs

void PortClose(PORT* port) {
    if (port) {
        port->status = 0;
    }
}

int FastGetPortHardware(int com, int* irqnum, int* address) {
    *irqnum = 5;
    *address = 0x3F8;
    return ASSUCCESS;
}

int FastSetPortHardware(int com, int irqnum, int port) {
    return ASSUCCESS;
}

PORT* PortOpenGreenleafFast(int com, int baud, int parity, int wordlen, int stopbits) {
    PORT* port = (PORT*)malloc(sizeof(PORT));
    if (port) {
        port->status = 1;
        port->count = 0;
    }
    return port;
}

int WriteBuffer(PORT* Port, const char* SendBuf, size_t sendlen) {
    return (Port && SendBuf) ? (int)sendlen : -1;
}

int SpaceUsedInRXBuffer(PORT* port) {
    return port ? port->count : 0;
}

void ClearError(PORT* port) {
    if (port) {
        port->status = 0;
    }
}

int HMDial(PORT* port, const char* str) {
    return (port && str) ? ASSUCCESS : ASUSERABORT;
}

void HMSetDialingMethod(PORT* port, int method) {
}

int ReadBuffer(PORT* port, const char* buffer, int size) {
    return (port && buffer) ? size : -1;
}

int GetLineStatus(PORT* port) {
    return port ? port->status : -1;
}

void ClearLineStatus(PORT* port) {
    if (port) {
        port->status = 0;
    }
}

void PortKillTime(PORT* port, int time) {
}

void HMWaitForOK(int cond, void*) {
}

int HMSendString(PORT* port, const char* str) {
    return (port && str) ? ASSUCCESS : ASUSERABORT;
}

int HMSendStringNoWait(PORT* port, const char* str, int terminator) {
    return (port && str) ? ASSUCCESS : ASUSERABORT;
}

void SetDtr(PORT* port, int dtr) {
}

int HMInputLine(PORT* port, int delay, char* buffer, int buffer_len) {
    return (port && buffer) ? buffer_len : -1;
}

void HMSetUpEchoRoutine(void(*func)(char c)) {
}

void HMSetUpAbortKey(int key) {
}

void SetAbortModemFunctionPtr(int (*func)(PORT*)) {
}

int Change8259Priority(int priority) {
    return ASSUCCESS;
}

int GetModemStatus(PORT* port) {
    return port ? CTS_SET : -1;
}

int HMAnswer(PORT* port) {
    return (port) ? ASSUCCESS : ASUSERABORT;
}
