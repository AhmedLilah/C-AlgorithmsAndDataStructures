/** Coded by
 * Ahmed Sabry Lilah
 * Mohamed moataz **/

 /********************************************************************************************************************/
 // headers
#include <iostream>

using namespace std;

/********************************************************************************************************************/
// node deffinition
typedef struct node
{
    string name;
    double salary;
    int age;
    char gender;
    node* next;
}node;


/********************************************************************************************************************/
// fuactioins deffinition
void get_data ( node* h );
node* create ( );
void upd_n ( node* head, string name, double salary );
node* del_a ( node* head, int age1, int age2 );
void print ( node* temp );


/********************************************************************************************************************/
// main function 
int main ( )
{
    int age1, age2;
    string name;
    double salary;
    node* head = NULL;
    char s = 0;
    while (1)
    {
        cout << "Enter your choice : " << endl;
        cout << "1) add new Employee \n2) print all Employees \n3) delete by age \n4) Update salary by name \n5)write 'q' to exit\n";

        cin >> s;
        switch (s)
        {
        case '1':
            head = create ( );
            break;
        case '2':
            print ( head );
            break;
        case '3':
            cout << " enter start and end age :";

            cin >> age1 >> age2;
            head = del_a ( head, age1, age2 );
            break;
        case '4':
            cout << "Enter the name : ";
            cin >> name;
            cout << " enter the new salary : ";
            cin >> salary;
            upd_n ( head, name, salary );
            break;
        default:
            break;
        }
        if (s == 'q' || s == 'Q')
            break;
    }
    return 0;
}



/********************************************************************************************************************/
// this fucntion creates new nodes 
node* create ( )
{
    int c;
    cout << "how many employee you want to add : ";
    cin >> c;
    static node* temp = NULL;
    static node* head = NULL;
    static node* p = NULL;
    static int counter = 0;

    for (int i = 0; i < c; i++)
    {
        temp = new node;

        if (head == NULL)
        {

            head = temp;
            temp->next = NULL;
            get_data ( temp );

        }
        else
        {
            p->next = temp;
            temp->next = NULL;
            get_data ( temp );
        }
        p = temp;
        counter++;
    }
    return head;
}



/********************************************************************************************************************/
//function to update salary by name 
void upd_n ( node* head, string name, double salary )
{
    while (head != NULL)
    {
        if (head->name == name)
        {
            head->salary = salary;
        }
        head = head->next;
    }
}



/********************************************************************************************************************/
// function to delete by age
node* del_a ( node* head, int age1, int age2 )
{
    node* temp = head;
    node* p = NULL;
    while (temp != NULL)
    {
        if (age1 <= temp->age && temp->age <= age2)
        {
            if (head == temp && temp->next != NULL) //first item
            {
                head = head->next;
                temp = head;
                p = temp;
                continue;
            }
            else if (head == temp && temp->next == NULL)
            {
                head = NULL;
            }
            else if (head != temp && temp->next == NULL)
            {
                p->next = NULL;
            }
            else
            {
                p->next = temp->next;
            }
        }
        p = temp;
        temp = temp->next;
    }
    return head;
}


/********************************************************************************************************************/
// fuction to print the employees data
void print ( node* temp )
{
    while (temp != NULL)
    {
        cout << "employee name : " << (temp->name) << endl;
        cout << "employee age : " << (temp->age) << endl;
        cout << "employee salary : " << (temp->salary) << endl;
        cout << "employee gender : " << (temp->gender) << endl;
        cout << "*********************************\n";
        temp = (temp->next);
    }
    cout << "\n*********************************************\n\n\n";
}


/********************************************************************************************************************/
// fuction to get the node data
void get_data ( node* temp )
{
    cout << "enter the employee's name: ";
    cin >> temp->name;
    cout << "enter the employee's age: ";
    cin >> temp->age;
    cout << "enter the employee's salary: ";
    cin >> temp->salary;
    cout << "enter the employee's gender: ";
    cin >> temp->gender;
}