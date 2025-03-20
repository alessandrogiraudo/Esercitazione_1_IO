#include <fstream>
#include <iostream>
#include <iomanip>

double slice(double x)
{
    return -1 + (x -1) * (3.0/4.0);
}


int main()
{
    std::ifstream file("data.txt");
    if(file.fail())
{
    std::cerr << "errore nell'apertura del file" << std::endl;
    return 1; 
}
    
   /* 
    std::string tmp;
    while (std::getline(file, tmp)){}

    std::cout << tmp << std::endl;
    */

    std::ofstream fout("result.txt", std::ios::app);

    double val=0.0;
    double sum=0.0;
    double lineCount = 1.0;
    double mean=0.0;
    std::string line;
    std::cout << "# N MEAN" << std::endl;
    fout << "# N MEAN" << std::endl;
    while (file >> val) // Legge il file riga per riga 
    {     
    sum = sum + slice(val);
    mean = sum / lineCount;
    std::cout << int(lineCount) << " " << std::setprecision(16) << std::scientific << mean << std::endl;
    fout << int(lineCount) << " " << std::setprecision(16) << std::scientific <<mean << std::endl;
    ++lineCount;

}
    fout.close();    

    return 0;
}
