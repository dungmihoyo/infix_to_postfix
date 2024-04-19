#include<iostream>
#include<string> 
#include"stack.h"

using namespace std ; 

int Take_number (string &expresion ) { 

    int num; 
    int lenght = expresion.length();
    // Khoi tao bien luu tru number trong chuoi 
    int number = 0;

    // Khoi tao vong lap truy cap vao tung phan tu trong chuoi 
    for ( int i = 0; i < lenght; i ++){ 

        // Neu gap ki tu la so 
        if (isdigit(expresion[i])) { 
            // Gan num bang gia tri cua ki tu do 
            num =  expresion[i] - '0'; 
            //Neu number = 0 gan gia tri moi cua number = num 
            if(number == 0 ) { 
                number = num; 
            }
            // neu number dang luu tru gia tri, cap nhat don vi gia tri do roi cong gia tri moi vao 
            else { 
                number *= 10; 
                number += num; 
            }
        }
        // neu khong phai la ki tu thi dung vong lap va tra ve gia tri so 
        if (!isdigit(expresion[i]) ){ 
            break; 
        }
    }
    // tra ve gia tri so duoc tach 
    return number ; 
}

// void DeleteElement(string &temp){ 
//     int length = temp.length();
//     for ( int i=0 ; i <length; i++) { 
//         temp.erase(temp.begin()); 
//         if (!isdigit(temp[0])) { break; }
//     }
// }

// Ham xao khang tang trong chuoi 
string DeleteSpace (string expresion) { 
    string temp = expresion; 
    int i = temp.length() ; 
    while ( i >= 0 ){
        if (expresion[i] == ' ') { 
           temp.erase(temp.begin() +i) ; 
        }
        i--; 
    }
    return temp ; 
}

int Prioritize( char token){

    if ( token == '('){ 
        return 0 ; 
    }
    if ( token == '+' || token == '-' ){ 
        return 1 ; 
    }
    if ( token == '*' || token == '/' || token == '%'){ 
        return 2 ; 
    }
}

void Transform( string infix, string &postfix){ 
    
    char element , prev, swap; 
    Stack<char> token ;

    infix = DeleteSpace(infix) ;
    int length = infix.length() ;
    for ( int i = 0; i < length; i++){ 

        element = infix[i] ; 

        if(isdigit(element)) { 
            postfix.push_back(element); 
        }

        // if (element = ')'){ 
        //     while (prev = token.Pop() != '('){ 
        //         if ( Prioritize(prev) <= Prioritize(token.GetTop())){ 
        //             postfix.push_back(token.Pop()) ; 
        //             postfix.push_back(' ') ;
        //             token.Push(prev) ; 
        //         }
        //         else { 
        //             postfix.push_back(prev) ; 
        //             postfix.push_back(' ') ;
        //         }
        //     }
        // }       

        if (!isdigit(element)){

            postfix.push_back(' ') ; 

            // if (element == ')'){ 
            //     while (token.GetTop() != '(' && !token.IsEmpty()){ 
            //         prev = token.Pop(); 
            //         postfix.push_back(prev) ; 
            //         postfix.push_back(' ') ; 
            //     }
            // }
            if (token.IsEmpty()) { 
                token.Push(element) ; 
            } 
            else { 

                if (Prioritize(element) < Prioritize(token.GetTop())) { 
                    while (!token.IsEmpty()){ 
                        postfix.push_back(token.Pop()) ; 
                        postfix.push_back(' ') ; 
                    }
                    token.Push(element) ; 
                }
                else { 
                    token.Push(element) ; 
                }
            }
        }
        if ( i == length - 1 ) { 
            postfix.push_back( ' ' ) ; 
        }
    }
    while(!token.IsEmpty()){ 
        postfix.push_back(token.Pop()); 
        postfix.push_back(' ') ; 
    }
}


int main ( ) { 
    
    int number ; 
    // Khoi tao chuoi bieu thuc trung to 
    string infix_expresion ; 
    
    // khoi tao chuoi bieu thuc hau to 
    string postfix_expresion ; 

    // Khoi tao Stack so nguyen luu tru cac so o trong chuoi 
    Stack<int> num_in_expresion ;
     
    // Nhap vao chuoi phep tinh 
    cout << "Enter Infit-Epression : " ; 
    getline(cin, infix_expresion);
    
    Transform(infix_expresion, postfix_expresion) ; 
    cout << postfix_expresion<< endl; 

    
    return 0 ; 

}
