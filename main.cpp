#include <iostream>
#include <windows.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
template <class A, class B>
class Library
{
private:
    A size;
    A length,NumBorrow;
    B *Titl;
    B *Typ;
    B *Auth;
    A *Avai;
    A *Is;
    A NumAvailable,Isbn;
    B Title,Author,Type;
public:
    //Create dynamic array inside constructor
    Library(A arrSize)
    {
        if(arrSize>0)
        {
            size=arrSize;
            Titl=new B[arrSize];
            Typ=new B[arrSize];
            Auth=new B[arrSize];
            Avai=new A[arrSize];
            Is=new A[arrSize];
            length=0;
            NumBorrow=0;
        }
        else
        {
            cout<<"Error!! must enter a valid number\n";
            return;
        }
    }

    //Fill Array
    void Fill()
    {
        A num,c=0;
        cout<<"How many books do you want to store? ";
        cin>>num;
        cout<<endl;
        for(A i=0; i<num; i++)
        {
            cout<<"\nRecord the information of the book "<<++c;
            cout<<"\n1. The title of the book => ";
            cin>>Title;
            cout<<"\n2. Author of the book => ";
            cin>>Author;
            cout<<"\n3. Book type => ";
            cin>>Type;
            cout<<"\n4. The available number of this book => ";
            cin>>NumAvailable;
            cout<<"\n5. Serial number for this book => ";
            cin>>Isbn;
            Titl[i]=Title;
            Typ[i]=Type;
            Auth[i]=Author;
            Avai[i]=NumAvailable;
            Is[i]=Isbn;
            length++;
            cout<<"_____________________________\n";
        }
        cout<<endl;
    }
    //Add New Element
    void Add(A Index)
    {
        if(Index>=0 && Index<size)
        {
            //shift elements to right
            A j=length-1;
            for(A i=length; i>Index; i--)
            {
                Titl[i]=Titl[j] ;
                Typ[i]=Typ[j];
                Auth[i]=Auth[j];
                Avai[i]=Avai[j];
                Is[i]=Is[j];
                j--;
            }
            cout<<"\nRecord information about a new added book ";
            cout<<"\n1. The title of the book => ";
            cin>>Title;
            cout<<"\n2. Author of the book => ";
            cin>>Author;
            cout<<"\n3. Book type => ";
            cin>>Type;
            cout<<"\n4. The available number of this book => ";
            cin>>NumAvailable;
            cout<<"\n5. Serial number for this book => ";
            cin>>Isbn;
            Titl[Index]=Title;
            Typ[Index]=Type;
            Auth[Index]=Author;
            Avai[Index]=NumAvailable;
            Is[Index]=Isbn;
            length++;

        }
        else
            cout<<"Index is out of range! \n";
    }
    //Search for an item using its Title
    A Search(B titl)
    {
        A ind=-1;
        for(A i=0; i<length; i++)
        {
            if(titl==Titl[i])
            {
                ind=i;
                break;
            }
        }
        return ind;
    }
    //Delete element specific index
    void Delete(A Indx)
    {
        if(Indx>=0 && Indx<size)
        {
            //shift elements to left
            A j=Indx+1;
            for(A i=Indx; i<length; i++)
            {
                Titl[i]=Titl[j] ;
                Typ[i]=Typ[j];
                Auth[i]=Auth[j];
                Avai[i]=Avai[j];
                Is[i]=Is[j];
                j++;
            }
            length--;
        }
        else
            cout<<"Index is out of range! \n";
    }

    //Display Library
    void Display()
    {
        cout<<"Array content\x03\n";
        for(A i=0; i<length; i++)
        {
            cout<<"\n\tBook "<<Titl[i]<<endl;
            cout<<"Author: "<<Auth[i]<<endl;
            cout<<"Type: "<<Typ[i]<<endl;
            cout<<"Available_Number: "<<Avai[i]<<endl;
            cout<<"ISBN: "<<Is[i]<<endl;
            cout<<"******************************************";
        }
        cout<<endl;
    }
    //Sort array based on available number for each book
    //Descending Order
    void Sort()
    {
        B temp1,temp2,temp3;
        A temp4,temp5,j=1;
        for(A i=0; i<length-1; i++)
        {
            if(Avai[i]<Avai[j])
            {
                temp1=Titl[i];
                Titl[i]=Titl[j];
                Titl[j]=temp1;
                ///
                temp2=Auth[i];
                Auth[i]=Auth[j];
                Auth[j]=temp2;
                ///
                temp3=Typ[i];
                Typ[i]=Typ[j];
                Typ[j]=temp3;
                ///
                temp4=Avai[i];
                Avai[i]=Avai[j];
                Avai[j]=temp4;
                ///
                temp5=Is[i];
                Is[i]=Is[j];
                Is[j]=temp5;
                ///
                j++;

            }

        }

    }
    //Change the size of the array
    void ChangeSize()
    {
        A newSize;
        cout<<"Enter the new array size: ";
        cin>>newSize;
        cout<<endl;
        if(newSize>size)
        {
            size=newSize;
            //Store old array
            B *old1=Titl;
            B *old2=Typ;
            B *old3=Auth;
            A *old4=Avai;
            A *old5=Is;
            Titl=new B[newSize];
            Typ=new B[newSize];
            Auth=new B[newSize];
            Avai=new A[newSize];
            Is=new A[newSize];
            //Copy old elements in new array
            for(A i=0; i<length; i++)
            {
                Titl[i]=old1[i];
                Typ[i]=old2[i];
                Auth[i]=old3[i];
                Avai[i]=old4[i];
                Is[i]=old5[i];
            }
            //final delete old array
            delete []old1;
            delete []old2;
            delete []old3;
            delete []old4;
            delete []old5;

        }
        else
        {
            cout<<"New Size Must be Larger than current size\n";
        }

    }
//Borrow a book
    void Borrow()
    {
        B titleBorrow;
        cout<<"Enter the title of the book you want: " ;
        cin>>titleBorrow;
        cout<<endl;
        A indx= Search(titleBorrow);
        if(indx>=0 && Avai[indx]>0)
        {
            Avai[indx]-=1;
            NumBorrow++;

        }
        else
        {
            cout<<"Unavailable"<<endl;
        }
    }
    //Number of books available
    A getAvailable()
    {
        A TotalAv=0;
        for(A i=0; i<length; i++)
        {
            TotalAv+=Avai[i];
        }
        return TotalAv;
    }
    //Number of books borrowed
    A getBorrow()
    {
        return NumBorrow;
    }

};
int main()
{
    system("color 74");
    int siz;
    cout<<"Enter the store size: ";
    cin>>siz;
    cout<<endl;
    Library <int,string> obj(siz);
    Sleep(500);
    system("cls");
    char z;
    do
    {
        char x;
        cout<<"Do you want to access the Administration section [A] or the Client section [C]? ";
        cin>>x;
        Sleep(500);
        system("cls");
        if(x=='A' || x=='a')
        {
            system("color 71");

            int choic;
            do
            {
                cout<<"Choose what you want to do...\n";
                cout<<"1. Fill Store\n";
                cout<<"2. Add New Element\n";
                cout<<"3. Sort Store\n";
                cout<<"4. Change Size Current Store\n";
                cout<<"5. Show how many books are borrowed\n";
                cout<<"6. Show the number of books available\n";
                cout<<"7. Delete a selected item\n";
                cout<<"0. Return to the main interface\n";
                cin>>choic;
                Sleep(500);
                system("cls");
                if(choic==1)
                {
                    system("color 75");
                    obj.Fill();
                    Sleep(1000);
                    system("cls");
                }
                else if(choic==2)
                {
                    system("color 75");
                    int indx;
                    cout<<"Enter the new element position first: ";
                    cin>>indx;
                    cout<<endl;
                    obj.Add(indx);
                    Sleep(1000);
                    system("cls");

                }
                else if(choic==3)
                {
                    system("color 75");
                    obj.Sort();
                    Sleep(500);
                    system("cls");

                }
                else if(choic==4)
                {
                    system("color 75");
                    obj.ChangeSize();
                    Sleep(500);
                    system("cls");

                }
                else if(choic==5)
                {
                    system("color 75");
                    cout<<"The total number of books borrowed is =>"<<obj.getBorrow()<<endl;
                    Sleep(1000);
                    system("cls");

                }
                else if(choic==6)
                {
                    system("color 75");
                    cout<<"The total number of books available is =>"<<obj.getAvailable()<<endl;
                    Sleep(1000);
                    system("cls");

                }
                else if(choic==7)
                {
                    system("color 75");
                    int Index;
                    cout<<"Enter the position of the item you want to delete: ";
                    cin>>Index;
                    cout<<endl;
                    obj.Delete(Index);
                    Sleep(500);
                    system("cls");

                }
                else if(choic==0)
                {
                    system("color 75");
                    cout<<"See you soon\x02\n";
                    Sleep(1000);
                    system("cls");
                }
                else
                {
                    system("color 75");
                    cout<<"Please Enter a valid choice\n";
                    Sleep(500);
                    system("cls");

                }
            }
            while(choic!=0);
        }
        else if(x=='C' || x=='c')
        {
            system("color 71");
            int check;
            do
            {
                cout<<"Choose what you want to do...\n";
                cout<<"1. View available books\n";
                cout<<"2. Search for a specific book\n";
                cout<<"3. Would you like to borrow a book?\n";
                cout<<"0. Exit a program\n";
                cin>>check;
                Sleep(500);
                system("cls");
                if(check==1)
                {
                    system("color 72");
                    obj.Display();
                    Sleep(4000);
                    system("cls");
                }
                else if(check==2)
                {
                    system("color 72");
                    string title;
                    cout<<"Enter the title of the book you want to search for: ";
                    cin>>title;
                    cout<<endl;
                    int a=obj.Search(title);
                    if(a!=-1)
                        cout<<"It was found and position is =>"<<a<<endl;
                    else
                        cout<<"Not Found\n";
                    Sleep(2000);
                    system("cls");
                }
                else if(check==3)
                {
                    system("color 72");
                    obj.Borrow();
                    Sleep(500);
                    system("cls");
                }
                else if(check==0)
                {
                    system("color 72");
                    cout<<"We are happy to have you in our library\n";
                    Sleep(600);
                    system("cls");
                }
            }
            while(check!=0);
        }
        else
        {
            system("color 74");
            cout<<"An input error occurred!\n";
            Sleep(700);
            system("cls");
        }
        system("color 71");
        cout<<"Are You Sure Exit Y or N? ";
        cin>>z;
        cout<<endl;
        Sleep(700);
        system("cls");
    }
    while(z=='n' || z=='N');
    return 0;
}
