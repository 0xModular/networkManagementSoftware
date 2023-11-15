/*
 * LocalSave.cpp
 * Created on: Nov 10, 2023
 *
 * Author:
 */

#include "LocalSave.h"

bool LocalSave::openFile(std::string inputFileString, LocalSave *createdSave){

    std::ifstream *temp = new std::ifstream(inputFileString, std::ios::binary);

    if (!temp) 
        return false;
    else {

        createdSave = new LocalSave(temp);
        return true;
    }
}

LocalSave::LocalSave(std::ifstream *input){

    f = input;

}



bool LocalSave::BackupSave(std::string destinationPath) {

    	// Open the destination file for writing
    	std::ofstream destinationFile(destinationPath, std::ios::binary);
    
	if (!destinationFile) {
        
		return false;
    
	}

    // Copy the content of the source file to the destination file
    destinationFile << f->rdbuf();

    	// Check if the copy was successful
    
	if (!destinationFile) {
        
		return false;
    
	}

    // Close the files
    destinationFile.close();

}





