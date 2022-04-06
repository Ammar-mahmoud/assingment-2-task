// Name : Ammar Mahmoud Abd EL-Hafez 
// ID : 20210254 

#include<iostream>
#include<string>
#include<map> //to make a value of each letter 
#include<sstream>
#include<cctype>
#include <algorithm> // to convert to lowercase 

using namespace std ;

string message , the_conversion , Cipher ;
int choose = 0; // the user choose the service he wants
istringstream input("");

map < char , string > conversion{
    {'a' , "aaaaa"} , {'b' , "aaaab"} , {'c' , "aaaba"} , {'d' , "aaabb"} ,
    {'e' , "aabaa"} , {'f' , "aabab"} , {'g' , "aabba"} , {'h' , "aabbb"} ,
    {'i' , "abaaa"} , {'j' , "abaab"} , {'k' , "ababa"} , {'l' , "ababb"} ,
    {'m' , "abbaa"} , {'n' , "abbab"} , {'o' , "abbba"} , {'p' , "abbbb"} ,
    {'q' , "baaaa"} , {'r' , "baaab"} , {'s' , "baaba"} , {'t' , "baabb"} ,
    {'u' , "babaa"} , {'v' , "babab"} , {'w' , "babba"} , {'x' , "babbb"} ,
    {'y' , "bbaaa"} , {'z' , "bbaab "} 
}; // each letter of the plaintext is replaced by a group of five of the letters 'a' or 'b'

void to_Baconian_Cipher(); 
void to_real_message();

int main(){ 
    while(!(choose == 1 || choose == 2)){
        cout << "1) convert to Baconian Cipher --- 2) convert to the message : " << endl;
        cin >> choose ;
        cin.ignore(); // to exit from cin mode then i can use getline cin mode
        if (choose == 1){
            to_Baconian_Cipher(); // the output is cipher
            break ;             
        }
        else if (choose == 2){
            to_real_message(); // the output is real words
            break;
        }}}

void to_Baconian_Cipher(){
    cout << "enter the message to convert : " ;  
    getline(cin , message); // to take all message not only first word
    // to convert the message to lowercase because only small litters has a value
    transform(message.begin(), message.end(), message.begin(), ::tolower); 
    for (char character : message){
        cout << conversion[character] << " "; // give the value of each litter
    }
    cout <<"\n";
}

void to_real_message(){
    cout << "enter the Baconian Cipher message : ";
    getline(cin , Cipher);
    input.str(Cipher);
    input >> the_conversion;
    while(input){ // path through each value and give its litter
        for (char character = 97 ; character < 125 ; character++ ){ // try all characters if character = 
            if (conversion[character] == the_conversion){
                cout << character ;
            }}
        input >> the_conversion; // 1 bit offset
    }
    cout << "\n";
}
