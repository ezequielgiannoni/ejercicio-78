#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char delimitador = ':';
char nombreDeArchivo[15] = "inventario.txt";

struct Producto {
    int codigoDeProducto;
    int precioUnitario;
    int stock; 
};

struct Pedido {
    int codigoDeProducto;
    int cantidadComprada;
};

void crearInventarioInicial() {
    Producto producto;
    vector<Producto> inventarioDeProductos;
    cout << "A continuacion generaremos el archivo de inventario" << endl;
    while(true){
        producto = {}; //reseteamos el producto
        cout << "Porfavor, ingrese el codigo del producto, para finalizar, ingrese 0" << endl;
        cin >> producto.codigoDeProducto;
        if(producto.codigoDeProducto == 0){
            break;
        }
        cout << "Porfavor, ingrese el precio unitario del producto" << endl;
        cin >> producto.precioUnitario;
        cout << "Porfavor, ingrese el stock del producto" << endl;
        cin >> producto.stock;
        inventarioDeProductos.push_back(producto);
    };
    ofstream archivo(nombreDeArchivo);
    for( int i; i < inventarioDeProductos.size(); i++){
        archivo 
            << inventarioDeProductos[i].codigoDeProducto 
            << delimitador
            << inventarioDeProductos[i].precioUnitario 
            << delimitador
            << inventarioDeProductos[i].stock 
            << endl;
    };
    archivo.close();
    return;
};

bool chequearInventario () {
    
}

bool tomarPedido(vector<Pedido> &carritoDeCompra) {
    int counter = 0;
    cout<< "A continuacion, ingrese el pedido. Para terminar, ingrese codigo de producto: 0" << endl;
    while (true) {
        Pedido pedido = {};
        cout << "Porfavor, ingrese el codigo del producto numero " << counter + 1 << " que desea adquirir." << endl;
        cin >> pedido.codigoDeProducto;
        if(pedido.codigoDeProducto == 0){
            break;
        };
        cout << "Ingrese la cantidad que requiere comprar del producto " << pedido.codigoDeProducto << "." << endl;
        cin >> pedido.cantidadComprada;
        if (chequearInventario()){
            carritoDeCompra.push_back(pedido);
            counter++;
        } else {
            return false; 
        }
    }
    return true;
}

int main(){
    crearInventarioInicial();
    //por ahora deje comentado el tomarPedido() para poder debuggear el resto
    // tomarPedido();
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