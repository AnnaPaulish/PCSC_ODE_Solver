
#include "setup.h"
#include "output.h"
#include "handle_method.h"

int main (int argc, char **argv) {

    auto user_setup = SetUp();

    auto ode = MakeMethod(user_setup);

    auto solution = ode->Solve();

    auto output = Output(user_setup, solution);
    output.write();

    RemoveMethod(ode);

    return 0;
}
