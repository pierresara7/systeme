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
sprintf(nom,"theme/%s.txt",theme);
FILE* fichier = NULL;
fichier = fopen(nom, "a+");
sprintf(complet,"\n%d%d%d#%d%d%d#%s#%s",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond,msg,pseudo);//# sera un separateur pour recuperer les diff�rentes information
//fputs(complet,fichier);
fprintf(fichier,complet);
printf("%s",complet);
// format du fichier pour chaque ligne date#heure#msg#pseudo
fclose(fichier);

}
void nouveauMessage(){
char theme[30];
char msg[81];
printf("Entrer votre message : ");
fgets(msg,81, stdin);
msg[strlen(msg)-1]='\0'; //enl�ve le '\n'
printf("%s",msg);
printf("Entrer le theme : \n ");
scanf("%s",theme);
posterMessage(theme,msg,"alphonse");

}
void connexion(char pseudo[]){

}
int main(int argc, CHAR* argv[])
{
nouveauMessage();
    return 0;
}
