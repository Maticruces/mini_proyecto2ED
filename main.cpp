 #include <iostream>
// #include "QuadTree.h"
#include "QuadTree.cpp"
using namespace std;

void printInfo(Node* n){
  cout << "Info:" << endl;
  cout << "Coordenadas: (" << n->pos.x << ", " << n->pos.y << ")" << endl;
  cout << "Población: " << n->pos.nombreciudad <<endl;
  for(int i = 0; i < n->data.size(); i++){
    cout << n->data[i] << " ";
  }
  cout << endl;
  cout << "---------------------" << endl;
}

int main(){
  
  QuadTree plane2D(Point(0.0, -100.0, "NONAME",0), Point(120.0, 150.0, "NONAME",0));
  //Datos del archivo que usaremos pero ingresados a mano por mientras
  Node p1(Point(40.920404,39.19209, "NONAME",0));
  Node p2(Point(40.246859,35.51488, "NONAME",0));
  Node p3(Point(46.867656,33.583913, "NONAME",0));
  Node p4(Point(50.523429,29.461285, "NONAME",0));
  Node p5(Point(37.4816667,-83.3252778, "NONAME",0));
  Node p6(Point(11.166667,106.316667, "NONAME",0));
  Node p7(Point(49.377695,37.621363, "NONAME",0));
  Node p8(Point(60.433333,28.45, "NONAME",0));

  p1.data.push_back(102929);//primer dato en p1
  p1.data.push_back(2000);//segundo dato en p1
  p1.data.push_back(9960);//tercer dato en p1
  p2.data.push_back(23579);
  p3.data.push_back(365611);
  p4.data.push_back(498401);
  p5.data.push_back(104102);
  p6.data.push_back(372437);
  p7.data.push_back(363384);
  p8.data.push_back(607700);

  plane2D.insert(p1.pos, p1.data[0]);
  plane2D.insert(p2.pos, p2.data[0]);
  plane2D.insert(p3.pos, p3.data[0]);
  plane2D.insert(p4.pos, p4.data[0]);
  plane2D.insert(p5.pos, p5.data[0]);
  plane2D.insert(p6.pos, p6.data[0]);
  plane2D.insert(p7.pos, p7.data[0]);
  plane2D.insert(p8.pos, p8.data[0]);
  
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
