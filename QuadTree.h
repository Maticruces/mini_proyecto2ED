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
  Point pos;
  string nodeType;
  int data;
  vector<Node*> quadrants;
  Node(Point _pos, int _data){
    pos = _pos;
    data = _data;
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

/* Nota: Cualquier función adicional que sea implementada optará a puntaje adicional. La cantidad de puntaje extra queda a criterio del profesor. */
#endif
