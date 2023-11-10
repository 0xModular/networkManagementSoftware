/*
 * LocalSave.h
 * Created on: Oct 26, 2023
 *
 * Author: Will & Layne
 */

#pragma once
#include <fstream>
#include <string>
#include <vector>

class LocalSave{

	public:

		//Public Static Methods
		static std::vector<LocalSave> GetSaves();
		static LocalSave NewSave();
		static bool RestoreSave();
	

		//Public Methods
		LocalSave(std::string s); //used for new save -- Constructor

		std::string ReadSave();
		std::string OverwriteSave(std::string save);
		bool BackupSave(std::string destinationPath);		
		
	private:

		//Members
		std::string file;

};
