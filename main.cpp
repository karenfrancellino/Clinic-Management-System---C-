#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <regex>

// ==================== CLASSE BASE ====================
class Persona {
protected:
    std::string nombre, apellidos, domicilio, localidad, postal, telefono, dni;
    std::string fechaNacimiento;

public:
    Persona(const std::string& nombre, const std::string& apellidos,
            const std::string& domicilio, const std::string& localidad,
            const std::string& postal, const std::string& telefono,
            const std::string& dni, const std::string& fecha)
        : nombre(nombre), apellidos(apellidos), domicilio(domicilio),
          localidad(localidad), postal(postal), telefono(telefono),
          dni(dni), fechaNacimiento(fecha) {}

    // Getters
    std::string getNombre() const { return nombre; }
    std::string getApellidos() const { return apellidos; }
    std::string getDomicilio() const { return domicilio; }
    std::string getLocalidad() const { return localidad; }
    std::string getPostal() const { return postal; }
    std::string getTelefono() const { return telefono; }
    std::string getDNI() const { return dni; }
    std::string getFechaNacimiento() const { return fechaNacimiento; }

    // Setters
    void setNombre(const std::string& valor) { nombre = valor; }
    void setApellidos(const std::string& valor) { apellidos = valor; }
    void setDomicilio(const std::string& valor) { domicilio = valor; }
    void setLocalidad(const std::string& valor) { localidad = valor; }
    void setPostal(const std::string& valor) { postal = valor; }
    void setTelefono(const std::string& valor) { telefono = valor; }
    void setDNI(const std::string& valor) { dni = valor; }
    void setFechaNacimiento(const std::string& valor) { fechaNacimiento = valor; }
};

// ==================== PACIENTE ====================
class Paciente : public Persona {
public:
    Paciente(const std::string& nombre, const std::string& apellidos,
             const std::string& dni, const std::string& fecha,
             const std::string& domicilio, const std::string& localidad,
             const std::string& postal, const std::string& telefono)
        : Persona(nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha) {}
};

// ==================== EMPLEADO ====================
class Empleado : public Persona {
private:
    std::string departamento;
    std::string categoria;

public:
    Empleado(const std::string& nombre, const std::string& apellidos,
             const std::string& dni, const std::string& fecha,
             const std::string& domicilio, const std::string& localidad,
             const std::string& postal, const std::string& telefono,
             const std::string& departamento, const std::string& categoria)
        : Persona(nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha),
          departamento(departamento), categoria(categoria) {}

    std::string getDepartamento() const { return departamento; }
    std::string getCategoria() const { return categoria; }

    void setDepartamento(const std::string& valor) { departamento = valor; }
    void setCategoria(const std::string& valor) { categoria = valor; }
};

// ==================== VALIDACIONES ====================
bool isVacio(const std::string& str) {
    return str.empty() || str.find_first_not_of(' ') == std::string::npos;
}

bool validarFecha(const std::string& fecha) {
    std::regex formato(R"(^\d{2}/\d{2}/\d{4}$)");
    if (!std::regex_match(fecha, formato)) return false;

    int d, m, y;
    std::sscanf(fecha.c_str(), "%d/%d/%d", &d, &m, &y);

    if (m < 1 || m > 12 || d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;

    if (m == 2) {
        bool bissexto = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        if (d > (bissexto ? 29 : 28)) return false;
    }

    return true;
}

// ==================== INPUT ====================
void leerDatosComunes(std::string& nombre, std::string& apellidos,
                     std::string& dni, std::string& fecha,
                     std::string& domicilio, std::string& postal,
                     std::string& localidad, std::string& telefono) {

    do {
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
    } while (isVacio(nombre));

    do {
        std::cout << "Apellidos: ";
        std::getline(std::cin, apellidos);
    } while (isVacio(apellidos));

    do {
        std::cout << "DNI/NIE: ";
        std::getline(std::cin, dni);
    } while (isVacio(dni));

    do {
        std::cout << "Fecha (dd/mm/yyyy): ";
        std::getline(std::cin, fecha);
    } while (!validarFecha(fecha));

    do {
        std::cout << "Domicilio: ";
        std::getline(std::cin, domicilio);
    } while (isVacio(domicilio));

    do {
        std::cout << "Código postal: ";
        std::getline(std::cin, postal);
    } while (isVacio(postal));

    do {
        std::cout << "Localidad: ";
        std::getline(std::cin, localidad);
    } while (isVacio(localidad));

    do {
        std::cout << "Teléfono: ";
        std::getline(std::cin, telefono);
    } while (isVacio(telefono));
}

void leerDatosEmpleado(std::string& departamento, std::string& categoria) {
    std::cout << "Departamento: ";
    std::getline(std::cin, departamento);

    std::cout << "Categoría: ";
    std::getline(std::cin, categoria);
}

// ==================== MAIN ====================
int main() {
    int opcion;

    std::cout << "=== Clinica Radiologica ===\n";
    std::cout << "1. Paciente\n2. Empleado\n";
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string nombre, apellidos, domicilio, localidad, postal, telefono, dni, fecha;
    std::string departamento, categoria;

    if (opcion == 1) {
        leerDatosComunes(nombre, apellidos, dni, fecha, domicilio, postal, localidad, telefono);

        Paciente p(nombre, apellidos, dni, fecha, domicilio, localidad, postal, telefono);

        std::ofstream file("pacientes.txt", std::ios::app);
        if (file) {
            file << p.getNombre() << " " << p.getApellidos() << "\n";
            std::cout << "Paciente guardado correctamente\n";
        }

    } else if (opcion == 2) {
        leerDatosComunes(nombre, apellidos, dni, fecha, domicilio, postal, localidad, telefono);
        leerDatosEmpleado(departamento, categoria);

        Empleado e(nombre, apellidos, dni, fecha, domicilio, localidad, postal, telefono, departamento, categoria);

        std::ofstream file("empleados.txt", std::ios::app);
        if (file) {
            file << e.getNombre() << " " << e.getApellidos() << "\n";
            std::cout << "Empleado guardado correctamente\n";
        }

    } else {
        std::cout << "Opcion invalida\n";
    }

    return 0;
}
