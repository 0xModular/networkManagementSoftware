#include <string>
#include <fstream>
#include "LocalSave.h"

bool LocalSave::BackupSave(std::string destinationPath) {

    // Open the source file for reading
    std::ifstream sourceFile(f, std::ios::binary);
    if (!sourceFile) {
        return false;
    }

    // Open the destination file for writing
    std::ofstream destinationFile(destinationPath, std::ios::binary);
    if (!destinationFile) {
        return false;
    }

    // Copy the content of the source file to the destination file
    destinationFile << sourceFile.rdbuf();

    // Check if the copy was successful
    if (!destinationFile) {
        return false;
    }

    // Close the files
    sourceFile.close();
    destinationFile.close();

    return true;
}





