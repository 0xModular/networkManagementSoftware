/*
 * Login.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */
#include <string>
#include <vector>
#include "Account.h"

#ifndef SRC_LOCALSAVE_H_
#define SRC_LOCALSAVE_H_

class LocalSave{

	public:

		//public static methods
		static std::vector<LocalSave> getSaves();
		static LocalSave newSave();
		static bool restoreSave();
	

		//public methods
		LocalSave(std::string ) //used for new save
		std::string readSave();
		std::string overwriteSave();
		void backupSave();

		
		

	private:

		LocalSave(file f); //used by getSaves to create objects for existing save files
		static file checkForFile();

		RemoteNetworkChangesLog getFileData();

		static vector<file> localSaves;
		file f;



};


#endif /* SRC_LOCALSAVE_H_ */
