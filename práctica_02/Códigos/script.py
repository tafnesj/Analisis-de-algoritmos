#   Título: Script.
# 	----------------------------------------------
#   Descripción:
# 	  Script para la obtención de los tiempos.
# 	----------------------------------------------
#   Fecha: 26/Noviembre/2020.
#   Versión: Versión 1.0
#   Autor: Tafnes Jiménez.


import os
import subprocess
import numpy as np
import matplotlib.pyplot as plt
import json
import statistics


# Función graficar
def graficar(data_x, data_y, legends, label_x, label_y, title, file, marker):
    for i in range(0, len(data_x)):
        plt.plot(data_x[i], data_y[i], label=legends[i], marker=marker)
    plt.grid(True)
    plt.xlabel(label_x)
    plt.ylabel(label_y)
    plt.title(title)
    plt.legend(loc='upper center', bbox_to_anchor=(
        0.5, -0.1), shadow=True, ncol=4)
    plt.savefig(file, bbox_inches='tight')
    plt.clf()


# Compilación
estado = os.system("gcc main.c tiempo.c -lpthread -2")
if estado != 0:
    print("No compiló.")
    exit(0)
valores = [1000000, 2000000, 3000000, 4000000, 5000000,
           6000000, 7000000, 8000000, 9000000, 10000000]
buscar = [0, 5000, 61396, 152503, 214826, 3128036, 6337399,
          10393545, 14700764, 187645041, 450057883, 1295390003,
          1360839354, 1493283650, 1843349527, 1980098116, 2109248666,
          2147445644, 2147470852]
etiquetas = ['Búsqueda lineal', 'Búsqueda árbol binario',
             'Búsqueda binaria', 'Búsqueda exponencial',
             'Búsqueda Fibonacci', 'Búsqueda lineal con hilos',
             'Búsqueda binaria con hilos', 'Búsqueda exponencial con hilos',
             'Búsqueda exponencialyy con hilos']
num_algoritmos = len(etiquetas)
memoria = [{} for i in range(num_algoritmos)]


# Gráficas indivudales de tiempo
for x in range(1, num_algoritmos+1):
    info_actual = {}
    for n in valores:
        n_en_algoritmo = {}
        for z in buscar:
            print(F"Algoritmo: {etiquetas[x-1]} tamaño {n} buscando {z}")
            if x <= 2 or x == 6:
                salida = subprocess.check_output(
                    # Tamaño Algoritmo Número Archivo
                    F"./a.out {n} {x} {z} < 10millones_desordenados.txt",
                    shell=True, universal_newlines=True)
            elif x > 2 or x < 6 or x > 6:
                salida = subprocess.check_output(
                    # Tamaño Algoritmo Número Archivo
                    F"./a.out {n} {x} {z} < 10millones_ordenados.txt",
                    shell=True, universal_newlines=True)
            datos = [float(i) for i in salida.split()]

            found = datos[0]
            tiempo_real = datos[1]

            n_en_algoritmo[z] = {'found': found, 'tiempo_real': tiempo_real}
            print(F"{tiempo_real} {found}")

        info_actual[n] = n_en_algoritmo

    memoria[x-1] = info_actual

# Guardarlo en un archivo JSON
archivo = open(F"memoria.txt", "w")
archivo.write(json.dumps(memoria))
archivo.close()

for x in range(num_algoritmos):
    # Guardar en un archivo las salidas
    archivo = open(F"{etiquetas[x]}.txt", "w")
    for n in valores:
        archivo.write("Número a buscar\tTamaño de n\tTiempo\tEncontrado\n")
        for z in buscar:
            archivo.write(
                F"{z}\t{n}\t{memoria[x][n][z]['tiempo_real']}\t{memoria[x][n][z]['found']}\n")
        archivo.write("\n")

    # Aproximaciones temporales
    eje_x = np.array([])
    eje_y = np.array([])

    for n in valores:
        promedio = statistics.mean([dato['tiempo_real']
                                    for dato in memoria[x][n].values()])
        eje_x = np.append(eje_x, [n])
        eje_y = np.append(eje_y, [promedio])

    # Coeficientes
    cf = []

    cf.append(np.polyfit(eje_x, eje_y, 1))
    cf.append(np.polyfit(np.log(eje_x), eje_y, 1))
    cf.append(np.polyfit(eje_x, np.log(eje_y), 1))
    cf.append(np.polyfit(np.log(eje_x), np.log(eje_y), 1))
    cf.append(np.polyfit(eje_x, 1.0/eje_y, 1))

    # Funciones de aproximación
    archivo.write("\nCoeficientes\n")
    archivo.write(F"f(n)= {cf[0][0]}*n+{cf[0][1]}\n")
    archivo.write(F"f(n)= {cf[1][0]}*n^{cf[1][1]}\n")
    archivo.write(F"f(n)= {cf[2][0]}*e^({cf[2][1]}n)\n")
    archivo.write(F"f(n)= {cf[3][0]}*ln(n)+{cf[3][1]}\n")
    archivo.write(F"f(n)= 1/({cf[4][0]}*n+{cf[4][1]})\n")

    # Cerrar archivo
    archivo.close()

    eje_x_poly = np.linspace(1, eje_x[-1], 1000)

    eje_y_poly = []
    eje_y_poly.append(
        np.array(list(map(lambda t: cf[0][0]*t+cf[0][1], eje_x_poly))))
    eje_y_poly.append(
        np.array(list(map(lambda t: cf[1][0]*t**cf[1][1], eje_x_poly))))
    eje_y_poly.append(
        np.array(list(map(lambda t: cf[2][0]*np.exp(cf[2][1]*t), eje_x_poly))))
    eje_y_poly.append(
        np.array(list(map(lambda t: cf[3][0]*np.log(t)+cf[3][1], eje_x_poly))))
    eje_y_poly.append(
        np.array(list(map(lambda t: 1/(cf[4][0]*t+cf[4][1]), eje_x_poly))))

    # Gráfica de los polimonios I
    graficar([eje_x_poly]*4, np.concatenate((eje_y_poly[0:3],[eje_y_poly[4]])),
             [F"Aproximación: {i} " for i in [0, 1, 2, 4]],
             "Valor de n", "Tiempo aproximado", F"Aproximaciones de {etiquetas[x]}",
             F"aprox_1_{etiquetas[x]}.png", "")

    # Gráfica de los polimonios II
    graficar([eje_x_poly], [eje_y_poly[3]], [F"Aproximación: {i} " for i in [3]],
             "Valor de n", "Tiempo aproximado", F"Aproximaciones de {etiquetas[x]}",
             F"aprox_2_{etiquetas[x]}.png", "")