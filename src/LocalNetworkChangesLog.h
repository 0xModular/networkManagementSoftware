/*
 * LocalNetworkChangesLog.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Light
 */

#ifndef SRC_LOCALNETWORKCHANGESLOG_H_
#define SRC_LOCALNETWORKCHANGESLOG_H_

class LocalNetworkChangesLog{

	public:

	static LocalNetworkChangesLog start();
	bool updateWithAction();

	private:

		static file checkForFile();
		LocalNetworkChangesLog getFileData();
		file f;

};



#endif /* SRC_LOCALNETWORKCHANGESLOG_H_ */
