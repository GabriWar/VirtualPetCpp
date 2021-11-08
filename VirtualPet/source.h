﻿#pragma once
#include <string>
#include <string>
#include <iostream>
using std::string;


//codigo de obtencao das colunas e linhas da janela #############
struct winsizestruct
{
	int Wcollumns, Wrows;
};

struct winsizestruct winsize();
//####################################################################
//codigo de renderizacao da janela
void renderwindow(int offsetup = 0, int offsetdown = 4, bool alt = false);
//################################
//codigo de receber as teclas pressionadas de modo assincrono :)
void asynckey();
//#############################################################
class pet
{
private:
	int _pettype;
	string _name;
	bool _isalive;
	int _hunger;
	int _thirst;
	int _happyness;
	bool _issick;
public:
	pet();
	pet(string _name, int _pettype);
	int gettype();
	string getname();
	int gethunger();
	int getthirst();
	int gethappyness();
	bool getifsick();
	bool getifalive();
	void die();
	void becomesick();
	void givewather();
	void givefood();
	void play();
	void givemedicine();
};
