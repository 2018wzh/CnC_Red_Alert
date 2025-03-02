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

/* $Header: /CounterStrike/CCPTR.H 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : CCPTR.H                                                      *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 06/07/96                                                     *
 *                                                                                             *
 *                  Last Update : June 7, 1996 [JLB]                                           *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


#ifndef CCPTR_H
#define CCPTR_H

/*
**	The CCPtr class is designed for a specific purpose. It functions like a pointer except that
**	it requires no fixups for saving and loading. If pointer fixups are not an issue, than using
**	regular pointers would be more efficient.
*/
template<class T>
class CCPtr
{
	public:
		CCPtr(void) : ID(-1) {;}
		CCPtr(NoInitClass const & ) {;}
		CCPtr(T * ptr);

		operator T * (void) const {
			if (ID == -1) return(NULL);
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return((T*) (*Heap)[ID]);
		}
		T & operator * (void) const {
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return(*(T*)(*Heap)[ID]);
		}
		T * operator -> (void) const {
			if (ID == -1) return(NULL);
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return((T*) (*Heap)[ID]);
		}

		bool Is_Valid(void) const {return(ID != -1);}

		bool operator == (CCPtr<T> const & rvalue) const {return(ID == rvalue.ID);}
		bool operator != (CCPtr<T> const & rvalue) const {return(ID != rvalue.ID);}
		bool operator > (CCPtr<T> const & rvalue) const;
		bool operator <= (CCPtr<T> const & rvalue) const {return (rvalue > *this);}
		bool operator < (CCPtr<T> const & rvalue) const {return (*this != rvalue && rvalue > *this);}
		bool operator >= (CCPtr<T> const & rvalue) const {return (*this == rvalue || rvalue > *this);}

		long Raw(void) const {return(ID);}
		void Set_Raw(long value) {ID = value;}

	private:

		static FixedIHeapClass * Heap;

		/*
		**	This is the ID number of the object it refers to. By using an ID number, this class can
		**	be saved and loaded without pointer fixups.
		*/
		int ID;
};

/*
**	These template helper functions tell the compiler what to do in the
**	ambiguous case of a CCPtr on one side and a regular type pointer on the
**	other side. In such a case the compiler could create a temp CCPtr object
**	OR call the conversion operator on the existing CCPtr object. Either way
**	is technically valid, but the compiler doesn't know which is better so it
**	generates an error. These routines force the conversion operator rather than
**	creating a temporary object. This presumes that the conversion operator is
**	cheaper than constructing a temporary and that cheaper solutions are desirable.
*/
template<class T>
int operator == (CCPtr<T> & lvalue, T * rvalue)
{
	return((T*)lvalue == rvalue);
}

template<class T>
int operator == (T * lvalue, CCPtr<T> & rvalue)
{
	return(lvalue == (T*)rvalue);
}

// mango - these need to be here 

/*
**	These member functions for the CCPtr class cannot be declared inside the
**	class definition since they could refer to other objects that themselves
**	contain CCPtr objects. The recursive nature of this type of declaration
**	is not handled by Watcom, hence the body declaration is dislocated here.
*/
template<class T>
CCPtr<T>::CCPtr(T * ptr) : ID(-1)
{
	if (ptr != NULL) {
		ID = ptr->ID;
	}
}

/***********************************************************************************************
 * CCPtr<T>::operator > -- Greater than comparison operator.                                   *
 *                                                                                             *
 *    This will compare two pointer value to see if the left hand value is greater than the    *
 *    right hand. The values are compared by comparing based on their Name() functions.        *
 *                                                                                             *
 * INPUT:   rvalue   -- The right handle CCPtr value.                                          *
 *                                                                                             *
 * OUTPUT:  Is the left hand value greater than the right hand value?                          *
 *                                                                                             *
 * WARNINGS:   The values pointed to by CCPtr must have a Name() function defined.             *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
bool CCPtr<T>::operator > (CCPtr<T> const & rvalue) const
{
	return (stricmp((*this)->Name(), rvalue->Name()) > 0);
}

#endif
