#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <sstream>

using namespace std;

string eraseNum(string source){
   for(int i=0;i<source.length();i++){
      if(!(((source[i]>='A'&&source[i]<='Z')||(source[i]>='a'&&source[i]<='z'))||(source[i] == ' '))){
         source.erase(i,1);
            i--;
      }  
   }
   return source;
}

int countSubstring(const string& str, const string& sub){
   if (sub.length() == 0) return 0;
      int count = 0;
      for (int offset = str.find(sub); offset != string::npos; offset = str.find(sub, offset + sub.length())){
         ++count;
      }
   return count;
}

double countWords(string source){
  string newsource = eraseNum(source);
  double words = 0;	
	for(int i = 0; i < newsource.length(); i++){
		if(newsource.at(i) == ' '){
			words++;
		} 		
	}
 	return words;
}

double countSents(string source){
double sents = 0;	
	for(int i = 0; i < source.length(); i++){
		if(source.at(i) == '.'){
			sents++;
		} 		
	}
	return sents;
}

double getAvg(string source){
   double avg = countWords(source) / countSents(source);
   return avg;
}

int countUnique(string source){
   string newsource = eraseNum(source);
   int z = newsource.length();
   string arr[z];
   int i = 0;
   stringstream ssin(newsource);
   while (ssin.good() && i < z){
      ssin >> arr[i];
      i++;
   }
   for(i = 0; i < z; i++){
      for(int j = i + 1; j < z; j++){
         if(arr[i] == arr[j]){
            arr[j] = "0";
         }
      }
   }
   int count = z;
   for(int k = 0; k < z; k++){
      if(arr[k] == "0"){
         count--;
      }
   }
   return count;
}

int main()
{
string source = "I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo. I got the ramblin fever. Said goodbye to ma and pa. Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky. I saw miles and miles of Texas gonna live here till I die.";
cout << "Substring count: " << countSubstring(source, "is") << '\n';
cout << "Word count: " << countWords(source) << "\n";
cout << "Unique words count: " << countUnique(source) << "\n";
cout << "Sentence count: " << countSents(source) << "\n";
cout << "Average number of words per sentence: " << getAvg(source) << "\n";
double lex = (countUnique(source) / countWords(source)) * 100;
cout << "Lexical Density: " << lex;
return 0;
}
