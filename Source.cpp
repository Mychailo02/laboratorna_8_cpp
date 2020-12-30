
#include <iostream>


void fill_matrix_random(int* , int , int , int );
void find_max_element_in_row(int* , int , int& , int& );
void print_matrix(int* , int );
void print_vector(int* , int );
void initvec(int* , int );

int main() {

    setlocale(LC_ALL, "Russian");

   
    const int n = 5;
    int matrix[n][n];
    fill_matrix_random(*matrix, n, 1, 10);
    print_matrix(*matrix, n);
    int vec[n];
    initvec(vec, n);

    // проходимся циклом по строкам матрицы
    for (int i = 0; i < n; i++) {
        
        int max{ 0 }, idx{ 0 };
        find_max_element_in_row(matrix[i], n, max, idx);

        std::cout << "Максимальний елемент " << i << "-го рядка = " << max << " с iндексом " << idx << std::endl;

        for (int j = 0; j < n; j++) {
         
            vec[i] += matrix[i][j] * matrix[j][idx];
        }

        std::cout << "Скалярний добуток " << i << "-го рядка та " << idx << "-го стовпця = " << vec[i] << std::endl;
    }

   
    print_vector(vec, n);


}

void fill_matrix_random(int* m, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i * n + j] = a + rand() % (a - b); 
        }
    }
}

void find_max_element_in_row(int* row, int n, int& val, int& idx) {
    val = row[0];
    idx = 0;

    for (int i = 0; i < n; i++) {
        if (row[i] > val) {
            val = row[i];
            idx = i;
        }
    }
}

void print_matrix(int* m, int n) {
    std::cout << "Матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << m[i * n + j] << " ";
        }
        std::cout << "\n";
    }
}

void print_vector(int* v, int n) {
    std::cout << "Вектор:\n";
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
    std:: cout << "\n";
}
void initvec(int* v, int num)
{
    for (int i = 0; i < num; i++) {
        v[i] = 0;
    }
}