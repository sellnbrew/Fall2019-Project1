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
      usleep(1000000);
    }
    else if(input == 2){
      cout<<a.getMean(a.getNumChar(),a.getNumLines())<<endl;
      out<<a.getMean(a.getNumChar(),a.getNumLines())<<endl;;

    }
    else if(input == 3){
      cout<<a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines())<<endl;
    }
    else if(input == 4){
      cout<<a.getStanDeviation(a.getVariance(a.getMean(a.getNumChar(),a.getNumLines()),a.getNumLines()))<<endl;
    }
    else if(input == 5){
      cout<<a.getTypeAProbability(a.getTotal())<<endl;
      cout<<a.getTypeTProbability(a.getTotal())<<endl;
      cout<<a.getTypeCProbability(a.getTotal())<<endl;
      cout<<a.getTypeGProbability(a.getTotal())<<endl;
    }
    else if(input == 6){
      cout<<a.getBigramProbability()<<endl;
    }
    else if(input == 7){
      cout<<a.getGaussianDistribution()<<endl;
    }
    else if(input == 8){
      std::exit(0);
    }
  }


  // std::string fileName = "hew.txt";
	// ofstream out;
	// out.open("GabbyPinto.out");
  //
	// //	std::string name = fileName;
	// 	std::ifstream infile(fileName.c_str());
	// 	string sequence="";
	// 	if(infile.fail()){
	// 		cout << "Your file didn't work" << endl;
	// 	}

		//reading each line from the file
		// else{
		// 	string line;
    //   //writing to file
		// 	while(infile>>line){
		// 		sequence+=line+" ";
    //     //cout<<line;
    //     //out<<line;
		// 	}
		// }

    //correct
      // cout<<"Mean: "<<a.getMean(a.getNumChar(),a.getNumLines()) << "\n" << endl;
      // cout<<"Variance: "<<a.getVariance(a.getMean(a.getNumChar(), a.getNumLines()), a.getNumLines()) << "\n" << endl;
      // cout<<"Standard Deviation: "<< a.getStanDeviation(a.getVariance(a.getMean(a.getNumChar(), a.getNumLines()), a.getNumLines()))<< "\n"<<endl;
       // cout<<"print from prob: "<<a.getTypeAProbability(a.getTotal())<<endl;
       // cout<<"print from prob: "<<a.getTypeTProbability(a.getTotal())<<endl;
       // cout<<"print from prob: "<<a.getTypeGProbability(a.getTotal())<<endl;
       // cout<<"print from prob: "<<a.getTypeCProbability(a.getTotal())<<endl;



      // cout<<"\n"<<a.getBigramProbability()<<"\n"<<endl;
      //  cout<<"\n"<<a.getGaussianDistribution()<<"\n"<<endl;
}






















// if(arg>1){
//
//   ifstream hewwo("hew.txt");
//     if(!hewwo){
//         cout<< "cannot open input file.\n";
//         return 1;
//     }
//
//     char str[255]; //what does this mean?
//     while(hewwo){
//         hewwo.getline(str, 255);
//         if(hewwo) cout<<str<<endl;
//     }
//     hewwo.close();
//
//     cout<<"sum of lines is: "<< p.addLines(hewwo) <endl;
//     return 0;
//     }
//
// else{
//   return 1;
// }
