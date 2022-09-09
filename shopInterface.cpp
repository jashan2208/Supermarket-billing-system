#include<iostream>
#include<fstream>
using namespace std;
//Shop class
class shop
{
    private:
        int productId;
        double productPrice;
        double productDiscount;
        string productName;
    public:
        void menu();//main menu which shows options of employee and customer
        void employee();//used to access the employee menu
        void customer();//used to access customer menu
        void add();//adds a new item to the database
        void edit();//changes value of an item from the database
        void remo();//removes an item from the database
        void list();//shows list of items in the database
        void receipt();//shows the items bought by the customer
};
void shop:: menu()
{
    m:
    int choice;
    string email;//it is 1234
    string password;//it is 1234
    cout<<"\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t             MAIN MENU            \n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t__________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t             1)Employee           \n";
    cout<<"\t\t\t\t             2)Customer           \n";
    cout<<"\t\t\t\t             3)Exit               \n";
    cout<<"Please select one of the above options\n";
    cin>>choice;
    switch(choice)//switches between 3 options of employee,customer,exit
    {
        case 1:
            cout<<"\t\t\t\t      EMPLOYEE LOG IN          \n";
            cout<<"Please enter your Employee email ID(1234)"<<endl;//1234
            cin>>email;
            cout<<"Please enter your Employee password(1234)"<<endl;
            cin>>password;
            if(email=="1234"&&password=="1234")
            {
                employee();
            }
            else
            {
                cout<<"Invalid Email or Password\n";
            }
            break;
        case 2:
        cout<<"Welcome dear customer\n";
            customer();
            break;
        case 3:
            exit(0);
        default:
            cout<<"Please enter one of the above options only\n";

    }
    goto m;
}
void shop::employee()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\tEMPLOYEE MENU";
    cout<<"\n\t\t\t|____1)Add a new product__________|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|____2)Modify an existing product_|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|____3)Remove an existing product_|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|____4)Go back to the Main menu___|";
    cout<<"\n\n\tPlease enter one of the above options";
    cin>>choice;
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remo();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Please enter a valid choice!";
    }
    goto m;
}
void shop::customer()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t|____CUSTOMER MENU____________|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|____1)Buy a product______________|";
    cout<<"\n\t\t\t|                                 |";
    cout<<"\n\t\t\t|____2)Go back to the Main menu___|";
    cout<<"\n\n\tPlease enter one of the above options";
    cin>>choice;
    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
            cout<<"Please enter a valid choice!";
    }
    goto m;
}
void shop::add()
    {   
        m:
        fstream data;
        int id;
        int token;
        double price;
        double discount;
        string name;
        //ENTRY OF NEW PRODUCT DETAILS
        cout<<"\n\n\t\t\t Add a new product";
        cout<<"\n\n\tProduct ID of the product";
        cin>>productId;
        cout<<"\n\n\tName of the product";
        cin>>productName;
        cout<<"\n\n\tPrice of the product";
        cin>>productPrice;
        cout<<"\n\n\tDiscount on the product";
        cin>>productDiscount;

        data.open("database.txt",ios::in);//opens database file in reading mode

        if(!data)//if database file doesn't exist
        {
            data.open("database.txt",ios::app|ios::out);//opens database file in writing mode
            //Writes the data of product in the file
            data<<" "<<productId<<" "<<productName<<" "<<productPrice<<" "<<productDiscount<<"\n";
            data.close();
        }
        else
        {
            data>>id>>name>>price>>discount;//copies values of items from database in the variables

            while(!data.eof())//checks if the iteration is not at the end of file
            {
                if(id==productId)//checks if there already product exists with same id
                {
                    token++;
                }
                data>>id>>name>>price>>discount;//copies values of items from database in the variables
            }
            data.close();
            if(token==1)
            {
                cout<<"Product already exists in the database\n";
                goto m;
            }
            else
            {//writes the value of new product in the database if a duplicate doesn't exist
                data.open("database.txt",ios::app|ios::out);
                data<<" "<<productId<<" "<<productName<<" "<<productPrice<<" "<<productDiscount<<"\n";
                data.close();
            }
        }
        
      cout<<"Record Inserted";  
    }
void shop::edit()
{
    fstream data,data1;
    int productkey;
    int token=0;
    int c;//product id
    double p;//price
    double d;//discount
    string n;//name

    cout<<"\n\t\t\tModify the record";
    cout<<"\n\t\t\tProduct Code:";
    cin>>productkey;//enter product id of product which want to edit

    data.open("database.txt",ios::in);//open database file with data object
    if(!data)//checks if there isn't any data in the file 
    {
        cout<<"\n\nFile doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);//opens new databasse file

        data>>productId>>productName>>productPrice>>productDiscount;//copies data of product in the variables from database
        while(!data.eof())
        {
            if(productkey==productId)//checks the product id of the product to edit its details
            {
                cout<<"\n\t\t Product new code";
                cin>>c;
                cout<<"\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";//writes the new details of the product in the new file
                cout<<"\n\n\t\tRecord Edited";
                token++;
            }
            else
            {//Writes all of the data as it is from database to database1 except the file which needs to be edited
                data1<<" "<<productId<<" "<<productName<<" "<<productPrice<<" "<<productDiscount<<"\n";
            }
            data>>productId>>productName>>productPrice>>productDiscount;//copies data of product in the variables from database
        }
        data.close();
        data1.close();

        remove("database.txt");//deletes database file
        rename("database1.txt","database.txt");//changes name of database to database1
        if(token==0)
        {
            cout<<"\n\nRecord not found!";
        }
    }
}
void shop::remo()
{
    fstream data,data1;
    int productKey;
    int token=0;
    cout<<"\n\n\tDelete product";
    cout<<"\n\n\tProduct Id";
    cin>>productKey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File Doesn't exist";

    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>productId>>productName>>productPrice>>productDiscount;
        while(!data.eof())
        {//Writes all the data of database file to database1 except the information of the product which whose id is given
            if(productKey==productId)
            {
                cout<<"\n\n\tProduct deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<productId<<" "<<productName<<" "<<productPrice<<" "<<productDiscount<<"\n";
            }
            data>>productId>>productName>>productPrice>>productDiscount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\nRecord not found";
        }
    }

}
void shop::list()
{//Prints information of all the products in the database
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n______________________________________________\n";
    cout<<"ProductNumber\t\tName\t\tPrice\n";
    data>>productId>>productName>>productPrice>>productDiscount;
    while(!data.eof())
    {
        cout<<productId<<"\t\t\t "<<productName<<"\t\t "<<productPrice<<"\n";
        data>>productId>>productName>>productPrice>>productDiscount;
    }
    data.close();

}
void shop::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    double amount=0;
    double total=0;
    cout<<"\n\n\t\tPRODUCTS AVAILABLE ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nNo products available";
    }
    else
    {
        data.close();
        list();
        cout<<"\n________________________________________________________\n";
        cout<<"\n                                                        \n";
        cout<<"\n                  PLEASE PLACE AN ORDER                 \n";
        cout<<"\n                                                        \n";
        cout<<"\n________________________________________________________\n";
        do
        {   
            m:
            //Enter the information of product which you want to buy
            cout<<"\n\nEnter the product id or code";
            cin>>arrc[c];
            cout<<"\n\nEnter the quantity of product you want";
            cin>>arrq[c];
            for(int i=0;i<c;i++)//checks if duplicate products are being bought
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\nDuplicate product code.Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\nDo you want to buy another product? Press Y if yes and N if no";
            cin>>choice;

        } while (choice=='Y');
        cout<<"\n\n\t\t\t____________RECEIPT____________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t Price\t    Discount\n";

        for(int j=0;j<c;j++)
        {
            data.open("database.txt",ios::in);
            data>>productId>>productName>>productPrice>>productDiscount;
            while(!data.eof())
            {
                if(productId==arrc[j])
                {//checks the id of the product and calculates the price of the products bought by customer
                    amount=productPrice*arrq[j];
                    total+=amount;
                    cout<<"\n"<<" "<<productId<<"\t\t  "<<productName<<"\t\t  "<<arrq[j]<<"\t\t "<<amount<<"\t\t"<<productDiscount;
                }
                data>>productId>>productName>>productPrice>>productDiscount; 
            }
        }
        data.close();
    }
    cout<<"\n\n_______________________________________________";
    cout<<"\nToatal Amount :"<<total;
}
int main()
{
    
    shop s;
    s.menu();

return 0;
}