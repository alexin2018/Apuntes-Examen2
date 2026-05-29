#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTOS 1000

/** Definir al Estructura de los datos */
struct alumno
{
  int legajo;
  char nombre[20];
  char apellido[20];
  float promedio;
};

//definir procedimientos y funciones

struct alumno buscarProducto(struct alumno inventario[], int n);
void listaralumnos(struct alumno inventario[], int n);
void eliminarProducto(struct alumno inventario[], int *n);
void agreagarProducto(struct alumno inventario[], int *n);
void modificarProducto(struct alumno inventario[], int n);

int main()

{

  /** Inicializar los datos  */

  struct alumno inventario[MAX_PRODUCTOS] = {
      {58293012, "Monitor","Monitor", 120.00},
      {19485726, "Mousepad","Monitor", 10.00},
      {83746501, "Procesador","Monitor", 200.00},
      {37482910, "Teclado","Monitor", 25.50},
      {92837465, "Fuente ATX","Monitor", 75.00},
      {48291037, "Webcam","Monitor", 55.00},
      {10293847, "Silla Gamer","Monitor", 250.00},
      {74659283, "Impresora","Monitor", 85.00},
      {29384756, "Disco SSD","Monitor",95.00},
      {65748392, "Mouse Choco","Monitor", 15.75},
      {51928374, "Parlantes","Monitor", 40.20},
      {84756291, "Cables HDMI","Monitor", 8.50},
      {38475629, "Auriculares","Monitor", 65.50},
      {91028374, "Gabinete","Monitor", 60.00},
      {27384950, "Microfono","Monitor", 30.00},
      {46573829, "Adaptador USB","Monitor", 5.99},
      {15263748, "Memoria RAM","Monitor", 50.00},
      {73849506, "Pendrive","Monitor", 12.99},
      {62738495, "Placa Video","Monitor", 350.00},
      {39485761, "Escritorio","Monitor", 150.00}};

  int n = 20; // cantidad actual de productos



  //ordenar
  int i, j;
  struct alumno temp;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - 1 - i; j++)
    {
      if (inventario[j].legajo > inventario[j + 1].legajo)
      {
        // Intercambio
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  /** Menu de opciones */

  int opcion;

  do
  {
    printf("\nMenu de opciones:\n");
    printf("1) Listar Productos\n");
    printf("2) Buscar Producto\n");
    printf("3) Eliminar Producto\n");
    printf("4) Agregar un producto\n");
    printf("5) Modificar Producto\n");
    printf("6) Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
      printf("\nInventario ordenado y actualizado:\n");
      listaralumnos(inventario, n);
      break;

    case 2:
    {
      struct alumno productoEncontrado;
      productoEncontrado = buscarProducto(inventario, n);
      if (productoEncontrado.legajo != 0)
      {
        printf("\nalumno encontrado:\n");
        printf("Nombre %s: \n", productoEncontrado.nombre);
        printf("apellido: %s\n", productoEncontrado.apellido);
        printf("Promedio: %.2f\n", productoEncontrado.promedio);
      }
      else
      {
        printf("\nNo se encontro el numero de legajo.\n");
      }
      break;
    }
    case 3:
    {
      eliminarProducto(inventario, &n);

      break;
    }

    case 4:
    {
      agreagarProducto(inventario, &n);
      break;
    }

    case 5:
    {
      modificarProducto(inventario, n);
      break;
    }

    case 6:
      printf("\nSaliendo del programa...\n");
      break;

    default:
      printf("\nOpcion invalida. Intente nuevamente.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}


//buscar
struct alumno buscarProducto(struct alumno inventario[], int n)
{
  int nroProductoBuscado;
  int inicio = 0;
  int fin = n - 1;

  printf("Ingrese el numero de legajo a buscar: ");
  scanf("%d", &nroProductoBuscado);

  while (inicio <= fin)
  {
    int medio = inicio + (fin - inicio) / 2;

    if (inventario[medio].legajo == nroProductoBuscado)
    {
      return inventario[medio];
    }

    if (inventario[medio].legajo < nroProductoBuscado)
    {
      inicio = medio + 1;
    }
    else
    {
      fin = medio - 1;
    }
  }
  // Devolver un producto vacío si no se encuentra
  struct alumno productoVacio = {0, "","", 0.0};
  return productoVacio;
}


//listar
void listaralumnos(struct alumno inventario[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d \t %d \t %s \t %s \t %.2f\n",
           i + 1,
           inventario[i].legajo,
           inventario[i].nombre,
           inventario[i].apellido,
           inventario[i].promedio);
  }
}


//eliminar
void eliminarProducto(struct alumno inventario[], int *n)
{
  int nroProductoEliminar;
  printf("Ingrese el numero de legajo a eliminar: ");
  scanf("%d", &nroProductoEliminar);

  int i, j;
  int encontrado = 0;

  for (i = 0; i < *n; i++)
  {
    if (inventario[i].legajo == nroProductoEliminar)
    {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("\nNo se encontro un legajo con ese numero.\n");
    return;
  }

  for (j = i; j < *n - 1; j++)
  {
    inventario[j] = inventario[j + 1];
  }

  (*n)--;
  printf("\nlegajo eliminado correctamente.\n");
}


//agregar
void agreagarProducto(struct alumno inventario[], int *n)
{
  if (*n >= MAX_PRODUCTOS)
  {
    printf("\nNo se pueden agregar mas legajos. Inventario lleno.\n");
    return;
  }

  struct alumno nuevoProducto;

  printf("Ingrese el numero de legajo: ");
  scanf("%d", &nuevoProducto.legajo);
  printf("Ingrese el nombre del alumno: ");
  scanf(" %19[^\n]", nuevoProducto.nombre);
  printf("Ingrese el apellido del alumno: ");
  scanf(" %19[^\n]", nuevoProducto.apellido);
  printf("Ingrese el promedio del producto: ");
  scanf("%f", &nuevoProducto.promedio);

  inventario[*n] = nuevoProducto;
  (*n)++;

  // Reordenar el inventario después de agregar un nuevo producto
  int i, j;
  struct alumno temp;

  for (i = 0; i < *n - 1; i++)
  {
    for (j = 0; j < *n - 1 - i; j++)
    {
      if (inventario[j].legajo > inventario[j + 1].legajo)
      {
        // Intercambio
        temp = inventario[j];
        inventario[j] = inventario[j + 1];
        inventario[j + 1] = temp;
      }
    }
  }

  printf("\n alumno agregado y ordenado correctamente.\n");
}


//modificar
void modificarProducto(struct alumno inventario[], int n)
{
  printf("Ingrese el legajo del alumno a modificar: ");
  int nroProductoModificar;
  scanf("%d", &nroProductoModificar);

  struct alumno productoEncontrado;
  productoEncontrado = buscarProducto(inventario, n);

  if (productoEncontrado.legajo == 0)
  {
    printf("\nNo se encontro el alumno.\n");
    return;
  }

  printf("Ingrese el nuevo nombre del alumno: ");
  scanf(" %19[^\n]", productoEncontrado.nombre);
  printf("Ingrese el nuevo apellido del alumno: ");
  scanf(" %19[^\n]", productoEncontrado.apellido);
  printf("Ingrese el nuevo promedio del alumno: ");
  scanf("%f", &productoEncontrado.promedio);

  // Actualizar el producto en el inventario
  for (int i = 0; i < n; i++)
  {
    if (inventario[i].legajo == nroProductoModificar)
    {
      inventario[i] = productoEncontrado;
      break;
    }
  }

  printf("\nProducto modificado correctamente.\n");
}