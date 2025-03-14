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

/* $Header: /CounterStrike/DYNAVEC.CPP 1     3/03/97 10:24a Joe_bostic $ */
/***************************************************************************
 *                                                                         *
 *                 Project Name : Red Alert                                *
 *                                                                         *
 *                    File Name : DYNAVEC.CPP                              *
 *                                                                         *
 *                   Programmer : Bill R Randolph                          *
 *                                                                         *
 *                   Start Date : 09/18/96                                 *
 *                                                                         *
 *                  Last Update : September 18, 1996 [BRR]                 *
 *                                                                         *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 *   DynamicVectorClass<T>::Add -- Add an element to the vector.           *
 *   DynamicVectorClass<T>::Add_Head -- Adds element to head of the list.  *
 *   DynamicVectorClass<T>::Add_Head -- Adds element to head of the list.  *
 *   DynamicVectorClass<T>::Delete -- Deletes specified index from vector. *
 *   DynamicVectorClass<T>::Delete -- Remove specified object from vector. *
 *   DynamicVectorClass<T>::DynamicVectorClass -- Constructor              *
 *   DynamicVectorClass<T>::ID -- Find matching value in dynamic vector.   *
 *   DynamicVectorClass<T>::Resize -- Changes size of a dynamic vector.    *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include	"function.h"
#include "vector.h"
#ifdef WINSOCK_IPX
#include	"WSProto.h"
#include	"WSPUDP.h"
#endif	//WINSOCK_IPX
#include	<mem.h>
#include	<stdio.h>

// mango - moved code to header
