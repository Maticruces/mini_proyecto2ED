#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "QuadTree.h"
#include "QuadTree.cpp"

int main() {
    std::ifstream file("worldcitiespop_fixed.csv");
    std::string line;
    QuadTree quadtree;  

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string temp, city_name, population_str, lat_str, lon_str;

        // Leer y descartar las columnas no deseadas
        for (int i = 0; i < 1; ++i) {
            std::getline(ss, temp, ';');
        }

        std::getline(ss, city_name, ';');  

        // Leer y descartar las columnas no deseadas
        for (int i = 0; i < 2; ++i) {
            std::getline(ss, temp, ';');
        }

        std::getline(ss, population_str, ';');  // Quinta columna: población
        std::getline(ss, lat_str, ';');  // Sexta columna: latitud
        std::getline(ss, lon_str, ';');  // Séptima columna: longitud 
        long long population;
        std::stringstream(population_str) >> population;
        
        double lat;  //std::(lat_str) >> lat;
        double lon;  //std::(lon_str) >> lon;   //ERS: esto me quitaba decimales, no era necesario

        
        quadtree.insert(Point(lat, lon, city_name, population),0); //ERS: no estaba separado por comas estaba separado por ;
        cout<< "INSERTADO: " << city_name <<"::" << population <<"::"<< lat <<","<< lon << endl; //!!BANDERA!! relantiza mucho el tiempo !!quitar despues
    }
    


    return 0;
}
