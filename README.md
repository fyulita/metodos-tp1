# Métodos Numéricos - TP1

### Integrantes

- Justo López Menardi (juslopezm@gmail.com)
- Matías Strobl (matias.strobl@gmail.com)
- Federico Yulita (fyulita@dc.uba.ar)

## Instrucciones

Desde alguna consola se puede ejecutar `g++ -o tp01 *.cpp` para compilar el código con g++ o
`python src/metnum.py compile` para compilar el código con python. Para ejecutar algún algoritmo
desde la consola se puede ejecutar `./tp01 [entrada] [salida] [método]`.

Los archivos de entrada se encuentran en `'data/'`, `'src/TestsCMM'/` y `'src/TestsWP/'` con la extensión `.in`
y los archivos de salida en las mismas carpetas con la extensión `.out`. Las
opciones de métodos son 0 para usar el algoritmo de Colley (*CMM*) y 1 para usar el algoritmo
de porcentaje de victoria (*WP*).

El archivo `Notebook.ipynb` es un cuaderno de python usando Jupyter Notebook que contiene toda la
experimentación que se realizó. Para poder ejecutarlo correctamente primero hay que instalar
los paquetes necesarios de python que se encuentran en `requirements-python.txt`. Para esto se
puede usar pip desde consola ejecutando `pip install -r requirements-python.txt`.
