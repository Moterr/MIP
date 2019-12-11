#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

void n(char *pole){
    FILE *znaky;
    int i;
    char zn;
    i=0;
    if((znaky = fopen("sifra.txt","r"))==NULL){			//naèítanie do pola
        printf("Spravu sa nepodarilo nacitat");
    }
    else{
        while((zn = fgetc(znaky)) != EOF) {
            pole[i] = zn;
            i++;
            }
        fclose(znaky);
    }
}

void v(char *pole){
    int i;
    for(i=0;i<strlen(pole);i++){
    	printf("%c",pole[i]);					//výpis pola
    	if(i==strlen(pole)-1){
    		break;
		}
    }
}

void u(char *pole,char *upravene_pole){			//úprava pola
    int i;
    char pism;
    for(i=0;i<MAX;i++){
    if  (pole[i]>='a' && pole[i]<='z'){			
        pism=pole[i];
        pism=pism+32;
        upravene_pole[i]=pism;
        printf("%c",pism);
    }
    if  (pole[i]>='A' && pole[i]<='Z'){
        pism=pole[i];
        upravene_pole[i]=pism;
    }
    }
}
void s(char *upravene_pole){		//výpis upraveneho pola
    int i,k;
    for(i=0;i<MAX;i++){
        if(upravene_pole[i]!=' '){
            printf("%c",upravene_pole[i]);
            k++;
            }
        if (k==0)
            printf("Nie je k dispozicii upravena sprava\n");
    }
}

void d(char *pole){						//odstranenie medzier a nepísmenkových znakov
    int i,k,j;
    char pdoc[10],zn;
    FILE *znaky;
    k=getchar();
    if((znaky = fopen("sifra.txt","r"))==NULL){
        printf("Spravu sa nepodarilo nacitat");
    }
    else{
    while((zn = fgetc(znaky)) != EOF) {
            while(zn!=' '){
           	 pdoc[i] = zn;
        	i++;}
            if((j-1)==k){
                for(j=0;j<strlen(pdoc);j++)
                    printf("%c",pdoc[j]);
                    if(strlen(pdoc)==j-1){
                        printf("\n");}
            }
            }
    }

}
void p(char *pole){						//spoèítanie velkých a malych pismen
    int i,m,v;
    m=0;
    v=0;
    if (strlen(pole)!=0){
    for(i=0;i<strlen(pole);i++){
        if(pole[i]>='A' && pole[i]<='Z'){
            v++;
        }
        if(pole[i]>='a' && pole[i]<='z'){
            m++;
        }
    }
    printf("%d:%d\n",v,m);
    }
    else{
        printf("Sprava nie je nacitana");
    }
}

void z(char *pole){							
    int z,k,i,j;
    scanf(" %d %d\n",&z,&k);
    if (strlen(pole)!=0 && z<k){

    for(i=0;i<(k-z);i++){           //posun èísel
        for(j=0;j<strlen(pole);j++){
            pole[z+j-1]=pole[k+j-1];
        }
    }
    for(i=0;i<(k-z);i++){       //vymazanie posledných èísel, ktoré sa posunuli
        pole[strlen(pole)-k-z+1+i]=' ';
    }
    printf("Retazec sa zmazal\n");
    }
    else{
        printf("Nie je k dispozicii upravena sprava");
    }
}
/*
void b(){
    int b,k,l;
    char c;
    if(k>=0&&k<=25){
        scanf("%d %c",&b,&c);
        caesar();
        for(i=0;i<strlen(caesar);i++){
            if(caesar[i]==c){
                l++;
            }
        }
        printf("%d",l);
    }
    else{
        printf("Nie je k dispozicii upravena sprava");
    }
}
void caesar(){                  //tu má byt caesarova šifra, ktorú som nespravil k projektu, prepáète :(
    int k,l;
    char p1,p2;
    l=0;
    scanf("%d",&k);
    for(i=0;i<strlen(p1);i++){
        if(p1[i]>='a' && p[i]<='z'){
            p1[i]=p1[i]+32;
        }
    }
    if(p1[i]>='A' && p[i]<='Z'){
        for(i=0;i<strlen(p1);i++){
            if (i>=25-k){
                l=0;
            }
                p2[i]=p1[l]+k;
                l++;

        }
    }

}
*/
int main()
{
    char pole[MAX],upravene_pole[MAX],bod;
    int i;
    scanf("%c",&bod);
    for(i=0;i<MAX;i++){
    	pole[i]='\n';
    	upravene_pole[i]='\n';
	}
    while (bod!='l'){
        scanf("%c",&bod);
        switch(bod){
        case 'k' :
            n(pole);
            break;

        case 'v' :
            v(pole);
            break;

        case 'u' :
            u(pole,upravene_pole);
            break;
        case 's' :
            s(pole);
            break;
        case 'd' :
            d(pole);
            break;
        case 'p' :
            p(pole);
            break;
        case 'z' :
            z(pole);
            break;
        case 'b' :
            //b();
            break;

        }
    }
}






