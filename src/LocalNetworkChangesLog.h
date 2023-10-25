/*
 * LocalNetworkChangesLog.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef FILES_LOCALNETWORKCHANGESLOG_H_
#define FILES_LOCALNETWORKCHANGESLOG_H_

class LocalNetworkChangesLog{

	public:

	static LocalNetworkChangesLog start();
	bool updateWithAction();

	private:

		static file checkForFile();
		LocalNetworkChangesLog getFileData();
		file f;

};



#endif /* FILES_LOCALNETWORKCHANGESLOG_H_ */
