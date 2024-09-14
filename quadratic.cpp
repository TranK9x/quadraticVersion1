
#include <cmath>      // provides 'sqrt' module
#include <iostream>
//#include <typeinfo>
//using namespace std;


void welcome();
void input_data(double &a, double &b, double &c);
void roots_calculation(double a, double b, double c,
    double &root1, double &root2, double discriminant);
void output_results(double a, double b, double c,
    double root1, double root2, double discriminant);
void calculation_discriminant(double a, double b, double c, double& discriminant);
void continue_exit();
void validate_input(double &a);



int main()
{
    /*double f;
    std::cin >> f;
    std::cout << typeid(f).name() << std::endl;*/
    double a, b, c;       // coefficients of Ax^2 + Bx + C = 0
    double root1, root2;  // roots of the equation
    double discriminant;  // (b*b) + (4*a*c)
    welcome();
    input_data(a, b, c);
    calculation_discriminant(a, b, c, discriminant);
    roots_calculation(a, b, c, root1, root2,discriminant);
    output_results(a, b, c, root1, root2, discriminant);
    continue_exit();
}

//
// An output module that displays information about the program.
//
void welcome()
{
    std::cout << "This program computes and displays the"  << std::endl;
    std::cout << "roots of a second-degree polynomial"     << std::endl;
    std::cout << "equation of the form Ax^2 + Bx + C = 0." << std::endl;
    std::cout                                              << std::endl;
    std::cout << "You will be prompted to input the three" << std::endl;
    std::cout << "coefficients A, B, and C."               << std::endl;
    std::cout                                              << std::endl;
    std::cout << "This program acts unpredictably when"    << std::endl;
    std::cout << "given coefficients that do not produce"  << std::endl;
    std::cout << "real-valued roots."                      << std::endl;
    std::cout                                              << std::endl;
}

//
// An input module that gets the coefficients of a second-degree polynomial
// in the form Ax^2 + Bx + C
//
void input_data(double &a, double &b, double &c)
{
    std::cout << "Enter coefficient 'A': ";
    std::cin >> a;
    validate_input(a);
    std::cout << "Enter coefficient 'B': ";
    std::cin >> b;
    validate_input(b);
    std::cout << "Enter coefficient 'C': ";
    std::cin >> c;
    validate_input(c);

}

//
// Roots calculation
//
void roots_calculation(double a, double b, double c,
    double &root1, double &root2, double discriminant)
{
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        }
    else if (discriminant ==0)
    {
        root1 = root2 = (-b) / (2 * a);
    }
    else { //if the discriminant < 0... there are no solutions, ask user wanna try ano the quadratic equation or not
        std::cout << "The equation "
            << a << "x^2 + "
            << b << "x + "
            << c << std::endl;
        std::cout << "Your quadratic equation dont have solution because discriminant is a negative number: "<<discriminant << std::endl;
        continue_exit();
    }
}
//
//this function will caculate the discriminant
//
void calculation_discriminant(double a, double b, double c, double &discriminant) {
    discriminant = (b * b) - (4 * a * c);
}

//
// An output module that displays the equation and its roots.
//
void output_results(double a, double b, double c,
    double root1, double root2, double discriminant)
{
    std::cout << std::endl;
    std::cout << "The discriminant is: " << discriminant << std::endl;
    if (root1 != root2) {
        std::cout << std::endl;
        std::cout << "The roots of the equation "
            << a << "x^2 + "
            << b << "x + "
            << c << std::endl;
        std::cout << "are (" << -b << " +-sqrt("<< discriminant<< "))/"<< 2*a << " = " << root1 << " and " << root2 << std::endl;
       }
    else { // if root1 = root2
        std::cout << std::endl;
        std::cout << "The root of the equation "
            << a << "x^2 + "
            << b << "x + "
            << c << std::endl;
        std::cout << "is: " << root1 << std::endl;
    }
    
}
//
// continue or exit after giving user the result.
//
void continue_exit() {
    int num;
    std::cout << "Do you want to try another quadratic equation?" << std::endl;
    std::cout << "Enter 1 / YES" << std::endl;
    std::cout << "Anything else / NO" << std::endl;
    std::cin >> num;
    if (num == 1) {
        std::cout<< std::endl << std::endl;
        main(); // run the program again if the user enter 1
    }
    else {
        exit(0); // exit the program
    }
}

//
//this module use to validate inputs
//
void validate_input(double &a) {
    while (true) {
        //check if input operation failed
        if (std::cin.fail()) { //if fail
            std::cin.clear();// Clear the error flags on the input stream.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // leave the rest of the line or clear buffer line
            std::cout << "Please enter a number: "; //ask user enter new value
            std::cin >> a;
        }
        else {
            break;
        }
    }
}
