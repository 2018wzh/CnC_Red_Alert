#ifndef _COMMLIB_H_
#define _COMMLIB_H_


struct PORT
{
    int status;
    int count;
};

void PortClose(PORT* port);
int FastGetPortHardware( int com, int* irqnum, int* address );
int FastSetPortHardware( int com, int irqnum, int port );
PORT* PortOpenGreenleafFast ( int com, int baud, int parity, int wordlen, int stopbits );

int WriteBuffer( PORT* Port, const char* SendBuf, size_t sendlen );
#define ASSUCCESS  0
#define ASIRQINUSE 1
#define ASUSERABORT 100

#define COM1 1
#define COM2 2
#define COM3 3
#define COM4 4
#define COM5 5
#define ASBUFREMPTY 200

int SpaceUsedInRXBuffer( PORT* port );
void ClearError( PORT* port );
int HMDial( PORT* port, const char* str );
void HMSetDialingMethod( PORT* port, int method );
int ReadBuffer( PORT* port, const char* buffer, int size );
int GetLineStatus( PORT* port );
void ClearLineStatus( PORT* port );
void PortKillTime( PORT* port, int time );
void HMWaitForOK( int cond, void* );
int HMSendString( PORT* port, const char* str );
int HMSendStringNoWait( PORT* port, const char* str, int terminator );
void SetDtr( PORT* port, int dtr );
int HMInputLine( PORT* port, int delay, char* buffer, int buffer_len );
void HMSetUpEchoRoutine( void(*func)(char c) );
void HMSetUpAbortKey(int key);
void SetAbortModemFunctionPtr(int (*func)(PORT*));
int Change8259Priority(int priority);
int GetModemStatus(PORT* port);
int HMAnswer(PORT* port);

#define PORTBUF_MAX           64 // dialog field sizes
#define IRQBUF_MAX            3
#define BAUDBUF_MAX           7
#define INITSTRBUF_MAX        41
#define CWAITSTRBUF_MAX       16
#define CREDITSBUF_MAX        5
#define PACKET_TIMING_TIMEOUT 40              // ticks b/w sending a timing packet
#define MODEM_NAME_MAX        PORTBUF_MAX - 1 // Max length of modem name in list box


/*
** Modem send result codes
*/
enum SendModemEnum {
    MODEM_CMD_TIMEOUT = 0,
    MODEM_CMD_OK,
    MODEM_CMD_0,
    MODEM_CMD_ERROR
};


/*
** Enums for modem status flags
*/
enum {
    CTS_SET  = 0x10,
    DSR_SET  = 0x20,
  RI_SET   = 0x40,
  CD_SET   = 0x80
};


class PhoneEntryClass
{
public:
	enum
    {
        PHONE_MAX_NAME = 21,
        PHONE_MAX_NUM = 21
    };

    PhoneEntryClass(){;}
    ~PhoneEntryClass(){;}

    bool operator==(PhoneEntryClass& obj)
    {
        return (memcmp(Name, obj.Name, strlen(Name)) == 0);
    }
    bool operator!=(PhoneEntryClass& obj)
    {
        return !(obj==*this);
    }

    SerialSettingsType Settings;
    char Name[PHONE_MAX_NAME];  // destination person's name
    char Number[PHONE_MAX_NUM]; // phone #
};

#endif
