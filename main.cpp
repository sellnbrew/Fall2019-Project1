#include "Calc.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

// int countLines(string fileName);
int main(int argc , char **argv)
{
  ofstream out;
  out.open("BillyRoss.out");

  Calcs a;
  string mainFileName;
  cout<<"What is the name of the file you would like to run"<<endl;
  cin>>mainFileName;
  a.setFile(mainFileName);
  a.setCalcs();
  bool use = true;
  int input;
  while(use==true){
    cout<<"What would you like to do?"<<endl;
    cout<<"1) Get the sum"<<endl;
    cout<<"2) Get the mean"<<endl;
    cout<<"3) Get the variance"<<endl;
    cout<<"4) Get the standard deviation"<<endl;
    cout<<"5) Get the probability of each nucleotide"<<endl;
    cout<<"6) Get the probability of each bigram"<<endl;
    cout<<"7) Output and generate 1000 strings of DNA"<<endl;
    cout<<"8) Quit the program"<<endl;
    cin>>input;
    if(input == 1){
      cout<<a.getNumChar()<<endl;
    }
    else if(input == 2){
      cout<<a.getMean(a.getNumChar(),a.getNumLines())<<endl;
      out<<a.getMean(a.getNumChar(),a.getNumLines())<<endl;;

    }
    else if(input == 3){
      cout<<a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines())<<endl;
      out<<a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines());
    }
    else if(input == 4){
      cout<<a.getStanDeviation(a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines()))<<endl;
      cout<<a.getStanDeviation(a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines()));

    }
    else if(input == 5){
      cout<<a.getTypeAProbability(a.getTotal())<<endl;
      cout<<a.getTypeTProbability(a.getTotal())<<endl;
      cout<<a.getTypeCProbability(a.getTotal())<<endl;
      cout<<a.getTypeGProbability(a.getTotal())<<endl;
      out<<a.getTypeAProbability(a.getTotal());
      out<<a.getTypeTProbability(a.getTotal());
      out<<a.getTypeCProbability(a.getTotal());
      out<<a.getTypeGProbability(a.getTotal());
    }
    else if(input == 6){
      cout<<a.getBigramProbability()<<endl;
      out<<a.getBigramProbability();

    }
    else if(input == 7){
      cout<<a.getGaussianDistribution()<<endl;
      out<<a.getGaussianDistribution();

    }
    else if(input == 8){
      std::exit(0);
    }
  }
}
