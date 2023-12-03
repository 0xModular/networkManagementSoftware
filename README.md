# Network Management Software

IMPORTANT!! \/

DO NOT try to compile every folder in this repository. It will not work.

The Network Manager software is in folder "src". Compiling every cpp file in this location along with the C++ SQL Connector and wxWidgets library will create the correct binary file. Compiling AND running the Network Manager software will only work on LINUX SYSTEMS. 

The network end device background process is kept in the folder "client". Compiling every cpp file in this location will create the background process binary. The background process can only be compiled and ran on WINDOWS SYSTEMS. No libraries outside standard C++ libraries are required for compiling.

The end device background process MUST BE RUN AS ADMINISTRATOR to function properly.

Additionally these to programs WILL NOT WORK CORRECTLY on virtual machines, unless your VM has a bridged virtual network card that can properly interact with the LAN. These programs will properly compile on VMs and will run but they will always report network connectivity issues on VMs not using bridged NICs. 

### Dependencies:

* [wxWidgets v3.2.3](https://github.com/wxWidgets/wxWidgets)
* [Connector/C++ 8.2.0](https://dev.mysql.com/downloads/connector/cpp/)
Additionally if your version of linux does not come with the "arp" command pre-installed, you will have to install "net-tools". On ubuntu this can be done with "sudo apt-get install net-tools"

