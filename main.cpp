#include <iostream>
#include "tes.h"

using namespace std;

int main(){

    cout<<"enter the size of your word"<<endl;
    cin>>siz;
    for(int i = 0; i < siz; i++) s+='.';
    cout<<s<<endl<<endl;

    while(ctn != siz){
        ch = 'a' + idx;
        clrscr();
        cout<<"Is your word has "<<"% "<<ch<<" %"<<" character      "<<"y/n :"<<endl;
        cin>>b;
        if(b != 'y' || b != 'n') b = characterFound(b);
        while(b == 'y'){
                clrscr();
                cout<<"write its position in your word starting from index 1"<<endl;
                in = integerFound(in);
                in = indexCorrect(in);
                if(in == -1){
                    cout<<"No problem try again the next time"<<endl;
                    return 0;
                }
                s[in-1] = ch;
                clrscr();
                cout<<"like that "<<s<<"   y/n :"<<endl;
                cin>>b;
                b = characterFound(b);

                while(b == 'n'){
                    s[in-1] = '.';
                    ag = agree(b, in);
                    if(ag == -1){
                        s[in-1] = '.';
                        ctn--;
                        b = 'y';
                    }else{
                        s[ag-1] = ch;
                        b = 'y';
                    }
                }
                ctn++;
                if(ctn == siz) break;
                clrscr();
                cout<<"Is your word has another "<<"% "<<ch<<" %"<<" character     "<<"y/n :"<<endl;
                cin>>b;
                b = characterFound(b);
        }
        idx++;
    }
    cout<<endl;
    cout<<"\"I won the word is \" "<<"% "<<s<<" %"<<"   hahaha !"<<endl;
    cout<<endl;
}
