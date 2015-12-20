#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void heureCourant (){
    SYSTEMTIME t;
GetSystemTime(&t);
printf("Date:%d-%d-%d Heure:%d:%d:%d ",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);
}

void posterMessage(char theme[30],char msg[300],char pseudo[10]){
char nom[30];
char complet[300]; // msg+pseudo
 SYSTEMTIME t;
GetSystemTime(&t);
sprintf(nom,"%s.txt",theme);
FILE* fichier = NULL;
fichier = fopen(nom, "a+");
sprintf(complet,"%d%d%d#%d%d%d#%s#%s",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond,msg,pseudo);
fputs(complet,fichier);
printf("%s",complet);
fclose(fichier);

}
int main()
{
    posterMessage("math","a+b","alphonse");
    return 0;
}
