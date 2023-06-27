#include <string>
#include <vector>
using namespace std;

/**
 * @brief 'Point' define una estructura de datos que representa un punto en un sistema de coordenadas 2D.
 * 
 * Contiene dos variables de tipo double, 'x' e 'y', que representan las coordenadas del punto en el plano.
 * 
 * Tiene además, dos constructores: uno que toma como parámetro dos valores 'double' e inicializa 'x' e 'y'
 * con estos valores. Y otro sin parámetros que inicializa ambas variables en 0.0.
 */
struct Point{
    double x, y;
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    Point(){
        x = 0.0;
        y = 0.0;
    }
};

/**
 * @brief ' Node' define una estructura de datos de tipo nodo para la clase QuadTree.
 *
 * Contiene un punto 'pos' que representa la posición del nodo, una variable string 'nodeType' que representa
 * el tipo de nodo ("white" o "black"), un vector<int> 'data' que almacena información asociada al nodo 
 * (población para esta implementación) y un vector<Node*> 'quadrants' que almacena 4 enlaces a otros nodos 
 * representando cuadrantes del plano.
 * 
 * Tiene 2 constuctores: uno que toma un punto como parámetro y asigna la posición del nodo, además de 
 * inicializar el resto de variables. Y otro constructor sin parámetros que inicializa las variables con 
 * sus valores por defecto.
 */
struct Node{
    Point pos;
    string nodeType;
    vector<int> data;
    vector<Node*> quadrants;
    Node(Point _pos){
        pos = _pos;
        nodeType = "";
        data.clear();
        quadrants.resize(4, nullptr);
    }
    Node(){
        pos.x = 0.0;
        pos.y = 0.0;
        nodeType = "";
        data.clear();
        quadrants.resize(4, nullptr);
    }

};

/**
 * Definición de la clase 'QuadTree' que representa una estructura de datos quadtree.
 */
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
        void setNodeType(Node* n);
        string getNodeType(Node* n);
    public:
        QuadTree();
        QuadTree(Point topLeft, Point bottomRight);
        int totalPoints();
        int totalNodes();
        void insert(Node* node);
        void insert(Point p, int data);
        vector<Node> list();
        int countRegion(Point p, int d);
        int aggregateRegion(Point p, int d);
};
