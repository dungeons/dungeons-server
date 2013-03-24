#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib.h"
#include <iostream>
#include <string>


int main()
{
	void * lib_h;
    char *error;

	lib_h = dlopen ("./libl.so", RTLD_LAZY);
	if (!lib_h) {
        fputs (dlerror(), stderr);
        exit(1);
    }
    func1 = (void(*)())dlsym(lib_h, "func1");
    if (( error = dlerror() ) != NULL)  {
        fputs(error, stderr);
        exit(1);
    }
	func1();
	dlclose(lib_h);
	std::string a;
	std::cin >> a;
	lib_h = dlopen ("./libl.so", RTLD_LAZY);
    func1 = (void(*)())dlsym(lib_h, "func1");

	func1();
	dlclose(lib_h);
}