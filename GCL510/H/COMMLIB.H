#ifndef _COMMLIB_H_
#define _COMMLIB_H_

typedef unsigned short PORT;

int WriteBuffer( PORT* Port, const char* SendBuf, size_t sendlen );
#define ASSUCCESS  0
#define ASIRQINUSE 1

#define PORTBUF_MAX           64 // dialog field sizes
#define IRQBUF_MAX            3
#define BAUDBUF_MAX           7
#define INITSTRBUF_MAX        41
#define CWAITSTRBUF_MAX       16
#define CREDITSBUF_MAX        5
#define PACKET_TIMING_TIMEOUT 40              // ticks b/w sending a timing packet
#define MODEM_NAME_MAX        PORTBUF_MAX - 1 // Max length of modem name in list box


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
