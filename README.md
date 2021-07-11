Un comercio que vende no más de 30 productos diferentes, cuenta con un archivo de sus productos conteniendo 
Cód Producto (3 díg) PU (precio unitario) y Stk (cantidad en stock) 

Se pide
Ingresar por consola pedidos hasta CodP=0 con 
Cód Producto y Cantidad Pedida,
informando por cada uno según haya stock suficiente o no:
-el pedido solicitado tiene un importe de $9999,99
o
-no puede entregarse el pedido por stock insuficiente
o
-el producto solicitado no existe (en caso que se haya solicitado un código de producto inexistente)

Una vez finalizado el ingreso, actualizar el archivo de productos con las nuevas cantidades en stock 

Nota: para resolver este problema deberá generar un vector con la info de productos, que luego grabará dentro del archivo de productos para actualizarlo

Cada vez que el stock de un pedido es insuficiente, se rechaza dicho pedido completo. Por ejemplo si se solicitan 20 unidades y quedan 15, se rechazan las 20 y continúan quedando las 15 restantes en stock.