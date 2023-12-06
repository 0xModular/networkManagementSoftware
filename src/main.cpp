/*
 * main.cpp
 * Created on: Oct 19, 2023
 *
 * Author:
 */

#include "GUI.h"

wxIMPLEMENT_APP(App);


/*
GUI bypass for testing
#include "Device.h"
#include "ReferenceValidationMechanism.h"

int main(){



    Device d("temp", "192.168.223.141", false, "target");
    d.GetDeviceConnections(new ReferenceValidationMechanism(true));
    std::vector<Connection> v = d.GetConnectionVector();
    for (Connection c : v){
        std::cout << c.localPort << " " << c.remotePort << " " << c.remoteIp << " " << c.status << " " << c.PID << "\n";
    }
    std::cout << "\n\n\n      test      \n\n\n\n";
    d.TerminateConnection(12564, new ReferenceValidationMechanism(true));
    std::vector<Connection> vv = d.GetConnectionVector();
    for (Connection c : vv){
        std::cout << c.localPort << " " << c.remotePort << " " << c.remoteIp << " " << c.status << " " << c.PID << "\n";
    }

}
*/

