#include "QuadTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

const int allCitys = 3173648;

/**
 * Método para normalizar la latitud, pasamos de [-90,90] a [0,180].
 * @param latitude es un valor doble que representa una coordenada de latitud en grados.
 * @return retorna la latitud normalizada.
 */
double normalizeLatitude(double latitude){
    return (latitude + 90.0) / 180.0 * 180.0;
}

/**
 * Método para normalizar la longitud, pasamos de [-180,180] a [0,360].
 * @param longitude es un valor doble que representa una coordenada de longitud en grados.
 * @return retorna la longitud normalizada.
 */
double normalizeLongitude(double longitude){
    return (longitude + 180.0) / 360.0 * 360.0;
}

/**
 * Método para leer datos desde un archivo CSV, extrae la latitud, longitud y población, normaliza
 * la latitud y longitud e inserta estas coordenadas junto a la población al QuadTree.
 * @param filename es el nombre del archivo CSV que contiene la información que queremos leer.
 * @param quadtree estructura de datos quadtree donde almacenaremos los datos leídos desde el CSV.
 * @param numCitys valor entero para indicar cuantas filas queremos leer desde el archivo CSV, equivalente
 * al número de ciudades que se insertarán.
 */
void readCSV(const string& filename, QuadTree& quadtree, int numCitys){
    ifstream file(filename);
    string line;
    int count = 0;
    getline(file, line);
    while(getline(file, line) && count < numCitys){
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while(getline(ss, token, ';')){
            tokens.push_back(token);
        }
        if(tokens.size() >= 8){
            double latitude = stod(tokens[5]);
            double longitude = stod(tokens[6]);
            int population = stoi(tokens[4]);
            double normLatitude = normalizeLatitude(latitude);
            double normLongitude = normalizeLongitude(longitude);
            quadtree.insert(Point(normLatitude, normLongitude), population);
        }
        count++;
    }
    file.close();
}

/**
 * Método que mide el tiempo que toma insertar la información desde el archivo CSV al quadtree.
 * @param numCitys entero que representa cuantas filas (ciudades) del archivo CSV queremos insertar.
 * @return retorna el tiempo (en microsegundos) que toma insertar un número específico de filas 
 * desde un archivo CSV a un quadtree.
 */
double insertTime(int numCitys){
    QuadTree quadtree(Point(0.0, 0.0), Point(180.0, 360.0));
    auto start = chrono::high_resolution_clock::now();
    readCSV("worldcitiespop_fixed.csv", quadtree, numCitys);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count();
}

/**
 * Método que calcula el tiempo promedio que tarda el método insert en ingresar la información de 
 * un cierto número de filas (ciudades) repitiendo el proceso el número de veces que se indique.
 * @param numCitys cantidad de ciudades que se insertarán.
 * @param rep número de veces que se repetirá el experimento.
 */
void insertTimeReps(int numCitys, int rep){
    long long totalTime = 0;
    for(int i = 0; i < rep; i++){
        double repTime = insertTime(numCitys);
        totalTime += repTime;
    }
    double avgTime = static_cast<double>(totalTime)/rep;
    cout << "Para " << numCitys << " ciudades: " << avgTime << " microsegundos" << endl;
}

/**
 * Método que mide el tiempo que tarda en ejecutarse countRegion en una región a cierta distancia
 * de un punto central.
 * @param center punto que representa el centro de la región considerada.
 * @param distance distancia desde el punto central hacia arriba, abajo, derecha e izquierda. 
 * @return retorna el tiempo (en microsegundos) que tarda en ejecutarse el método countRegion.
 */
double countRegionTime(QuadTree& quadtree, Point center, int distance){
    auto start = chrono::high_resolution_clock::now();
    quadtree.countRegion(center, distance);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count();
}

/**
 * Método que calcula el tiempo promedio que tarda en ejecutarse el método countRegion con un número dado
 * de repeticiones.
 * @param center punto que representa el centro de la región considerada.
 * @param distance distancia desde el punto central hacia arriba, abajo, derecha e izquierda.
 * @param rep representa el número de veces que será llamará a la función countRegion para calcular el tiempo
 * promedio de ejecución.
 */
void countRegionTimeReps(QuadTree& quadtree, Point center, int distance, int rep){
    long long totalTime = 0;
    for(int i = 0; i < rep; i++){
        double repTime = countRegionTime(quadtree, center, distance);
        totalTime += repTime;
    }
    double avgTime = static_cast<double>(totalTime)/rep;
    cout << "Área de " << distance << "x" << distance << ": " << avgTime << " microsegundos" << endl;
}

/**
 * Método que mide el tiempo que tarda en ejecutarse aggregateRegion en una región a cierta distancia
 * de un punto central.
 * @param center punto que representa el centro de la región considerada.
 * @param distance distancia desde el punto central hacia arriba, abajo, derecha e izquierda. 
 * @return retorna el tiempo (en microsegundos) que tarda en ejecutarse el método aggregateRegion.
 */
double aggregateRegionTime(QuadTree& quadtree, Point center, int distance){
    auto start = chrono::high_resolution_clock::now();
    quadtree.aggregateRegion(center, distance);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count();
}

/**
 * Método que calcula el tiempo promedio que tarda en ejecutarse el método aggregateRegion con un número dado
 * de repeticiones.
 * @param center punto que representa el centro de la región considerada.
 * @param distance distancia desde el punto central hacia arriba, abajo, derecha e izquierda.
 * @param rep representa el número de veces que será llamará a la función aggregateRegion para calcular el tiempo
 * promedio de ejecución.
 */
void aggregateRegionTimeReps(QuadTree& quadtree, Point center, int distance, int rep){
    long long totalTime = 0;
    for(int i = 0; i < rep; i++){
        double repTime = aggregateRegionTime(quadtree, center, distance);
        totalTime += repTime;
    }
    double avgTime = static_cast<double>(totalTime)/rep;
    cout << "Área de " << distance << "x" << distance << ": " << avgTime << " microsegundos" << endl;
}
