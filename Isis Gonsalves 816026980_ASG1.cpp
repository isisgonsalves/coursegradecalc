#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main(){
	
	ifstream in; //declare input file
	ifstream in2; //second input file
	ofstream out; //declare output file
	
	int *studentId;
	
	int *mark3275;
	int *mark3150;
	
	mark3275= (int *)malloc (sizeof(int));
	mark3150= (int *)malloc (sizeof(int));
	
	*mark3150 =10;
	
	*mark3275=*mark3150;
	
	cout<<*mark3275;
	
	int *mark3275_Sum=0;
	int *mark3150_Sum=0;
	
	int *numStudents;
	
	double *mark3275_Avg=0;
	double *mark3150_Avg=0;
	
	int *mark3275_high = 0;
	int *mark3275_low;
	
	
	int *mark3150_high = 0;
	int *mark3150_low ;
	
	int *mark3150_Diff=0;
	
	studentId= (int *)malloc (sizeof(int));
	
//	mark3275= (int *)malloc (sizeof(int));
//	mark3150= (int *)malloc (sizeof(int));
	
	mark3275_Sum= (int *)malloc (sizeof(int));
	mark3150_Sum= (int *)malloc (sizeof(int));
	
	numStudents= (int *)malloc (sizeof(int));
	
	mark3275_Avg= (double *)malloc (sizeof(int));
	mark3150_Avg= (double *)malloc (sizeof(int));
	
	mark3275_high= (int *)malloc (sizeof(int));
	mark3275_low= (int *)malloc (sizeof(int));
	
	mark3150_high= (int *)malloc (sizeof(int));
	mark3150_low= (int *)malloc (sizeof(int));
	
	mark3150_Diff= (int  *)malloc (sizeof(int));
	
	in.open("course.txt");
	in2.open("course.txt");
	out.open("A1_816026980.txt");
	
	if (!in.is_open()) {
		cout << "\nERROR: File cannot be found...Try again\n";
		return 0;
	}
	else 
		
		cout<<"File was Read Successfully... "<<endl<<endl; 
	
	
	
	
	in >> *studentId;
	in>>*mark3275;
	in>>*mark3150;
	
	
	*mark3275_low = *mark3275; //set low to be the first mark read
	*mark3150_low = *mark3150; //set low to be the first mark read
	
	cout<<"\t-------------STUDENT FILE-------------\n\n";
	out<<"\t-------------STUDENT FILE-------------\n\n";
	
	while (*studentId != -1){
		
		*numStudents += 1;
		
		*mark3275_Sum = *mark3275_Sum + *mark3275;
		*mark3150_Sum = *mark3150_Sum + *mark3150;
		
		cout<<"Student Id: "<<*studentId<< "  Mark for 3275: "<<*mark3275<<"   Mark for 3150: "<<*mark3150<<endl<<endl;
		out<<"Student Id: "<<*studentId<< "  Mark for 3275: "<<*mark3275<<"   Mark for 3150: "<<*mark3150<<endl<<endl;

		//Checking for highest mark 3275
		if(*mark3275 > *mark3275_high){
			*mark3275_high= *mark3275;
		}
		
		//Checking for lowest mark 3275
		if(*mark3275 < *mark3275_low){
			*mark3275_low= *mark3275;
		}
		
		//Checking for highest mark 3150
		if(*mark3150 > *mark3150_high){
			*mark3150_high= *mark3150;
		}
		
		//Checking for lowest mark 3150
		if(*mark3150 < *mark3150_low){
			*mark3150_low= *mark3150;
		}
		
		in>>*studentId;
		in>>*mark3275;
		in>>*mark3150;
		
	}	
		//Average calculated outside loop
		*mark3275_Avg= (*mark3275_Sum) / (*numStudents);
		*mark3150_Avg= (*mark3150_Sum) / (*numStudents);
	
		
		cout<<"\nNumber of students: "<<*numStudents<<endl<<endl;
		out<<"\nNumber of students: "<<*numStudents<<endl<<endl;
		
	
		cout<<"\nHighest mark received in 3275: "<<*mark3275_high;
		cout<<"\nLowest mark received in 3275: "<<*mark3275_low<<endl<<endl;
		out<<"\nHighest mark received in 3275: "<<*mark3275_high;
		out<<"\nLowest mark received in 3275: "<<*mark3275_low<<endl<<endl;
		
		
		cout<<"\nHighest mark received in 3150: "<<*mark3150_high;
		cout<<"\nLowest mark received in 3150: "<<*mark3150_low<<endl<<endl;
		out<<"\nHighest mark received in 3150: "<<*mark3150_high;
		out<<"\nLowest mark received in 3150: "<<*mark3150_low<<endl<<endl;
		
		
		cout<<"\nAverage of marks for 3275: "<<*mark3275_Avg;
		cout<<"\nAverage of marks for 3150: "<<*mark3150_Avg<<endl<<endl;
		out<<"\nAverage of marks for 3275: "<<*mark3275_Avg;
		out<<"\nAverage of marks for 3150: "<<*mark3150_Avg<<endl<<endl;
		
		
		in2 >> *studentId; 
		
		cout<<"\n-------------DIFFERENCE FROM AVERAGE (Course: 3150)----------\n\n";
		out<<"\n-------------DIFFERENCE FROM AVERAGE (Course: 3150)----------\n\n";
		
		while (*studentId != -1){
		
		in2>>*mark3275;
		in2>>*mark3150;
		
		
		*mark3150_Diff = *mark3150 - *mark3150_Avg;
		
		
		cout<<"Student Id: "<<*studentId<<"   Mark for 3150: "<<*mark3150 <<"   Difference from Average: "<<*mark3150_Diff<<endl<<endl;
		out<<"Student Id: "<<*studentId<<"   Mark for 3150: "<<*mark3150 <<"   Difference from Average: "<<*mark3150_Diff<<endl<<endl;

		in2>> *studentId;
		
		}
		
	in.close();
	in2.close();
	

	return 0;
}
