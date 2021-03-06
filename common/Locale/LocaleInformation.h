/*
	Noel Lopes is an Assistant Professor at the Polytechnic Institute of Guarda, Portugal (for more information see readme.txt)
    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 Noel de Jesus Mendon�a Lopes

	This file is part of Multiple Back-Propagation.

    Multiple Back-Propagation is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LocaleInformation_h
#define LocaleInformation_h

// WARNING: This value works only for LOCALE_SDECIMAL and LOCALE_STHOUSAND and LOCALE_SLIST
#define MAX_SIZE_LOCALE_INFORMATION (4)

class LocaleInformation {
	public:
		static CString GetLocaleInformation(LCTYPE desiredInformation, char * defaultValue) {
			WCHAR information[MAX_SIZE_LOCALE_INFORMATION];

			if (!GetLocaleInfo(LOCALE_NAME_USER_DEFAULT, desiredInformation, information, MAX_SIZE_LOCALE_INFORMATION)) {
				return CString(defaultValue);
			}

			return information;
		}

		static CString GetDecimalSeparator() {
			return GetLocaleInformation(LOCALE_SDECIMAL, ".");
		}

		static CString GetListSeparator() {
			return GetLocaleInformation(LOCALE_SLIST, ",");
		}

		static CString GetThousandsSeparator() {
			return GetLocaleInformation(LOCALE_STHOUSAND, ",");
		}
};

#endif