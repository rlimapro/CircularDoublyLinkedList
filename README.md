# Circular Doubly Linked List with Sentinel node

## Descrição
A estrutura de dados desenvolvida é uma lista duplamente encadeada, mais
especificamente, uma lista circular duplamente encadeada. Para este projeto, foi
requisitado que houvesse um nó sentinela para demarcar o início e o fim da lista. A
imagem abaixo representa a estrutura de dados descrita.

![Captura de tela de 2023-04-13 20-21-03](https://user-images.githubusercontent.com/107145885/231903387-7b5caca1-9df3-446b-bebe-a1fb875ac322.png)

## Operações 
Comando   | Significado
--------- | ------
create          | cria um lista vazia
exit            | sair do programa
show            | imprime na tela todas as listas
empty _n_       | retorna se a lista _n_ está vazia ou não
size _n_        | retorna o número de elementos da lista _n_
clear _n_       | esvazia a lista _n_
pushFront _x_ _n_ | adiciona o elemento _x_ no inicio da lista _n_
pushBack _x_ _n_  | adiciona o elemento _x_ no final da lista _n_
front _n_       | retorna o primeiro elemento da lista _n_
back _n_        | retorna o último elemento da lista _n_
popFront _n_    | remove o primeiro elemento da lista _n_
popBack _n_     | remove o último elemento da lista _n_
insertAt _x_ _y_ _n_| insere o elemento _x_ no índice y da lista _n_
removeAt _x_ _n_  | remove o elemento do índice _x_ da lista _n_
removeAll _x_ _n_ | remove todos as ocorrências de _x_ da lista _n_
swap _x_ _y_        | troca os elementos da lista _x_ com a _y_
concat _x_ _y_      | concatena a lista y ao final da lista _x_
copy _n_          | cria uma cópia da lista _n_
append _n_ _a1_.._an_ | adiciona os elementos a1,..., an ao final da lista _n_
equals _x_ _y_      | retorna se as listas _x_ e _y_ são iguais ou não
reverse _n_       | Inverte a ordem dos elementos da lista _n_
merge _x_ _y_       | intercala os elementos da lista _x_ e _y_ em _x_


## Referências 
* [GeekForGeeks](https://www.geeksforgeeks.org/insertion-in-doubly-circular-linked-list/)
* [Doubly Linked List - by Brad Vander Zanden](http://web.eecs.utk.edu/~bvanderz/teaching/cs140Fa10/notes/Dllists/)
