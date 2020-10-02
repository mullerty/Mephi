#include <iostream>
#include "Prog2.h"

using namespace std;
using namespace prog2;

int main(){
    Evolvent line;
    int rc;
    while (static_cast<void>(display_menu()), get_command(rc)){
        calc(rc, line);
        cout << endl;
    }

    cout << "ERROR: NO ERRORS!\n     Bye!" << endl;
    return 0;
}
