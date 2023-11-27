#include "Ejercicio02.h"

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    vector<string>* resultado = new vector<string>();
    unordered_map<string, int> mapa;

    string current = "";
    Node<char>* temp = head;

    while (temp != nullptr) {
        current += temp->value;

        if (current.length() == 10) {
            if (mapa.find(current) == mapa.end()) {
                mapa[current] = 0;
            }
            else if (mapa[current] == 0) {
                resultado->push_back(current);
                mapa[current]++;
            }

            current.erase(0, 1);
        }

        temp = temp->next;
    }

    return resultado;
}
