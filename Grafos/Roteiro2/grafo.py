#-*- coding: utf-8 -*-
from copy import copy

class VerticeInvalidoException(Exception):
    pass

class ArestaInvalidaException(Exception):
    pass

class Grafo:

    QTDE_MAX_SEPARADOR = 1
    SEPARADOR_ARESTA = '-'

    def __init__(self, N=[], A={}):
        '''
        Constrói um objeto do tipo Grafo. Se nenhum parâmetro for passado, cria um Grafo vazio.
        Se houver alguma aresta ou algum vértice inválido, uma exceção é lançada.
        :param N: Uma lista dos vértices (ou nodos) do grafo.
        :param V: Uma dicionário que guarda as arestas do grafo. A chave representa o nome da aresta e o valor é uma string que contém dois vértices separados por um traço.
        '''
        for v in N:
            if not(Grafo.verticeValido(v)):
                raise VerticeInvalidoException('O vértice ' + v + ' é inválido')

        self.N = N

        for a in A:
            if not(self.arestaValida(A[a])):
                raise ArestaInvalidaException('A aresta ' + A[a] + ' é inválida')

        self.A = A

    def arestaValida(self, aresta=''):
        '''
        Verifica se uma aresta passada como parâmetro está dentro do padrão estabelecido.
        Uma aresta é representada por um string com o formato a-b, onde:
        a é um substring de aresta que é o nome de um vértice adjacente à aresta.
        - é um caractere separador. Uma aresta só pode ter um único caractere como esse.
        b é um substring de aresta que é o nome do outro vértice adjacente à aresta.
        Além disso, uma aresta só é válida se conectar dois vértices existentes no grafo.
        :param aresta: A aresta que se quer verificar se está no formato correto.
        :return: Um valor booleano que indica se a aresta está no formato correto.
        '''

        #Não pode haver mais de um caractere separador
        if aresta.count(Grafo.SEPARADOR_ARESTA) != Grafo.QTDE_MAX_SEPARADOR:
            return False

        #Índice do elemento separador
        i_traco = aresta.index(Grafo.SEPARADOR_ARESTA)

        #O caractere separador não pode ser o primeiro ou o último caractere da aresta
        if i_traco == 0 or aresta[-1] == Grafo.SEPARADOR_ARESTA:
            return False

        #Verifica se as arestas antes de depois do elemento separador existem no Grafo
        if not(self.existeVertice(aresta[:i_traco])) or not(self.existeVertice(aresta[i_traco+1:])):
            return False

        return True

    @classmethod
    def verticeValido(self, vertice=''):
        '''
        Verifica se um vértice passado como parâmetro está dentro do padrão estabelecido.
        Um vértice é um string qualquer que não pode ser vazio e nem conter o caractere separador.
        :param vertice: Um string que representa o vértice a ser analisado.
        :return: Um valor booleano que indica se o vértice está no formato correto.
        '''
        return vertice != '' and vertice.count(Grafo.SEPARADOR_ARESTA) == 0

    def existeVertice(self, vertice=''):
        '''
        Verifica se um vértice passado como parâmetro pertence ao grafo.
        :param vertice: O vértice que deve ser verificado.
        :return: Um valor booleano que indica se o vértice existe no grafo.
        '''
        return Grafo.verticeValido(vertice) and self.N.count(vertice) > 0

    def existeAresta(self, aresta=''):
        '''
        Verifica se uma aresta passada como parâmetro pertence ao grafo.
        :param aresta: A aresta a ser verificada
        :return: Um valor booleano que indica se a aresta existe no grafo.
        '''
        existe = False
        if Grafo.arestaValida(self, aresta):
            for k in self.A:
                if aresta == self.A[k]:
                    existe = True

        return existe

    def adicionaVertice(self, v):
        '''
        Adiciona um vértice no Grafo caso o vértice seja válido e não exista outro vértice com o mesmo nome
        :param v: O vértice a ser adicionado
        :raises: VerticeInvalidoException se o vértice passado como parâmetro não puder ser adicionado
        '''
        if self.verticeValido(v) and not self.existeVertice(v):
            self.N.append(v)
        else:
            raise VerticeInvalidoException('O vértice ' + v + ' é inválido')

    def adicionaAresta(self, nome, a):
        '''
        Adiciona uma aresta no Grafo caso a aresta seja válida e não exista outra aresta com o mesmo nome
        :param v: A aresta a ser adicionada
        :raises: ArestaInvalidaException se a aresta passada como parâmetro não puder ser adicionada
        '''
        if self.arestaValida(a):
            self.A[nome] = a
        else:
            ArestaInvalidaException('A aresta ' + self.A[a] + ' é inválida')

    def __str__(self):
        '''
        Fornece uma representação do tipo String do grafo.
        O String contém um sequência dos vértices separados por vírgula, seguido de uma sequência das arestas no formato padrão.
        :return: Uma string que representa o grafo
        '''
        grafo_str = ''

        for v in range(len(self.N)):
            grafo_str += self.N[v]
            if v < (len(self.N) - 1):  #Só coloca a vírgula se não for o último vértice
                grafo_str += ", "

        grafo_str += '\n'

        for i, a in enumerate(self.A):
            grafo_str += self.A[a]
            if not(i == len(self.A) - 1): #Só coloca a vírgula se não for a última aresta
                grafo_str += ", "

        return grafo_str


        #Q2
    #A) Encontre todos os pares de vértices não adjacentes.

    def vertices_nao_adjacentes(self):
        #Iniciando lista que conterá os pares adjacentes
        paresNAdj = list()
        #Percorrendo o conjunto de vértices, chamando-os de node
        for node in self.N:
            #A estrutura set não armazena dois elementos iguais
            #será nosso conjunto de adjacentes, a fim de evitar vértices repetidos
            verticesAdj = set()

            #Percorrendo o conjunto de arestas para cada um dos vértices
            for aresta in self.A:
                #Procurando os vértices adjacentes dentro de cada 
                #subconjunto de A(aresta) em relação ao vértice atual
                if(node in self.A[aresta]):
                    verticeAdj = self.A[aresta]
                    #Removendo o vértice que está conectado com o atual da repetição
                    #Ex: J-C --> C
                    verticeAdj = verticeAdj.replace(node, "").replace("-", "")
                    #Adicionando o vértice adjacente, já tratado, ao conjunto de adjacentes
                    verticesAdj.add(verticeAdj)
            
            verticesNAdj = [paresNAdj.append(node + "-" + v) for v in self.N if v not in list(verticesAdj)]
        
        #Ex: Se considerarmos que J-M é o mesmo par que M-J,
        #é necessários excluirmos os pares palíndromos:

        #Retorno da nossa lista de pares não adjacentes
        return paresNAdj
            


    #B) Há algum vértice adjacente a ele mesmo? (Retorne True ou False)
    def ha_laco(self):
        #Para cada vértice vemos suas arestas
        for vertice in self.A:
            #Se a função da aresta é palíndromo, ela é um laço
            #sedo um laço, sabemos que é adjacente a si mesmo
            if(self.A[vertice] == self.A[vertice][::-1]):
                return True
                
        return False

    #C) Há arestas paralelas? (Retorne True ou False)
    def ha_paralelas(self):
        #Transformamos os valores do dicionário de arestas em uma lista
        allVertices = list(self.A.values())
        #Percorremos os vertices vendo se possui mais de uma conexão igual(aresta)
        #ou vendo se possui uma aresta palindromo, que também seria paralela
        for vertice in allVertices:
            if(allVertices.count(vertice) > 1 or vertice[::-1] in allVertices):
                return True

        return False


    #D) Qual o grau de um vértice arbitrário?
    def grau(self, verticeC):
        #iniciamos nosso contador para grau
        count = 0

        for aresta in self.A:
            #Percorremos os vértices e verificamos quantas vezes
            #o vértice passado se repete no conjunto de arestas
            if(verticeC in self.A[aresta]):
                count+= 1 
        return count


    #E) Quais arestas incidem sobre um vértice N arbitrário?
    def arestas_sobre_vertice(self, verticeC):
        return [aresta for aresta in self.A if verticeC in self.A[aresta]]

    # F) Esse self é completo?
    def eh_completo(self):

        for vertice in self.N:
            arestas = self.A.values()
            #Verificando vertices adjacentes e únicos para cada aresta
            arestas_adj = set([aresta for aresta in arestas if vertice in aresta and aresta!=aresta[::-1]])
            
            #Comparando se o vertice se conecta com todos os distintos adjacentes
            if(len(arestas_adj) < len(self.N) - 1): 
                return False
        
        return True

    #G) Para essa atividade foi criado um conjunto de casos de teste. Use-o para testar seu módulo em Python.
            #https://drive.google.com/file/d/1fjPhfXAIe3AoawVogPJEdW978-BubOvY/view?usp=sharing
            
    #H) As funções devem ser criadas dentro do arquivo self.py

    def dfs_generator(self, raizDFS):
        # Se o vertice ESTÁ na lista visitados, ele foi visitado. Senão, ele não foi visitado
        visitados = set()
        # NADA
        # DIRECIONADO
        # RETORNO
        arestas = dict([(nomeAresta, [self.A[nomeAresta], "NADA"]) for nomeAresta in self.A.keys()])
        pai = raizDFS

        arvoreDFS = Grafo(N=self.N)

        while(True):
            visitados.add(pai)
            arestasFilhas = self.arestas_sobre_vertice(pai)

            # Usaremos o vértice de maior grau como o nosso pai
            for filha in arestasFilhas:
                ## arestas[filha][1] != "DIRECIONADO"
                if(arestas[filha][1] != "RETORNO"):
                    destino = arestas[filha][0].replace(pai, "").replace("-","")
                    if(arestas[filha][1] == "NADA"):
                        if(not destino in visitados):
                            arestas[filha][1] = "DIRECIONADO"
                            #arvoreDFS.adicionaVertice(destino)
                            arvoreDFS.adicionaAresta(filha, arestas[filha][0])
                            pai = destino
                            break
                        else:
                            arestas[filha][1] = "RETORNO"
                            if(all([arestas[arestaFilhaCorr][1] == "RETORNO" for arestaFilhaCorr in arestasFilhas])):
                                pai = destino
                            break

                    else:
                        arestas[filha][1] = "RETORNO"
                        #pai = destino


                    # if self.grau(filhaCorrente) > maiorG:
                    #     maiorG = self.grau(filhaCorrente)
                    #     maiorFilha = filhaCorrente
                    #     maiorAresta = filha
            

            
            # if(arestas[maiorAresta][1] == "NADA"):
            #     if(not maiorFilha in visitados):
            #         arestas[maiorAresta][1] = "DIRECIONADO"
            #         arvoreDFS.adicionaVertice(maiorFilha)
            #         arvoreDFS.adicionaAresta(maiorAresta, arestas[maiorAresta])
            #         #isitados.add(pai)
            #         pai = maiorFilha
            #         arestas[maiorAresta][1] = "RETORNO"
      

            if(len(visitados) == len(self.N)):
                break

        #arvoreDFS = Grafo(N=self.N, A = {key: value[0] for (key, value) in arestas.items() if value[1]=="DIRECIONADO"})
        return arvoreDFS