/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   csv.cpp
 * Author: Onasis Reyes
 * 
 * Created on 11 de diciembre de 2020, 01:09 PM
 */

#include "csv.h"

csv::csv() {
}

csv::csv(const csv& orig) {
}

csv::~csv() {
}

vector<vector<string>> csv::sort(int column, bool up) {
    if (up) {
        for (int i = 0; i < data.size() - 1; i++) {
            if (((vector<string>)(data.at(i))).at(column) < ((vector<string>)(data.at(i + 1))).at(column)) {
                string temporal = ((vector<string>)(data.at(i))).at(column);
                string temporal2 = ((vector<string>)(data.at(i + 1))).at(column);
                ((vector<string>)(data.at(i))).at(column) = temporal2;
                ((vector<string>)(data.at(i + 1))).at(column) = temporal;
            }
        }//fin for
    } else {
        for (int i = 0; i < data.size() - 1; i++) {
            if (((vector<string>)(data.at(i))).at(column) > ((vector<string>)(data.at(i + 1))).at(column)) {
                string temporal = ((vector<string>)(data.at(i))).at(column);
                string temporal2 = ((vector<string>)(data.at(i + 1))).at(column);
                ((vector<string>)(data.at(i))).at(column) = temporal2;
                ((vector<string>)(data.at(i + 1))).at(column) = temporal;
            }//fin if
        }//fin for
    }//fin else
    return data;
}//fin método*/

vector<string> csv::get_column(int index) {
    vector<string> column;
    for (int i = 0; i < data.size(); i++) {
        column.push_back(((vector<string>)data.at(i)).at(index));
    }
    return column;
}//fin método

vector<string> csv::get_row(int index) {
    return data.at(index);
}//fin método

vector<string> csv::get_max(int column) {
    int max_fila = 0;
    string max_temporal = "";
    string maximo = "";
    for (int i = 0; i < data.size(); i++) {
        // if (((vector<string>)data.at(i)).at(column)) {
        max_temporal = ((vector<string>)data.at(i)).at(column);
        if (max_temporal > maximo) {
            maximo = max_temporal;
            max_fila = i;
        }//fin if
        // }//fin if
    }//fin for
    return data.at(max_fila);
}//fin método*/

vector<string> csv::get_min(int column) {
    int min_fila = 0;
    string min_temporal = "";
    string minimo = "";
    min_temporal = ((vector<string>)data.at(0)).at(column);
    for (int i = 0; i < data.size(); i++) {
        //if (((vector<string>)data.at(i)).at(column)) {
        min_temporal = ((vector<string>)data.at(i)).at(column);
        if (min_temporal > minimo) {
            minimo = min_temporal;
            min_fila = i;
        }//fin if
        //}//fin if
    }//fin for
    return data.at(min_fila);
}//fin método

/*
csv csv::concat(csv fila, string nombre_poner){
    
}*/

void csv::truncate_column(int index) {
    vector<vector < string>> new_data;
    vector<string> data_temporal;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.at(i).size(); j++) {
            if (j != index) {
                data_temporal.push_back((((vector<string>)data.at(i)).at(index)));
            }//fin if
        }//fin for
        data_temporal.clear();
        new_data.push_back(data_temporal);
    }//fin for
    data.clear();
    data = new_data;
}//fin void

void csv::truncate_row(int index) {
    vector<vector < string>> new_data;
    for (int i = 0; i < data.size(); i++) {
        new_data.push_back(data.at(i));
    }//fin for
    data.clear();
    data = new_data;
    data_count--;
}//fin void

csv::csv(string file_name){
    this -> file_name = file_name;
    load_file(false);
}

csv::csv(string file_name, bool header){
    this -> file_name = file_name;
    load_file(header);
}

void csv::print_data() {
    if (data.empty()) {
        cout << "El archivo esta vacío." << endl << endl;
    } else {
        //imprimo los header si existen
        if (headers.size() > 0) {
            for (int i = 0; i < headers.size(); i++) {
                cout << headers.at(i) << setw(15);
            }//fin for
        }//fin if
        cout << endl;
        //imprimo la demas informacion
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data.at(i).size(); j++) {
                cout << setw(5) << ((vector<string>)data.at(i)).at(j); //es lo mismo que ((vector<string>)data.at(i)).at(j) == data[i][j]
            }//fin for
            cout << endl;
        }//fin for
    }//fin else
}//fin método

void csv::write_file() {
    ofstream save_file;
    save_file.open(file_name, ofstream::out | ofstream::trunc);
    if (save_file.is_open()) {
        if (headers.size() > 0) {
            for (int i = 0; i < headers.size(); i++) {
                string header = headers.at(i);
                save_file << header << ',';
            }//fin for
            save_file << endl;
        }//fin if
        for (int i = 0; i < data.size(); i++) {
            vector<string> data_temporal = data[i];
            for (int i = 0; i < data_temporal.size(); i++) {
                string informacion = data_temporal.at(i);
                save_file << informacion;
            }//fin for
            save_file << endl;
        }//fin for
    }//fin if
    save_file.close();
}//fin método

void csv::load_file(bool hedear) {
    fstream read_file;
    read_file.open(file_name);
    if (read_file.is_open()) {
        string informacion = "";
        vector<string> lista_datos_temp;
        cout << "Se ha ingresado al archivo." << endl;
        string buffer = "";
        if (hedear) {
            getline(read_file, buffer);
            for (int i = 0; i < buffer.length(); i++) {
                if (buffer[i] == ',') {
                    headers.push_back(informacion);
                    informacion = "";
                } else if (i == buffer.length() - 1) {
                    headers.push_back(informacion);
                    informacion = "";
                } else {
                    informacion += buffer[i];
                }//fin else
            }//fin for
            buffer.clear();
            while (getline(read_file, buffer)) {
                informacion = "";
                for (int i = 0; i < buffer.length(); i++) {
                    if (buffer[i] == ',') {
                        lista_datos_temp.push_back(informacion);
                        informacion = "";
                    } else if (i == buffer.length() - 1) {
                        lista_datos_temp.push_back(informacion);
                        informacion = "";
                    } else {
                        informacion += buffer[i];
                    }//fin else
                }//fin for
                data.push_back(lista_datos_temp);
                lista_datos_temp.clear();
            }//fin while
        } else {
            while (getline(read_file, buffer)) {
                informacion = "";
                for (int i = 0; i < buffer.length(); i++) {
                    if (buffer[i] == ',') {
                        lista_datos_temp.push_back(informacion);
                        informacion = "";
                    } else if (i == buffer.length() - 1) {
                        lista_datos_temp.push_back(informacion);
                        informacion = "";
                    } else {
                        informacion += buffer[i];
                    }//fin else
                }//fin for
                data.push_back(lista_datos_temp);
                lista_datos_temp.clear();
            }//fin while
        }//fin else
    }//fin if
    cout << "No se ha podido ingresar al archivo." << endl;
    read_file.close();
}//fin método