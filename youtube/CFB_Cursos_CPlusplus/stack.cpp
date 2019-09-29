#include <iostream>
#include <stack>

int main()
{

  std::stack <std::string> cartas;

  cartas.push("Rei de Copas");
  cartas.push("Rei de Espadas");
  cartas.push("Rei de Ouros");
  cartas.push("Rei de Paus");

  std::cout << "Tamanho pilha: " << cartas.size() << std::endl;

  std::cout << "Carta topo: " << cartas.top() << std::endl;

  cartas.pop();

  std::cout << "Carta topo: " << cartas.top() << std::endl;


  return 0;
}
