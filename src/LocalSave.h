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
		static bool openFile();
	

		//public methods
		std::string ReadSave();
		std::string OverwriteSave(std::string s);
		bool BackupSave(std::string location);		
		bool openFile(std::string inputFileString, LocalSave *createdSave);

		
		
	private:

		//private functions
		LocalSave(std::fstream f); //used by getSaves to create objects for existing save files -- Constructor

		//member
		std::ifstream *f;
		LocalSave(std::ifstream *input); 

};
