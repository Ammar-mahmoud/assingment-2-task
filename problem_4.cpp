// Name : Ammar Mahmoud Abd El-Hafez
// ID : 20210254

#include <iostream>
#include<string>
using namespace std ;
int main(){
double x1 , y1 , x2 , y2 , m , check ;

// first user enter two points to calculate the slop
cout << "enter X1 : " ;
cin >> x1 ; 
cout << "enter X2 : " ;
cin >> x2 ; 
cout << "enter Y1 : " ;
cin >> y1 ; 
cout << "enter Y2 : " ;
cin >> y2 ; 

m = (y2 - y1) / (x2 - x1) ; //The equation for finding the slope
check = y1 -x1 * m; // constant value
cout << "the slop = " << m << endl << endl ;
// if constant value > 0 print '+' before it
check  > 0 ? cout << "y = " << m << " x + " << ((- x1) * m)+ y1 << endl 
: cout << "y = " << m << " x " << ((- x1) * m)+ y1 << endl ;

}