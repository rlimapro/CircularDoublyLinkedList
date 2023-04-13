#include "List.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/**
 * @author Rian Lima
 * @date 22/01/2022
 *
 * Observação:
 * A primeira lista criada é numerada como lista 0 
 */

// Para executar via terminal (cmd):
// g++ *.cpp -o main && .\main


// Lista de comandos e seus significados:
//    [Comando]    |    [Significado]
// create          | cria um lista vazia
// exit            | sair do programa
// show            | imprime na tela todas as listas
// empty n         | retorna se a lista n está vazia ou não
// size n          | retorna o número de elementos da lista n
// clear n         | esvazia a lista n
// pushFront x n   | adiciona o elemento x no inicio da lista n
// pushBack x n    | adiciona o elemento x no final da lista n
// front n         | retorna o primeiro elemento da lista n
// back n          | retorna o último elemento da lista n
// popFront n      | remove o primeiro elemento da lista n
// popBack n       | remove o último elemento da lista n
// insertAt x y n  | insere o elemento x no índice y da lista n
// removeAt x n    | remove o elemento do índice x da lista n
// removeAll x n   | remove todos as ocorrências de x da lista n
// swap x y        | troca os elementos da lista x com a y
// concat x y      | concatena a lista y ao final da lista x
// copy n          | cria uma cópia da lista n 
// append n a1..an | adiciona os elementos a1,..., an ao final da lista n
// equals x y      | retorna se as listas x e y são iguais ou não
// reverse n       | Inverte a ordem dos elementos da lista n
// merge x y       | intercala os elementos da lista x e y em x


int main()
{   
    vector<List*> lists;

	for(; ;)
	{
		try
        {
            string command;
            getline(cin, command);
            std::stringstream ss{ command };
            vector<string> tokens;
            string buffer;

            cout << "$" << ss.str() << "\n";

            while(ss >> buffer) 
                tokens.push_back(buffer);

            // create
            if(tokens[0] == "create") 
            {
                List *list = new List;
                lists.push_back(list);
            }
            // exit
            else if(tokens[0] == "exit") {
                for(unsigned i = 0; i < lists.size(); i++)
                    delete lists[i];
                lists.clear();
                break;
            }
            // empty l
            else if(tokens[0] == "empty")
            {
                int l = std::stoi(tokens[1]); 
                if(l >= lists.size())
                {
                    cout << "Non-existent list!\n";
                }
                else
                {
                    if(lists[l]->empty()) { cout << "Empty list\n"; }
                    
                    else { cout << "List is not empty\n"; }
                }
            }
            // size l
            else if(tokens[0] == "size")
            {
                int l = std::stoi(tokens[1]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { cout << lists[l]->size() << " Elements\n"; }
            }
            // clear l
            else if(tokens[0] == "clear")
            {
                int l = std::stoi(tokens[1]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->clear(); }
            }
            // pushFront x l
            else if(tokens[0] == "pushFront") {
                int x = std::stoi(tokens[1]); 
                int l = std::stoi(tokens[2]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->push_front(x); }
            }
            // pushBack x l
            else if(tokens[0] == "pushBack") {
                int x = std::stoi(tokens[1]);
                int l = std::stoi(tokens[2]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->push_back(x); }
            }
            // popFront l
            else if(tokens[0] == "popFront")
            {
                int l = std::stoi(tokens[1]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->pop_front(); }
            }
            // popBack l
            else if(tokens[0] == "popBack")
            {
                int l = std::stoi(tokens[1]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->pop_back(); }
            }
            // front l
            else if(tokens[0] == "front")
            {
                int l = std::stoi(tokens[1]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { cout << lists[l]->front() << "\n"; }
            }
            // back l
            else if(tokens[0] == "back")
            {
                int l = std::stoi(tokens[1]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { cout << lists[l]->back() << "\n"; }
            }
            // insertAt x y l
            else if(tokens[0] == "insertAt") {
                int x = std::stoi(tokens[1]); 
                int y = std::stoi(tokens[2]);  
                int l = std::stoi(tokens[3]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->insertAt(x, y); }
            }
            // removeAt x l
            else if(tokens[0] == "removeAt") {
                int x = std::stoi(tokens[1]); 
                int l = std::stoi(tokens[2]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->removeAt(x); }
            }
            // removeAll x l
            else if(tokens[0] == "removeAll") {
                int x = std::stoi(tokens[1]); 
                int l = std::stoi(tokens[2]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->removeAll(x); }
            }
            // swap l1 l2
            else if(tokens[0] == "swap") {
                int l1 = std::stoi(tokens[1]); 
                int l2 = std::stoi(tokens[2]);
                if(l1 >= lists.size() || l2 >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l1]->swap(*lists[l2]); }
            }
            // concat l1 l2
            else if(tokens[0] == "concat") {
                int l1 = std::stoi(tokens[1]); 
                int l2 = std::stoi(tokens[2]); 
                if(l1 >= lists.size() || l2 >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l1]->concat(*lists[l2]); }
            }
            // copy l
            else if(tokens[0] == "copy")
            {
                int l = std::stoi(tokens[1]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else
                {
                    List *list = new List;
                    list = lists[l]->copy();
                    lists.push_back(list);
                }
            }
            // append l a1 ... an
            else if(tokens[0] == "append")
            {
                int l = std::stoi(tokens[1]); 
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else
                {
                    int n = tokens.size()-2; 
                    int *v = new int[n];
                    for(int i = 0; i < n; i++)
                    {
                        v[i] = std::stoi(tokens[i+2]);
                    }
                    lists[l]->append(v, n);
                }
            }
            // equals l1 l2
            else if(tokens[0] == "equals")
            {
                int l1 = std::stoi(tokens[1]);
                int l2 = std::stoi(tokens[2]); 
                if(l1 >= lists.size() || l2 >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else
                {
                    if(lists[l1]->equals(*lists[l2]))
                    {
                        cout << "Equal lists\n";
                    }
                    else { cout << "Different lists\n"; }
                }
            }
            // reverse l
            else if(tokens[0] == "reverse")
            {
                int l = std::stoi(tokens[1]);
                if(l >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l]->reverse(); }
            }
            // merge l1 l2
            else if(tokens[0] == "merge")
            {
                int l1 = std::stoi(tokens[1]); 
                int l2 = std::stoi(tokens[2]); 
                if(l1 >= lists.size() || l2 >= lists.size())
                {
                    std::cerr << "Non-existent list!\n";
                }
                else { lists[l1]->merge(*lists[l2]); }
            }
            // show
            else if(tokens[0] == "show") 
            {
                if(lists.size() == 0) { std::cerr << "No lists\n"; }
                
                else
                {
                    for(unsigned i = 0; i < lists.size(); ++i) 
                    {
                        cout << "List " << i << ": " << *lists[i];
                    } 
                }
            }
            else { cout << "Invalid command!" << "\n"; }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
	}
	return 0;
}
