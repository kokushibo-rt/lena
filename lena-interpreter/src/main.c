#include <lena.h>
#include <stdio.h>

#include <dlfcn.h>
#include <ffi.h>

int main(void) {
    printf("Lena interpreter\n");

    void* shrd = dlopen("./lib1.so", RTLD_NOW);

    if (!shrd) {
        perror("lib1.so isn't loaded!");
        return EXIT_FAILURE;
    }
        

    void (*func1)(void);
    
    func1 = dlsym(shrd, "print_lena");

    if (!func1) {
        dlclose(shrd);
        perror("print_lena isn't loaded!");
        return EXIT_FAILURE;
    }

    printf("Call funciton:\n");
    func1();

    dlclose(shrd);
    return EXIT_SUCCESS;
}