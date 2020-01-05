#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <map>
#include <vector>

using namespace std;

int duhovi, prinosi;
vector <int> target;
vector <int> zrtva;
map <int, int> m;
int a;
int n;
vector <int> pokusaj[5];
vector <char> rez[5];

int main(){

srand(time(NULL));

cout <<"Enter the number of ghosts!\n"; cin >>duhovi; n=duhovi;
cout <<"Enter the number of different offers!\n"; cin >>prinosi;

for(int i=0; i<duhovi; i++)zrtva.push_back(0);

for(int i=0; i<duhovi; i++){

    a=rand()%prinosi + 1;
    target.push_back(a); m[a]++;

}

//for(int i=0; i<duhovi; i++)cout <<target[i]<<' '; cout <<endl;

for(int j=0; j<3 && n>0; j++){

    for(int i=0; i<duhovi; i++){

        if(zrtva[i]!=target[i]){
            cout <<"Enter the index for the offering to the ghost "<<i+1<<endl;
            cin >>a; zrtva[i]=a;
            pokusaj[j+1].push_back(a);
            if(zrtva[i]==target[i]){m[a]--; n--;}
            }
        else{ pokusaj[j+1].push_back(0);}

        }

    for(int i=0; i<duhovi; i++){
        if(zrtva[i]==target[i]){
            if(pokusaj[j+1][i]==0)rez[j+1].push_back('-');
            else rez[j+1].push_back('G');
        }
        if(zrtva[i]!=target[i]){

            if(m[zrtva[i]]==0){
                rez[j+1].push_back('R'); //cout <<"Nikome ne treba prinos: "<<zrtva[i]<<endl;
            }
            else rez[j+1].push_back('Y');
        }
    }

    for(int k=1; k<=j+1; k++){
        for(int i=0; i<duhovi; i++)
            cout <<pokusaj[k][i]<<rez[k][i]<<' ';
        cout <<endl;
    }
}

if(n==0)cout <<"Congrats! :D :D"<<endl;

return 0;
}
