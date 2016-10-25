#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include "ncurses.h"
#include <ctime> //difftime
using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

int main() {
/*    time_t now=time(0);
    struct tm tstruct;
    char buff[80];
    tstruct = *localtime(&now);*/
    time_t now;
    double hora;
    double minuts;
    double segons;
    struct tm temps_llegit;
    char temps[50];
    int i=1;
    do{
    cout << "Entra l'hora (00..24)" << endl;
    cin >> hora;
    }while(hora<0 || hora >24);
    do{
	cout << "Entra els minuts (00..59)" << endl;
	cin >> minuts;
    }while(minuts<0 || minuts>59);
    do{
	cout << "Entra els segons (00..59)" << endl;
	cin >> segons;
    }while(segons <0 || segons>59);
    temps_llegit.tm_hour = hora;
    temps_llegit.tm_min = minuts;
    temps_llegit.tm_sec = segons;
//  temps_llegit.tm_mon = 0;
//  temps_llegit.tm_mday = 1;
   // sprintf(temps, //"%d:%d:%d", hora, minuts, temps);
    //strftime (temps, 50, "%X", temps_llegit); //hora, minuts, segons);
    cout << "Temps entrat = " << temps << "Temps_llegit.tm_hour = " << temps_llegit.tm_hour;
    cout << "currentDateTime()=" << currentDateTime() << endl;
    cout << " now = " << now << endl;
 //   difftime(time_t time1, time_t time0);
    printf("Diferencia de temps(en segons) = %.f", difftime(mktime(&temps_llegit),now));
    /* convertir date to string
	http://stackoverflow.com/questions/16357999/current-date-and-time-as-string

		https://duckduckgo.com/?q=c%2B%2B+difftime+api&t=ffsb&atb=v35-2a_&ia=webxit;
    */ 
    /*do{
    if(difftime(now,mktime(&temps_llegit))==0){
		/*
	http://en.cppreference.com/w/cpp/chrono/duration ?? c++11 ?include<chrono> al head
		*/
		//PlaySound("", NULL, SND_ASYNC);
/*		//beep();
		cout << endl << "ÉS L'HORA?!!!" << endl;
		i=0;
		break;
	}
    else cout << endl << "temps = " << difftime(now,mktime(&temps_llegit));
    }while(i!=0);
//comparacio hora a hora, minuts a minuts i segons a segons ???
*/
    getchar();  // wait for keyboard input
    return (0);
}
