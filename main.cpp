//
// Created by mmora on 11/04/2024.
//

#include "funciones.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string currentDir = ".";

    while(true){


        if(!validarDirectorio(currentDir)){//se valida que el directorio actual sea valido
            cout<<"El directorio "+currentDir+" no existe"<<endl;
            currentDir="/";
            cout<<"El directorio se cambio a la raiz '/'"<<endl;
        }

        cout << "\nDirectorio actual: " << currentDir << "\n";
        mostrarContenido(currentDir);

        cout << "\nOpciones:\n";
        cout << "1. Cambiar directorio\n";//ok
        cout << "2. Copiar archivo\n";//********problemas con los permisos de los archivos*******
        cout << "3. Renombrar archivo\n";//ok
        cout << "4. Mover archivo\n";//*********error en la funcion***********
        cout << "5. Borrar archivo\n";//ok
        cout << "6. Renombrar carpeta\n";//ok
        cout << "7. Crear carpeta\n";//ok
        cout << "8. Borrar una carpeta\n";//ok
        cout << "9. Abrir directorio\n";//ok
        cout << "10. Salir\n";//ok


        cout << "\nIngrese la opcion deseada: ";
        int opcion;
        cin >> opcion;

        switch (opcion){
            case 1: {//cambiar el directorio
                string newDir;
                cout << "Ingrese la ruta del nuevo directorio: ";
                cin >> newDir;
                currentDir = newDir;
                break;
            }
            case 2:{//copiar archivos
                string source, destination;
                cout << "Ingrese el nombre del archivo a copiar: ";
                cin >> source;
                cout << "Copiar "+currentDir+"/"+source+" al directorio: ";
                cin >> destination;
                copiarArchivo(currentDir+"/"+source, destination);
                break;
            }
            case 3:{//renombrar archivos
                string oldName, newName;
                cout << "Ingrese el nombre actual del archivo: ";
                cin >> oldName;
                cout << "Ingrese el nuevo nombre para el archivo: ";
                cin >> newName;
                renombrarArchivo(currentDir + "/" + oldName, currentDir + "/" + newName);
                break;
            }
            case 4:{//mover un archivo
                std::string source, destination;
                std::cout << "Ingrese el nombre del archivo a mover: ";
                std::cin >> source;
                std::cout << "Ingrese la ruta de destino para mover el archivo: ";
                std::cin >> destination;
                moverArchivo(currentDir+"/"+source, destination);
                break;
            }
            case 5:{//borrar un archivo
                std::string filePath;
                std::cout << "Ingrese el nombre del archivo a borrar: ";
                std::cin >> filePath;
                borrarArchivo(currentDir+"/"+filePath);
                break;
            }
            case 6:{//cambiar el nombre a una carpeta
                string oldName, newName;
                cout << "Ingrese el nombre de la carpeta a renombrar: ";
                cin >> oldName;
                cout << "Ingrese el nuevo nombre para la carpeta: ";
                cin >> newName;
                renombrarCarpeta(currentDir + "/" + oldName, currentDir + "/" + newName);
                break;
            }
            case 7:{//crear una carpeta
                string newFolder;
                cout << "Ingrese el nombre de la nueva carpeta: ";
                cin >> newFolder;
                crearCarpeta(currentDir + "/" + newFolder);
                break;
            }

            case 8:{//eliminar una carpeta
                string folder;
                cout<<"ingrese el nombre de la carpeta a eliminar: " ;
                cin>>folder;
                eliminarCarpeta(currentDir+"/"+folder);
                break;
            }

            case 9:{//abrir una carpeta del directorio actual
                string newFolder;
                cout<<"Ingrese el nombre de la carpeta que quiere abrir: ";
                cin>>newFolder;

                if(currentDir=="/"){
                    currentDir=currentDir+newFolder;
                }else{
                    currentDir=currentDir+"/"+newFolder;
                }
                break;
            }

            case 10:
                std::cout << "Saliendo del programa...\n";
                return 0;

            default:{
                std::cerr << "Opcion invalida. Por favor, intente de nuevo.\n";
                break;
            }
        }
   }
}
