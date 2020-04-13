#ifndef especie_hh
#define especie_hh

class especie {
    private:
        string id;// idk what to put here
        string gen;

    public:
    /** @brief Constructora
     * pre
     * post
     */
    especie();
    /** @brief Lee una especie
     * \pre true
     * \post id i gen 
     */
    especie(string & id const, string & gen const) {
        this->id = id;
        this->gen = gen;
    }
    void leer_especie();

    string obtener_id(); // return id
    string obtener_gen(); // return g
    
}
#endif
