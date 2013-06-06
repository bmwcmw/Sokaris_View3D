#include "loadVectors.h"


vector<Plane> readPlanesFromFile(string filename)
{
	const int nbElemPlanes=12;
	vector<Plane> temp;
	ifstream f_input;
	f_input.open(filename.c_str());
	if(!f_input)
	{
		return temp;
	}
	string str_output;
	while(getline(f_input,str_output))
	{
		Plane p;
		stringstream ss(str_output);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vStrings(begin, end);
		//copy(vStrings.begin(), vStrings.end(), ostream_iterator<string>(cout, "\n"));
		if(vStrings.size()!=nbElemPlanes){
			return temp;
		}
		p.point1.x = atof(vStrings[0].c_str());
		p.point1.y = atof(vStrings[1].c_str());
		p.point1.z = atof(vStrings[2].c_str());
		p.point2.x = atof(vStrings[3].c_str());
		p.point2.y = atof(vStrings[4].c_str());
		p.point2.z = atof(vStrings[5].c_str());
		p.point3.x = atof(vStrings[6].c_str());
		p.point3.y = atof(vStrings[7].c_str());
		p.point3.z = atof(vStrings[8].c_str());
		p.point4.x = atof(vStrings[9].c_str());
		p.point4.y = atof(vStrings[10].c_str());
		p.point4.z = atof(vStrings[11].c_str());
		temp.push_back(p);
	}
	f_input.close();
	return temp;
}


vector<Intersection> readIntersectionsFromFile(string filename){
	const int nbElemInts=4;
	vector<Intersection> temp;
	ifstream f_input;
	f_input.open(filename.c_str());
	if(!f_input)
	{
		return temp;
	}
	string str_output;
	while(getline(f_input,str_output))
	{
		Intersection i;
		stringstream ss(str_output);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> vStrings(begin, end);
		//copy(vStrings.begin(), vStrings.end(), ostream_iterator<string>(cout, "\n"));
		if(vStrings.size()!=nbElemInts){
			return temp;
		}
		i.position.x = atof(vStrings[0].c_str());
		i.position.y = atof(vStrings[1].c_str());
		i.position.z = atof(vStrings[2].c_str());
		i.time = atof(vStrings[3].c_str());
		temp.push_back(i);
	}
	f_input.close();

	return temp;
}
