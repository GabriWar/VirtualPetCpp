#include "source.h"
#include <iostream>
#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
using std::thread;

int main()
{
	auto* myvirtualpet = new pet("cat", 1);
	std::cout << "\n";
	system("cls");

	//############## loop de detectar teclas assincrono
	thread asynckeyth(asynckey);
	//##################################################
	//################# codigo de renderizacao da janela
	renderwindow();
	//##################################################
	//############## fechando o loop pra nn crashar nada
	asynckeyth.join();
	//##################################################
	std::cin;
	return 0;
}
