# -*- coding: utf-8 -*-

from grafo import Grafo
from quests import *
from grafo_test import TestGrafo


## Casos de teste adicionais que não foram considerados na implementação do grafo_test

g_1 = Grafo(['C','D','A'], {'a1': 'C-D', 'a2':'C-D','a3':'D-A','a4':'A-A'})
print(g_1.eh_completo())

g_2 = Grafo(['A'], {})
print(g_2.eh_completo())

teste = TestGrafo()

teste.setUp()

teste.test_vertices_nao_adjacentes()

teste.test_ha_laco()

teste.test_grau()

teste.test_arestas_ha_paralelas()

teste.test_arestas_sobre_vertice()

teste.test_eh_completo()
