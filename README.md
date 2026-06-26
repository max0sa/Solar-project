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

## Objetivo general
El enfoque se mantiene en precisar el cálculo de presupuesto, para esto se integran nuevas variables cómo baterías e inversores.

## Objetivos específicos
  - Diseñar y desarrollar nuestro código adaptado al lenguaje de programación C++ aplicando *programación orientada a objetos*. 
  - Profundizar el cálculo y diseño implementando nuevas variables cómo las baterías e inversores.
  - Desarrollar la función _mostrarBaterias_ la cual muestre el catálogo de baterías. 
  - Desarrollar la función _mostrarInversores_ la cual muestra el catálogo de inversores. 
  - Desarrollar la función _potenciaTotalSistema_ la cual es necesaria para el cálculo en la función _calcularInversores_. 
  - Desarrollar la función _calcularBaterias_ que calcula la cantidad de baterías necesarias según el consumo, la cobertura y la capacidad de la batería. 
  - Desarrollar la función _calcularInversores_ la cual calcula cantidad de inversores necesarios según la potencia del sistema. 
  - Actualizar la función _calcularCosto_. 
  - Actualizar la función _mostrarResumen_ según las nuevas variables baterías e inversores. 

## Trabajo realizado
Se migró al lenguaje de programación C++ rediseñando el código aplicando programación orientada objetos, con clases como paneles, inversores y baterías, cada una de ellas con sus respectivas características cómo nombre, precio, energía, etc... Se implementaron constructores que facilitan la creación y asignación de valores.

Se implementaron nuevas funciones como _mostrarInversores_, _potenciaTotalSistema_ y _calcularInversores_.

Dentro del nuevo código definimos 3 tipos de clases para paneles, baterías e inversores. Ayudándonos así a organizar los datos y bajar el nivel de complejidad de los cálculos , ya que cada clase tiene su nombre, precio , energía, etc.

Actualmente lo que nuestro código es capaz de hacer es lo sigiuiente: mostrar el menú de interfaz donde el usuario debe escoger los productos que sean de su preferencia, además debe indicar el consumo eléctrico aproximado que tiene en un mes, para posteriormente indicar cual es el porcentaje de ahorro que el usuario quiere obtener con la compra o instalación de los paneles solares.

Lo que el código le entregará, será un presupuesto acorde a sus preferencias y bastante aproximado a la realidad, debido a que para los precios nos basamos en E-sol, tienda pionera en chile en el rubro de las energías renovables, y suele ser catalogada como una de las opciones más económicas para comprar al por mayor.

## Instrucciones de compilamiento C++
Pasos a seguir para ejecutar el programa:
1- `g++ funciones_c++.cpp main.cpp -o main`
2- `./main`


## Avances Hito 3

## Objetivo general
El objetivo de este hito es desarrollar una interfaz gráfica para el programa mediante QtCreator.

## Objetivos Específicos
  - Diseñar y trasladar el código realizado en el hito 2 a un formato compatible para el uso de signals y slots en QtCreator.
  - Crear y diseñar las interacciones que el usuario va a enfrentarse en nuestro programa.
  - Crear funciones que calculen la huella de carbono evitada y el ahorro mensual estimado.
  - Crear función que permita descargar en PDF el presupuesto generado por el programa.

## Trabajo realizado
Se realizó un boceto en el cuál se organizan las interacciones necesarias para que el programa funcione y se diseñaron para que la interfaz sea lo más intuitiva y accesible posible.

![image alt](https://github.com/max0sa/Solar-project/blob/a2c4cd04401d60239e6c490de5e4286781e34060/images/Captura%20de%20pantalla%202026-06-23%20155903.png)

Se trabajó en las funciones que permiten calcular la huella de carbono evitada y el ahorro de dinero estimado mensualmente.

Se realizó la interfaz gráfica en QtCreator haciendo uso de QtWidgets cómo SpinBox, TextEdit, label y pushbutton estos se conectaron a sus funciones mediante su respectiva signal. El widget de spinBox se ocupa en las funciones de elegir panel, batería e inversor, desplegando el catalogo de estos y en la función de elegir región. El widget textEdit se ocupa en el modo lectura y va mostrando al usuario sus selecciones y el presupuesto final entregado. El widget label se ocupa para introducir texto que le permita al usuario comprender mejor cómo ocupar el programa. Por último los push buttons son ocupados para abrir la ventana emergente en las selecciones de panel, batería e inversores.
![image alt](https://github.com/max0sa/Solar-project/blob/a2c4cd04401d60239e6c490de5e4286781e34060/images/Captura%20de%20pantalla%202026-06-26%20175725.png)

## Fórmulas 
  - Calcular número de paneles solares:
    - Consumo Diario: (Consumo mensual / 30) * 1000 * (Porcentaje de cobertura / 100)
    - Cantidad de paneles: Consumo Diario / (Potencia del panel * horas pico de sol de la región)
  - Calculo de baterías:
    - Energía diaria: (Consumo mensual / 30) * 1000 * (Porcentaje de cobertura / 100)
    - Cantidad de baterías: Energía diaria / Capacidad de batería (en Watts/hora)
  - Calculo de inversores:
    - Potencia total paneles: Número de paneles requeridos * Potencia individual del panel seleccionado
    - Cantidad de inversores: Potencia total paneles / máxima potencia soportada por el inversor
  - Calculo costo total del proyecto:
    - Costo total = (n° paneles * Precio panel) + (n° baterias * Precio bateria) + (n° inversores * precio inversor)

## Comentarios recibidos
En la presentación realizada el día 24 de Junio se comentó la posibilidad de sacar más metricas con los datos que se solicitan en el programa y se retroalimentó acerca de la abundancia de texto en el apoyo visual. Es por esto que añadimos al resumen entregado por nuestro programa el dinero que se ahorra, este se saca mediante el valor del Kwh multiplicado por la cantidad de Kwh que se espera cubrir. Se agregó la huella de carbono evitada que se calcula multiplicando los Kwh ahorrado por los kg de CO2 que hay en un Kwh.
## Conclusiones
Durante el transcurso del proyecto logramos cumplir con nuestro objetivo de crear un programa que facilitara la planificación de la instalación de un sistema fotovoltaico, el cual trajo consigo varias dificultades como el uso de lenguajes como c y c++ los cuales no conocíamos, el uso de punteros o clases para completar lo requerido con los hitos, el uso de github ya que era una plataforma nueva para nosotros e incluso la implementación de la interfaz grafica mediante Qt creator nos trajo ciertas dificultades, a pesar de todo aprendimos no solo nuevos lenguajes de programación sino que también a el como llevar de una buena manera un proyecto grupal. En caso de darle continuación a este proyecto, se puede especificar aún más el cálculo del precio y materiales de un proyecto de energía fotovoltáica, agregando variables cómo los metros de cables, altura, etc..
