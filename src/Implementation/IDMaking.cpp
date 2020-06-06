#include <iostream>
#include <sstream>
#include <algorithm>
// For testing change it to linked list later
#include <list>
using namespace std;


// for testing in the linked list order
string getIDOrder(list<string> ids){
    string highest = ids.back().substr(6,8);
    stringstream temp(highest);
    int tempNew = 0;
    temp >> tempNew;
    tempNew += 1;
    string tempNewS;
    if(tempNew < 100){
        if(tempNew < 10){
            tempNewS = "00" + to_string(tempNew);
        }
        else{
            tempNewS = "0" + to_string(tempNew);
        }
    }
    return (tempNewS);
}
// NOTE
// Remove list parameter when connected to linked list in avl 
// It should use a function to call the list inside the avl but i cant do it here
int getID(string firstName, string lastName,list<string>ids){
    // First name - 65 to match the hashtable (0-12) 13 keys 
    int firstL = (int(toupper(char(firstName[0]))) - 65)%13;
    int firstN = 00;
    int lastN = 00;

    // Iterate through the first name
    for(int i = 0; i < firstName.length();i++){
        firstN = firstN + int(toupper(char(firstName[i])));
        //cout << firstN << endl;
    }

    // Mod 13
    firstN = firstN % 13;

    // If there is no last name input "-"
    // If there is last name
    if (lastName != "-"){
        string lastNameC = lastName;
        lastNameC.erase(remove(lastNameC.begin(), lastNameC.end(), ' '), lastNameC.end());
        // Iterate through the last name
        for(int i = 0; i < lastNameC.length();i++){
            lastN = lastN + int(toupper(char(lastNameC[i])));
        }
        // Mod 13
        lastN = lastN % 13;
        
    }
    else{
        int lastN = 0;
    }
    
     // Turn into string (first name)
    string firstNResult = "";
    if (firstN > 0){
        if (firstN > 9){
            firstNResult = to_string(firstN);
        }
        else{ // To force it to be 2 digit
            firstNResult = "0" + to_string(firstN);
        }
    }
    else{
        firstNResult = "00";
    }
    // Turn into string (first letter)
    string firstLResult = "";
    if (firstL > 0){
        if (firstL > 9){
            firstLResult = to_string(firstL);
        }
        else{ // To force it to be 2 digit
            firstLResult = "0" + to_string(firstL);
        }
    }
    else{
        firstLResult = "00";
    }
    cout << firstLResult << endl;

    // turn into string (last name)
    string lastNResult = "";
    if (lastN > 0){
        if (lastN > 9){
            lastNResult = to_string(firstN);
        }
        else{ // to force it to be 2 digit
            lastNResult = "0" + to_string(lastN);
        }
    }
    else{
        lastNResult = "00";
    }

    string result = firstLResult + (firstNResult)  + lastNResult;
    // This is the linked list index pls add :)
    string order = "000";
    order =  getIDOrder(ids);


    result = result + order;
    cout << result;
    return 0;
}

int main(){
    list <string> ids;
    ids.push_back("040003000");
    ids.push_back("040003001");
    ids.push_back("040003002");
    getID("Rion","Frey Windhill",ids);

    return 0;
}