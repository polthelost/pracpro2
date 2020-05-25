/** @file especie.cc
  @brief Código de la clase Celula
  */
#include "especie.hh"
#define _USE_MATH_DEFINES
void especie::generar_kmeros() {
    int n = gen.size();
    string kmero;
    for (int i = 0; i < n-(k-1); ++i) {
        kmero = gen.substr(i,k);
        kmeros[kmero] += 1;
    }
}

especie::especie() {
    string id;
    string gen;
}

especie::especie(const string & id , const string & gen ) {
    this->id = id;
    this->gen = gen;
    generar_kmeros();
}


string especie::consultar_id() const {
    return id;
}

string especie::consultar_gen() const {
    return gen;
}

int especie::k = 0;

void especie::insertar_k(int k) {
    especie::k = k;
}
double especie::distancia(const especie &e1, const especie &e2) {
    map<string, int>::const_iterator it1, it2;
    it1 = e1.kmeros.begin();
    it2 = e2.kmeros.begin();
    double producto = 0;
    double norma1 = 0;
    double norma2 = 0;
    while (it1 != e1.kmeros.end() and it2 != e2.kmeros.end()) {
        if (it1->first == it2->first) {
            producto += it1->second * it2->second;
            norma1 += it1->second * it1->second;
            norma2 += it2->second * it2->second;
            ++it1;
            ++it2;
        }
        else if (it1->first > it2->first) {
            norma2 += it2->second * it2->second;
            ++it2;
        }
        else {
            norma1 += it1->second * it1->second;
            ++it1;
        }
    }
    while (it1 != e1.kmeros.end()) {
        norma1 += it1->second * it1->second;
        ++it1;
    }
    while (it2 != e2.kmeros.end()) {
        norma2 += it2->second * it2->second;
        ++it2;
    }
    //cout << producto << endl;
    //cout << norma1 << endl;
    //cout << norma2 << endl;
    double resultat, aux;
    aux = producto/(sqrt(norma1) * sqrt(norma2));
    //cout << aux << endl;
    //cout << acos(aux) << endl;
    //cout << M_1_PI << endl;
    //cout << 1-(1/M_1_PI) << endl;
    
    resultat = (1- ((M_1_PI) *acos(aux)) )*100;
    return resultat;
}
/*
double especie::distancia(const especie &e1, const especie &e2) {
    map<string, int>::const_iterator it1, it2;
    it1 = e1.kmeros.begin();
    it2 = e2.kmeros.begin();
    double uni, inter;
    uni = 0;
    inter = 0;
    while (it1 != e1.kmeros.end() and it2 != e2.kmeros.end()) {
        if (it1->first == it2->first) {
            uni += max(it1->second, it2->second);
            inter += min(it1->second, it2->second);
            ++it1;
            ++it2;
        }
        else if (it1->first > it2->first) {
            uni += it2->second;
            ++it2;
        }
        else {
            uni += it1->second;
            ++it1;
        }
    }
    while (it1 != e1.kmeros.end()) {
        uni += it1->second;
        ++it1;
    }
    while (it2 != e2.kmeros.end()) {
        uni += it2->second;
        ++it2;
    }
    double resultat;
    resultat = (1-(inter/uni))*100;
    return resultat;
}
*/
