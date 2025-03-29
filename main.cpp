#include <iostream>
#include <fstream>
#include <iomanip>

double maps_Points(double x) {
	return 0.75 * x - 1.75;
}

int main() {
   std:: ifstream input("data.txt");
   std:: ofstream output("result.txt");
    
    if (input.fail()) {
        std::cerr << "File not found" << std::endl;
        return 1;
    }
    
    double value = 0.0;
	double sum = 0.0;
	double average = 0.0;
    unsigned int count = 0;
	
    output << "# N Mean" << std::endl;
    
    while (input >> value) {
        double map = maps_Points(value);
        sum += map;
        count++;
		average = sum/count;
        output << count << " " << std::setprecision(16) << std::scientific << average << std::endl;
    }
    
    input.close();
    output.close();
    
    std::cout << "Results saved successfully in result.txt" << std::endl;
    return 0;
}

