//Project3_Jones_nhj0004.cpp 
//Dr. Li's COMP2710
//Compiled using G++ on a Linux machine by entering command ' g++ "Project3_Jones_nhj0004.cpp -o "p3" and then "./p3"
//References: 
//cplusplus.com/doc/oldtutorial/files/
//cplusplus.com/reference/ios/ios/good/
//https://stackoverflow.com/questions/14516915/read-numeric-data-from-a-text-file-in-c

#include <fstream> 
#include <iostream> 
#include <vector> 
using namespace std; 
 
/* declare your user-defined functions */ 
bool check_file(string); 
//check to see if file exists or not 
vector<int> read_file(string); 
//Read and return a vector that contains the numbers in file 
void write_file(string, vector<int>); 
//Writes the numbers from vector to new file
vector<int> merge(vector<int>, vector<int>); 
//Combine all of the values from two vectors into one
//Sort final vector into ascending order


/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() { 
 /* declare your variables */ 
//input file 1
string file1;
//input file 2
string file2;
//output file
string file3;
//integer vector with values from file1
vector<int> vec1;
//integer vector with values from file2
vector<int> vec2;
//integer vector with final, sorted values from both files
vector<int> vecFinal;
//Print welcome message
cout << "***Welcome to Noah's Sorting Program***" << endl;
do {
  /* user friendly interfaces */ 
  //prompt user to enter first txt file 
  cout << "Enter the name of the first text file containing values" << endl;
  //retrieve file from user 
  cin >> file1;
  cout << "\n" << endl;
}
//while file1 is valid and cin.fail passes
  while (cin.fail() || !check_file(file1)); 
 
 /* Get and display numbers from file one. */ 
 //calls readFile function
 vec1 = read_file(file1); 
 //call toString method to print contents from file1
 to_string(file1, vec1); 
 /* Get name of file two. */ 
 do { 
  /* user friendly interfaces */ 
  //prompt user to enter second txt file
  cout << "Enter the name of the second text file containing values" << endl;
  //retrieve file from user 
  cin >> file2;
  cout << "\n" << endl;
 } while (cin.fail() || !check_file(file2)); 
 
 /* Get and display numbers from file two. */ 
 //calls readFile function
 vec2 = read_file(file2);
 //call toString method to print contents from file 
 to_string(file2, vec2);
 /* Combine vectors and display the sorted result. */
 //calls merge function (defined below)
 vecFinal = merge(vec1, vec2); 
 //printed output
 cout << "The sorted list of " << vecFinal.size() << " numbers is: " << endl;
//loop through the final combined vector
      for (int i = 0; i < vecFinal.size() - 1; i++) {
            //print each individual value
            cout << vecFinal.at(i) << "\n";
      }
 /* Get name of output file. */ 
 do { 
//prompt user for name of output txt file
  cout << "Enter the name of the output file: " << endl;
  //ask user what they would like to name the output file of sorted values
  cin >> file3;
  cout << "\n" << endl;
 } while (cin.fail()); 
 /* Write combined vector to output file. */ 
 //calls writefile function (defined below)
 write_file(file3, vecFinal);
 //after write, print success output
 cout <<  "***Please check the new file - " << file3 << " ***\n";
 cout << "***Goodbye. ***\n";
      //upon success
      return 1;
}
//end of main()
bool check_file(string file) { 
 /* Input file stream. (ifstream) */ 
 //declare input file stream variable
 ifstream stream; 
 /* Check whether file exists. */ 
 //f stream must be declared in header 
 stream.open(file.c_str()); 
 if (stream.fail()) { 
  //print error message
  cout << "File not found." << endl; 
 } 
 //close stream
 stream.close(); 
 return true; 
} 
 
vector<int> read_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 /* Vector containing numbers from file. (vector<int>) */ 
 //midpoint between input and output files
 vector<int> v; 
 /* Integer read from file. (int) */ 
 int i; 
 /* Add each number in the file to a vector. */ 
 stream.open(file.c_str()); 
 //ensure that no flags in stream  
 while (stream.good()) { 
  //input stream data from int i     
  stream >> i; 
  //add i to end of the vector using 'push_back' predefined function
      v.push_back(i);
 } 
 //shrink vector to last int
 v.pop_back();
 //close the stream 
 stream.close();
 return v; 
} 
 
void write_file(string file, vector<int> v) { 
 /* Output file stream. (ofstream) */
 //declare output stream variable 
 ofstream ostream;
 // Unsigned short 
 //Vector Iterator
 unsigned short i;
 //open c_str in file
 ostream.open(file.c_str());
 //write each number in v to file
 //loop through vector 
 for (i=0; i < v.size() -1; i++) {
     //add each elements from v to the output stream 
     ostream << v.at(i) << "\n";
 }
 ostream << v.at(v.size() - 1);
 //close stream
 ostream.close();
} 

vector<int> merge(vector<int> vec1, vector<int> vec2) { 
// Complete & Sorted Vector 
vector<int> vec3;
 /* Compare both vectors. */ 
 //ensure both vectors are greater than zero
 // loop through size of v1 
    while (vec1.size() > 0 && vec2.size() > 0) {
        if (vec1.at(0) < vec2.at(0)) {
        //use push_back to add current element of v1 to v3
        vec3.push_back(vec1.at(0));
        //erase og vector
        vec1.erase(vec1.begin());
    }
    else {
        vec3.push_back(vec2.at(0));
        //erase og vector
        vec2.erase(vec2.begin());
    }
    }
 /* Add any remaining numbers from vector one. */ 
 //if there are any numbers left in v1
 if (vec1.size() > 0) {
     //loop through all of v1
     for (int i = 0; i < vec1.size(); i++) {
         //add values from vec1 to completed vector
         vec3.push_back(vec1.at(0));
         //erase og vector
         vec1.erase(vec1.begin());
     }
} 
 /* Add any remaining numbers from vector two. */ 
 if (vec2.size() > 0) {  
  //loop thru vec2
  for (int i = 0; i < vec2.size(); i++) {
      //add values for vec2 to vec3
      vec3.push_back(vec2.at(0));
      //erase og vector
      vec2.erase(vec2.begin());
  }
 } 
 //return completed vector
 return vec3; 
} 

void to_string(string file, vector<int> vec) { 
 /* Vector iterator number. (unsigned short) */ 
 unsigned short x; 
 /* Display the numbers contained in a vector. */ 
    cout << "This list of " << vec.size() << " numbers "
    << "in file " << file << " is:\n" ;
    //print
    for (x = 0; x < vec.size(); x++) {
        cout << vec.at(x) << "\n";
    }
    cout << "\n";
}