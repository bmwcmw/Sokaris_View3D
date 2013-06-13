// Sokaris_Gaze_Mock_Writer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string filename = "Intersections.ini";

	int choice=1;

	printf(" ************************************************ \n");
	printf(" ************************************************ \n");
	printf(" ****    Sokaris - Gaze mock writer 0.0.3    **** \n");
	printf(" ************************************************ \n");
	printf(" ************************************************ \n\n");
	cout << "Emplacement du fichier mock : " << filename << "\n\n";
	//cout << "Choisir la simulation : 1=SalleTP 2=MockCouloir\n\t";
	//cin >> choice;

	float x;
	float y;
	float z;
	double start = GetTickCount();
	double end;

	cout << "Mocking... \n";
	string filenameN = "IntersectionsHN.ini";
	string filenameW = "IntersectionsHW.ini";
	string filenameE = "IntersectionsHE.ini";
	string filenameS = "IntersectionsHS.ini";
	ofstream fs(filename);
	fs.close();
	ofstream fsN(filenameN);
	fsN.close();
	ofstream fsS(filenameS);
	fsS.close();
	ofstream fsE(filenameE);
	fsE.close();
	ofstream fsW(filenameW);
	fsW.close();
	switch(choice)
	{
	case 1:
		while(1){
			ofstream ffs(filename);
			ffs.close();
			ofstream ffsN(filenameN);
			ffsN.close();
			for(float i=3.065; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsN(filenameN,ios::app);
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsN.close();
			}
			for(int i=0; i<30; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << double((rand() % 50)/100.0) << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << double((rand() % 50)/100.0) << " " << 3.945 << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsN(filenameN,ios::app);
				fsN << ceil((rand() % 50 + 307)) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsN << ceil((rand() % 50 + 307)) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsN.close();
			}
			for(float i=0; i>-3.065; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsN(filenameN,ios::app);
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsN.close();
			}
			for(float i=3.945; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsW(filenameW,ios::app);
				fsW << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsW << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsW.close();
			}
			for(int i=0; i<30; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << -3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsW(filenameW,ios::app);
				fsW << ceil((rand() % 50 + 395)) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsW << ceil((rand() % 50 + 395)) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsW.close();
			}
			for(float i=0; i<3.945; i+=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << -3.065 << " " << i << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsW(filenameW,ios::app);
				fsW << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsW << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsW.close();
			}
			for(float i=-3.065; i<3.065; i+=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << i << " " << 3.945 << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsN(filenameN,ios::app);
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsN << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsN.close();
			}
			for(float i=3.945; i>0; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsE(filenameE,ios::app);
				fsE << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsE << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsE.close();
			}
			for(int i=0; i<40; i++){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << 3.065 << " " << double((rand() % 50)/100.0) << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsE(filenameE,ios::app);
				fsE << ceil((rand() % 50 + 395)) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsE << ceil((rand() % 50 + 395)) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsE.close();
			}
			for(float i=0; i>-3.945; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << 3.065 << " " << i << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsE(filenameE,ios::app);
				fsE << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsE << ceil((i+3.945)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsE.close();
			}
			for(float i=3.065; i>-3.065; i-=0.1){
				Sleep(40);
				end = GetTickCount();
				ofstream fs(filename,ios::app);
				fs << i << " " << -3.945 << " " << double((rand() % 30 + 170)/100.0) << " " << (end-start)/1000 << "\n";
				fs << i << " " << -3.945 << " " << double((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)/100.0) << " " << (end-start)/1000 << "\n";
				fs.close();
				ofstream fsS(filenameS,ios::app);
				fsS << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170)) << "\n";
				fsS << ceil((i+3.065)*100) << " " << ceil((rand() % 30 + 170 + gaussLimited(1,-1.5)*100)) << "\n";
				fsS.close();
			}
			system("python D:\\DEV\\GitHub\\pyheatmap\\drawHeatmap.py");
			cout << "HeatMap g¨¦n¨¦r¨¦ avec succ¨¨s...\n";
			cin >> choice;
		   }
		   break;
	case 2:
		while(1){
			cout << " Attention : Map mal choisi "<< gaussLimited(1.5,-1.5) << "\n";
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