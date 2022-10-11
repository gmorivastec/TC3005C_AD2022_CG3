# define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "glm/glm.hpp"

using namespace std;
using namespace glm;

int main() {

    // no hay funcion para convertir a radianes pero es fácil
    float grados = 30;
    float radianes = (grados * M_PI) / 180; 
    float cosAngulo = cos(radianes);
    float sinAngulo = sin(radianes);

    // definiendo tipo de datos

    // vectores
    vec4 posicion(10.0f, 20.0f, 5.0f, 1.0f);

    // matrices
    // se pueden definir de 2 maneras 
    // 1 - con todos los valores especificados explícitamente

    // IMPORTANTE DIFERENCIA CON PROCESSING
    // CADA 4 VALORES SON UNA COLUMNA NO UN RENGLÓN
    mat4 traslacion(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        5.0f, 6.0f, 8.0f, 1.0f
    );

    mat4 escala(
        0.5f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 2.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    // con un 1 de argumento te crea una matriz identidad
    mat4 traslacionSimple(1);

    traslacionSimple[3][0] = 5.0f;
    traslacionSimple[3][1] = 6.0f;
    traslacionSimple[3][2] = 8.0f;

    // ejemplo 1 - 
    // trasladar el vértice en (5, 6, 8)
    // después escalar en (0.5, 1, 2)

    // aquí las matrices se multiplican con *
    // el operador está sobrecargado

    // el orden sigue siendo inverso
    mat4 transformaciones = escala * traslacion;

    // al final aplicamos transformaciones a vértice
    vec4 transformado = traslacionSimple * posicion;

    // multiplicaciones

    cout << transformado.x << " " << transformado.y << " " << transformado.z << endl;
    return 0;
}