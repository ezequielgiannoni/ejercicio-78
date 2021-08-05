#include <iostream>
#include <fstream>

using namespace std;
struct Producto {
    int codigoDeProducto;
    int precioUnitario;
    int stock;
    int posicion;
};
struct RegistroDeInventario {
    bool existe = false;
    Producto producto;
};
struct Pedido {
    int codigoDeProducto;
    int cantidadComprada;
};

// ********* variables globales **************** 
char delimitador = ':';
char nombreDeArchivo[15] = "inventario.txt";
int cantidadDeProductos;
Producto inventarioDeProductos[30];
// *********************************************

void reachazarPedido(string motivo) {
    cout << "No puede entregarse el pedido: " << motivo << endl;
}

RegistroDeInventario chequearInventario (int codigoDeProducto) {
    RegistroDeInventario registroDeInventario;
    for (int i =0; i < cantidadDeProductos ; i++){
        if(inventarioDeProductos[i].codigoDeProducto == codigoDeProducto){
            registroDeInventario.existe = true;
            registroDeInventario.producto = inventarioDeProductos[i];
        };
    };
    return registroDeInventario;
};



int tomarPedido(Pedido (&carritoDeCompra)[30]) {
    int contador = 0;
    int subtotal;
    Pedido pedido;
    RegistroDeInventario registroDeInventario;
    cout<< "A continuacion, ingrese el pedido. Para terminar, ingrese codigo de producto: 0" << endl;
    while (true) {
        cout << "Porfavor, ingrese el codigo del producto que desea adquirir." << endl;
        cin >> pedido.codigoDeProducto;

        if(pedido.codigoDeProducto == 0) break;
        registroDeInventario = chequearInventario(pedido.codigoDeProducto);
        if (registroDeInventario.existe){
            cout 
                << "Ingrese la cantidad que requiere comprar del producto " 
                << pedido.codigoDeProducto << "." << endl;
            cin >> pedido.cantidadComprada;

            if(registroDeInventario.producto.stock < pedido.cantidadComprada) 
                reachazarPedido("stock insuficiente");
            else {
                subtotal = registroDeInventario.producto.precioUnitario * pedido.cantidadComprada;
                // chequear porque esta comparacion siempre es cierta, algo esta funcionando mal
                if(float(subtotal) == 999,99)
                    cout << "El pedido solicitado tiene un importe de $9999,99" << endl;
                carritoDeCompra[contador] = {
                    pedido.codigoDeProducto,
                    pedido.cantidadComprada
                };
                contador++;
            };
        }else {
            reachazarPedido("el producto solicitado no existe");
        }
    };
    return contador;
};

// tenemos que restar las unidades compradas de cada producto al stock de cada producto.
// bool procesarCompra(Pedido carritoDeCompra[30]){
//     ofstream archivoModoEscritura(nombreDeArchivo);
// };

// la idea de levantar el inventario en memoria es que no estemos abriendo y cerrando el archivo por cada consulta
void levantarInventarioEnMemoria() {
    ifstream archivoModoLectura(nombreDeArchivo);
    int posicionActual = 0;
    string linea;
    while(archivoModoLectura >> linea){
        inventarioDeProductos[posicionActual] = {
            stoi(linea.substr(0,linea.find(delimitador))),
            stoi(linea.substr(linea.find(delimitador)+1, linea.find_last_of(delimitador) + 1)),
            stoi(linea.substr(linea.find_last_of(delimitador) + 1)),
            // si vemos que cuando queremos buscar al producto en cuestion por posicion esta defasado por 1 una unidad,
            // entonces en esta asignacion le agregamos un +1 (no se si el seekg() arranca de 0 o de 1)
            posicionActual
        };
        posicionActual++;
    }
    cantidadDeProductos = posicionActual;
};


int main() {
    int cantidadDeProductosAdquiridos;
    Pedido carritoDeCompra[30];
    levantarInventarioEnMemoria();    
    // esta parte es para debuguear el inventario, despues hay que eliminarla para la entrega
    cout << "**************************** INVENTARIO ACTUAL *********************************" << endl;
    for( int i =0; i < cantidadDeProductos; i++){
        cout << "codigo de producto: " << inventarioDeProductos[i].codigoDeProducto;
        cout << " precio unitario: " << inventarioDeProductos[i].precioUnitario;
        cout << " stock: " << inventarioDeProductos[i].stock;
        cout << " posicion en inventario: " << inventarioDeProductos[i].posicion << endl;
    };
    cout << "********************************************************************************" << endl;
    cout << endl;
    cantidadDeProductosAdquiridos = tomarPedido(carritoDeCompra);
    // esta parte es para debuguear el carrito de compra, despues hay que eliminarla para la entrega
    cout << "**************************** CARRITO DE COMPRA *********************************" << endl;
    for( int i =0; i < cantidadDeProductosAdquiridos; i++){
        cout << "Producto adquirido: " << carritoDeCompra[i].codigoDeProducto;
        cout << " cantidad solicitada: " << carritoDeCompra[i].cantidadComprada << endl;
    };
    cout << "********************************************************************************" << endl;
    cout << endl;
    // procesarCompra(carritoDeCompra);
    cin.get();
    return 0;
};