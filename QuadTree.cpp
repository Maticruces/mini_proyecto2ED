#include "QuadTree.h"  //t mayuscula !!!!!!!
#include <cmath>

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

bool QuadTree::inBoundary(Point p){ 
    return (p.x >= topLeft.x && p.x <= bottomRight.x && p.y >= topLeft.y && p.y <= bottomRight.y);
}//indica si un punto está dentro del quadtree definido en main

int QuadTree::totalPoints(){//Retorna la cantidad de puntos almacenados en el QuadTree
    return pointCount;
} 

int QuadTree::totalNodes(){//Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
    int nodeCount = 1;//Parte en uno porque siempre tenemos nodo raíz
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

void QuadTree::insert(Node* node){
    if(node == nullptr){
        return;
    }
    if(!inBoundary(node->pos)){
        return;
    }
    if(abs(topLeft.x - bottomRight.x) <= 1 && abs(topLeft.y - bottomRight.y) <= 1){
        if(n == nullptr){
            n = node;
            n->nodeType = "black";
            pointCount++;
        }else{
            n->data.push_back(node->data[0]);
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
    if((topLeft.x + bottomRight.x) / 2 >= node->pos.x){
        if((topLeft.y + bottomRight.y) / 2 >= node->pos.y){
            if(topLeftTree == nullptr){
                topLeftTree = new QuadTree(Point(topLeft.x, topLeft.y), Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2));
            }  
            topLeftTree->insert(node);
            node->quadrants[0] = topLeftTree->n;
        }else{
            if(bottomLeftTree == nullptr){
                bottomLeftTree = new QuadTree(Point(topLeft.x, (topLeft.y + bottomRight.y) / 2), Point((topLeft.x + bottomRight.x) / 2, bottomRight.y));
            } 
            bottomLeftTree->insert(node);
            node->quadrants[2] = bottomLeftTree->n;
        }
    }else{
        if((topLeft.y + bottomRight.y) / 2 >= node->pos.y){
            if(topRightTree == nullptr){
                topRightTree = new QuadTree(Point((topLeft.x + bottomRight.x) / 2, topLeft.y), Point(bottomRight.x, (topLeft.y + bottomRight.y) / 2));
            }   
            topRightTree->insert(node);
            node->quadrants[1] = topRightTree->n;
        }else{
            if(bottomRightTree == nullptr){
                bottomRightTree = new QuadTree(Point((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2), Point(bottomRight.x, bottomRight.y));
            } 
            bottomRightTree->insert(node);
            node->quadrants[3] = bottomRightTree->n;
        }
    }
    pointCount++;
}

//Se ocupará como auxiliar para el insert(Node* node) porque es más sencillo que cambiar todo
void QuadTree::insert(Point p, int data){//Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la información disponible en data (ej. la población de una ciudad con coordenadas p).
    //este if es para que no se cree un nuevo nodo en caso de insertar un valor en un punto que ya tiene valor
    //así si el punto ya existe simplemente guarda el nuevo valor en el vector data del nodo
    if(n != nullptr && n->pos.x == p.x && n->pos.y == p.y){
        n->data.push_back(data);
        return;
    }
    Node* newNode = new Node(p);
    newNode->data.push_back(data);
    insert(newNode);
}

vector<Node> QuadTree::list(){//Elegí preorder porque me gusta más, creo que es más ordenado para ver el quadtree
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

int QuadTree::countRegion(Point p, int d){
    //Retorna la cantidad de puntos en una región del plano, tomando como centro el punto p y una distancia d.
    
} 
    
int QuadTree::AggregateRegion(Point p, int d){
    //Retorna la población estimada dentro de una región del plano, tomando como centro el punto p y una distancia d.
    
} 
