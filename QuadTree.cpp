#include "QuadTree.h"
#include <cmath>

/**
 * Constructor de la clase QuadTree que inicializa todas las variables con sus valores por defecto.
 */
QuadTree::QuadTree(){
    topLeft = Point(0.0, 0.0);
    bottomRight = Point(0.0, 0.0);
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    bottomLeftTree = nullptr;
    bottomRightTree = nullptr;
    pointCount = 0;
}

/**
 * Constructor de la clase QuadTree que toma como parámetros dos puntos para asignar sus valores 
 * a las variables topLeft y bottomRight.
 * 
 * @param topL Esquina superior izquierda del rectángulo delimitador del QuadTree.
 * @param bottomR Esquina inferior derecha del rectángulo delimitador del QuadTree.
 */
QuadTree::QuadTree(Point topL, Point bottomR){
    topLeft = topL;
    bottomRight = bottomR;
    n = nullptr;
    topLeftTree = nullptr;
    topRightTree = nullptr;
    bottomLeftTree = nullptr;
    bottomRightTree = nullptr;
    pointCount = 0;
}

/**
 * Este método verifica si un punto dado está dentro de los límites del rectángulo definido por topLeft y
 * bottomRight. 
 * 
 * @param p 'p' es un punto (Point).
 * 
 * @return 'inBoundary' retorna un valor booleano. 'true' si el punto está dentro del rectángulo definido o
 * 'false' si no lo está.
 */
bool QuadTree::inBoundary(Point p){
    return (p.x >= topLeft.x && p.x <= bottomRight.x 
            && p.y >= topLeft.y && p.y <= bottomRight.y);
}

/**
 * Este método asigna el tipo de nodo, blanco si representa un cuadrante sin puntos, negro si representa un
 * cuadrante con al menos un punto. 
 * 
 * @param n puntero a un nodo del quadtree.
 */
void QuadTree::setNodeType(Node* n){
    if(n == nullptr){
        return;
    }
    if(n->data.empty()){
        n->nodeType = "white";
    }else{
        n->nodeType = "black";
    }
}

/**
 * Este método nos entrega el tipo de nodo.
 * 
 * @param n puntero a un nodo del quadtree.
 * 
 * @return retorna la propiedad 'nodeType' del nodo solicitado.
 */
string QuadTree::getNodeType(Node* n){
    if(n == nullptr){
        return "";
    }
    return n->nodeType;
}

/**
 * Este método entrega la cantidad de puntos en el QuadTree.
 * 
 * @return 'totalPoints()' retorna un valor entero que representa el número total de puntos almacenados en 
 * el QuadTree.
 */
int QuadTree::totalPoints(){
    return pointCount;
}

/**
 * Este método calcula el total de nodos en el QuadTree.
 * 
 * @return 'totalNodes' retorna un valor entero que representa el número total de nodos en el QuadTree.
 */
int QuadTree::totalNodes(){
    int nodeCount = 1;
    if(topLeftTree != nullptr){
        nodeCount += topLeftTree->totalNodes();
    }
    if(topRightTree != nullptr){
        nodeCount += topRightTree->totalNodes();
    }
    if(bottomLeftTree != nullptr){
        nodeCount += bottomLeftTree->totalNodes();
    }
    if(bottomRightTree != nullptr){
        nodeCount += bottomRightTree->totalNodes();
    }
    return nodeCount;
}

/**
 * Este método inserta un nodo en el QuadTree recibiendo como parámetro un nodo.
 * 
 * @param node El nodo que será insertado en el QuadTree, contiene su ubicación e información adicional.
 * 
 * @note Adaptado de https://www.geeksforgeeks.org/quad-tree/. Se agregan: el contador de puntos, la 
 * asignación de tipo de nodo y se almacenan los punteros de cada nodo a sus 4 hijos. Adicionalmente, se
 * considera que un punto podría ser la posición de más de un dato.
 */
void QuadTree::insert(Node* node){
    if(node == nullptr){
        return;
    }
    if(!inBoundary(node->pos)){
        return;
    }
    if(abs(topLeft.x - bottomRight.x) <= 1 
        && abs(topLeft.y - bottomRight.y) <= 1){
        if(n == nullptr){
            n = node;
            n->nodeType = "black";
            pointCount++;
        }
        return;
    }
    if(n == nullptr){
        node->nodeType = "white";
        n = node;
        pointCount++;
        return;
    }
    node->nodeType = "black";
    if((topLeft.x + bottomRight.x)/2 > node->pos.x){
        if((topLeft.y + bottomRight.y)/2 > node->pos.y){
            if(topLeftTree == nullptr){
                topLeftTree = new QuadTree(
                        Point(topLeft.x, topLeft.y), 
                        Point((topLeft.x + bottomRight.x)/2, 
                              (topLeft.y + bottomRight.y)/2));
            }  
            topLeftTree->insert(node);
            node->quadrants[0] = topLeftTree->n;
        }else{
            if(bottomLeftTree == nullptr){
                bottomLeftTree = new QuadTree(
                        Point(topLeft.x, (topLeft.y + bottomRight.y)/2), 
                        Point((topLeft.x + bottomRight.x)/2, bottomRight.y));
            } 
            bottomLeftTree->insert(node);
            node->quadrants[2] = bottomLeftTree->n;
        }
    }else{
        if((topLeft.y + bottomRight.y)/2 > node->pos.y){
            if(topRightTree == nullptr){
                topRightTree = new QuadTree(
                        Point((topLeft.x + bottomRight.x)/2, topLeft.y), 
                        Point(bottomRight.x, (topLeft.y + bottomRight.y)/2));
            }   
            topRightTree->insert(node);
            node->quadrants[1] = topRightTree->n;
        }else{
            if(bottomRightTree == nullptr){
                bottomRightTree = new QuadTree(
                        Point((topLeft.x + bottomRight.x)/2, 
                              (topLeft.y + bottomRight.y) / 2), 
                        Point(bottomRight.x, bottomRight.y));
            } 
            bottomRightTree->insert(node);
            node->quadrants[3] = bottomRightTree->n;
        }
    }
    pointCount++;
}

/**
 * Este método inserta un nuevo nodo con su punto e información (población) en el QuadTree.
 * 
 * @param p es un punto que representa las coordenadas del nodo que se insertará al QuadTree.
 * @param data es un valor entero que representa la información (población) asociada al nodo que está o 
 * estará en la posición p. Se almacenará en el vector 'data' del nodo.
 * 
 * @note Se crea un nuevo nodo sólo si NO hay un nodo en la posición indicada por p, de lo contrario
 * la información (población) se almacena dentro del vector data del nodo anteriormente creado/insertado
 * en el QuadTree en esa posición.
 */
void QuadTree::insert(Point p, int data){
    if(n != nullptr && n->pos.x == p.x && n->pos.y == p.y){
        n->data.push_back(data);
        return;
    }
    Node* newNode = new Node(p);
    newNode->data.push_back(data);
    insert(newNode);
}

/**
 * Este método entrega un vector con todos los nodos del QuadTree siguiendo un recorrido preorder.
 * 
 * @return 'list()' retorna un vector que contiene todos los nodos del QuadTree.
 */
vector<Node> QuadTree::list(){
    vector<Node> quadData;
    if (n != nullptr) {
        Node currentNode;
        currentNode.pos = n->pos;
        currentNode.data = n->data;
        quadData.push_back(currentNode);
    }
    if(topLeftTree != nullptr){
        vector<Node> subquad = topLeftTree->list();
        quadData.insert(quadData.end(), subquad.begin(), subquad.end());
    }
    if(topRightTree != nullptr){
        vector<Node> subquad = topRightTree->list();
        quadData.insert(quadData.end(), subquad.begin(), subquad.end());
    }
    if(bottomLeftTree != nullptr){
        vector<Node> subquad = bottomLeftTree->list();
        quadData.insert(quadData.end(), subquad.begin(), subquad.end());
    }
    if(bottomRightTree != nullptr){
        vector<Node> subquad = bottomRightTree->list();
        quadData.insert(quadData.end(), subquad.begin(), subquad.end());
    }
    return quadData;
}


/**
 * Este método calcula la cantidad de puntos en una región del plano, tomando como centro el punto p
 * y una distancia d.
 * 
 * @param p es un punto que representa el punto central de una región del plano que se considerará 
 * para los cálculos.
 * @param d es la distancia desde el punto central 'p' que define la región a la cual se le contarán
 * los puntos presentes.
 * 
 * @return retorna el total del puntos presentes en una región del plano centrada en el punto 'p' y 
 * extendida a una distancia 'd' desde este punto.
 */
int QuadTree::countRegion(Point p, int d){
    int regionPoints = 0;
    if(n != nullptr){
        if(abs(n->pos.x - p.x) <= d && abs(n->pos.y - p.y) <= d){
            regionPoints += n->data.size();
        }
    }
    if(topLeftTree != nullptr){
        regionPoints += topLeftTree->countRegion(p, d);
    }
    if(topRightTree != nullptr){
        regionPoints += topRightTree->countRegion(p, d);
    }
    if(bottomLeftTree != nullptr){
        regionPoints += bottomLeftTree->countRegion(p, d);
    }
    if(bottomRightTree != nullptr){
        regionPoints += bottomRightTree->countRegion(p, d);
    }
    return regionPoints;
}

/**
 * Este método calcula la población total en una región del plano, tomando como centro el punto p y 
 * una distancia d.
 * 
 * @param p es un punto que representa el punto central de la región que se requiere.
 * @param d es la distancia desde el punto central 'p' que define la región a la cual se calculará la
 * población.
 * 
 * @return retorna la población total de la región del plano centrada en el punto 'p' y extendida a 
 * una distancia 'd' desde este punto.
 */
int QuadTree::aggregateRegion(Point p, int d){
    int totalPopulation = 0;
    if(n != nullptr){
        if(abs(n->pos.x - p.x) <= d && abs(n->pos.y - p.y) <= d){
            for(int i = 0; i < n->data.size(); i++){
                int data = n->data[i];
                totalPopulation += data;
            }
        }
    }
    if(topLeftTree != nullptr){
        totalPopulation += topLeftTree->aggregateRegion(p, d);
    }
    if(topRightTree != nullptr){
        totalPopulation += topRightTree->aggregateRegion(p, d);
    }
    if(bottomLeftTree != nullptr){
        totalPopulation += bottomLeftTree->aggregateRegion(p, d);
    }
    if(bottomRightTree != nullptr){
        totalPopulation += bottomRightTree->aggregateRegion(p,d);
    }
    return totalPopulation;
}
