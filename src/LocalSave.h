#pragma once
#include <fstream>
#include <string>
#include <vector>

class LocalSave{

	public:

		//public static methods
		static std::vector<LocalSave> getSaves();
		static LocalSave newSave();
		static bool restoreSave();
	

		//public methods
		LocalSave(std::string s); //used for new save
		std::string readSave();
		std::string overwriteSave(std::string s);
		bool backupSave(std::string l);

		
		

	private:

		//private functions
		LocalSave(std::fstream f); //used by getSaves to create objects for existing save files

		//member
		std::fstream f;



};


