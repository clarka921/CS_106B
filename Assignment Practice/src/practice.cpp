#include <iostream>
#include <cctype>
#include "console.h"
#include "simpio.h"
#include "strlib.h"

#include "tokenscanner.h"
#include <fstream>
using namespace std;

//Class declarations
class TokenScanner;

//Function prototype
ifstream infile;
int isalpha( int ch );
string integerToString(int);
int abs(int n );
bool is_e(char c);
bool is_vowel(char c);
bool is_NotProc(int x, string str);
bool is_LastE(int g, int k, char q);
bool is_FirstLetter(int x);
bool letter_BeforeIsVowel(string stra, int x);
bool is_LastLetter(int x, int y);



int main() {

    while (true){

        cout << endl;
        cout << "Enter 0 to quit this shizz" << endl;
        cout << "Enter 1 for division" << endl;
        cout << "Enter 2 for modulus" << endl;
        cout << "Enter 3 to convert from an 'int' to a 'ch'"<< endl;
        cout << "Enter 4 to test your TokenScanner implementation" << endl;
        cout << endl;
        int choice = getInteger("Choose, peasant!: ");
        cout << endl;

        if (choice == 0)  {break;}
        else if (choice == 1) {
            cout << "You have chosen division!" << endl;
            int divid = getInteger("Enter a dividend: ");
            int divis = getInteger("Enter a divisor: ");
            cout << divid/divis << endl;
            cout << endl;
        } else if (choice == 2) {
            cout << "You have chosen modulus!" << endl;
            int divid = getInteger("Enter a dividend: ");
            int divis = getInteger("Enter a divisor: ");
            cout << divid%divis << endl;
            cout << endl;
        } else if (choice ==3){
            cout << "You have chosen to convert!" << endl;
            int num = getInteger("Enter an int: ");
            char ch = char(num + '0');
            cout << ch << endl;
            cout << endl;
        } else if (choice == 4){

            cout << "You have chosen to test your TokenScanner implementation. My expectations are... modest." << endl;

            string loc = "/Users/andrew/Library/Mobile Documents/com~apple~CloudDocs/CS106B/Assignment Practice/res/";
            string file = getLine("Enter a file name: ");
            string path = loc + file;
            cout << path << endl;
            infile.open(path.c_str());


            TokenScanner scanner(infile);
            scanner.ignoreWhitespace();
            scanner.addWordCharacters("'");
            int wordCounter = 0;
            int sentenceCounter = 0;
            int syllableCounter = 0;
            while (scanner.hasMoreTokens()) {
                string token = scanner.nextToken();
                int syl = 0;
                if (isalpha(token[0]) != 0){
                    wordCounter++;
                    int b = token.length();
                    for(int i = 0; i < b; i++){
                        char w = token[i];
                        if(is_vowel(w) == true && letter_BeforeIsVowel(token, i) == false && is_LastE(i, b, w) == false){
                            syl++;
                            syllableCounter++;
                        }

                    }
                    if (syl == 0){
                        syl++;
                        syllableCounter++;
                    }
                }
                if(token[0]== '!' || token[0]== '.' || token[0]== '?' ){
                    sentenceCounter++;
                }
                cout << token << " " << syl << endl;
            }
            string intNumWords = integerToString(wordCounter);
            string intSenWords = integerToString(sentenceCounter);
            cout << endl;
            cout << "===============" << endl;
            cout << endl;
            cout << "There are " + intNumWords + " words in this file" << endl;
            cout << "There are " + intSenWords + " sentences in this file" << endl;
             cout << "There are " << syllableCounter <<  " syllables in this file" << endl;
            infile.close();
            cout << endl;
        }


    }
    cout << "Exiting......." << endl;
    return 0;
}

//////////////////////
//FUNCTION DEFINITIONS
//////////////////////


bool is_vowel(char c) {
    switch(tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        return true;
    default:
        return false;
    }
}

//////////////////////

bool is_NotProc(int x, string strg){
    if(is_FirstLetter(x) == false && letter_BeforeIsVowel(strg, x) == false){
        return true;
    } else{
        return false;
    }
}

//////////////////////

bool is_FirstLetter(int x){
    if(x == 0){
        return true;
    } else {
        return false;
    }
}

//////////////////////

bool letter_BeforeIsVowel(string stra, int x){
    int prevI = x-1;
    char cha = stra[prevI];
    if(is_vowel(cha) == true){
        return true;
    } else{
        return false;
    }
}

//////////////////////

bool is_LastE(int x, int u, char c){
    if(is_e(c) == true && is_LastLetter(x, u) == true){
        return true;
    }else {
        return false;
    }

//    if last letter in word e, return true
//     else return false
}

//////////////////////

bool is_e(char c) {
    if(tolower(c) == 'e'){
        return true;
    } else {
        return false;
    }
}

//////////////////////

bool is_LastLetter(int x, int y){
    if((x+1) == y){
        return true;
    }else{
        return false;
    }
}




