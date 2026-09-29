#include <iostream>
#include <string>
#include <iomanip> // Usado para formatar as casas decimais na tabela

using namespace std;

// REQUISITO TÉCNICO: Função para calcular a média de 3 notas
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

// Estrutura para organizar os dados de um aluno
struct Aluno {
    string nome;
    float notas[3]; // Vetor para guardar as 3 notas
    float media;
    string situacao;
};

int main() {
    // REQUISITO TÉCNICO: Vetor para armazenar dados de até 5 alunos
    Aluno turma[5];

    cout << "=== CADASTRO DE ALUNOS ===" << endl << endl;

    // REQUISITO TÉCNICO: Estrutura de repetição (for) para entrada de dados
    for (int i = 0; i < 5; i++) {
        cout << "Digite o nome do aluno " << (i + 1) << ": ";
        cin >> turma[i].nome;

        cout << "Digite as 3 notas de " << turma[i].nome << ":" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "  Nota " << (j + 1) << ": ";
            cin >> turma[i].notas[j];
        }

        // Utilizando a função para calcular a média
        turma[i].media = calcularMedia(turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);

        // REQUISITO TÉCNICO: Estrutura condicional (if/else) para situação
        if (turma[i].media >= 7.0) {
            turma[i].situacao = "Aprovado";
        } else {
            turma[i].situacao = "Reprovado";
        }

        cout << "-----------------------------------" << endl;
    }

    // Exibição dos resultados em formato de tabela
    cout << endl << "=== TABELA DE RESULTADOS ===" << endl;
    cout << fixed << setprecision(1); // Configura para exibir 1 casa decimal (ex: 8.5)

    cout << "---------------------------------------------------------" << endl;
    cout << "Nome\t\tNota 1\tNota 2\tNota 3\tMédia\tSituação" << endl;
    cout << "---------------------------------------------------------" << endl;

    int indiceMaiorMedia = 0;

    // REQUISITO TÉCNICO: Estrutura de repetição (for) para exibição e busca da maior média
    for (int i = 0; i < 5; i++) {
        cout << turma[i].nome << "\t\t"
             << turma[i].notas[0] << "\t"
             << turma[i].notas[1] << "\t"
             << turma[i].notas[2] << "\t"
             << turma[i].media << "\t"
             << turma[i].situacao << endl;

        // Lógica para descobrir qual aluno teve a maior média
        if (turma[i].media > turma[indiceMaiorMedia].media) {
            indiceMaiorMedia = i;
        }
    }

    cout << "---------------------------------------------------------" << endl;

    // Informa o aluno com a maior média da turma
    cout << endl << "Destaque da Turma:" << endl;
    cout << "O aluno com a maior media foi " << turma[indiceMaiorMedia].nome 
         << " com a media " << turma[indiceMaiorMedia].media << "!" << endl;

    return 0;
}                                                            
