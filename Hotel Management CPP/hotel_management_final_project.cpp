//Create 2 text files RoomInfo and CustInfo b4 running program

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<process.h>
#include<fstream>
#include<iomanip>
#include<math.h>
#define MAX_LENGTH 16


using namespace std;


int i;
char hc2;


void gotoxy(int,int);
void textcolor(int);
void border(int,int,int,int,int);
void delay(int);
void flush();
int login();
void lscreen();
void menu();
void sscreen();


void gotoxy(int a,int b)
{
   COORD coord={a,b};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void textcolor(int k)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),k);
}


void delay(int y)
{
   double x=pow(10,y);
   while(x!=0)
   {
       --x;
   }
}

void border(int x1,int y1,int x2,int y2,int k)
{
   textcolor(k);
   int d;
   gotoxy(x1,y1);
   cout<<setfill(char(178))<<setw(x2-x1+1)<<char(178);
   for(d=1;d<y2-y1;d++)
   {
      gotoxy(x1,y1+d);
      cout<<char(178);
      gotoxy(x2,y1+d);
      cout<<char(178);
   }
   gotoxy(x1,y2);
   cout<<setfill(char(178))<<setw(x2-x1+1)<<char(178);
}

void flush()
{
   cin.clear();
   fflush(stdin);
}


void lscreen()
{
   gotoxy(12,11);
   cout<<char(201);
   gotoxy(12,13);
   cout<<char(200);
   gotoxy(58,11);
   cout<<char(187);
   gotoxy(58,13);
   cout<<char(188);
   for(int j=0;j<45;j++)
    {
      gotoxy(13+j,11);
      cout<<char(203);
      gotoxy(13+j,13);
      cout<<char(202);
    }
   for(int i=0;i<47;i++)
    {
      gotoxy(12+i,12);
      textcolor(9);
      cout<<char(219);
      delay(7);
    }
   delay(4);
}

int login()
{
   int mc;
   char get_uname[15],keypressed;
   string password="";
   flush();
   textcolor(7);
   system("cls");
   gotoxy(30,12);
   strcpy(get_uname,"");
   gotoxy(30,15);
   cout<<"Enter 1 For Login";
   gotoxy(30,16);
   cout<<"Enter 2 Initialise DataBase";
   gotoxy(30,17);
   cin>>mc;
   switch(mc)
   {
      case 1:
      ps:
      system("cls");
      border(20,16,65,20,178);
      textcolor(9);
      gotoxy(30,17);
      cout<<"Enter Username     : ";
      gotoxy(30,18);
      cout<<"Enter Password     : ";
      textcolor(7);
      gotoxy(51,17);
      flush();
      gets(get_uname);
      gotoxy(51,18);
      for (;;)
      {
          keypressed=NULL;
          keypressed=getch();
          if (password.size() < MAX_LENGTH && ((keypressed>=60 && keypressed<=90) || (keypressed>=97 && keypressed<=122) || (keypressed>=48 && keypressed<=57) || keypressed==32))
          {
             password+=keypressed;
             cout<<"*";
          }
          else if (password.size()>0 && keypressed==8)
          {
             password.resize(password.size()-1);
             gotoxy(51,18);
             for (unsigned char l=0; l<password.size(); l++)
             cout<<"*";
             cout<<" ";
             gotoxy(51+password.size(),18);
          }
          else if (keypressed==13)
          break;
      }
      if(password=="project" && strcmp(get_uname,"hotel")==0)
      {
          return(1);
      }
      if(password!="project" && strcmp(get_uname,"hotel")==0)
      {
          system("cls");
          gotoxy(30,12);
          textcolor(4);
          cout<<"!!!!WRONG PASSWORD!!!!" ;
          getch();
          flush();
          goto ps;
      }
      if(password=="project" && strcmp(get_uname,"hotel")!=0)
      {
          system("cls");
          gotoxy(30,12);
          textcolor(4);
          cout<<"!!!!WRONG USERNAME!!!!" ;
          getch();
          flush();
          goto ps;
      }
      if(password!="project" && strcmp(get_uname,"hotel")!=0)
      {
          system("cls");
          gotoxy(25,12);
          textcolor(4);
          cout<<"!!!!BOTH USERNAME AND PASSWORD IS INCORRECT!!!!";
          getch();
          flush();
          goto ps;
      }
      break;
      case 2:
      return(2);
      break;
   }
}

void sscreen()
{
    gotoxy(25,10);
    textcolor(3);
    cout<<"Loading...Please Wait";
    lscreen();
    system("cls");
    textcolor(7);
    for(i=0;i<15;i++)
    {
        gotoxy(0,i);
        textcolor(7);
        cout<<setfill(char(219))<<setw(75)<<char(219);
        textcolor(14);
        border(20,4,60,8,3);
        gotoxy(25,6);
        cout<<"WELCOME TO HOTEL CODESTAY";
        gotoxy(8,13);
        textcolor(2);
        cout<<"#############################################################";
        gotoxy(8,14);
        cout<<"# Project Submitted By: Ashley James                        #";
        gotoxy(8,15);
        cout<<"# School              : Saraswathi Vidya Nikethan           #";
        gotoxy(8,16);
        cout<<"# Project Topic       : Hotel Mangement                     #";
        gotoxy(8,17);
        cout<<"# Class               : 12 - D                              #";
        gotoxy(8,18);
        cout<<"#############################################################";
        textcolor(7);
        delay(7);
        flush();
        gotoxy(0,25-i);
        cout<<setfill(char(219))<<setw(75)<<char(219);
        }
    getch();
}

void menu()
{
    time_t t;
    system("cls");
    t = time(NULL);
    cout<<"\n  "<<ctime(&t);
    t -= 24L*60L*60L;
    textcolor(10);
    border(0,0,60,20,7);
    system(" ");
    cout<<"\n";
    gotoxy(5,3);
    textcolor(3);
    cout<<"1.ROOM INFO             2.CUSTOMER INFO";
    gotoxy(5,4);
    cout<<"3.NEW ROOM              4.FEATURES OF ROOMS";
    gotoxy(5,5);
    cout<<"5.CHECKOUT              6.EXIT";
}

//------------------------classes--------------------------------

class rooms
{
    public:
    int rno,mem,days,dd,mm,yy;
    double charge,tcost;
    char rtype[8],cust[20],avail,date[8];
    rooms()
    {
        avail='Y';
        days=0;
    }
    void getdata()
    {
        flush();
        avail='N';
        cout<<"Enter customer name           : ";
        gets(cust);
        cout<<"Enter number of members       : ";
        cin>>mem;
        cout<<"Enter number of days          : ";
        cin>>days;
        flush();
        cout<<"Enter arrival date(DD/MM/YYYY)  : ";
        gets(date);
        process(date);
    }
    void process(char xd[8])
    {
        int i=0,k=0,dd=0,mm=0,yy=0;
        while(xd[i]!='\0')
        {
            if(xd[i]!='/' && k==0)
            {
                dd=(10*dd)+(int(xd[i])-48);
            }
            if(xd[i]!='/' && k==1)
            {
                mm=(10*mm)+(int(xd[i])-48);
            }
            if(xd[i]!='/' && k==2)
            {
                yy=(10*yy)+(int(xd[i])-48);
            }
            if(xd[i]=='/')
            {
                k++;
            }
            i++;
        }
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int DD,MM,YY;
        int tdd,tmm,tyy;
        DD=ltm->tm_mday;
        MM=1+ltm->tm_mon;
        YY=1900+ltm->tm_year;
        if(yy<YY)
        {
            cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
            getch();
            system("cls");
            getdata();
        }
        if(mm<MM && YY==yy)
        {
            cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
            getch();
            system("cls");
            getdata();
        }
        if(MM==mm)
        {
            if(dd<DD)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
            if((dd-DD)>7)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
        }
        if(MM!=mm && (MM==1||MM==3||MM==5||MM==7||MM==8||MM==10))
        {
            tdd=31-DD;
            if((dd+tdd)>7)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
        }
        if(MM!=mm && (MM==4||MM==6||MM==9||MM==11))
        {
            tdd=30-DD;
            if((dd+tdd)>7)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
        }
        if(MM!=mm && MM==2 && YY%4==0)
        {
            tdd=29-DD;
            if((dd+tdd)>7)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
        }
        if(MM!=mm && MM==2 && YY%4!=0)
        {
            tdd=28-DD;
            if((dd+tdd)>7)
            {
                cout<<"\nRoom Cannot Be Booked On The Specified Date\n";
                getch();
                system("cls");
                getdata();
            }
        }
        if(mm>12 || mm<0)
        {
            cout<<"\n\nWrong Date";
            getch();
            system("cls");
            getdata();
        }
        if((dd>30 && mm==4)||(dd>30 && mm==6)||(dd>30 && mm==9)||(dd>30 && mm==11))
        {
            cout<<"\n Wrong date";
            getch();
            system("cls");
            getdata();
        }
        if(dd>29 && mm==2 && yy%4==0)
        {
            cout<<"\n Wrong date";
            getch();
            system("cls");
            getdata();
        }
        if(dd>28 && mm==2 && yy%4!=0)
        {
            cout<<"\n Wrong date";
            getch();
            system("cls");
            getdata();
        }
        calcdod(dd,mm,yy);
    }
    void calcdod(int a,int b,int c)
    {
        if((a+days)>31 && (b==1||b==3||b==5||b==7||b==8||b==10))
        {
            dd=a+days-31;
            mm=b+1;
            yy=c;
        }
        if((a+days)<=31 && (b==1||b==3||b==5||b==7||b==8||b==10||b==12))
        {
            dd=a+days;
            mm=b;
            yy=c;
        }
        if((a+days)>31 && b==12)
        {
            dd=a+days-31;
            mm=1;
            yy=c+1;
        }
        if((a+days)>30 && (b==4||b==6||b==9||b==11))
        {
            dd=a+days-30;
            mm=b+1;
            yy=c;
        }
        if((a+days)<=30 && (b==4||b==6||b==9||b==11))
        {
            dd=a+days;
            mm=b;
            yy=c;
        }
        if((a+days)>28 && b==2 && (c%4)!=0)
        {
            dd=a+days-28;
            mm=3;
            yy=c;
        }
        if((a+days)<=28 && b==2 && (c%4)!=0)
        {
            dd=a+days;
            mm=2;
            yy=c;
        }
        if((a+days)>29 && b==2 && (c%4)==0)
        {
            dd=a+days-29;
            mm=b+1;
            yy=c;
        }
        if((a+days)<=29 && b==2 && (c%4)==0)
        {
            dd=a+days;
            mm=b;
            yy=c;
        }
    }
    void room_type(int x)
    {
        if(x>0 && x<10)
        strcpy(rtype,"Deluxe");
        if(x>=10 && x<20)
        strcpy(rtype,"Sp. Dlx");
        if(x>=20 && x<=25)
        strcpy(rtype,"Premium");
    }
    char retroom(int n)
    {
        if(n>0 && n<10)
         {
            strcpy(rtype,"Deluxe");
         }
        if(n>=10 && n<20)
         {
            strcpy(rtype,"Sp. Dlx");
         }
        if(n>=20 && n<=25)
         {
            strcpy(rtype,"Premium");
         }
        return rtype[0];
    }
    void putdata(int l)
    {
        gotoxy(0,l+2);
        cout<<rno;
        gotoxy(5,l+2);
        cout<<rtype;
        gotoxy(20,l+2);
        cout<<avail;
        gotoxy(35,l+2);
        cout<<cust;
    }
    void total(int rdays,int roomr)
    {
        if(roomr>0 && roomr<10)
        charge=0.12*(1000*rdays)+(1000*rdays);
        if(roomr>=10 && roomr<20)
        charge=0.12*(3000*rdays)+(3000*rdays);
        if(roomr>=20 && roomr<=25)
        charge=0.12*(7000*rdays)+(7000*rdays);
    }
};


class custInfo:public rooms
{
    public:
    char nat[15],city[15],mob[10];
    void getCustdata()
    {
        flush();
        cout<<"Enter City           : ";
        gets(city);
        cout<<"Enter Nationality    : ";
        gets(nat);
        cout<<"Enter Mobile Number  : ";
        gets(mob);
    }
    void putCustdata(int l)
    {
        gotoxy(0,l+2);
        cout<<rno;
        gotoxy(15,l+2);
        cout<<city;
        gotoxy(30,l+2);
        cout<<mob;
        gotoxy(45,l+2);
        cout<<nat;
    }
};

//----------main----------

int main()
{
    int h,ch,mrno,mdays,mmem,ch1,f,mavail, mdd ,mmm, myy;
    long pos,cu,pos1,pos2;
    char rt,hc;
    char mcust[20],mdate[8],mcity[20],mnat[20],mmob[10],mrtype[8];
    rooms r;
    double mcharge;
    custInfo c;
    fstream f1,f2;
    sscreen();
    f1.open("RoomInfo.txt",ios::in | ios::out | ios::binary );
    f2.open("CustInfo.txt",ios::in | ios::out | ios::binary );
    int choice;
    ch1=login();
    if(ch1==1)
    {
        restart:
        system("cls");
        xyz:
        flush();
        menu();
        gotoxy(5,8);
        textcolor(9);
        cout<<"Enter a number: ";
        cin>>choice;
        textcolor(7);
        flush();
        switch (choice)
        {
            case 1:
                   system("cls");
                   gotoxy(0,0);
                   cout<<"RNo.";
                   gotoxy(5,0);
                   cout<<"RoomType";
                   gotoxy(20,0);
                   cout<<"Availability";
                   gotoxy(35,0);
                   cout<<"Customer";
                   gotoxy(0,1);
                   cout<<setfill('-')<<setw(78)<<"-\n";
                   f1.seekg(0,ios::beg);
                   for(i=0;i<25;i++)
                   {
                    f1.read((char*) &r,sizeof(r));
                    r.putdata(i);
                    cout<<"\n";
                   }
                   getch();
                   break;
            case 2:
                   system("cls");
                   gotoxy(0,0);
                   cout<<"Room no";
                   gotoxy(15,0);
                   cout<<"City";
                   gotoxy(30,0);
                   cout<<"Mobile";
                   gotoxy(45,0);
                   cout<<"Nationality";
                   gotoxy(0,1);
                   cout<<setfill('-')<<setw(78)<<"-\n";
                   f2.seekg(0,ios::beg);
                   for(i=0;i<25;i++)
                   {
                       f2.read((char*) &c,sizeof(c));
                       c.putCustdata(i);
                       cout<<"\n";
                   }
                   getch();
                   break;
            case 3:
                   abc:
                   system("cls");
                   textcolor(7);
                   cout<<"\t\t\tWelcome,Fill up the details to reserve a room\n\n\n";
                   cout<<"***Rooms Cannot Be Booked More Than One Week In Advance***\n";
                   cout<<"choose preffered room type\n\n\n";
                   cout<<"1.Deluxe";
                   cout<<"\n2.Special Deluxe";
                   cout<<"\n3.Premium\n";
                   cout<<"4.Back to main menu\n\n";
                   cout<<"--->";
                   cin>>h;
                   switch (h)
                   {
                       case 1:
                       cout<<"\n\nAvailable rooms : ";
                       rt='D';
                       f1.seekg(0,ios::beg);
                       for(i=0;i<9;i++)
                       {
                           f1.read((char*) &r,sizeof(r));
                           if(r.avail=='Y')
                           cout<<r.rno<<" ";
                       }
                       break;
                       
                       case 2:
                       cout<<"\n\nAvailable rooms : ";
                       f1.seekg(0);
                       for(i=0;i<25;i++)
                        {
                           f1.read((char*)&r,sizeof(r));
                           if(r.rtype[0]=='S' && r.avail=='Y')
                           cout<<r.rno<<" ";
                        }
                       break;
                       
                       case 3:
                       cout<<"\n\nAvailable rooms : ";
                       f1.seekg(0);
                       for(i=0;i<25;i++)
                        {
                           f1.read((char*)&r,sizeof(r));
                           if(r.rtype[0]=='P' && r.avail=='Y')
                            {
                               cout<<r.rno<<" ";
                            }
                        }
                       break;
                       
                       case 4 :
                       system("cls");
                       gotoxy(25,10);
                       textcolor(3);
                       cout<<"Loading...Please Wait";
                       lscreen();
                       goto xyz;
                       break;     
                       
                       default:
                       textcolor(4);
                       cout<<"\n\nWrong choice";
                       textcolor(7);
                       delay(8);
                       system("cls");
                       goto abc;
                       break;
                   }
                   cout<<"\nEnter Room Number --> ";
                   cin>>mrno;
                   r.room_type(mrno);
                   system("cls");
                   gotoxy(25,10);
                   textcolor(3);
                   cout<<"Loading...Please Wait";
                   lscreen();
                   uvwx:
                   system("cls");
                   flush();
                   f1.seekg(0,ios::beg);
                   f2.seekg(0,ios::beg);
                   textcolor(7);
                   r.getdata();
                   c.getCustdata();
                   r.total(r.days,mrno);
                   mcharge=r.charge;
                   strcpy(mrtype,r.rtype);
                   strcpy(mdate,r.date);
                   r.process(mdate);
                   mmem = r.mem;
                   strcpy(mmob, c.mob);
                   strcpy(mcity, c.city);
                   strcpy(mnat, c.nat);
                   strcpy(mcust,r.cust);
                   mavail=r.avail;
                   mdays=r.days;
                   r.room_type(mrno);
                   mdd=r.dd;
                   mmm=r.mm;
                   myy=r.yy;
                   for(i=0;i<25;i++)
                   {
                       pos1=f1.tellg();
                       pos2=f2.tellg();
                       f1.read((char*)&r,sizeof(r));
                       f2.read((char*)&c,sizeof(c));
                       if(r.rno==mrno)
                       {
                           strcpy(r.cust,mcust);
                           strcpy(c.city,mcity);
                           strcpy(c.mob,mmob);
                           strcpy(c.nat,mnat);
                           strcpy(r.date,mdate);
                           r.charge=mcharge;
                           r.dd=mdd;
                           r.mm=mmm;
                           r.yy=myy;
                           r.avail=mavail;
                           f1.seekp(pos1);
                           f2.seekp(pos2);
                           f1.write((char*)&r,sizeof(r));
                           f2.write((char*)&c,sizeof(c));
                           break;
                       }
                   }
                   gotoxy(0,0);
                   system("cls");
                   border(8,0,50,15,3);
                   gotoxy(25,2);
                   textcolor(7);
                   cout<<"BOOKING CONFIRMATION";
                   textcolor(2);
                   gotoxy(10,4);
                   cout<<"Customer name         : ";
                   gotoxy(10,5);
                   cout<<"Number Of Members     : ";
                   gotoxy(10,6);
                   cout<<"Room Number           : ";
                   gotoxy(10,7);
                   cout<<"Room type             : ";
                   gotoxy(10,8);
                   cout<<"Days                  : ";
                   gotoxy(10,9);
                   cout<<"Date Of Arrival       : ";
                   gotoxy(10,10);
                   cout<<"Date Of Departure     : ";
                   gotoxy(10,11);
                   cout<<"Total Cost(12% tax)   : ";
                   delay(7);
                   r.room_type(mrno);
                   delay(7);
                   gotoxy(35,4);
                   delay(7);
                   cout<<mcust;
                   delay(7);
                   gotoxy(35,5);
                   cout<<mmem;
                   delay(7);
                   gotoxy(35,6);
                   cout<<mrno;
                   delay(7);
                   gotoxy(35,7);
                   puts(mrtype);
                   delay(7);
                   gotoxy(35,8);
                   cout<<mdays;
                   delay(7);
                   gotoxy(35,9);
                   cout<<mdate;
                   delay(7);
                   gotoxy(35,10);
                   cout<<mdd<<"/"<<mmm<<"/"<<myy;
                   delay(7);
                   gotoxy(35,11);
                   delay(7);
                   cout<<mcharge;
                   textcolor(7);
                   gotoxy(8,14);
                   cout<<"Do You Want To modify Details?(Y/N)";
                   cin>>hc;
                   if(hc=='Y'||hc=='y')
                   goto uvwx;
                   break;
            case 4:
                   efg:
                   system("cls");
                   gotoxy(0,9);
                   border(8,8,28,14,3);
                   gotoxy(10,10);
                   textcolor(3);
                   cout<<"1.Deluxe";
                   gotoxy(10,11);
                   cout<<"2.Special Deluxe";
                   gotoxy(10,12);
                   cout<<"3.Premium";
                   gotoxy(3,16);
                   textcolor(2);
                   cout<<"Enter corresponding number to view the features: ";
                   textcolor(5);
                   cin>>ch;
                   system("cls");
                   gotoxy(25,10);
                   textcolor(3);
                   cout<<"Loading...Please Wait";
                   system("cls");
                   switch(ch)
                   {
                       case 1:
                           border(21,9,40,19,3);
                           gotoxy(23,11);
                           cout<<"BED:        2";
                           gotoxy(23,12);
                           cout<<"AC:       YES";
                           gotoxy(23,13);
                           cout<<"GEYSER:    NO";
                           gotoxy(23,14);
                           cout<<"TV:        NO";
                           gotoxy(23,15);
                           cout<<"WiFi:      NO";
                           gotoxy(23,16);
                           cout<<"EXTRA BED: NO";
                           getch();
                           break;
                       case 2:
                           border(21,9,40,19,3);
                           gotoxy(23,11);
                           cout<<"BED:         2";
                           gotoxy(23,12);
                           cout<<"AC:        YES";
                           gotoxy(23,13);
                           cout<<"GEYSER:    YES";
                           gotoxy(23,14);
                           cout<<"TV:         NO";
                           gotoxy(23,15);
                           cout<<"WiFi:       NO";
                           gotoxy(23,16);
                           cout<<"EXTRA BED: YES";
                           getch();
                           break;
                       case 3:
                           border(21,9,40,19,3);
                           gotoxy(23,11);
                           cout<<"BED:         2";
                           gotoxy(23,12);
                           cout<<"AC:        YES";
                           gotoxy(23,13);
                           cout<<"GEYSER:    YES";
                           gotoxy(23,14);
                           cout<<"TV:        YES";
                           gotoxy(23,15);
                           cout<<"WiFi:      YES";
                           gotoxy(23,16);
                           cout<<"EXTRA BED: YES";
                           getch();
                           break;
                       default:
                       system("cls");
                       cout<<"Wrong choice";
                       delay(8);
                       goto efg;
                       break;
                   }
                   gotoxy(23,20);
                   cout<<"Do you want to view features of rooms(Y/N): ?";
                   cin>>hc;
                   if(hc=='Y'||hc=='y')
                   goto efg;
                   if(hc=='N'||hc=='n')
                   goto xyz;
                   break;
            case 5:
                   system("cls");
                   cout<<"Enter room number: ";
                   cin>>mrno;
                   f1.seekg(0,ios::beg);
                   f2.seekg(0,ios::beg);
                   for(i=0;i<25;i++)
                   {
                       f1.read((char*)&r,sizeof(r));
                       f2.read((char*)&c,sizeof(c));
                       if(mrno==r.rno)
                           {
                           pos1=f1.tellg();
                           pos2=f2.tellg();
                           break;
                           }
                   }
                   f1.seekg(pos1-sizeof(r));
                   f2.seekg(pos2-sizeof(c));
                   f1.read((char*)&r,sizeof(r));
                   f2.read((char*)&c,sizeof(c));
                   if(r.avail=='N')
                   {
                   cout<<"\nName:             "<<r.cust;
                   cout<<"\nRoom type:        "<<r.rtype;
                   cout<<"\ntotal cost:       "<<r.charge;
                   cout<<"\n\nTotal cost is inclusive of tax,room service & Extra Bed";
                   cout<<"\n\nPress any key to print bill";
                   getch();
                   system("cls");
                   cout<<"\n\n\tThank You...Do Visit Us Again\n\n\n";
                   for(i=0;i<25;i++)
                   {
                       f1.seekp(pos1-sizeof(r),ios::beg);
                       f2.seekp(pos2-sizeof(c),ios::beg);
                       r.rno=mrno;
                       strcpy(r.cust,"None");
                       r.avail='Y';
                       f1.write((char*)&r,sizeof(r));
                       strcpy(c.city,"N.A");
                       strcpy(c.mob,"N.A");
                       strcpy(c.nat,"N.A");
                       f2.write((char*)&c,sizeof(c));
                   }
            }
            else
            {
            cout<<"Account does not exist";
            getch();
            goto xyz;
            }
            break;
        case 6:
               system("cls");
               cout<<"Thank you,Do visit us again";
               getch();
               delay(8);
               exit(0);
               break;
               default:
               gotoxy(5,10);
               cout<<"Wrong choice";
               delay(8);
               goto xyz;
        }
        fgh:
        cout<<"\n\tYou will be redirected to main menu screen shortly";
        textcolor(7);
        delay(8);
        delay(7);
        goto xyz;
    }
    else if(ch1==2)
    {
        for(i=0;i<25;i++)
        {
            r.rno=i+1;
            r.room_type(i+1);
            r.avail='Y';
            r.charge=0;
            r.tcost=0;
            strcpy(r.date,"1/1/2014");
            strcpy(r.cust,"None");
            f1.write((char*) &r,sizeof(r));
        }
        for(i=0;i<25;i++)
        {
            c.rno=i+1;
            strcpy(c.city,"N.A");
            strcpy(c.mob,"N.A");
            strcpy(c.nat,"N.A");
            f2.write((char*) &c,sizeof(c));
        }
        system("cls");
        gotoxy(22,10);
        textcolor(3);
        cout<<"DataBase initialising...Please Wait";
        lscreen();
        system("cls");
        cout<<"Data Base Initialised...Press Any Key To Restart";
        getch();
        login();
        goto restart;
    }
    return 0;
}




