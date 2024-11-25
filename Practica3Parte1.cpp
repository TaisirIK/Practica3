#include <iostream>
using namespace std;

struct Point{
    float x;
    float y;
};

int main(){
    int CantCoord = 0;
    cout<< "Por favor, ingrese el numero de coordenadas a analizar: ";
    cin>> CantCoord;

    Point coordinates[CantCoord];

    for(int i = 0; i < CantCoord; i++){
        cout<< "Ingrese la posicion X de la coordenada " << (i + 1) << ": ";
        cin>> coordinates[i].x;
        cout<< "Ingrese la posicion Y de la coordenada " << (i + 1) << ": ";
        cin>> coordinates[i].y;
    }

    for(int i = 0; i < CantCoord; i++){
        if(coordinates[i].x > 0 && coordinates[i].x > 0){
            cout<< "La coordenada " << (i + 1) << " esta en el cuadrante 1" << endl;
        } else if(coordinates[i].x < 0 && coordinates[i].y > 0){
            cout<< "La coordenada " << (i + 1) << " esta en el cuadrante 2" << endl;
        } else if(coordinates[i].x < 0 && coordinates[i].y < 0){
            cout<< "La coordenada " << (i + 1) << " esta en el cuadrante 3" << endl;
        } else if(coordinates[i].x > 0 && coordinates[i].y < 0){
            cout<< "La coordenada " << (i + 1) << " esta en el cuadrante 4" << endl;
        } else if(coordinates[i].x == 0 && coordinates[i].y == 0){
            cout<< "La coordenada " << (i + 1) << " es el punto de origen" << endl;
        } else{
            cout<< "La coordenada " << (i + 1) << " no pertenece a un solo cuadrante o no es valida" << endl;
        }
    }

    for(int i = 0; i < CantCoord; i++){
        float yEsperada = coordinates[i].x + 1;
        if(coordinates[i].y == yEsperada){
            cout<< "La coordenada (" << coordinates[i].x << ", " << coordinates[i].y << ") se encuentra en la ecuacion f(x)=x+1" << endl;
        } else{
            cout<< "La coordenada (" << coordinates[i].x << ", " << coordinates[i].y << ") no se encuentra en la ecuacion f(x)=x+1" << endl;
        }
    }
    
    return 0;
}