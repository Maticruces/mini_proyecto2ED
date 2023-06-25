#include "Experimentos.h" //Archivo donde se encuentran los métodos usados para la experimentación

int main(){

    int rep = 20;

    //Para probar los tiempos de inserción se hace un caso a la vez para no sobrecargar el pc
    //cout << "Tiempos promedio para insert(Point p, int data): " << endl;
    //insertTimeReps(100000, rep);
    //insertTimeReps(200000, rep);
    //insertTimeReps(400000, rep);
    //insertTimeReps(800000, rep);//Desde acá es mejor hacer dos rondas de 10 repeticiones para no sobrecargar el pc
    //insertTimeReps(1600000, rep);
    //insertTimeReps(allCitys, rep);

    //Pruebas para countRegion y aggregateRegion
    QuadTree quadtree(Point(0.0, 0.0), Point(180.0, 360.0));
    readCSV("worldcitiespop_fixed.csv", quadtree, allCitys);

    cout << "Tiempos promedio para countRegion(Point p, int d): " << endl << endl;
    Point center (90.0, 180.0);
    cout << "Punto central (" << center.x << ", " << center.y << "): " << endl << endl;
    countRegionTimeReps(quadtree, Point(center), 1, rep);
    countRegionTimeReps(quadtree, Point(center), 25, rep);
    countRegionTimeReps(quadtree, Point(center), 50, rep);
    countRegionTimeReps(quadtree, Point(center), 100, rep);
    countRegionTimeReps(quadtree, Point(center), 150, rep);
    countRegionTimeReps(quadtree, Point(center), 250, rep);
    
    
    cout << endl << "Tiempos promedio para aggregateRegion(Point p, int d): " << endl << endl;
    cout << "Punto central (" << center.x << ", " << center.y << "): " << endl << endl;
    aggregateRegionTimeReps(quadtree, Point(center), 1, rep);
    aggregateRegionTimeReps(quadtree, Point(center), 25, rep);
    aggregateRegionTimeReps(quadtree, Point(center), 50, rep);
    aggregateRegionTimeReps(quadtree, Point(center), 100, rep);
    aggregateRegionTimeReps(quadtree, Point(center), 150, rep);
    aggregateRegionTimeReps(quadtree, Point(center), 250, rep);
    
    return 0;

}
