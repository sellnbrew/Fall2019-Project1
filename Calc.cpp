#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

class Calcs{
  public:
    string line; // param name of the lines in file
    int countLines;
    string actualFileName;
    int lines;
    float mean;
    int numChar;
    int countChars;
    int sumVar; //final variance
    Calcs(); //constructors;
    ~Calcs(); //deconstructor
    //methods
    //accessors
    float getNumLines(){
      return countLines;
    }

    float getNumChar(){
      return countChars;
    }

    float getMean(float numChar, float lines){
      return numChar/lines;
    }
    void setFile(string file){
      actualFileName = file;
    }
    void setCalcs(){
      countLines = -1;
      countChars = 0;

      ifstream fileName(actualFileName);
        if(!fileName){
            cout<< "cannot open input file.\n";
            std::exit(0);
            //exit out of program if no file
        }
        while(fileName){
            getline(fileName,line);
            countChars += line.length();
            countLines++;
        }
    }

    float getVariance(int mean, int countLines)
    {
        float varSum = 0.0;
        int tempLength;
        string line1;
        int countDNA_str = 0;

        ifstream fileName(actualFileName);
        while(fileName){
            getline(fileName,line1);
            if(line1 == "")
              continue;  //SKIPS THE BLANK LINE
            tempLength = line1.length();
            varSum += (tempLength - mean) * (tempLength - mean);
        }
        return varSum/(countLines -1);
    }

    float getStanDeviation(float variance){
      return sqrt(variance);
    }

    float getTotal(){

        string line;
        string dnaSequence="";
        string letter;

        float counterA = 0;
        float counterG = 0;
        float counterT = 0;
        float counterC = 0;
        float total;

        ifstream fileName(actualFileName);
        while(fileName){
            getline(fileName,line);
            if(line == "")
              continue;
            dnaSequence+=line;
            //iterate throught the entire string
              for(int i = 0; i<line.length(); ++i)
              {
                letter = toupper(line[i]);
                if (letter == "A")
                  counterA++;
                else if (letter == "G")
                  counterG++;
                else if (letter == "T")
                  counterT++;
                else if (letter == "C")
                  counterC++;
                else
                  //if there's an error in the input
                  continue;
              }
        }
        total = counterA + counterC + counterG + counterT;
        return total;
        // , probC, probG, probT;
    }

    float getTypeAProbability(int total){

      float counterA = 0;
      string dnaSequence;
      string line;
      string letter;

      ifstream fileName(actualFileName);
      while(fileName){
          getline(fileName,line);
          if(line == "")
            continue;
          dnaSequence+=line;

          for(int i = 0; i<line.length(); ++i)
          {
            letter = toupper(line[i]);
            if (letter == "A")
              counterA++;
            else
              continue;
          }
      }

      return counterA/total;

  }

  float getTypeTProbability(int total){
    float counterT = 0;
    string dnaSequence;
    string line;
    string letter;

    ifstream fileName(actualFileName);
    while(fileName){
        getline(fileName,line);
        if(line == "")
          continue;
        dnaSequence+=line;

        for(int i = 0; i<line.length(); ++i)
        {
          letter = toupper(line[i]);
          if (letter == "T")
            counterT++;
          else
            continue;
        }
    }

    return counterT/total;

}

float getTypeGProbability(int total){
  float counterG = 0;
  string dnaSequence;
  string line;
  string letter;

  ifstream fileName(actualFileName);
  while(fileName){
      getline(fileName,line);
      if(line == "")
        continue;
      dnaSequence+=line;

      for(int i = 0; i<line.length(); ++i)
      {
        letter = toupper(line[i]);
        if (letter == "G")
          counterG++;
        else
          continue;
      }
  }

  return counterG/total;

}

float getTypeCProbability(int total){
  float counterC = 0;
  string dnaSequence;
  string line;
  string letter;

  ifstream fileName(actualFileName);
  while(fileName){
      getline(fileName,line);
      if(line == "")
        continue;
      dnaSequence+=line;

      for(int i = 0; i<line.length(); ++i)
      {
        letter = toupper(line[i]);
        if (letter == "C")
          counterC++;
        else
          continue;
      }
  }

  return counterC/total;

}



    string getBigramProbability(){
      //counters for each pair
        string dnaSeq;
        string bigram;
        string test;
        float pairAA = 0;
        float pairCA = 0;
        float pairTA = 0;
        float pairGA = 0;
        float pairAC = 0;
        float pairCC = 0;
        float pairTC = 0;
        float pairGC = 0;
        float pairAT = 0;
        float pairCT = 0;
        float pairTT = 0;
        float pairGT = 0;
        float pairAG = 0;
        float pairCG = 0;
        float pairTG = 0;
        float pairGG = 0;
        float totalPair = 0;

        ifstream fileName(actualFileName);
        while(fileName){
            getline(fileName,line);
            if(line == "")
              continue;
            dnaSeq+=line;
        }
        for(int i = 0;i<dnaSeq.length()-1; i++){
          //gets bigram by indexing (makes them)
          bigram = bigram + dnaSeq[i] + dnaSeq[i+1];
        }
        cout<<bigram<<"\n"<<endl;

        for(int i=0;i<bigram.length()-1;i++){
          //gets pairs of bigrams
          test =  test + bigram[i]+bigram[i+1];
          cout<<test<<endl;
          if(test == "AA"){
            pairAA++;
            totalPair++;
          }
          else if(test == "CA"){
            pairCA++;
            totalPair++;
          }
          else if(test == "TA"){
            pairTA++;
            totalPair++;
          }
          else if(test == "GA"){
            pairGA++;
            totalPair++;
          }
          else if(test == "AC"){
            pairAC++;
            totalPair++;
          }
          else if(test == "CC"){
            pairCC++;
            totalPair++;
          }
          else if(test == "TC"){
            pairTC++;
            totalPair++;
          }
          else if(test == "GC"){
            pairGC++;
            totalPair++;
          }
          else if(test == "AT"){
            pairAT++;
            totalPair++;
          }
          else if(test == "CT"){
            pairCT++;
            totalPair++;
          }
          else if(test == "TT"){
            pairTT++;
            totalPair++;
          }
          else if(test == "GT"){
            pairGT++;
            totalPair++;
          }
          else if(test == "AG"){
            pairAG++;
            totalPair++;
          }
          else if(test == "CG"){
            pairCG++;
            totalPair++;
          }
          else if(test == "TG"){
            pairTG++;
            totalPair++;
          }
          else if(test == "GG"){
            pairGG++;
            totalPair++;
          }
          test = "";
          i++;
        }
        //prints all pairs at once
        std::string probability =
        "prob pair AA: " + std::to_string(pairAA/totalPair)+"\n"
        "prob pair CA: " + std::to_string(pairCA/totalPair)+"\n"
        "prob pair TA: " + std::to_string(pairTA/totalPair)+"\n"
        "prob pair GA: " + std::to_string(pairGA/totalPair)+"\n"
        "prob pair AC: " + std::to_string(pairAC/totalPair)+"\n"
        "prob pair CC: " + std::to_string(pairCC/totalPair)+"\n"
        "prob pair TC: " + std::to_string(pairTC/totalPair)+"\n"
        "prob pair GC: " + std::to_string(pairGC/totalPair)+"\n"
        "prob pair AT: " + std::to_string(pairAT/totalPair)+"\n"
        "prob pair CT: " + std::to_string(pairCT/totalPair)+"\n"
        "prob pair TT: " + std::to_string(pairTT/totalPair)+"\n"
        "prob pair GT: " + std::to_string(pairGT/totalPair)+"\n"
        "prob pair AG: " + std::to_string(pairAG/totalPair)+"\n"
        "prob pair CG: " + std::to_string(pairCG/totalPair)+"\n"
        "prob pair TG: " + std::to_string(pairTG/totalPair)+"\n"
        "prob pair GG: " + std::to_string(pairGG/totalPair)+"\n";
        return probability;
      }

    string getGaussianDistribution(){
      //generates 1000 lines of DNA
      int total = getTotal();
      float variance = getVariance(mean,countLines);
      float probA = getTypeAProbability(total);
      float probC = getTypeCProbability(total);
      float probT = getTypeTProbability(total);
      float probG = getTypeGProbability(total);
      float meanNum = getMean(numChar, lines);
      float standDev = getStanDeviation(variance);
      string randDNA="";
      int count=0;
      float randomNum = rand();
      float randomNum2 = rand();
        while(count<1000){
          float randomNum = rand();
          float randomNum2 = rand();
          double a = (randomNum/(RAND_MAX));
          double b = (randomNum2/(RAND_MAX));

          float varC = (sqrt(-2*log(a)))*(cos(2*(M_PI)*b));
          float varD = standDev *varC + mean + 1;
          if(varD<0)
            varD*=-1;

          for(int i = 0; i < varD; ++i) {
             float size = float(rand())/RAND_MAX;
             // generating a random number lower than 100
            //This gives ranges of how often each nucleotide should be used, generating them at the same rate they appear in the original
            if(size <= probA) {
              randDNA+= "A";
            }
            else if(size <= (probA + probC)) {
              randDNA+= "C";
            }
            else if(size <= (probA + probC + probT)) {
              randDNA+= "T";
            }
            else {
              randDNA+= "G";
            }
        }
          randDNA+="\n";
          count++;
        }
        return randDNA;
  }
};
//default constuctor
Calcs::Calcs(){
}
Calcs::~Calcs(){
  std::cout<<"Closing"<<endl;
}
