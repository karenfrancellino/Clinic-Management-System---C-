# 🏥 Clinic Management System - C++

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/status-in%20progress-yellow?style=for-the-badge)

---

## 📌 About the Project

This is a C++ console application designed to manage patient and employee data for a clinic.

The system allows users to input personal information, validate it, and store it in text files.

---

## 🚀 Features

- 🧱 Object-Oriented Programming (Inheritance)
- 👤 Base class: `Persona`
- 🏥 Derived classes: `Paciente`, `Empleado`
- ✅ Input validation (empty fields, date format)
- 📅 Date validation using `regex`
- 💾 File storage (`.txt`)
- 📋 Structured data output

---

## 🛠️ Technologies

- C++
- Standard Library:
  - `iostream`
  - `string`
  - `fstream`
  - `regex`
  - `ctime`
  - `iomanip`

---

## 💻 How it works

1. User selects:
   - Patient
   - Employee
2. Inputs required data
3. System validates input
4. Data is saved to:
   - `pacientes.txt`
   - `empleados.txt`

---

## 📷 Example
Bienvenido a Clinica Radiológica Aranguren.

Pulse 1 para introducir los datos de un paciente
Pulse 2 para introducir los datos de un empleado

Introduzca el nombre:
Ana

Introduzca los apellidos:
López
...


---

## 📁 Output Example


Paciente con DNI/NIE: 12345678A
Nombre y apellidos: Ana López
Fecha de nacimiento: 01/01/1990
Domicilio: Calle Mayor 1
C. P.: 28001; Localidad: Madrid
Nº Teléfono: 600123456
