#ifndef MATRICE_H
#define MATRICE_H

int** m_init(int, int);
void m_value(int** &, int, int);
void sottom_value(int**, int** &, int, int, int, int);
void m_print(int**, int, int);
void m_deinit(int**, int, int);

#endif