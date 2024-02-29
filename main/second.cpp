#include <iostream>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <sys/ioctl.h>
    #include <unistd.h>
#endif

using namespace std;

int main(int argc, char const *argv[])
{

    cout << "Rows: " << rows << " Cols: " << cols << endl;
    
    /* code */
    return 0;
}