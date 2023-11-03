Get accesss to a vector of Device objects from ReferenceValidationMechanism.cpp inside networkAdminTools() or networkEngineerTools() using std::vector<Device> d = n->getDeviceList(this).
This will return Device object with 4 parameters filled out, string name, string ipv4, bool wired, and string mac

Device members can be retrieved using their get method
These get methods require the ReferenceValidationMechanism object to be passed to them (security feature).