#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Для setw() та setfill()
#include <cstdlib> // Для system()
#include <locale>  // Для setlocale()

using namespace std;

/**
 * @brief Обчислює та виводить декартовий добуток D = C x A x B
 * у чіткому табличному форматі.
 */
void calculate_cartesian_product_formatted() {
    // Input Sets
    const vector<string> A = { "a", "b", "c" };
    const vector<string> B = { "x", "y", "z" };
    const vector<string> C = { "0", "1" };

    const int total_elements = C.size() * A.size() * B.size();

    // 1. Header
    cout << "\n==============================================\n";
    cout << "  CARTESIAN PRODUCT D = C x A x B (Size: " << total_elements << ")\n";
    cout << "==============================================\n";

    // 2. Column Headers
    cout << " " << left << setw(5) << "N" << " | "
        << left << setw(20) << "ELEMENT (C, A, B)" << "\n";

    // Separator line
    cout << setfill('-') << setw(30) << "" << setfill(' ') << "\n";

    int j = 1; // Start numbering from 1

    // 3. Calculation and Output (Nested loops for C x A x B)
    for (int ic = 0; ic < C.size(); ++ic) {
        for (int ia = 0; ia < A.size(); ++ia) {
            for (int ib = 0; ib < B.size(); ++ib) {

                // Form the ordered triplet
                string element_tuple = "(" + C[ic] + ", " + A[ia] + ", " + B[ib] + ")";

                // Output the result in table format: N | (C, A, B)
                cout << right << setw(3) << j << " | "
                    << left << setw(20) << element_tuple << "\n";

                j++; // Increment index
            }
        }
    }

    // 4. Footer
    cout << "==============================================\n";
}

int main() {
    // Set up for correct display in the console (e.g., Windows)
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "C"); // Set locale to 'C' for standard output

    calculate_cartesian_product_formatted();

    return 0;
}