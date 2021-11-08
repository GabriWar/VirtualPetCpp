#include "source.h"
#include <chrono>
#include <string>
#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
using std::string;
bool IsDebug = false;
using std::tuple;



//codigo da janela#############
struct winsizestruct winsize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	winsizestruct returnthis;
	returnthis.Wcollumns = columns;
	returnthis.Wrows = rows;
	return returnthis;
}
//############################


//codigo do loop de detectar teclas de modo assincrono
void asynckey()
{
	while (true) 
	{
		std::cout << char(_getch())<< "\n";
	}
}
//####################################
//
//codigo de renderizacao da janela
void renderwindow(int offsetup,int offsetdown, bool alt)
{
	while (true)
	{
		int Wcollumns = winsize().Wcollumns; int Wrows = winsize().Wrows;

		if (alt) {
			for (int i = 0; i <= offsetup; i++) {
				std::cout << "\n";
			}
			for (int i = 0; i < Wcollumns; i++)
			{
				std::cout << "+";
			}
			std::cout << "\n";
			for (int i = offsetdown; i < Wrows; i++)
			{
				std::cout << "+";
				for (int i = 2; i < Wcollumns; i++)
				{
					std::cout << " ";
				}
				std::cout << "+";
				std::cout << "\n";

			}
			for (int i = 0; i < Wcollumns; i++)
			{
				std::cout << "+";
			}
		}
		std::cout << std::string(offsetup, '\n') << std::endl;
		std::cout << std::string(Wcollumns, '*') << std::endl;
		for (int i = offsetdown; i < Wrows; i++) {
			std::cout << "*";
			std::cout << std::string(Wcollumns - 2, ' ');
			std::cout << "*";
		}
		std::cout << std::string(Wcollumns, '*') << std::endl;
		std::cout << " rows= " << Wrows << " columns =" << Wcollumns << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");

	}
}
//#############################################

pet::pet(string _name, int _pettype)
{

	this->_name = _name;
	this->_pettype = _pettype;
	this->_isalive = true;
	this->_hunger = 100;
	this->_thirst = 100;
	this->_happyness = 100;
	this->_issick = false;
	if (IsDebug) {
		std::cout << "obj (" << _name << ")[" << this << "] created ";
	}
}

int pet::gettype()
{
	return this->_pettype;
}
string pet::getname()
{
	return this->_name;
}

int pet::gethunger()
{
	return this->_hunger;
}

int pet::getthirst()
{
	return this->_thirst;
}

int pet::gethappyness()
{
	return this->_happyness;
}

bool pet::getifsick()
{
	return this->_issick;
}

bool pet::getifalive()
{
	return this->_isalive;
}

void pet::die()
{
	this->_isalive = false;
}

void pet::becomesick()
{
	this->_issick = true;
}

void pet::givewather()
{
	this->_thirst += 30;
}

void pet::givefood()
{
	this->_hunger += 10;
}

void pet::play()
{
	this->_happyness += 50;
}

void pet::givemedicine()
{
	this->_issick = false;
}

