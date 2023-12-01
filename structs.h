#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>
#include <stdio.h>
#include "functions.c"

void MdTotal(struct MainDish* md, const float prices[]);
void MaindishAmt(struct MainDish* md, const float prices[]);
void SdTotal(struct Sides* sd, const float prices[]);
void SideDishAmt(struct Sides* sd, const float prices[]);
void DTotal(struct Drinks* dk, const float prices[]);
void DrinkAmt(struct Drinks* dk, const float prices[]);
void BTotal(struct Burger* B, const float price[]);
void BAmt(struct Burger* B, const float prices[]);
void MenuTotal(struct MainDish* md, struct Sides* sd, struct Drinks* dk, struct Burger* B);
void Recipt(struct MainDish* md, struct Sides* sd, struct Drinks* dk, struct Burger* B);
void readTextFile();
#endif