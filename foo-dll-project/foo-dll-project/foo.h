// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the FOO_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// FOO_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FOO_EXPORTS
#define FOO_API __declspec(dllexport)
#else
#define FOO_API __declspec(dllimport)
#endif

FOO_API int multiply_two_numbers(int a, int b);

/*
// This class is exported from the dll
class FOO_API Cfoo {
public:
	Cfoo(void);
	// TODO: add your methods here.
};

extern FOO_API int nfoo;

FOO_API int fnfoo(void);
*/