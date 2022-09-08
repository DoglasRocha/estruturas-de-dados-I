# Lista de Clientes

* Neste trabalho, desenvolvi duas listas capazes de guardar Nome e RG de clientes.

* Uma lista é duplamente encadeada e a outra é sequencial

* É necessário ter o compilador GCC para compilar este programa

* Para compilar o programa, simplesmente navegue para o diretório ```lists``` e digite, em seu terminal :

  ```sh	
  make main
  ```

* E para rodar o programa:

  ```sh
  ./main
  ```

* Para eliminar o binário, rode em seu terminal:

  ```sh
  make clean
  ```

* Requisitos do trabalho:

  * Faça um programa que use as duas formas de armazenar os dados em paralelo e mostre a diferença de tempo entre cada ação realizada nas duas listas.

    1. Lista sequencial
    2. Lista encadeada

  * Cada dado consiste dos campos de **nome** e **RG**.

    1. O usuario pode ficar escolhendo entre as funções:

       1. Inserção de um nó no início da lista **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
       2. Inserção de um nó no fim da lista **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
       3. Inserção de um nó na posição N **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
       4. Retirar um nó do início da lista **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista..
       5. Retirar um nó no fim da lista **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
       6. Retirar um nó na posição N **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
       7. **Procurar** um nó com o campo RG **e apresentar** Nome, RG, C(n), M(n), Tempo de execução e sua posição N na lista.
          1. Usando busca sequencial.
       8. **Mostrar** a lista na tela.
       9. Salvar a lista em um arquivo.
          1. no formato **nome,RG**
       10. Ler a lista de um arquivo.
           1. no formato **nome,RG**
           2. (colocar na lista)
       11. Sair do sistema.

       

       

       1. Cada trabalho deve usar os arquivos prontos com 10, 100, 1K, 1M e 100M nomes e RG cadastrados.
          1. Estes arquivos são somente para comparar a diferença de custo entre as listas.
          2. [Arquivos com Nome e RG para o trabalho](https://pessoal.dainf.ct.utfpr.edu.br/maurofonseca/lib/exe/fetch.php?media=cursos:if63c:arquivocomprimidonomerg.zip)
          3. A avaliação será feita usando estes arquivos de dados.

       1. Cada vez que for escolhida uma função **será apresentada além da função pedida nas duas listas** a comparação entre os dois custos para cada uma das listas:
          1. Número de comparações **C(n)** entre chaves.
             1. **número de nós comparados(numeros de IF executados) para executar a função.**
          2. \- Número de movimentações **M(n)** de itens.
             1. **número de copias realizadas para executar a função. (x=y)**