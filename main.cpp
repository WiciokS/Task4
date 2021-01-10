#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string test=" ";

string typedetection(string a)
{
int digit=0, floa=0, alpha=0, date=0, unknown=0;
for(int i=0; i<a.size(); i++)// scan type
{
if(isdigit(a[i])) digit++;
if(a.find('.') != string::npos) floa++;
if(isalpha(a[i])) alpha++;
if(a.find('/') != string::npos) date++;
if(test==a) unknown++;
}
test=a;
//output type
if(date>0) return "date ";
else if(digit>0 && floa>0) return "float ";
else if(((digit>0 || digit==0) && (alpha>0 || alpha==0)) && a.size()==1)
{
  if(digit>0) return "int||char ";
  return "char ";
}
else if(digit>0 && alpha==0) return "int ";
else if(unknown>0) return "unknown ";
else if((digit>0 || digit==0) && alpha>0) return "string ";
else return "ERROR!!!";

}
int main() 
{
  cout << "How many lines (MAX 91858)?" << endl;
  int size;
  cin >> size;//choosing size
  if(size>91858 || size<1)//check
  {
    cout << "Sorry I do not understand"<<endl;
    return 0;
  }
  //zmienne
  vector<string> info;
  string a, line;
  info.reserve(91858);
	ifstream justfile;
  justfile.open("CRISP_PRJ_C_FY2009.CSV");
	for(int m=0;m<size;m++)// replacement
  {
    for(int n=0;n<=21;n++)
    {
		  getline(justfile, line, ',');
		  istringstream ss(line);
		  ss >> a;
      info.push_back(typedetection(a)); 
    }
  }
	justfile.close();
  info.shrink_to_fit();
  ofstream Output;//output to file output.txt
  Output.open("output.txt");
  int x=0;
  for(int m=0;m<size;m++)
  {
    for(int n=0;n<=21;n++)
    {
      Output << info[x];
      x++;
    }
    Output << endl;
  }
  Output.close();
}
