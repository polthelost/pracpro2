#ifndef cjt_especies_hh
#define cjt_especies_hh

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <map>
#include <string>
#endif

#include "especie.hh"
using namespace std;
/** @class cjt_especies
 * @brief Contiene el conjunto de las especies
 */
class cjt_especies {
    private:
        set <especie> espset;
        map <string, map<string, double >> distmap;
    public: 
        cjt_especies();
        /** @brief Devuelve una especie dado un string
         * \pre id se encuentra dentro del set espset
         * \post especie con el id de entrada
         */
        especie obtener_especie(const string& id) const; //espset.find(id)
        /** @brief Te dice si existe la especie con ese id
         * \pre id
         * \post si existe una especie con ese id, true, sino false
         */
        bool existe_especie (const string& id) const;
        /** @brief añade una especie al set de especies
         * \pre especie en la entrada
         * \post La especie se ha añadido al set espset i se ha añadido a la tabla de distancias
         */
        void insertar_especie (const especie& e);
        /** @brief Obtiene la distància dados dos id 
         * \pre Dos strings en la entrada  
         * \post El resultado es la distància entre las dos especies
         */
        double consultar_distancia(const string& id1, const string& id2) const; 
        /** @brief Se elimina una especie del conjunto
         * \pre Tamaño del set es estrictamente > 0
         * \post La especie se ha eliminado y se ha actualizado la tabla de distancias
         */
        void eliminar_especie(const string& id); 
        /** @brief Borra las especies del conjunto anterior y se añaden de nuevas desde  el input
         * \pre n especies en el input y el numero n
         * \post N especies en el conjunto
         */
        void leer_conjunto();
        /** @brief Imprime el conjunto de especies
         * \pre El conjunto no es vacio
         * \post Se escriben en el output el conjunto de especies
         */
        void imprimir_conjunto() const;
        /** @brief Imprime la tabla de distancias
         * \pre True
         * \post Se ha imprimido en el output la tabla de distancias
         */
        void imprimir_tabla_distancias();
        /** @brief Devuelve la tabla de distancias
         * \pre True
         * \post El resultado es la tabla de distancias
         */
        map<string, map<string, double>> consultar_tabla_distancias();

};
#endif
