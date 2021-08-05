#include <iostream>
#include <fstream>

using namespace std;

char delimitador = ':';
char nombreDeArchivo[15] = "inventario.txt";

struct Producto {
    int codigoDeProducto;
    int precioUnitario;
    int stock;
};
struct RegistroDeInventario {
    bool existe;
    int posicion;
    Producto producto;
};

struct Pedido {
    int codigoDeProducto;
    int cantidadComprada;
};

// void crearInventarioInicial() {
//     Producto producto;
//     Producto inventarioDeProductos [30];
//     ofstream archivoModoEscritura;
//     int contador = 0;
//     cout << "A continuacion generaremos el archivo de inventario" << endl;
//     while(true){
//         producto = {}; //reseteamos el producto
//         cout << "Porfavor, ingrese el codigo del producto, para finalizar, ingrese 0" << endl;
//         cin >> producto.codigoDeProducto;
//         if(producto.codigoDeProducto == 0){
//             break;
//         }
//         cout << "Porfavor, ingrese el precio unitario del producto" << endl;
//         cin >> producto.precioUnitario;
//         cout << "Porfavor, ingrese el stock del producto" << endl;
//         cin >> producto.stock;
//         inventarioDeProductos[contador] = producto;
//         cout << "acaaaaaa" << endl;
//         cout << "codigo de producto" << inventarioDeProductos[contador].codigoDeProducto;
//         cout << "precio unitario" << inventarioDeProductos[contador].precioUnitario;
//         cout << "stock " << inventarioDeProductos[contador].stock;
//     };
//     int cantidadDeProductosCargados = sizeof(inventarioDeProductos) / sizeof(inventarioDeProductos[0]);
//     archivoModoEscritura.open(nombreDeArchivo);
//     for( int i; i < cantidadDeProductosCargados; i++){
//         archivoModoEscritura
//             << inventarioDeProductos[i].codigoDeProducto 
//             << delimitador
//             << inventarioDeProductos[i].precioUnitario 
//             << delimitador
//             << inventarioDeProductos[i].stock 
//             << endl;
//     };
//     archivoModoEscritura.close();
//     return;
// };

RegistroDeInventario buscarRegistroEnInventario (int codigoDeProducto) {
    ifstream archivoModoLectura(nombreDeArchivo);
    RegistroDeInventario registroDeInventario;
    int posicionActual = 0;
    string linea;
    while(archivoModoLectura >> linea){
        registroDeInventario.producto.codigoDeProducto = stoi(linea.substr(0,linea.find(delimitador)));
        if (registroDeInventario.producto.codigoDeProducto == codigoDeProducto){
            registroDeInventario.existe = true;
            registroDeInventario.posicion = posicionActual;
            registroDeInventario.producto.stock = stoi(linea.substr(linea.find_last_of(delimitador) + 1));
            registroDeInventario.producto.precioUnitario = stoi(linea.substr(linea.find(delimitador)+1, linea.find_last_of(delimitador) + 1));
            cout << "index del producto " << registroDeInventario.posicion << endl;
            cout << "codigo de producto " << registroDeInventario.producto.codigoDeProducto << endl ;
            cout << "precio de producto " << registroDeInventario.producto.precioUnitario << endl ;
            cout << "stock de producto " << registroDeInventario.producto.stock << endl ;
        }
        posicionActual++;
    };
    return registroDeInventario;
};

void reachazarPedido(string motivo) {
    cout << "No puede entregarse el pedido: " << motivo << endl;
}

void tomarPedido(Pedido (&carritoDeCompra)[30]) {
    int contador = 0;
    int subtotal;
    Pedido pedido;
    RegistroDeInventario registroDeInventario;
    cout<< "A continuacion, ingrese el pedido. Para terminar, ingrese codigo de producto: 0" << endl;
    while (true) {
        pedido = {}; // reseteamos la estructura del pedido
        cout
            << "Porfavor, ingrese el codigo del producto numero " 
            << contador + 1 
            << " que desea adquirir." << endl;
        cin >> pedido.codigoDeProducto;

        if(pedido.codigoDeProducto == 0) break;

        cout 
            << "Ingrese la cantidad que requiere comprar del producto " 
            << pedido.codigoDeProducto << "." << endl;
        cin >> pedido.cantidadComprada;

        registroDeInventario = buscarRegistroEnInventario(pedido.codigoDeProducto);

        if (!registroDeInventario.existe)
            reachazarPedido("el producto solicitado no existe");
        else if(registroDeInventario.producto.stock < pedido.cantidadComprada) 
            reachazarPedido("stock insuficiente");
        else {
            subtotal = registroDeInventario.producto.precioUnitario * pedido.cantidadComprada;
            if(subtotal == 999,99)
                cout << "El pedido solicitado tiene un importe de $9999,99" << endl;
            carritoDeCompra[contador] = {
                pedido.codigoDeProducto,
                pedido.cantidadComprada
            };
            contador++;
        };
    };
};



// bool procesarCompra(Pedido carritoDeCompra[30]){

// };

void levantarInventarioEnMemoria(Producto (&arregloDeProductos)[30]) {
    int cantidadDeProductos = 6;
    for(int i; i <= cantidadDeProductos; i++){
        arregloDeProductos[i].codigoDeProducto = i;
        arregloDeProductos[i].precioUnitario = (i*10);
        arregloDeProductos[i].stock = (i*10);
    };
};

int main() {
    Producto inventarioDeProductos[30];
    Pedido carritoDeCompra[30];
    levantarInventarioEnMemoria(inventarioDeProductos);
    for( int i =0; i < 6; i++){
        cout << "codigo de producto: " << inventarioDeProductos[i+1].codigoDeProducto;
        cout << " precio unitario: " << inventarioDeProductos[i+1].precioUnitario;
        cout << " stock: " << inventarioDeProductos[i+1].stock << endl;
    };
    tomarPedido(carritoDeCompra);
    // procesarCompra(carritoDeCompra);
    cin.get();
    return 0;
};



// vector<Producto> leerInventario(ifstream &archivo) {
//     Producto producto = {};
//     vector<Producto> inventario;
//     string linea; // codigoDeProducto:precio:stock
//     vector<string> campos;
//     int counter = 0;
//     while(!archivo.eof()){

//         getline(archivo, linea);
//         campos = decodearLinea(linea);
//         producto  =  {
//             campos[0],
//             1,
//             2
//         }

//         counter++;
//     };
//     return inventario;
// };


// Producto decodearLinea(string linea){
    
//     Producto producto = {};
//     char codigoDeProducto[3]; 
//     int indexInicial = 0;
//     int indexDelDelimitador = 0;
//     vector<string> vectorResultado;
    
//     while(indexDelDelimitador >= 0){
//         indexDelDelimitador = texto.find(delimitador, indexInicial);
//         campo = texto.substr(indexInicial, indexDelDelimitador - indexInicial);
//         // hacemos un offset para preparar la siguiente iteracion
//         indexInicial = indexDelDelimitador++;
//         vectorResultado.push_back(campo);
//     }
//     return vectorResultado;
// }