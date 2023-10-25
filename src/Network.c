#ifndef SRC_NETWORK_H_
#define SRC_NETWORK_H_

#include "src/Device.h"
#include "src/Connection.h"

Network(){

    this.timeSinceReset = 0;


}

void refresh(){

    this.getDevices();
    this.getGeneralNetworkDetails();
    this.getCoonections();
    this.timeSinceReset = 0;

}

void getDevices(){

    while(/*?/*/){
        
        Device d = new Device(/*?*/);
        this.deviceList.add(d);

    }

}

void getGeneralNetworkDetails(){


}

void getConnections(){

 while(/*?/*/){
        
        Connection c = new Connection(/*?*/);
        this.connectionList.add(c);

    }

}

void editDevices(){


}

void editGeneralNetworkDetails(){


}

void editConnections(){


}
