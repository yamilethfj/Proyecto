// Examen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
#include <mysql.h>
#include <iostream>
#include <string> 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;
int q_estado;

class Compras {
private:
	int A_idCompra;
	int A_noOrdenCompra;
	int A_idProveedor;
	char* A_fechaOrden;
	char* A_fechaIngreso;


public:
	
	void SetIdCompra(int idCompra) { A_idCompra = idCompra; }
	void SetNoOrdenCompra(int no_orden_compra) { A_noOrdenCompra = no_orden_compra; }
	void SetIdProveedor(int idproveedor) { A_idProveedor = idproveedor; }
	void SetFechaOrden(char* fecha_orden) { A_fechaOrden = fecha_orden; }
	void SetFechaIngreso(char* fecha_ingreso) { A_fechaIngreso = fecha_ingreso; }

	const int GetIdCompra() { return A_idCompra; }
	const int GetNoOrdenCompra() { return  A_noOrdenCompra; }
	const int GetIdProveedor() { return A_idProveedor; }
	const char* GetFechaOrden() { return A_fechaOrden; }
	const char* GetFechaIngreso() { return A_fechaIngreso;  }
};

int main()
{
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "tareasql", 3307, NULL, 0);
	if (conectar) {
		
		int idcompra, no_orden_compra, idproveedor, opcion;
		string fecha_orden, fecha_ingreso;

		int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
		char fecha_orden_temp[20], fecha_ingreso_temp[20];

		cout << "MENU"<<endl;
		cout << "1. Insertar"<<endl;
		cout << "2. Actualizar" << endl;
		cout << "3. Eliminar" << endl;
		cout << "4. Listado" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1: {

			int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
			char fecha_orden_temp[20], fecha_ingreso_temp[20];

			Compras compra = Compras();
			system("cls");
			
			cout << "Ingrese numero de compra:";
			cin >> no_orden_compra_temp;
			compra.SetNoOrdenCompra(no_orden_compra_temp);

			cout << "Ingrese Id Proveedor:";
			cin >> idproveedor_temp;
			compra.SetIdProveedor(idproveedor_temp);

			cout << "Ingrese fecha ingreso :";
			cin >> fecha_ingreso_temp;
			compra.SetFechaIngreso(fecha_ingreso_temp);

			cout << "Ingrese fecha Orden :";
			cin >> fecha_orden_temp;
			compra.SetFechaOrden(fecha_orden_temp);

			string insert = "INSERT INTO `tareasql`.`compras`(`no_orden_compra`,`idProveedor`,`fecha_orden`,`fechaingreso`) value ('" + to_string(compra.GetNoOrdenCompra()) + "','" + to_string(compra.GetIdProveedor()) + "','" + compra.GetFechaOrden()+ "','" + compra.GetFechaIngreso() + "')";
			cout << insert;
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Ingreso existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			int idcompra_temp = 0, no_orden_compra_temp = 0, idproveedor_temp = 0;
			char fecha_orden_temp[20], fecha_ingreso_temp[20];

			Compras compra = Compras();
			system("cls");
			cout << "Ingrese Id compra:";
			cin >> idcompra_temp;
			compra.SetIdCompra(idcompra_temp);

			cout << "Ingrese numero de compra:";
			cin >> no_orden_compra_temp;
			compra.SetNoOrdenCompra(no_orden_compra_temp);

			cout << "Ingrese Id Proveedor:";
			cin >> idproveedor_temp;
			compra.SetIdProveedor(idproveedor_temp);

			cout << "Ingrese fecha ingreso :";
			cin >> fecha_ingreso_temp;
			compra.SetFechaIngreso(fecha_ingreso_temp);

			cout << "Ingrese fecha Orden :";
			cin >> fecha_orden_temp;
			compra.SetFechaOrden(fecha_orden_temp);

			string update = "update tareasql.compras  SET no_orden_compra = '" + to_string(compra.GetNoOrdenCompra()) + "', idProveedor = '" + to_string(compra.GetIdProveedor()) + "', fecha_orden = '" + compra.GetFechaOrden() + "', fechaingreso = '" + compra.GetFechaIngreso() + "'  where idCompra = " + to_string(compra.GetIdCompra()) + "  ";
			cout << update;
			const char* i = update.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Actualizo existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			int idcompra = 0;

			cout << "Ingrese Id compra";
			cin >> idcompra;

			string deleteSQL = "DELETE FROM tareasql.compras WHERE idCompra = " + to_string(idcompra) + "; ";
			cout << deleteSQL;
			const char* i = deleteSQL.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {
				cout << "Elimino existoso";
			}
			else {
				cout << "Error al ingresar";
			}
			system("pause");
			break;
		}
			
		case 4: {
			system("cls");
			cout << "Ingrese Id compra";
			cin >> idcompra;

			string selectSQL = "Select * from tareasql.compras WHERE idCompra = " + to_string(idcompra) + "; ";

			const char* i = selectSQL.c_str();
			q_estado = mysql_query(conectar, i);
			if (!q_estado) {

				resultado = mysql_store_result(conectar);
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << fila[2] << "," << fila[3];
				}
			}
			else {
				cout << "Error al ingresar";
			}
			system("pause");
			break;
		}
		}



	}
	else {
		cout << "2";
	}
}
