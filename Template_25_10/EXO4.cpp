
#include <iostream>
#include <array>
#include <stdexcept>
#include <vector>

template <typename Typedegats>
class Projectile {
protected:
    float vitesse;
    Typedegats degats;
    float position[2]; // position (x, y) 
    float direction[2]; // direction (dx, dy) 

public:
    // constructeur projectile
    Projectile(float vitesse, Typedegats degats, float x, float y, float dirX, float dirY)
        : vitesse(vitesse), degats(degats) {
        if (vitesse < 0) throw std::invalid_argument("la vitesse ne peut pas etre negative.");
        if (degats < 0) throw std::invalid_argument("les degats ne peuvent pas etre negatifs.");

        position[0] = x; // initialisation pos x
        position[1] = y; // initialisation pos y
        direction[0] = dirX; // initialisation direction x
        direction[1] = dirY; // initialisation direction y
    }

    // deplace le projectile
    virtual void move(float deltaTime) {
        position[0] += direction[0] * vitesse * deltaTime; // maj pos x
        position[1] += direction[1] * vitesse * deltaTime; // maj pos y
    }

    Typedegats getdegats() const { return degats; }

    std::array<float, 2> getPosition() const {
        return { position[0], position[1] };
    }

    virtual void impact() {
        std::cout << "impact du projectile a la position (" << position[0] << ", " << position[1] << ")\n";
    }
};
// fleche
class Fleche : public Projectile<int> {
public:
    Fleche(float vitesse, int degats, float x, float y, float dirX, float dirY)
        : Projectile<int>(vitesse, degats, x, y, dirX, dirY) {}

    void impact() override {
        std::cout << "la fleche perfore, infligeant " << degats << " degats.\n";
    }
};

//boule de Feu
class BouleDeFeu : public Projectile<float> {
private:
    float rayonExplosion;

public:
    BouleDeFeu(float vitesse, float degats, float rayonExplosion, float x, float y, float dirX, float dirY)
        : Projectile<float>(vitesse, degats, x, y, dirX, dirY), rayonExplosion(rayonExplosion) {}

    void impact() override {
        
        std::cout << "la boule de feu explose avec un rayon de " << rayonExplosion
            << ", infligeant " << degats << " degats de zone.\n";
    }
};

//int main() {
//    // utilisation fleche
//    Projectile<int> fleche(10.0f, 100, 0.0f, 0.0f, 1.0f, 0.5f);
//
//    // deplacement projectile
//    fleche.move(1.0f); // deplacemenr de 1 sec
//
//    float* pos = fleche.getPosition();
//    std::cout << "position fleche: (" << pos[0] << ", " << pos[1] << ")\n";                           // } main de laser/fleche basique
//    std::cout << "degats fleche: " << fleche.getdegats() << std::endl;
//
//    // utilisation laser
//    Projectile<float> laser(20.0f, 225.5f, 0.0f, 0.0f, 1.0f, 0.0f);
//    laser.move(1.0f); // deplacement 1sec
//
//    pos = laser.getPosition();
//    std::cout << "position laser: (" << pos[0] << ", " << pos[1] << ")\n";
//    std::cout << "degats laserr: " << laser.getdegats() << std::endl;
//}

int main() {
    try {
        // utilisation flèche
        Fleche fleche(10.0f, 100, 0.0f, 0.0f, 1.0f, 1.5f);
        fleche.move(1.0f); // deplacement de 1 sec
        fleche.impact(); // impact de la flèche

        // utilisation boule de feu
        BouleDeFeu bouleDeFeu(20.0f, 225.5f, 15.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        bouleDeFeu.move(1.0f); // deplacement de 1 sec
        bouleDeFeu.impact(); //impact de la boule de feu

    }
    catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
