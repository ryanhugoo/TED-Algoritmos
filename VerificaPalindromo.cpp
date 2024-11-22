#include <iostream>
#include <stack> // Utilizada para implementação da pilha
#include <string> // Utilizada para manipulação de strings de forma mais segura e prática
#include <cctype> // Utilizada para manipulação de caracteres através de funções

using namespace std;

bool verificarPalindromo(const string& texto) {
    stack<char> pilha;
    string textoLimpo;

    // Faz uma limpeza no texto, mantendo apenas letras e colocando todas em minúsculo
    for (char c : texto) {
        if (isalpha(c)) {
            textoLimpo += tolower(c);
        }
    }

    // Verifica se o texto limpo está vazio (caso de entrada inválida)
    if (textoLimpo.empty()) {
        throw invalid_argument("Entrada inválida: por favor, insira pelo menos uma letra.");
    }

    // Empilhando a primeira metade do texto
    int tamanho = textoLimpo.size();
    for (int i = 0; i < tamanho / 2; i++) {
        pilha.push(textoLimpo[i]);
    }

    // Determinando o ponto de início da comparação
    int pontoDeInicioComparacao = (tamanho % 2 == 0) ? tamanho / 2 : tamanho / 2 + 1;

    // Comparando a segunda metade do texto com os valores da pilha
    for (int i = pontoDeInicioComparacao; i < tamanho; i++) {
        if (pilha.top() != textoLimpo[i]) {
            // Retorna false em caso de caractere diferente e encerra a verificação
            return false;
        }
        pilha.pop(); // Retira o valor do topo para comparar com o próximo valor de textoLimpo
    }

    return true;
}

int main() {
    string texto;

    for (int i = 0; i < 5; i++) {
        cout << "Insira uma palavra ou frase: " << endl;
        getline(cin, texto);

        try {
            if (verificarPalindromo(texto)) {
                cout << "<<<<<<<<<< É UM PALÍNDROMO! :D >>>>>>>>>>" << endl;
            } else {
                cout << "<<<<<<<<<< NÃO É UM PALÍNDROMO! :( >>>>>>>>>>" << endl;
            }
        } catch (const invalid_argument& error) {
            // Exibe a mensagem de erro e pede nova entrada
            cout << error.what() << endl;
        }
    }

    return 0;
}
