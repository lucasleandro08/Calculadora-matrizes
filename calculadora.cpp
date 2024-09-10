#include <iostream>
#include <vector>

using namespace std;

// Função para exibir uma matriz
void exibirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& linha : matriz) {//const: Indica que a função não modificará a matriz fornecida.// &: Passa a matriz por referência para evitar a cópia, o que melhora a eficiência, especialmente para grandes matrizes.
        for (int elemento : linha) {
            cout << elemento << " ";//exibe os elementos da matriz
        }
        cout << endl;//quebra de linha
    }
}

// Função para adicionar duas matrizes
vector<vector<int>> adicionarMatrizes(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int linhas = A.size();
    int colunas = A[0].size();
    vector<vector<int>> resultado(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }

    return resultado;
}

// Função para subtrair duas matrizes
vector<vector<int>> subtrairMatrizes(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int linhas = A.size();
    int colunas = A[0].size();
    vector<vector<int>> resultado(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }

    return resultado;
}

// Função para multiplicar duas matrizes
vector<vector<int>> multiplicarMatrizes(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int linhasA = A.size();
    int colunasA = A[0].size();
    int colunasB = B[0].size();
    vector<vector<int>> resultado(linhasA, vector<int>(colunasB));

    for (int i = 0; i < linhasA; ++i) {
        for (int j = 0; j < colunasB; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunasA; ++k) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}

int main() {
    int linhas, colunas;
    cout << "Digite o número de linhas e colunas das matrizes: ";
    cin >> linhas >> colunas;

    vector<vector<int>> A(linhas, vector<int>(colunas));
    vector<vector<int>> B(linhas, vector<int>(colunas));

    cout << "Digite os elementos da matriz A:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Digite os elementos da matriz B:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> B[i][j];
        }
    }

    cout << "Matriz A:" << endl;
    exibirMatriz(A);
    cout << "Matriz B:" << endl;
    exibirMatriz(B);

    cout << "A + B:" << endl;
    exibirMatriz(adicionarMatrizes(A, B));

    cout << "A - B:" << endl;
    exibirMatriz(subtrairMatrizes(A, B));

    if (A[0].size() == B.size()) {
        cout << "A * B:" << endl;
        exibirMatriz(multiplicarMatrizes(A, B));
    } else {
        cout << "A multiplicação não é possível devido às dimensões incompatíveis." << endl;
    }

    return 0;
}
