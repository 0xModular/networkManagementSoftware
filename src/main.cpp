/*
 * main.cpp
 * Created on: Oct 19, 2023
 *
 * Author:
 */

//This program is a fucking monstrosity

#include "GUI.h"

wxIMPLEMENT_APP(App);


/*
#include "Device.h"
#include "ReferenceValidationMechanism.h"

int main(){



    Device d("temp", "192.168.142.141", false, "target");
    ReferenceValidationMechanism *r = new ReferenceValidationMechanism(true);

    
    d.RetrieveMoreDeviceDetails(r);
    std::vector<Connection> v = d.GetConnectionVector();
    for (Connection c : v){
        std::cout << c.localPort << " " << c.remotePort << " " << c.remoteIp << " " << c.status << " " << c.PID << "\n";
    }
    

    Network *n = new Network(r);
    std::vector<Device> l = n->GetDeviceList();
    std::cout << "start\n";
    for(Device dd: l){

        std::cout << dd.GetMac() << "\n";

    }

    n->UploadAllCurrentDevicesToDB(r);
   
}
*/

