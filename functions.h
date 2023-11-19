#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>

int read_integer_in_range(const char * prompt, int min, int max);
void text(int choice);
void MDCurrentDisp(struct MainDish* md);
void SDCurrentDisp(const struct Sides* sd);
void DrinkCurrentDisp(const struct Drinks* dk);
void BCurrentDisp1(const struct Burger* B);
void BCurrentDisp2(const struct Burger* B, int choice);

#endif