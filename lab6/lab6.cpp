#include <iostream>
#include <string>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
protected:
    string marca;
    string modelo;
    double precio;

public:
    // Constructor
    Vehiculo(string m, string mod, double p) : marca(m), modelo(mod), precio(p) {}

    // Métodos getters y setters
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    double getPrecio() { return precio; }

    void setMarca(string m) { marca = m; }
    void setModelo(string mod) { modelo = mod; }
    void setPrecio(double p) { precio = p; }

    // Método virtual para mostrar información
    virtual void mostrarInfo() {
        cout << "Vehículo: " << marca << " " << modelo << ", Precio: $" << precio;
    }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numPuertas;

public:
    Automovil(string m, string mod, double p, int puertas)
        : Vehiculo(m, mod, p), numPuertas(puertas) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Puertas: " << numPuertas << endl;
    }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string m, string mod, double p, int c)
        : Vehiculo(m, mod, p), cilindrada(c) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Cilindrada: " << cilindrada << "cc" << endl;
    }
};

// Clase derivada Camioneta
class Camioneta : public Vehiculo {
private:
    double capacidadCarga;

public:
    Camioneta(string m, string mod, double p, double carga)
        : Vehiculo(m, mod, p), capacidadCarga(carga) {
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << ", Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Cliente(string n, int e) : nombre(n), edad(e) {}

    // Método para comprar un vehículo
    void comprarVehiculo(Vehiculo& v) {
        cout << "Cliente " << nombre << " ha comprado un " << v.getMarca() << " " << v.getModelo() << "." << endl;
    }
};

// Función principal
int main() {
    // Crear objetos de las clases derivadas
    Automovil auto1("Toyota", "Corolla", 25000, 4);
    Motocicleta moto1("Yamaha", "R1", 18000, 1000);
    Camioneta camioneta1("Ford", "Ranger", 30000, 1.5);

    // Mostrar información de los vehículos
    auto1.mostrarInfo();
    moto1.mostrarInfo();
    camioneta1.mostrarInfo();

    // Crear un cliente y realizar la compra
    Cliente cliente1("Juan", 35);
    cliente1.comprarVehiculo(auto1);

    return 0;
}