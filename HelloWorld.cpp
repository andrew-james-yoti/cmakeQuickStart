#include <iostream>
#include "HelloWorld.h"
#include "HelloWorldConfig.h"
#ifdef USE_MYMATH
#  include "MathsFunctions/MathsFunctions.h"
#endif

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Hello World" << endl;

    if (argc < 2) {
        cout << argv[0] << " Version " << HelloWorld_VERSION_MAJOR << "." << HelloWorld_VERSION_MINOR << endl;
        cout << "Usage: " << argv[0] << " number" << endl;
    }

    #ifdef USE_MYMATH
        int sum = myadd(10, 20);
        cout << "sum = " << sum << endl;
    #else
        cout << "USE_MYMATH tuned off or not defined" << endl;
    #endif

    return 0;
}