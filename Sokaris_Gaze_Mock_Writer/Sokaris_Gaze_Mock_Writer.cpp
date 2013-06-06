// Sokaris_Gaze_Mock_Writer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "../Sokaris_View3D/Intersections.ini";
	int choice;

	printf(" ************************************************ \n");
	printf(" ************************************************ \n");
	printf(" ****    Sokaris - Gaze mock writer 0.0.1    **** \n");
	printf(" ************************************************ \n");
	printf(" ************************************************ \n\n");
	cout << "Emplacement du fichier mock : " << filename << "\n";
	cout << "Emplacement du fichier mock : 1=SalleTP 2=MockCouloir\n";
	cin >> choice;

	ofstream fs(filename);
	fs.close();
	float x;
	float y;
	float z;
	double start = GetTickCount();  
	double end;

	cout << "Mocking... \n";
	switch(choice)
	{
	case 1:
		while(1){
			
			for(float i=3.065; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(int i=0; i<30; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << double((rand() % 50)/100.0) << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=0; i>-3.065; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=3.945; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(int i=0; i<30; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=0; i<3.945; i+=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=-3.065; i<3.065; i+=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=3.945; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(int i=0; i<40; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=0; i>-3.945; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			for(float i=3.065; i>-3.065; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << -3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
			}
			ofstream ffs(filename);
			ffs.close();
		   }
		   break;
	case 2:
		while(1){
			Sleep(300);
			end = GetTickCount();
			ofstream fs(filename,ios::app);
			fs << "-10" << " " << double((rand() % 1300 - 300)/100.0) << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs << "-5" << " " << double((rand() % 800 + 200)/100.0) << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs << "7" << " " << double((rand() % 700 - 1000)/100.0) << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs << "10" << " " << double((rand() % 1200 - 1000)/100.0) << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs << double((rand() % 1500 - 500)/100.0) << " " << "2" << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs << double((rand() % 1700 - 1000)/100.0) << " " << "-3" << " " << double((rand() % 300)/100.0) << " " << (end-start)/1000 << "\n";
			fs.close();
		}
		break;
	}
	ofstream ffs(filename);
	ffs.close();
	return 0;
}