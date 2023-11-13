/*
 * LocalSave.cpp
 * Created on: Nov 10, 2023
 *
 * Author:
 */

#include "LocalSave.h"

bool LocalSave::openFile(std::string inputFileString, LocalSave *createdSave){

<<<<<<< HEAD
	// Open the source file for reading
	std::ifstream sourceFile(this->file, std::ios::binary);
    
    	if (!sourceFile) {
        
		return false;
    
	}
=======
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
>>>>>>> 0df8151 (hh)

    	// Open the destination file for writing
    	std::ofstream destinationFile(destinationPath, std::ios::binary);
    
	if (!destinationFile) {
        
		return false;
    
	}

<<<<<<< HEAD
    	// Copy the content of the source file to the destination file
    	destinationFile << sourceFile.rdbuf();
=======
    // Copy the content of the source file to the destination file
    destinationFile << f->rdbuf();
>>>>>>> 0df8151 (hh)

    	// Check if the copy was successful
    
	if (!destinationFile) {
        
		return false;
    
	}

<<<<<<< HEAD
    	// Close the files
	sourceFile.close();
    	destinationFile.close();

    	return true;
=======
    // Close the files
    destinationFile.close();
>>>>>>> 0df8151 (hh)

}





