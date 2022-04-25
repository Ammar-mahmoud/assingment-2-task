#include<iostream>
#include <string>
#include <algorithm>
#include <regex>
using namespace std ;

bool check_complex (string& stri);

int main (){
    string enter = "" ;
    while (enter != "exit")
    {
        int i = 1 , check = 1 , mid_pos;
        double real_sum, complex_sum , deno ;
        string str_num1 , str_num2 , str_num3 , str_num4 ;

        cout << "\nenter the Equation --> (a+bi) ' +, -, /, * ' (c+di) ' don't care about spaces ' or exit : "  ;
        getline(cin , enter);
        enter.erase(remove(enter.begin(), enter.end(), ' '), enter.end());

         if (check_complex(enter)){
            cout << "\nit's a complex number " << endl << endl ;
            if (enter[i]=='-') {
                i++ ;
                check = -1 ;
            }  

            while (!(enter[i]=='+' || enter[i]=='-')){
                str_num1 = str_num1 + enter [i];
                i++ ;
            }
            double part1 = stof(str_num1) * check;

            while (enter[i]!='i'){
                str_num2 = str_num2 + enter [i];
                i++ ;
            }
            double part2 = stof(str_num2) ;

            mid_pos = i + 2;
            i = i + 4;
    
            if (enter[i]=='-') {
                i++ ;
                check = -1 ;
                }
            else {
                check = 1;
            }

            while (!(enter[i]=='+' || enter[i]=='-')){
                str_num3 = str_num3 + enter [i];
                i++ ;
            }
            double part3 = stof(str_num3) * check;

            while (enter[i]!='i'){
                str_num4 = str_num4 + enter [i];
                i++ ;
            }   
            double part4 = stof(str_num4) ;

        
            if( enter[mid_pos] == '+' ) {
                real_sum = part1 + part3;
                complex_sum = part2 + part4;
                complex_sum  >= 0 ? cout<<"Sum = "<<"( " << real_sum << '+' << complex_sum  << "i )" 
                <<endl : cout << "( " << real_sum << complex_sum  << "i )\n" <<endl ;
            }

            else if( enter[mid_pos] == '-' ){
                real_sum = part1 - part3 ;
                complex_sum = part2 - part4 ;
                complex_sum >= 0 ? cout<<"Sum = "<<"( " << real_sum << " + " << complex_sum << "i )"
                <<endl : cout << "( " << real_sum << complex_sum << "i )\n" <<endl ;
            }

            else if ( enter[mid_pos] == '*' ){
                real_sum = ( part1 * part3 ) - ( part2 * part4 ) ;
                complex_sum = ( part1 * part4 ) + ( part2 * part3 ) ;
                complex_sum >= 0 ? cout<<"Sum = "<<"( " << real_sum << " + " << complex_sum << "i )"
                <<endl : cout << "( " << real_sum << complex_sum << "i )\n" << endl ;
            } 

            else if ( enter[mid_pos] == '/' ){
                deno = ( part3 * part3 ) + ( part4 * part4 ) ;
                real_sum =( ( part1 * part3 ) + ( part2 * part4 ) ) / deno ;
                complex_sum = ( ( - part1 ) * part4 + ( part2 * part3) ) / deno ;
                complex_sum >= 0 ? cout<<"Sum = "<<"( " << real_sum << " + " << complex_sum << "i )"
                <<endl : cout << "( " << real_sum << complex_sum << "i )\n" << endl ;
            }}

        else if (enter == "exit"){
            cout << "\nThanks or using FCAI Complex Number Calculator. " << endl ;
            return 0 ;
        }  

        else{
            cout << "\nit's not a complex number, missing brakets or missing all two operand " << endl ;
        }
    }
}

bool check_complex(string& stri){
    regex is_complex1 ("[(]([-]*)[0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)][-+*/][(]([-]*)[0-9]+(\\.[0-9]*)?[-+][0-9]+(\\.[0-9]*)?[i][)]");    
    return regex_match (stri , is_complex1);
}