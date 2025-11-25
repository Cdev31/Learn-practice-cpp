#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <utility>

using namespace std;

// Ejercicio 1
void isEvenOrOdd(){

    int number ;
    cout << "Ingrese un numero: \n";
    cin >> number;

    ( number%2 == 0 ) 
       ? cout << "El numero: " << number << " es par \n"
       : cout << "El numero: " << number << " es impar \n";
}

// Ejercicio 2
void maxMinArrayValue(){
    
    int numbers[10] ={0};

    cout << "Ingrese sus numeros: \n";
    for (size_t i = 0; i < 10; i++)
    {
        int number;
        cin >> number;
        numbers[i] = number;
    }

    int indexMaxNumber = 0;
    int indexMinNumber = 0;

    for( size_t i = 1; i < 10; i++){
        ( numbers[indexMaxNumber] < numbers[i] ) && (indexMaxNumber = i);
        ( numbers[indexMinNumber] > numbers[i] ) && (indexMinNumber = i);
    }

    cout << "El elemento mas grande es: " << numbers[indexMaxNumber] << endl;
    cout << "El elemento mas pequeno es: " << numbers[indexMinNumber] << endl;
    
}

// Ejercicio 3
void readAllVowels(){

    string phrase;
    cout << "Ingrese su frase: " << endl;
    getline(cin, phrase);

    int totalVowels = 0;
    for( char letter : phrase){

        if( isalpha(letter)){
            letter = tolower(letter);
            if( 
                letter == 'a' || letter == 'e' || letter == 'i' || 
                letter == 'o' ||  letter == 'u'
            ){
                totalVowels++;
            }
        }
    }
    cout << "El total de vocales es: " << totalVowels << endl;
}

// Ejercicio 21
void polynomialCalculator(){

    string polynomial;

    cout << "Ingrese su polinio: \n";
    getline(cin, polynomial);

    

}

void executeFunction (){
    readAllVowels();
}