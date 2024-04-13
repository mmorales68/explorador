//
// Created by mmora on 11/04/2024.
//

#ifndef EXPLORADOR_FUNCIONES_H
#define EXPLORADOR_FUNCIONES_H
#endif

#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

//mostrar el contenido de un directorio
void mostrarContenido(const string& path){
    try{
        cout << "Contenido de " << path << ":\n";
        for (const auto &entry: fs::directory_iterator(path)){
            cout << entry.path().filename().string() << "\n";
        }
    }catch(runtime_error& e){
        cout << "Error: " << e.what() << endl;
    }
}

//validacion de directorio
bool validarDirectorio(const string& path){
    if(fs::is_directory(path)){
        return true;
    } else{
        return false;
    }
}

//copiar un archivo
void copiarArchivo(const string& source, const string& destination){
    try{
        fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
        cout << "Archivo copiado exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//renombrar un archivo
void renombrarArchivo(const string& oldName, const string& newName){
    try{
        fs::rename(oldName, newName);
        cout << "Archivo renombrado exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//mover un archivo
void moverArchivo(const string& source, const string& destination){
    try{
        fs::rename(source, destination);
        cout << "Archivo movido exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//borrar un archivo
void borrarArchivo(const string& filePath){
    try{
        fs::remove(filePath);
        cout << "Archivo borrado exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//renombrar una carpeta
void renombrarCarpeta(const string& oldName, const string& newName){
    try{
        fs::rename(oldName, newName);
        cout << "Carpeta renombrada exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//crear una carpeta
void crearCarpeta(const string& path){
    try{
        if (!fs::exists(path)) {
            fs::create_directory(path);
            cout << "Carpeta creada exitosamente.\n";
        } else {
            cerr << "La carpeta ya existe.\n";
        }
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

//eliminar una carpeta
void eliminarCarpeta(const string& filePath){
    try{
        fs::remove_all(filePath);
        cout << "Carpeta borrada exitosamente.\n";
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
}

