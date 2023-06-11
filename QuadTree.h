#ifdef QUADTREE_H
#define QUADTREE_H
#include <vector>
#include <string>

using namespace std;

struct Point{
  int x, y;
  Point(int _x, int _y){
    x = _x;
    y = _y;
  }
  Point(){
    x = 0;
    y = 0;
  }
};

struct Node{
  Node* quadrants[4];
  Point pos;
  string nodeType;
  int data;
  Node(Point p, string nType, int d){
    pos = p;
    nodeType = nType;
    data = d;
    for(int i = 0; i < 4; i++){
      quadrants[i] = nullptr;
    }
  }
  Node(){
    for(int i = 0; i < 4; i++){
      quadrants[i] = nullptr;
    }
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
  public:
    QuadTree(Point topLeft, Point bottomRight);
    int totalPoints(); 
    int totalNodes(); 
    void insert(Point p, int data); 
    vector<Node> list(); 
    int countRegion(Point p, int d); 
    int AggregateRegion(Point p, int d); 
};

/* Nota: Cualquier función adicional que sea implementada optará a puntaje adicional. La cantidad de puntaje extra queda a criterio del profesor. */
#endif
