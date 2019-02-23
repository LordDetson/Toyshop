/*
 * ControllerIStream.cpp
 *
 *  Created on: 13 но€б. 2017 г.
 *      Author: ƒмитрий
 */

#include "ControllerIStream.h"

string inputString(istream& stream){
	string str;
	cout<<">> ";
	stream>>str;
	return str;
}

string inputLine(istream& stream){
	string str;
	cout<<">> ";
	stream.get();
	getline(stream,str);
	return str;
}

unsigned int inputUnsignedInt(istream& stream){
	return atoi(inputString(stream).c_str());
}

float inputFloat(istream& stream){
	while(true){
		float input = atof(inputString(stream).c_str());
		if(input > 0)
			return input;
	}
}
