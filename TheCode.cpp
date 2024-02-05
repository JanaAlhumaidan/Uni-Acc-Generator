#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	
    // INPUT
    int attempts = 0;

    while (true) {
    	
   		// Update attempts
        attempts++;  
		  	
	    // Full name
	    const int max = 100;
	    char full_name[max] = "";
		cout << "Enter a full name: ";
	    cin.getline(full_name, max);
	    
	    bool foundSpace = false;
	    string first_name = "";
	    string second_name = "";
	    string last_name = "";
		int i;
		
	    for ( i = 0; i < max; i++) {
	        if (full_name[i] == ' ') {
	            if (!foundSpace) {
	                foundSpace = true;
	            } 
				else {
	                break; // Stop at the second space
	            }
	        } 
			else {
	            if (!foundSpace) {
	                first_name += full_name[i];
	            } 
				else {
	                second_name += full_name[i];
	            }
	        }
	    }
	    
	    while (full_name[i] != '\0') {
	        last_name += full_name[i];
	        i++;
	    }

        // ID
        string id;
        cout << "Enter an ID: ";
        cin >> id;

        // Academic position
        char academic_position;
        cout << "Enter the academic position: ";
        cin >> academic_position;


        // Make sure that the inputs are correct
        // check name
        if (first_name.length() == 0 || second_name.length() == 0 || last_name.length() == 0) {
            cout << "\nInformation entered incorrectly. Please try again.\n" << endl;
            cin.ignore();
            continue;
        }

        // Check ID
        if (id.length() != 10) {
            cout << "\nInformation entered incorrectly. Please try again.\n" << endl;
            cin.ignore();
            continue;
        }

        // Check position
        if (!(academic_position == 's' || academic_position == 'S' || academic_position == 'e' || academic_position == 'E')) {
            cout << "\nInformation entered incorrectly. Please try again.\n" << endl;
            cin.ignore();
            continue;
        }
		
        // Batch year (for students only)
        string batch_year;
	    if (academic_position == 'S' || academic_position == 's') {
	        cout << "Batch year: ";
	        cin >> batch_year;
	        
			// check batch year
	        if (batch_year.length() != 4 || (batch_year < "2013" || batch_year > "2023")) {
	            cout << "\nInformation entered incorrectly. Please try again.\n" << endl;
	            cin.ignore();
	            continue;
	        }
	    }

	    // OUTPUT
	    // Switch based on academic position
		switch (academic_position) {
	    	// Case 1: Employee
	   		case 'E':
	    	case 'e':
	    	{
	        // Username
	        string firstletter_firstname, firstletter_secondname, user_end;
	
	        firstletter_firstname = toupper(first_name[0]);
	        firstletter_secondname = toupper(second_name[0]);	       
	        user_end = last_name;
	        
	        transform(last_name.begin(), last_name.end(), last_name.begin(), ::toupper);
	        last_name.erase(remove(last_name.begin(), last_name.end(), ' '), last_name.end());
	
	        cout << "\nUsername: " << firstletter_firstname << firstletter_secondname << last_name << endl;
	
	        // Email
	        string username, email;
	
	        username = firstletter_firstname;
	        username += firstletter_secondname;
	        username += last_name;
	
	        email = username + "@iau.edu.sa";
	
	        transform(email.begin(), email.end(), email.begin(), ::tolower);
	
	        cout << "Email: " << email << endl;
	
	        // Password
	        string firstletter_lastname, last_six_id;
	
	        firstletter_firstname = toupper(first_name[0]);
	        firstletter_secondname = tolower(second_name[0]);
	        firstletter_lastname = tolower(last_name[0]);
	
	        last_six_id = id.substr(4);
	        last_six_id.erase(remove(last_six_id.begin(), last_six_id.end(), ' '), last_six_id.end());
	
	        cout << "Password: " << firstletter_firstname << firstletter_secondname << firstletter_lastname << "_" << last_six_id << endl;
	        break;
	    	}
	
	   		// Case 2: Student
			case 'S':
			case 's':
			{
		    // Username
		    string username = "2" + batch_year.substr(2) + "000" + id.substr(6);
		    cout << "\nUsername: " << username << endl;
		
		    // Email
		    string email = username + "@iau.edu.sa";
		    cout << "Email: " << email << endl;
		    
		    // Password
                string firstletter_firstname, firstletter_secondname, firstletter_lastname, last_six_id;

                firstletter_firstname = toupper(first_name[0]);
                firstletter_secondname = tolower(second_name[0]);
                firstletter_lastname = tolower(last_name[1]);

                last_six_id = id.substr(4);
                last_six_id.erase(remove(last_six_id.begin(), last_six_id.end(), ' '), last_six_id.end());

                cout << "Password: " << firstletter_firstname << firstletter_secondname << firstletter_lastname << "_" << last_six_id << endl;
                break;
            }
		}
	
	    // Attempts count
	    if (attempts == 1){
	    cout << "\nUser information entered successfully, after " << attempts << " attempt.";    	
		}
		else{
			cout << "\nUser information entered successfully, after " << attempts << " attempts.";
		}
	    return 0;
	}
}



