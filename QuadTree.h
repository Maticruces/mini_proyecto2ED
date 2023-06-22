#ifndef QUADTREE_H
#define QUADTREE_H
#include <vector>
#include <string>
#define nullptr NULL

using namespace std;

struct Point{
  double x, y;
  string nombreciudad;  //x:horizontal:longitud   &   y:vertical:latitud ... En coordenadas va (y,x) Latitud,Longitud "a LA.LO le gusta la geografia"
  long pobla;
  Point(double _x, double _y, string nm, long po){  //caso con parametros
      x = _x;
      y = _y;
      nombreciudad = nm;
      pobla = po;
      
  }
  Point(){  //en caso de no poner parametros
      x = 0.0;
      y = 0.0;
      nombreciudad = "NO_GESTIONADO";
      pobla = 0;
  }
};  

struct Node{
  Point pos;
  string nodeType;
  vector<int> data;
  vector<Node*> quadrants;
  Node(Point _pos){
      pos = _pos;
      data.clear();
      quadrants.resize(4, nullptr);
  }
};

class QuadTree{
  private:
    Point topLeft;
    Point bottomRight;
    Node* n;
    QuadTree* topLeftTree;
    QuadTree* topRightTree;
    QuadTree* bottomLeftTree;
    QuadTree* bottomRightTree;
    int pointCount;
    bool inBoundary(Point p);
  public:
    QuadTree();
    QuadTree(Point topLeft, Point bottomRight);
    int totalPoints();
    int totalNodes();
    void insert(Node* node);
    void insert(Point p, int data);//auxiliar para el otro insert
    vector<Node> list(); 
    int countRegion(Point p, int d); 
    int AggregateRegion(Point p, int d); 
};


#endif

/* Nota: Cualquier función adicional que sea implementada optará a puntaje adicional. La cantidad de puntaje extra queda a criterio del profesor. */

