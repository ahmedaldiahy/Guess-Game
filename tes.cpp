#include "tes.h"

int siz;
char ch;
char b;
int in;
int arr[26] = {0};
int idx = 0;
int ctn = 0;
int ag;
int t;
char pos;
string s = "";

char characterFound(char b){
    while(b != 'y' && b != 'n'){
        clrscr();
        cout<<"write a valid letter y/n"<<endl;
        cin>>b;
    }
    return b;
}
int integerFound(int n){
    cin>>n;
    while(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        clrscr();
        cout<<"enter a valid number"<<endl;
        cin>>n;
    }
    return n;
}
int indexCorrect(int in){
    while(1){
        if(in >= 0 && in <= siz && s[in-1] == '.') return in;

        if(in < 0 || in > siz){
            clrscr();
            cout<<"your entered an index that is out of your word length"<<endl;
            cout<<"enter another index starting from index 1"<<endl;
            in = integerFound(in);
        }else if(s[in-1] != '.'){
            clrscr();
            cout<<"there's a character in this position already "<<endl;
            cout<<"if you wrote the wrong position to your current character and want to try again press 'y'"<<endl;
            cout<<"else if your ruined things up press 'n'"<<endl;
            cin>>pos;
            pos = characterFound(pos);
            if(pos == 'n') return -1;
            clrscr();
            cout<<"write the new position"<<endl;
            cin>>in;
        }
    }

}

int agree(char b, int n){
    while(1){
        clrscr();
        cout<<"if the position is wrong enter 1"<<endl;
        cout<<"if the character is wrong enter 2"<<endl;
        t = integerFound(t);
        if(t == 1){
            clrscr();
            cout<<"enter the position"<<endl;
            n = integerFound(n);
            n = indexCorrect(n);
            return n;
        }else if(t == 2){
            return -1;
        }else{
            cout<<"please enter 1 or 2"<<endl;
        }
    }
}

void clrscr()
{
    system("@cls||clear");
}

