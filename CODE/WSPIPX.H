/*
**	Command & Conquer Red Alert(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                     $Archive:: /Sun/WSPIPX.h                                               $*
 *                                                                                             *
 *                      $Author:: Joe_b                                                       $*
 *                                                                                             *
 *                     $Modtime:: 8/12/97 5:42p                                               $*
 *                                                                                             *
 *                    $Revision:: 3                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef WSPIPX_H
#define WSPIPX_H

#include	"WSProto.h"

/*
** Include Windows specific extensions for Winsock that allow IPX over winsock 1.1
*/
#include	<wsipx.h>

/*
** This file normally resides with the SDK. However, since it needs fixing up before watcom will
** compile it, it has been incorporated into the project.
*/

// mango - imported from wine
#ifdef USE_WS_PREFIX
#define WS(x)    WS_##x
#else
#define WS(x)    x
#endif

#ifndef USE_WS_PREFIX
#define IPX_PTYPE 0x4000
#define IPX_FILTERPTYPE 0x4001
#define IPX_DSTYPE 0x4002
#define IPX_STOPFILTERPTYPE 0x4003
#define IPX_EXTENDED_ADDRESS 0x4004
#define IPX_RECVHDR 0x4005
#define IPX_MAXSIZE 0x4006
#define IPX_ADDRESS 0x4007
#define IPX_GETNETINFO 0x4008
#define IPX_GETNETINFO_NORIP 0x4009
#define IPX_SPXGETCONNECTIONSTATUS 0x400b
#define IPX_ADDRESS_NOTIFY 0x400c
#define IPX_MAX_ADAPTER_NUM 0x400d
#define IPX_RERIPNETNUMBER 0x400e
#define IPX_RECEIVE_BROADCAST 0x400f
#define IPX_IMMEDIATESPXACK 0x4010
#else
#define WS_IPX_PTYPE 0x4000
#define WS_IPX_FILTERPTYPE 0x4001
#define WS_IPX_DSTYPE 0x4002
#define WS_IPX_STOPFILTERPTYPE 0x4003
#define WS_IPX_EXTENDED_ADDRESS 0x4004
#define WS_IPX_RECVHDR 0x4005
#define WS_IPX_MAXSIZE 0x4006
#define WS_IPX_ADDRESS 0x4007
#define WS_IPX_GETNETINFO 0x4008
#define WS_IPX_GETNETINFO_NORIP 0x4009
#define WS_IPX_SPXGETCONNECTIONSTATUS 0x400b
#define WS_IPX_ADDRESS_NOTIFY 0x400c
#define WS_IPX_MAX_ADAPTER_NUM 0x400d
#define WS_IPX_RERIPNETNUMBER 0x400e
#define WS_IPX_RECEIVE_BROADCAST 0x400f
#define WS_IPX_IMMEDIATESPXACK 0x4010
#endif /* USE_WS_PREFIX */

typedef struct _IPX_ADDRESS_DATA {
    INT   adapternum;
    UCHAR netnum[4];
    UCHAR nodenum[6];
    BOOLEAN wan;
    BOOLEAN status;
    INT maxpkt;
    ULONG linkspeed;
} IPX_ADDRESS_DATA, *PIPX_ADDRESS_DATA;
// mango - imported from wine

/*
** IPX interface class. This handles access to the IPX specific portions of the
** Winsock interface.
**
*/
class IPXInterfaceClass : public WinsockInterfaceClass {

	public:

		IPXInterfaceClass (void);
		//virtual ~IPXInterfaceClass(void){Close();};
		bool Get_Network_Card_Address (int card_number, SOCKADDR_IPX *addr);
	 	virtual long Message_Handler(HWND window, UINT message, UINT wParam, LONG lParam);
		virtual bool Open_Socket ( SOCKET socketnum );

		virtual ProtocolEnum Get_Protocol (void) {
			return (PROTOCOL_IPX);
		};

		virtual int Protocol_Event_Message (void) {
			return (WM_IPXASYNCEVENT);
		};


	private:
		/*
		** The address of the network we will send broadcasts to. Normally you would expect
		** this to be ff,ff,ff,ff but this fails under NT 4.0. Instead, we can use the network
		** number of the net that this PC is attached to. This limits broadcasts to the current
		** network.
		*/
		unsigned char	BroadcastNet[4];

		/*
		** The node to use as a broadcast address. Normally ff,ff,ff,ff,ff,ff.
		*/
		unsigned char	BroadcastNode[6];

		/*
		** The id of the network cars in this machine.
		*/
		unsigned char	MyNode[6];

		/*
		** The socket number to connect with. Normally this will be virgins reserved socket
		** number - VIRGIN_SOCKET (0x8813).
		*/
		SOCKET			IPXSocketNumber;

};



#endif