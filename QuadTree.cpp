#include "Quadtree.h"

QuadTree::QuadTree(Point topL, Point bottomR){
    n = NULL;
    topLeftTree = NULL;
    topRightTree = NULL;
    bottomLeftTree = NULL;
    bottomRightTree = NULL;
    topLeft = topL;
    bottomRight = bottomR;
    pointCount = 0;
}

int QuadTree::totalPoints(){//Retorna la cantidad de puntos almacenados en el QuadTree
    return pointCount;
} 

int QuadTree::totalNodes(){//Retorna la cantidad de nodos, tanto blancos como negros, en el QuadTree
    
} 

void QuadTree::insert(Point p, int data){//Inserta un nuevo punto p en el QuadTree, asociando a dicho punto la información disponible en data (ej. la población de una ciudad con coordenadas p).
    
} 

vector<Node> QuadTree::list(){
/*
Retorna un contenedor con todos los puntos almacenados en el QuadTree. 
Por cada punto retorna sus coordenadas y su valor asociado (ej. la población). 
Para esta función, queda a criterio de los estudiantes elegir un recorrido entre preorder, postorder o una variante de inorder. 
El tipo de retorno dependerá del tipo de contenedor que se utilice.
*/
    
}

int QuadTree::countRegion(Point p, int d){
    //Retorna la cantidad de puntos en una región del plano, tomando como centro el punto p y una distancia d.
    
} 
    
int QuadTree::AggregateRegion(Point p, int d){
    //Retorna la población estimada dentro de una región del plano, tomando como centro el punto p y una distancia d.
    
} 
