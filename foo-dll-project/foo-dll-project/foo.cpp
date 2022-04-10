// foo.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "foo.h"

FOO_API int multiply_two_numbers(int a, int b) {
    return (a + b) * 100;
}

/*
// This is an example of an exported variable
FOO_API int nfoo=0;

// This is an example of an exported function.
FOO_API int fnfoo(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Cfoo::Cfoo()
{
    return;
}
*/