#include <iostream>
using namespace std;

// to keep track on reserved seats and seat availability (6)
int allseatschecker(char arr[7][5]){ 
	int count=0;
	for(int i=0;i<7;i++){
		for(int j=1;j<5;j++){
			if(arr[i][j]=='X'){
				count++;
			}
		}
	}

	if(count==28){
		return 1;
	}
	return 0;
}

// to display the seats (1)
void display(char arr[7][5]){ 
	for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}

// to take user input (2)
string getData(){ 
	string userinput;
	cout<<"Enter preferred seat (Example 1A, 2B, 3C, QUIT to quit): ";
	cin>>userinput;
	return userinput;
}

// to update seat status (4)
void update(char arr[7][5], int row,int col){ 
	cout<<"Congratulations, your seat has been reserved for you.\n";
	cout<<"Updating seat status...\n\n";
	arr[row][col]='X';
}

// to validate user input to be accepted or rejected (3)
int check(char arr[7][5], string s){
	// if user input is not in range of 1A to 7D
	if(s[0]>'7' || s[0]<'1' || s[1]>'D' || s[1]<'A'){
		cout<<"Invalid seat number.\n"; //invalid sit no
		return 0;
	}

	int row=-1,col=-1;
	// to find the row number of the user seat
	for(int i=0;i<7;i++){
		if(arr[i][0]==s[0]){
			row=i;
		}
	}
	// to find the column number of user seat
	for(int j=0;j<5;j++){
		if(arr[row][j]==s[1]){
			col=j;
		}
	}
	// to check whether seat is already occupied or not
	if(col==-1){
		cout<<"Seat is already occupied.\n";
		return 0;
	}
	else{
		// to process the seat as requested if seat is valid and not occupied
		update(arr,row,col);
	}
	return 1;
}


void airline(char arr[7][5]){ //(5)
	// for user to stop process by entering 'QUIT'
	cout<<"Enter QUIT once you are done.\n"; 
	string s;
	// continuation if not interrupted by user or valid seat in unoccupied state is found
	while(true){
		s = getData(); // to get user input (assign userinput to s)
		// for user input to stop the process
		if(s[0]=='Q'){
			break; // break the loop
		}

		// to process the request & check accordingly
		if(check(arr,s)){
			display(arr);
		}
		
		if(allseatschecker(arr)){ // if all seats are occupied
			cout<<"We are sorry to inform you that we offer no more available seats."<<endl;
			break; // break the loop
		}
	}
	cout<<"Thank you for your cooperation."<<endl; // End of program
}

int main() // last program
{
	// 2-D array for storing seat numbers
	char arr[7][5]; 
	for(int i=0;i<7;i++){
		// 1st column is row number
		arr[i][0]=i+1+'0';
		for(int j=1;j<5;j++){
			// to represent seat number A, B, C, D respectively
			arr[i][j]='A'+j-1; 
		}
	}
	
	cout<<"Current seating arrangement:\n\n";
	display(arr); // requested seats are updated here
	airline(arr); // airline function

	return 0;
}

