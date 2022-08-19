#include<iostream>
#include<fstream> 

using namespace std;

class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
}

void shopping::menu()
{
    m;
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t     Supermarket Main Menu          \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t       1) Administrator        \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t       2) Buyer                \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t       3) Exit                 \n";
    cout<<"\t\t\t\t                               \n";
    cout<<"\t\t\t\t Please Select Among the options given above";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login  \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Enter Password  \n";
            cin>>password;

            if(email=="ekta@gmail.com" && password=="ekta@1234")
            {
                administrator();
            }
            else
            {
                cout<<" Invalid Email/Password";
            }
            break;

        case 2:
            buyer();
        
        case 3:
            exit(0);    //for successfull termination of the program 
        
        default:
            cout<<"Please select from the options given above";

    }

    goto m;
}

void shopping:: administrator()
{
    m;
    int choice;
    cout<<"\n\n\n\t\t\t  Administrator Menu ";
    cout<<"\n\n\t\t\t|_______1) Add the Product_______|";
    cout<<"\n\n\t\t\t|                                |";
    cout<<"\n\n\t\t\t|_______2) Modify the Product____|";
    cout<<"\n\n\t\t\t|                                |";
    cout<<"\n\n\t\t\t|_______3) Delete the Product____|";
    cout<<"\n\n\t\t\t|                                |";
    cout<<"\n\n\t\t\t|_______4) Back to Main Menu ____|";

    cout<<"\n\n\t\t Please enter your choice ";
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
            rem();
            break;
        case 4:
            menu();
            break;
        
        default:
            cout<<"Invalid choice";

    }

    goto m;

}

void shopping:: buyer()
{
    m;
    int choice;
    cout<<"\t\t\t|_____Buyer_____| \n";
    cout<<"                        \n";
    cout<<"\t\t\t 1) Buy Product   \n";
    cout<<"                        \n";
    cout<<"\t\t\t 2) Go Back       \n";
    cout<<"                        \n";
    cout<<"\t\t\t Enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;

        default:
            cout<<"Invalid Choice";
        
    }
    
    goto m;
}

void shopping::add()
{
    m;
    fstream data;   //for file handling operations -- object of fstream class--name of object is data
    int c,token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t\t\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the product";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on the product";
    cin>>dis;

    data.open("database.txt",ios::in);      /* ios::in open the file in reading mode*/

    if(!data)       //if the file does not exist
    {
        data.open("database.txt",ios::app|ios::out);     /*ios::out open the file in writing mode--ios::app is used to append/edit the file*/ 
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();
    }
    else        //if the file exist
    {
        data>>c>>n>>p>>d;       //to read from the file--indev of the file
                                 /* now we are gonna use while loop to iterate through the file-----here we are initializing the file*/
        while(!data.eof())      /*eof- End Of File(function)---------this while loop will make sure to check every content of the file by iterating it*/
        {
            if(c==pcode)    /*in case of duplicacy*/
            {
                token++;    
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt",ios::app|ios::out);      
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record Inserted  !";
}

void shopping:: edit()
{
    fstream data , data1 ;
    int pkey , token=0 , c ;
    float p, d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t\t this file doesn't exist !!";
    }
    else        /* we will open new file---save our edited data in new file and we will rename it to the original/old file name */
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the Product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
                cout<<"\n\n\t\t\t Record Edited ";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis; /*for increment purpose so that the while loop can iterarte*/
        }
        data.close();
        data1.close();

        /*these functions are used to remove the old file and update the new file in its place*/
        remove("database.txt");
        rename("database1.txt","database.txt");     /*database1 name will change into database*/

        if(token==0)
        {
            cout<<"Record not found ! ";
        }
    }
}

void shopping::remove()
{
    fstream data,data1;
    int pkey, token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out):
        data>>pcode>>pname>>price>>dis;     /*this is how we read from the file*/
        while(!data.eof())
        {
            /*in this 1st the if will execute once it matches the product will be deleted and and then else will execute 
            in which the updated file will show from where the product is deleted*/
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted successfully";
                token++;
            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis; /*for increment purpose so that the while loop can iterarte*/
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt"); 
        if(token==0)
        {
            cout<<"\n\n Record not found ! ";
        }
        
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n__________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n__________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pnmae<<"\t\t"<<price<<"\n";
        data>>pcode>>pnmae>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;
    int arrc[100];  /*array of code*/
    int arrq[100];  /* array of quantity*/
    char choice;
    int c=0;
    float amount=0, dis=0, total=0;

    cout<<"\n\n\t\t\t Receipt ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout<<"\n_____________________________________________\n";
        cout<<"\n|                                            \n";
        cout<<"\n           Please place the order            \n";
        cout<<"\n|                                            \n";
        cout<<"\n_____________________________________________\n";
        do
        {
            m;
            cout<<"\n\n Enter product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code please try again !";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If y then press yes else no ";
            cin>>choice;
        } 
        while(choice=="y");
        
        cout<<"\n\n\t\t\t____________________RECEIPT____________________\n";
        cout<<"\n Product No\t Product Name\t Product Quantity\t Price\t Amount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {/* we are matching if the code entered by the user in arrc is = to the code presnt in file
                if yes thn we will do the calculations add the files in the customer basket*/
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"pname<<"\t\t"arrq[i]<<"\t\t"price<<"\t\t"amount<<"\t\t"dis;
                }
                data>>pcode>>pnmae>>price>>dis;
            }
        }
        data.close(); 
    }
    cout<<"\n\n________________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main()
{
    shopping s;
    s.menu();
}