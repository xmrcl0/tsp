TSP
===

Traveling Salesman Problem
--------------------------

O TSP, mais conhecido como o problema do **Caixeiro Viajante** é um problema
logístico, que consiste, de maneira simplificada, visitar todas as "cidades"
viajando a menor distância possível.


----

Compilação
----------

Efetuar a compilação do código-fonte:

```
    $ gcc tsp.c print.c utils.c -o tsp -lm
```

----

Uso
---
Executar com a opção help:

```
    $ ./tsp -h
```

----

Exemplos
--------

Efetua cinco simulações para o TSP para um arquivo com quatro cidades:

```
    $ tsp -n 5 -m 2 -f data/grid04_xy.txt
```
