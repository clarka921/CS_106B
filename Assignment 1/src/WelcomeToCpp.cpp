/*
 * File: WelcomeToCpp.cpp
 * --------------------------
 * Name: [TODO: Andrew Clark]
 * Section: [TODO: My butt]
 * This file is the starter project for the first assignment of CS106B.
 * [TODO: rewrite the documentation]
 *
 * The repeating call sequence is
 *    triggerStackOverflow(137), which calls
 *    164, which calls 685, which calls 203, which calls 327, which calls 549, which calls 137
 *    triggerStackOverflow(137) again.
 */



//////////////////////
//SOURCE FILES
//////////////////////
#include "WelcomeToCpp.h"
#include "random.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <string>
#include "tokenscanner.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;






//////////////////////
//CLASS DECLARATIONS
//////////////////////
class TokenScanner;









//////////////////////
//FUNCTION PROTOTYPES
//////////////////////
int abs(int n );
bool is_e(char c);
bool is_vowel(char c);
bool is_NotProc(int x, string str);
bool is_LastE(int g, int k, char q);
bool is_FirstLetter(int x);
bool letter_BeforeIsVowel(string stra, int x);
bool is_LastLetter(int x, int y);







//////////////////////
//BEGINNING OF ASSIGNMENT CODE
//////////////////////




string flipCoin();

void flipHeads() {
    int coinFlipSentinel = 3;
       int counter = 0;
       Vector<string> vec;

       while (true){

           vec.add(flipCoin());
           if (vec[vec.size()-1] == "heads") {
               counter ++;
           } else {
               counter = 0;
           }
           cout << "Flip: " << vec[vec.size()-1] <<endl;
           if (counter == coinFlipSentinel) break;
       }
       cout << "It took " << vec.size() << " flips to get 3 consecutive heads" << endl;
   }

   string flipCoin() {
       if (randomChance(.5)){
           return "heads";
       } else {
           return "tails";
       }
   }







//////////////////////

int nChooseK(int n, int k) {
   if( n == k || k == 0) {
       return 1;
   } else {
       return nChooseK(n-1, k) + nChooseK(n-1, k-1);
   }
   return 0;
}






//////////////////////

int stringToInt(string str) {
    if(str.length() == 0){
        return 0;
    }else{
          return str[str.length() - 1] - '0' + stringToInt(str.substr(0, str.length() - 1)) * 10;
    }
    return 0;
}





//////////////////////

string intToString(int n) {
    if (n >= 0 && n < 10) {

        char ch = char(n + '0');
        string str(1, ch);
        return str;

    } else if (n < 0 && n > -10) {

        int posM = abs(n);
        char ch = char(posM + '0');
        string str(1, ch);
        return string("-") + str;

    } else if (n < -10) {

        int posN = abs(n);
        string a = intToString(posN/10);
        string b = intToString(posN%10);
        return string("-") + a + b;

    } else if (n > 10) {

        string a = intToString(n/10);
        string b = intToString(n%10);
        return a + b;
    }
    return 0;
}


//////////////////////

DocumentInfo statisticsFor(istream & source) {


    DocumentInfo docInfo = {0, 0, 0};

    TokenScanner scanner(source);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("'");

    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        int syl = 0;

        if(token[0]== '!' || token[0]== '.' || token[0]== '?' ){
            docInfo.numSentences++;
        }
        if (isalpha(token[0]) != 0){
            docInfo.numWords++;

            int b = token.length();
            for(int i = 0; i < b; i++){
                char w = token[i];
                if(is_vowel(w) == true && letter_BeforeIsVowel(token, i) == false && is_LastE(i, b, w) == false){
                    syl++;
                    docInfo.numSyllables++;

                }
            }
            if (syl == 0){
                docInfo.numSyllables++;
            }
        }
    }
    return docInfo;
}

//////////////////////


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

//////////////////////
//END/END/END/END/END/
//////////////////////



