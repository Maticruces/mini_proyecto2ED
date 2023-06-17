#include <iostream>
#include "QuadTree.h"
using namespace std;

int main(){

    QuadTree plane2D(Point(0.0, -100.0), Point(120.0, 150.0));

    plane2D.insert(Point(40.920404,39.19209), 102929);//Primer dato en este punto
    plane2D.insert(Point(40.920404,39.19209), 2222);//Segundo dato en el mismo punto
    plane2D.insert(Point(40.920404,39.19209), 33333);//Tercer dato en el mismo punto
    plane2D.insert(Point(40.246859,35.51488), 23579);
    plane2D.insert(Point(46.867656,33.583913), 365611);
    plane2D.insert(Point(50.523429,29.461285), 498401);
    plane2D.insert(Point(37.4816667,-83.3252778), 104102);
    plane2D.insert(Point(11.166667,106.316667), 372437);
    plane2D.insert(Point(49.377695,37.621363), 363384);
    plane2D.insert(Point(60.433333,28.45), 607700);

    cout << "Cantidad de Puntos: " << plane2D.totalPoints() << endl;
    cout << "Cantidad de Nodos: " << plane2D.totalNodes() << endl << endl;

    vector<Node> traversalResult = plane2D.list();
    for (int i = 0; i < traversalResult.size(); i++){
    Node nodo = traversalResult[i];
    cout << "Coordenadas: (" << nodo.pos.x << ", " << nodo.pos.y << ")" << endl;
    cout << "Población: ";
    for (int j = 0; j < nodo.data.size(); j++) {
        int data = nodo.data[j];
        cout << data << " ";
    }
    cout << endl << endl;
    }
  
  /*Quad plane2D(Point(0, 0), Point(8, 8));
  
  Node p1(Point(0, 0), 5);
  Node p2(Point(0, 1), 4);
  Node p3(Point(1, 0), 2);
  Node p4(Point(1, 1), 2);
  Node p5(Point(2, 1), 1);
  Node p6(Point(5, 1), 3);
  Node p7(Point(6, 2), 10);
  Node p8(Point(7, 7), 8);
  
  plane2D.insert(&p1);
  plane2D.insert(&p2);
  plane2D.insert(&p3);
  plane2D.insert(&p4);
  plane2D.insert(&p5);
  plane2D.insert(&p6);
  plane2D.insert(&p7);
  plane2D.insert(&p8);
  
  cout << "Cantidad de puntos: " << plane2D.totalPoints() << endl;
  cout << "Puntos ingresados:" << endl;
  printInfo(&p1);
  printInfo(&p2);
  printInfo(&p3);
  printInfo(&p4);
  printInfo(&p5);
  printInfo(&p6);
  printInfo(&p7);
  printInfo(&p8);
  
  cout << "Contenido en la coordenada (5,1): ";

  Node *p = plane2D.search(Point(5, 1));
  
  if(p != NULL) cout << p->data << endl;
  else cout << "No existe el punto." << endl;
  
  // Contenido en la coordenada (5,1): 3

  cout << "Contenido en la coordenada (1,5): ";
  
  p = plane2D.search(Point(1, 5));
  
  if(p != NULL) cout << p->data << endl;
  else cout << "No existe el punto." << endl;
  
  // Contenido en la coordenada (1,5): No existe el punto.*/
  return 0;
}
