// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "conexionBD.h"

using namespace std;
int q_estado;

class Compras {
private:
	int idCompra;
	int no_orden_compra;
	int idproveedor;
	char* fecha_orden;
	char* fecha_ingreso;

public:
	Compras(){}

	Compras(int no_orden_comprac, int idproveedorc, char* fecha_ordenc, char* fecha_ingresoc ) {
		no_orden_compra = no_orden_comprac;
		idproveedor = idproveedorc;
		fecha_orden = fecha_ordenc;
		fecha_ingreso = fecha_ingresoc;
	}
	Compras(int idComprac,int no_orden_comprac, int idproveedorc, char* fecha_ordenc, char* fecha_ingresoc) {
		idCompra = idComprac;
		no_orden_compra = no_orden_comprac;
		idproveedor = idproveedorc;
		fecha_orden = fecha_ordenc;
		fecha_ingreso = fecha_ingresoc;
	}

	Compras(int idComprac) {
		idCompra = idComprac;
	}


	void SetIdCompra(int idComprac) { idCompra = idComprac; }
	void SetNoOrdenCompra(int no_orden_comprac) { no_orden_compra = no_orden_comprac; }
	void SetIdProveedor(int idproveedorc) { idproveedor = idproveedorc; }
	void SetFechaOrden(char* fecha_ordenc) { fecha_orden = fecha_ordenc; }
	void SetFechaIngreso(char* fecha_ingresoc) { fecha_ingreso = fecha_ingresoc; }

	const int GetIdCompra() { return idCompra; }
	const int GetNoOrdenCompra() { return  no_orden_compra; }
	const int GetIdProveedor() { return idproveedor; }
	const char* GetFechaOrden() { return fecha_orden; }
	const char* GetFechaIngreso() { return fecha_ingreso; }

	//CRUD

	void createData(){
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insert = "INSERT INTO `tareasql`.`compras`(`no_orden_compra`,`idProveedor`,`fecha_orden`,`fechaingreso`) value ('" + to_string(no_orden_compra) + "','" + to_string(idproveedor) + "','" + fecha_orden + "','" + fecha_ingreso + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso existoso";
			}else {
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
	
	void updateData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string update = "update tareasql.compras  SET no_orden_compra = '" + to_string(no_orden_compra) + "', idProveedor = '" + to_string(idproveedor) + "', fecha_orden = '" + fecha_orden + "', fechaingreso = '" + fecha_ingreso + "'  where idCompra = " + to_string(idCompra) + "  ";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "update existoso";
			}
			else {
				cout << "Error al update";
			}
		}
		cn.cerrar_conexion();
	}

	void deleteData() {
		int q_estado;
		conexionBD cn = conexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string deleteSQL = "DELETE FROM tareasql.compras WHERE idCompra = " + to_string(idCompra) + "; ";
			cout << deleteSQL;
			const char* i = deleteSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "delete existoso";
			}else {
				cout << "Error al delete";
			}
		}
		cn.cerrar_conexion();
	}

	void selectData() {
		int q_estado;
		conexionBD cn = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string selectSQL = "Select * from tareasql.compras WHERE idCompra = " + to_string(idCompra) + "; ";
			const char* i = selectSQL.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << fila[2] << "," << fila[3];
				}
			}else{
				cout << "Error al ingresar";
			}
		}
		cn.cerrar_conexion();
	}
};