#include "stdio.h"
#include "conio.h"
//#include "../src/main.h"


extern "C" void runmain(char* linkInput);

int main(int argc, char **argv) {
	char* linkInput = "C:\\Users\\MaiVinhLam\\Desktop\\test.rtf";
	runmain(linkInput);
	getchar();
	return 0;
}