# Solar-project

## Integrantes / Roles
  - Maximiliano Ossa / programador jefe
  - José Contreras / programador
  - Maximiliano Lizana / programador
  - Cristóbal Arriagada / investigador/organizador

## Problematica a resolver 
Con la ayuda de este proyecto, se le facilita a un técnico la manera de ofrecer sus servicios de instalación de paneles fotovoltaicos, ahorrando tiempo en el calculo de el presupuesto correspondiente, y ayudando a transparentar el costo a sus respectivos clientes.

## Objetivo General
Facilitar la planificación para técnicos y clientes en proyectos de energía solar.


## Objetivos Específicos
  - Investigar sobre los distintos tipos de paneles solares, sus tecnologías, potencia y precios. Fuentes: [Solartex](https://www.solartex.cl), 
  [Esol](https://www.esol.cl), [autosolar](https://autosolar.pe/energia-solar/como-calcular-cuantos-paneles-solares-necesito?srsltid=AfmBOoqR19ASezeJkz16LaOKjeK1gAOIw2qrbcLmPp_cxOOwcTVlU4cM).
  - Desarrollar una interfaz de funcionamiento mediante consola que permita al usuario poder navegar a través de las funcionalidades del
    programa.
  - Desarrollar función _mostrarPaneles_.
  - Desarrollar función _calcularNpaneles_.
  - Desarrollar función _calcularCosto_.
  - Desarrollar función _mostrarResumen_.
  - Traslado proyecto al lenguaje C++.
  - Desarrollar interfaz visual.
  - Desarrollar base de datos para que el usuario guarde sus proyectos.

## Funcionalidades
Se plantea que el programa cuente con las siguientes funcionalidades:

  - Mostrar el catálogo de paneles con sus respectivos precios, potencia y su tipo de tecnología.
  - Calcular el número de paneles solares que se necesitan en base al consumo de energía que requiere cubrir el usuario, el promedio de las horas pico de sol en la región en la que se quiere implementar el          panel solar y el tipo de panel que se desea implementar. 
  - Calcular el costo aproximado del proyecto, basados en los precios del mercado.
  - Mostrar un resumen de lo calculado.

## Avances hito 1
En este hito se buscó avanzar en la interfaz de navegación para el usuario, donde pueda acceder a las distintas funcionalidades antes mencionadas y avanzar
en las propias funcionalidades del programa.

En el primer sprint se logró avanzar en la interfaz de navegación, logrando que el usuario a través de la terminal pueda interactuar y tenga la posibilidad de 
escoger las distintas funcionalidades.

En el segundo sprint se logró avanzar en la funcion _mostrarPaneles_ (opción 1 de la interfaz) que permitió al usuario ver la categoría de paneles solares y luego 
mostrar el tipo de panel con su respectiva tecnología y potencia.

En el tercer sprint se logró completar la opción 2 (Ingresar consumo) y las funciones _calcularNpaneles_ (opción 3), _calcularCosto_ (opción 4), _mostrarResumen_ (opción 5).

## Instrucciones de compilamiento
Pasos a seguir para ejecutar el programa:

1- `git main.c funciones.c -o main -lm`

2- `./main`

## Pasos a seguir hito 2
Para el próximo hito se plantea crear nuevas funciones según como vaya progresando el proyecto y las necesidades que estas implican, aplicar retroalimentaciones de profesores/ayudantes, trasladar el proyecto al lenguaje de programación C++ y empezar a trabajar en una interfaz más amigable y fácil de uso para el usuario.

## Avances hito 2
Actualmente nuestro enfoque sigue siendo facilitar el cálculo de presupuesto y finalmente la venta de un servicio de energía solar a un cliente.

Nos acercaremos a este objetivo esta vez en el hito 2 , de forma que la persona pueda tener una visión clara y ahora más específica de qué se le será instalado, con su correspondiente precio.

Durante el hito 2 pudimos llevar a cabo el cambio de lenguaje en el proyecto , desde C hacia C++, además pudimos implementar nuevas funciones como lo son : mostrarInversores, potenciaTotalSistema y calcularInversores.

Dentro del nuevo código definimos 3 tipos de clases para paneles, baterías e inversores. Ayudándonos así a organizar los datos y bajar el nivel de complejidad de los cálculos , ya que cada clase tiene su nombre, precio , energía, etc.

Actualmente lo que nuestro código es capaz de hacer es lo sigiuiente: mostrar el menú de interfaz donde el usuario debe escoger los productos que sean de su preferencia , además debe indicar el consumo eléctrico aproximado que tiene en un mes, para posteriormente indicar cual es el porcentaje de ahorro que el usuario quiere obtener con la compra o instalación de los paneles solares.

Lo que el código le entregará, será un presupuesto acorde a sus preferencias y bastante aproximado a la realidad, debido a que para los precios nos basamos en E-sol, tienda pionera en chile en el rubro de las energías renovables, y suele ser catalogada como una de las opciones más económicas para comprar al por mayor.


