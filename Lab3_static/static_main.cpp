#include <iostream>
#include "static_Prog3.h"

using namespace std;
using namespace prog3;

int main() {
    DoubNum item;
    int rc;
    while (static_cast<void>(display_menu()), get_command(rc)) {
        calc(rc, item);
        cout << endl;
    }

    cout << "ERROR: NO ERRORS!\n     Bye!" << endl;
    return 0;
}