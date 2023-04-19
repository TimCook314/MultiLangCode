// cApp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h> // Has int32_t
#include <stdlib.h> // Has EXIT_FAILURE, EXIT_SUCCESS, 
#include <process.h> //getpid
#include <string.h> // strlen
#include <direct.h> // _getcwd
#include <Windows.h> //GetModuleFileName
//#include <Tchar.h> //Character stuff

//#include <io.h> //_setmode
//#include <fcntl.h>

int main(int argc, char* argv[]) {
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //wprintf(L"Image \x263a : \n");
    printf("Image: %s\n", argv[0]);

    //Windows set unicode
    SetConsoleOutputCP(CP_UTF8);
    //gcc -municode main.c -o main.exe
    // tells the compiler to compile the program as a Unicode program, which sets the output mode to Unicode by default
    printf("Hello, world! \xE2\x98\xBA\n");
    
    //wprintf("Hello, world! \u263A\n");

    //char filename[MAX_PATH];
    //GetModuleFileName(NULL, filename, MAX_PATH);
    TCHAR filename[1024];
    GetModuleFileName(NULL, filename, 1024);
    GetModuleFileNameA(NULL, filename, 1024);
    wprintf(L"Executable image name: %s\n", filename);

    printf("Number of additional command line arguments: %d\n", argc-1);
    if (argc > 1) {
        printf("Command line arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    int32_t pid = _getpid();
    printf("Process ID: %d\n", pid);

    printf("Size of a pointer: %zu bytes\n", sizeof(void*));

    printf("Build on %s at %s.\n", __DATE__, __TIME__);

#ifdef _WIN64
    printf("This is a 64-bit Windows application.\n");
#elif _WIN32
    printf("This is a 32-bit Windows application.\n");
#elif __x86_64__
    printf("This is a 64-bit Linux application.\n");
#elif __i386__
    printf("This is a 32-bit Linux application.\n");
#else
    printf("This platform is not supported.\n");
#endif

#ifdef _DEBUG
    printf("This is a debug build.\n");
#else
    printf("This is a release build.\n");
#endif
    
    char* buffer;
    // Get the current working directory:
    if ((buffer = _getcwd(NULL, 0)) == NULL)
        perror("_getcwd error");
    else
    {
        printf("%s \nLength: %zu\n", buffer, strlen(buffer));
        free(buffer);
    }

#ifdef _WIN32
    char* path = NULL;
    size_t len;
    errno_t err = _dupenv_s(&path, &len, "PATH");
    if (err == 0 && path != NULL) {
        printf("PATH=%s\n", path);
        free(path);
    }
    else {
        printf("PATH environment variable not found.\n");
    }
#endif


#ifdef __linux__
    char* path = getenv("PATH");
    if (path != NULL) {
        printf("PATH=%s\n", path);
        free(path);
    }
    else {
        printf("PATH environment variable not found.\n");
    }
#endif

    int32_t bob = 34;
    printf("Bob = %d", bob);

    printf("Hello world!\n");

    printf("In function %s\n", __func__);
    printf("This code is on line %d, in file %s\n", __LINE__, __FILE__);


#ifdef _UNICODE
    printf("_UNICODE is defined\n");
#endif

#ifdef wchar_t 
    printf("wchar_t  is defined\n");
#endif

#ifdef _NATIVE_WCHAR_T_DEFINED
    printf("_NATIVE_WCHAR_T_DEFINED is defined\n");
#endif

#ifdef _DEBUG
    printf("_DEBUG is defined\n");
#endif

#ifdef NDEBUG
    printf("NDEBUG is defined\n");
#endif

    if (sizeof(char) > 0) {
        printf("sizeof(char): %zd\n", sizeof(char));
    }

    if (sizeof(TCHAR) > 0) {
        printf("sizeof(TCHAR): %zd\n", sizeof(TCHAR));
    }



    char str[] = "Hello, world!";
    int len = strlen(str) + 1;

    // Convert the char string to a wchar_t string
    wchar_t wstr[len];

    MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, len);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
