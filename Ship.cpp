//
// Created by Oliver Reckord Groten on 10/22/19.
//

#include "Ship.h"
using namespace std;

/* Constructor */

Ship::Ship(){

}
Ship::Ship(int size) {
    this->size = size;
    hits=0;
    isVertical=true;

    // set carriers dimensions and starting center position
    // do for each ship
    carrierShipTang = Tangle(30*5,30);
    carrierShipTang.setCenter(100, 500);

    battleShipTang = Tangle(30*4,30);
    battleShipTang.setCenter(145, 500);

    cruiserShipTang = Tangle(30*2,30);
    cruiserShipTang.setCenter(190, 500);

    subShipTang = Tangle(30*3,30);
    subShipTang.setCenter(235, 500);

    destroyerShipTang = Tangle(30*3,30);
    destroyerShipTang.setCenter(280, 500);
}
bool Ship::getVert(){
    return isVertical;
}
void Ship::setVert(bool vert){
    isVertical=vert;
}
void Ship::rotate(){
    if(isVertical){
        isVertical=false;
    }else{
        isVertical=true;
    }
}



/* Getters */
int Ship::getSize() {
    return size;
}
bool Ship::getDestroyed() {
    return size==hits;
}

int Ship::getCenterX_car() const {
    return shipCenter.x;
}
int Ship::getCenterY_car() const {
    return shipCenter.y;
}

/* Setters */
void Ship::setSize(int s) {
    size = s;
}
void Ship::setDestroyed(bool d) {
    destroyed = d;
}

// setters
void Ship::setCenterCarrier(int x,int y) {
    carrierShipTang.setCenter(x,y);
}

void Ship::setCenterDestroyer(int x,int y) {
    destroyerShipTang.setCenter(x,y);
}

void Ship::setCenterCruiser(int x,int y) {
    cruiserShipTang.setCenter(x,y);
}

void Ship::setCenterSub(int x,int y) {
    subShipTang.setCenter(x,y);
}

void Ship::setCenterBattle(int x,int y) {
    battleShipTang.setCenter(x,y);
}




void Ship::setCenterY(int y) {
    shipCenter.y = y;
}

void Ship::addHit() {
    hits++;
}

void Ship::drawShip_car(){

//    carrierShip.setDimensions(30*l,30);
//    int xC = 100;
//    int yC = 470;
//    carrierShip.setCenter(xC, yC);
    carrierShipTang.setFillColor(0.4, 0.4, 0.4);

    carrierShipTang.draw();
}

void Ship::drawShip_battle(){

//    carrierShip.setDimensions(30*l,30);
//    int xC = 100;
//    int yC = 470;
//    carrierShip.setCenter(xC, yC);
    battleShipTang.setFillColor(0.4, 0.4, 0.4);
    battleShipTang.draw();
}

void Ship::drawShip_destroyer(){
    destroyerShipTang.setFillColor(0.4, 0.4, 0.4);
    destroyerShipTang.draw();
}
void Ship::drawShip_cruiser(){
    cruiserShipTang.setFillColor(0.4, 0.4, 0.4);
    cruiserShipTang.draw();
}
void Ship::drawShip_sub(){
    subShipTang.setFillColor(0.4, 0.4, 0.4);
    subShipTang.draw();
}