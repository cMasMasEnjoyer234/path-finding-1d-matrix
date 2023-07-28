#include <iostream>
#include <string>
#include <windows.h>
#include <memory>
#include <stdlib.h>

#include <sstream> 
#include <cctype>

using namespace std;

class nums{

    public: 
        int max;
        int max2;
        unique_ptr<int[]>matrix;

    public: 
        nums(int argumento){
            max = INT_MIN;
            max2 = INT_MIN;
            matrix = make_unique<int[]>(argumento);
        }
    public:
        int finder(int total_n,int n,int a, int b, int num);
          
};

int nums::finder(int total_n,int n,int a, int b, int num){

    for ( int i = 0; i < total_n; i++){ // this just make a random number and put it on matrix.
        num = a + rand() % b;
        matrix[i] = num;
    }

    // this whole for is for finding the the biggest number.

    for (int j = 0; j < n; j++){
        if (max < matrix[j]){ // max are always less than matrix, when is true (usually) try finding but the half of the matrix, then save the big one
                
            for (int x = 0; x < 1; x++){
                for (int y = 0; y < n; y++)
                {
                    if (max < matrix[y]){
                        max = matrix[y];
                    }
                } 
            }
        
        }else{ // same as up.
                
            for (int x = 0; x < 1; x++){
                for (int y = n; y < total_n; y++)
                {
                    if (max2 < matrix[y]){
                        max2 = matrix[y];
                    }
                }
            }
                

        }
                
    }   
    return 0;

}

int excepcion(){

    while (true){
        system("cls");
        string Res_String;
        cout << "cuantos numeros pondra?: ";cin >> Res_String;

        int buttom = 0;
        for (char c : Res_String) {
            if (!std::isdigit(c)) {
                cout << "No ponga caracteres! " << endl;
                buttom = 0;
                Sleep(1000);
            }else
            {
                buttom = 1;
            }   
        }

        istringstream iss(Res_String);
        int total_n;
        iss >> total_n;

        if (total_n > 0)
        {
            if (buttom != 0 && total_n % 2 == 0)
            {
                return total_n;
                break;
            }else
            {
                cout << "Poner numeros pares." << endl;
                Sleep(1000);   
            }
                    
        }

    }


}

int main(){
    unique_ptr<nums> ptrNums;

    while (true){


        int n;
        int a = 1, b = 100;
        int num;
        int arg = 1;
      

        int total_n = excepcion();

        int matrix[total_n];

        system("cls");
        n = total_n/2;


        //..........
        ptrNums = make_unique<nums>(total_n);
        ptrNums->finder(total_n,n,a,b,num);   
        
        //..................
        // after the finder, i save the max 1 and 2 for better readable code.
        int max = ptrNums->max;
        int max2 = ptrNums->max2;
        //................  

        for (int y= 0; y < n; y++)// here i print the first half 
        {
            cout << "|"<< ptrNums->matrix[y] << "|";
        }
        cout << endl;
        cout << "Peak max 1 = " << max << endl;
        //...
        for (int y= n; y < total_n; y++)// and here the last part.
        {
            cout << "|"<< ptrNums->matrix[y] << "|";
        }
        cout << endl;
        cout << "Peak max 2 = " << max2 << endl;
        
        cout << endl;
        //,,,

        for (int i = 0; i < total_n; i++){
            cout << "|"<< ptrNums->matrix[i] << "|";
        }
        cout << endl;


        //..................................................

        if (max > max2){//and it ended up whith a compare and cout who is the biggest num.
            cout << "El peak es: "; cout << max;
        }else{
            cout << "El peak es: "; cout << max2;
        }
    
    

        cout << endl;

    
 
        string close;
        cout << "desea otra operacion?: ";cin >> close;
        if (close != "s"){break;}
        
    }
    


    return 0;
}
