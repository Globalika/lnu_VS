#pragma once
#ifndef _MENU_
#define _MENU_
#define GETCH _getch()-48
#include "..\TablesRepository.h"

#include <conio.h>

class Menu 
{
public:
	TablesRepository* repository;
};
#endif _MAIN_MENU_