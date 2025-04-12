
#include <stdlib.h>
#include <dlfcn.h>


void* shload(const char* filename) {
    return dlopen(filename, RTLD_LAZY);
}

void shdelete(void* library) {
    if (library)
        dlclose(library);
}

int shcall(void* library, void* function, void* args) {
    return 0;
}
