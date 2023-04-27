// Main Code (You make changes in Hm.cpp code and paste the changes in this code)
// Basic Functions of this code works but this code is  not fully optimized, it is still under repair.

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class Room
{
private:

    //addRooms()
    int room_no[50];
    float room_rent[50];
    string room_btype[50],room_stype[50],room_ac[50];

    //checkInRoom()
    int ci_room_no,ci_count=0,ci_status[50];
    float advance_payment[50];
    string cust_name[50],cust_address[50];
    string ci_date[50],co_date[50];

public:
    int count=0,i=0;                      // count = no. of Add Rooms, i = index of room no.

    void addRooms()
    {
        cout<<"Enter Room No.: ";
        cin>>room_no[i];
        cout<<"\nType AC/Non-AC (A/N) : ";
        cin>>room_ac[i];
        cout<<"\nType Beds Single/Double (S/D) : ";
        cin>>room_btype[i];
        cout<<"\nType Size (B/S) : ";
        cin>>room_stype[i];
        cout<<"\nDaily Rent : ";
        cin>>room_rent[i];
        cout<<"\n Room Added Successfully!\n";

        ci_status[i]=0;         // sets check-in status=0 means customer has not yet checked-in.

        count++;
        i++;
    }

    void checkInRoom()
    {
        int ci_flag=0;          // sets check-in flag = 0

        if(count==0)            // if rooms are not added then
        {
            cout<<"Please add the rooms first.";
            return;
        }
        else                    // if rooms are added then
        {
            cout<<"\nEnter Room number : ";
            cin>>ci_room_no;

            for(int i=0;i<count;i++)
            {
                if(ci_room_no==room_no[i])     //if the room you want to check-in == room you have already added
                {
                    cout<<"\nEnter Customer Name (First Name): ";
                    cin>>cust_name[i];
                    cout<<"\nEnter Address (only city): ";
                    cin>>cust_address[i];

                    double digits;
                    cout<<"\nPLease enter your phone number :\n";
                    cin>>digits;

                    try                        // Verify if phone number has 10 digits or not using exception handling
                    {
                        while(int(log10(digits))<=8||int(log10(digits))>=10)
                        {
                            throw(digits);
                        }
                        cout<<"\n\t\t\tPhone number is valid ";
                    }
                    catch(double digits)
                    {
                        cout<<"\n\t\t\tPhone number is not valid. Try Again!!!";
                        cout<<"\nPLease enter your phone number :\n";
                        cin>>digits;
                    }
                    cout<<"\nEnter Check in Date: ";
                    cin>>ci_date[i];
                    cout<<"\nEnter Check out Date: ";
                    cin>>co_date[i];
                    cout<<"\nEnter Advance Payment: ";
                    cin>>advance_payment[i];
                    cout<<"\n Customer Checked-in Successfully...\n";

                    ci_status[i]=1;          // indicates that the customer has checked-in successfully
                    ci_flag=1;               // sets check-in flag = 1
                    ci_count++;              // increments the number of customers checked-in
                }
            }
            if(ci_flag==0)                // if check-in flag = 0 then the room you want to check-in is not present in the added rooms
            {
                cout<<"Room Number "<<ci_room_no<<" not found! Please add the room first.";
                return;
            }
        }
    }

    void getAvailRoom()
    {
        if(count==0)           // if rooms are not added then
        {
            cout<<"Please add the rooms first.";
            return;
        }
        else if(count==ci_count)     // if the number of rooms added == number of customers checked in (means all rooms are reserved)
        {
            cout<<"All rooms are reserved! Please add more rooms.";
            return;
        }
        else
        {
            for(int i=0;i<count;i++)
            {
                if(ci_status[i]==0)        // if the rooms are added but have not yet checked-in or when the customers have checked-out after checking in (means the room is available)
                {
                    cout<<"\n\nRoom No.: "<<room_no[i];
                    cout<<"\nType AC/Non-AC (A/N) : "<<room_ac[i];
                    cout<<"\nType Beds Single/Double (S/D) : "<<room_btype[i];
                    cout<<"\nType Size (B/S) : "<<room_stype[i];
                    cout<<"\nDaily Rent : "<<room_rent[i];
                }
            }
        }
    }

    void searchCustomer()
    {
        int search_flag=0;      // sets the search_flag = 0
        string cname;

        if(count==0)            // if rooms are not added then
        {
            cout<<"Please add the rooms first.";
            return;
        }

        else if(ci_count==0)    // if rooms are added but the customers have not yet checked-in
        {
            cout<<"\n No Guests in Hotel !!";
            return;
        }
        else
        {
            cout<<"Enter Customer Name: ";
            cin>>cname;

            for(int i=0;i<count;i++)
            {
                if(cname==cust_name[i])
                {
                    cout<<"\nCustomer Name: "<<cust_name[i];
                    cout<<"\nRoom Number: "<<room_no[i];
                    search_flag=1;                            // sets the search_flag = 1
                }
            }
            if(search_flag==0)                  // if the person you are searching for is not present in our hotel
            {
                cout<<"\nPerson not found.\n";
                return;
            }
        }
    }

    void checkOutRoom()
    {
        int days,co_flag=0,co_room_no;       // sets the check-out_flag = 0
        float billAmount=0;

        if(count==0)                         // if rooms are not added then
        {
            cout<<"Please add the rooms first.";
            return;
        }
        else
        {
            cout<<"Enter Room Number : ";
            cin>>co_room_no;
            for(int i=0;i<count;i++)
            {
                if(co_room_no==room_no[i])
                {
                    cout<<"\nEnter Number of Days:\t";
                    cin>>days;
                    billAmount=days*room_rent[i];
                    cout<<"\n\t######## CheckOut Details ########\n";
                    cout<<"\nCustomer Name : "<<cust_name[i];
                    cout<<"\nRoom Number : "<<room_no[i];
                    cout<<"\nAddress : "<<cust_address[i];
                    cout<<"\nTotal Amount Due : "<<billAmount<<"/-";
                    cout<<"\nAdvance Paid: "<<advance_payment[i]<<"/-";
                    cout<<"\n*** Total Payable: "<<(billAmount-advance_payment[i])<<"/- only";

                    ci_status[i]=0;           // sets check-in status = 0 to make sure that after customer has checked-out, the check-in status of that room remains same as before checking in
                    ci_count--;               //
                    co_flag=1;                // sets the check-out_flag = 1
                }
            }
            if(co_flag==0)
            {
                cout<<"Room Number "<<co_room_no<<" not found!";
                return;
            }
        }
    }

    void guestSummaryReport()
    {
        if(count==0)            // if rooms are not added then
        {
            cout<<"Please add the rooms first.";
            return;
        }
        else
        {
            if(ci_count==0)    // if rooms are added but the customers have not yet checked-in
            {
                cout<<"\n No Guest in Hotel !!";
                return;
            }
            else
            {
                for(int i=0;i<ci_count;i++)
                {
                    if(ci_status[i]==1)    // if customers have checked-in
                    {
                        cout<<"\n Customer Name : "<<cust_name[i];
                        cout<<"\n Room Number : "<<room_no[i];
                        cout<<"\n Address (only city) : "<<cust_address[i];
                        cout<<"\n---------------------------------------";
                    }
                }
            }
        }
    }
};

int main()
{
    int choice;

    Room r1;

    while(choice!=7)
    {
        cout<<"\n######## Hotel Management #########\n";
        cout<<"\n1. Add Rooms";
        cout<<"\n2. Check-In Room";
        cout<<"\n3. Available Rooms";
        cout<<"\n4. Search Customer";
        cout<<"\n5. Check-Out Room";
        cout<<"\n6. Guest Summary Report";
        cout<<"\n7. Exit";
        cout<<"\n\nEnter Option: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                r1.addRooms();
                break;

            case 2:
                r1.checkInRoom();
                break;

           case 3:
                r1.getAvailRoom();
                break;

           case 4:
                r1.searchCustomer();
                break;

           case 5:
                r1.checkOutRoom();
                break;

            case 6:
                r1.guestSummaryReport();
                break;

            case 7:
                cout<<"\nTHANK YOU!";
                break;

            default:
                cout<<"\nPlease Enter correct option";
                break;
        }
    }
}
