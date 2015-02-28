/*
    cheali-charger - open source firmware for a variety of LiPo chargers
    Copyright (C) 2013  Paweł Stawicki. All right reserved.

    This program is free software: you can redistribute it and/or modify
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
#ifndef STATICEDITMENU_H_
#define STATICEDITMENU_H_

#include <stdint.h>
#include "EditMenu.h"
#include "cprintf.h"

class StaticEditMenu : public EditMenu {
public:
    static const uint16_t Always = 0xffff;
    static const uint16_t Last = 0;

	struct EditData {
		int16_t minValue;
		int16_t maxValue;
		int16_t step;
	};
	struct StaticEditData {
	    const char * staticString;
	    uint16_t enableCondition;
		cprintf::PrintData print;
		EditData edit;
	};

public:
	StaticEditMenu(const StaticEditData * staticEditData)
			: EditMenu(NULL), staticEditData(staticEditData) {};
    virtual void printItem(uint8_t item);
    virtual void editItem(uint8_t item, uint8_t key);

    int16_t * getEditAddress(uint8_t item);

    void setSelector(uint16_t selector);

private:
    uint8_t getSelectedIndexOrSize(uint8_t item);
    const StaticEditData * staticEditData;
    uint16_t selector;
};

#endif /* STATICEDITMENU_H_ */