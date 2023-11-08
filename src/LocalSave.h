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

		//public static methods
		static std::vector<LoalSave> GetSaves();
		static LocalSave NewSave();
		static bool RestoreSave();
	

		//public methods
		LocalSave(std::string s); //used for new save -- Constructor

		std::string ReadSave();
		std::string OverwriteSave(std::string s);
		bool BackupSave(std::string l);		
		
	private:

		//private functions
		LocalSave(std::fstream f); //used by getSaves to create objects for existing save files -- Constructor

		//member
		std::fstream f;

};
