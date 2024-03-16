#include <iostream>

// Define a node for the polynomial term
struct Term {
    int coefficient;
    int exponent;
    Term* next;

    // Constructor to initialize coefficient, exponent, and next pointer
    Term(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

// Define the Polynomial class
class Polynomial {
private:
    Term* head;

public:
    // Constructor to initialize the head pointer
    Polynomial() : head(nullptr) {}

    // Function to insert a term into the polynomial
    void insertTerm(int coeff, int exp) {
        Term* newTerm = new Term(coeff, exp);
        if (head == nullptr || exp > head->exponent) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Term* current = head;
            while (current->next != nullptr && exp < current->next->exponent) {
                current = current->next;
            }
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }

    // Function to add two polynomials
    Polynomial addPolynomials(Polynomial& poly2) {
        Polynomial result;
        Term* p1 = head;
        Term* p2 = poly2.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else if (p1->exponent < p2->exponent) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            } else {
                int sum = p1->coefficient + p2->coefficient;
                if (sum != 0)
                    result.insertTerm(sum, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        // Add remaining terms of polynomial 1
        while (p1 != nullptr) {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }

        // Add remaining terms of polynomial 2
        while (p2 != nullptr) {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }

    // Function to display the polynomial
    void display() {
        Term* current = head;
        while (current != nullptr) {
            std::cout << current->coefficient << "x^" << current->exponent;
            current = current->next;
            if (current != nullptr)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create first polynomial
    Polynomial poly1;
    poly1.insertTerm(3, 2); // 3x^2
    poly1.insertTerm(5, 1); // 5x^1
    poly1.insertTerm(2, 0); // 2x^0

    // Create second polynomial
    Polynomial poly2;
    poly2.insertTerm(4, 3); // 4x^3
    poly2.insertTerm(1, 1); // 1x^1
    poly2.insertTerm(6, 0); // 6x^0

    // Display the first polynomial
    std::cout << "First polynomial: ";
    poly1.display();

    // Display the second polynomial
    std::cout << "Second polynomial: ";
    poly2.display();

    // Add the two polynomials
    Polynomial result = poly1.addPolynomials(poly2);

    // Display the result
    std::cout << "Resultant polynomial: ";
    result.display();

    return 0;
}
