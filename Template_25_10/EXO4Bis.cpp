/*
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Personnage {
public:
    float vie;
    float attaque;
    float defense;

    Personnage(float vie, float attaque, float defense)
        : vie(vie), attaque(attaque), defense(defense) {}
};

// calcule moyenne
template <typename T>
double calculStatistique(const std::vector<T>& valeurs) {
    if (valeurs.empty()) throw std::invalid_argument("le tableau ne peut pas etre vide");

    double somme = 0.0;
    for (const T& valeur : valeurs) {
        somme += valeur;
    }
    return somme / valeurs.size();
}

// calcule variance
template <>
double calculStatistique<float>(const std::vector<float>& valeurs) {
    if (valeurs.empty()) throw std::invalid_argument("le tableau ne peut pas etre vide");

    double moyenne = calculStatistique(valeurs);
    double variance = 0.0;

    for (const float& valeur : valeurs) {
        variance += (valeur - moyenne) * (valeur - moyenne);
    }
    return variance / valeurs.size();
}

// generation tableau attributs
std::vector<float> genererViePersonnages(const std::vector<Personnage>& personnages) {
    std::vector<float> vies;
    for (const auto& personnage : personnages) {
        vies.push_back(personnage.vie);
    }
    return vies;
}

int main() {
    // creatuon du perso
    std::vector<Personnage> personnages = {
        Personnage(100.0f, 30.0f, 20.0f),
        Personnage(80.0f, 25.0f, 15.0f),
        Personnage(120.0f, 40.0f, 30.0f),
        Personnage(90.0f, 35.0f, 25.0f)
    };

    // creation tableau des vies
    std::vector<float> vies = genererViePersonnages(personnages);

    // calcul moyenne des vies
    double moyenneVie = calculStatistique(vies);
    std::cout << "Moyenne des vies : " << moyenneVie << std::endl;

    // calcul variance des vies
    double varianceVie = calculStatistique(vies);
    std::cout << "Variance des vies : " << varianceVie << std::endl;

    return 0;
}

*/