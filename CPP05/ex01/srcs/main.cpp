#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  {
    std::cout << "\n--> My tests <--" << std::endl;
    try {
      Bureaucrat a("Bred", 30);
      Form b("Bred's Check", 50, a.getGrade());
      b.beSigned(a);
      a.signForm(b);

      std::cout << b << std::endl;

      a.decrementGrade();
      std::cout << a << std::endl;

      a.incrementGrade();

      std::cout << a << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  {
    try {
      Bureaucrat a("Marcelo", 6);
      Form b("Sale Form", 5, 150);
	  Form c("Sale Form 2", 5, 150);
      try {
		std::cout << std::endl;
        std::cout << "--> Increment test <--" << std::endl;
        std::cout << "--> Start Form with Bureaucrat: <--" << std::endl;
        std::cout << a << std::endl;
		std::cout << b << std::endl;
        std::cout << "--> Increment grade of Bureaucrat: <--" << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        std::cout << "--> Sign Form: <--" << std::endl;
        a.signForm(b);
        std::cout << b << std::endl;
        std::cout << "--> End increment test <--" << std::endl;
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      try {
		std::cout << std::endl;
        std::cout << "--> Decrement test <--" << std::endl;
		std::cout << a << std::endl;
        std::cout << c << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        a.signForm(c);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      std::cout << a << std::endl;
	  std::cout << c << std::endl;
      std::cout << "--> End decrement test <--" << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}