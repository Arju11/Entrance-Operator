#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
class ENTR                                  //class for ENTN,date
{
char ENTN[40],ins[1000];
int date[3];
public:
char cho;
void fnt()
 {
 int n=0;
 char e[8];
 strcpy(e,"E");
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 setbkcolor(1);
 setcolor(14);
 settextstyle(5,0,4);
 struct date d;
 getdate(&d);
 printf("%d ", d.da_day);
 printf("%d ", d.da_mon);
 printf("%d ", d.da_year);
 for(int l=0,x=20,y=80,z=100;l<385;l++,x++)
  {
  arc(x,y,0,90,60);
  delay(5);
  if(l==z)
   {
   setcolor(2);
   outtextxy(l,30,e);
   setcolor(14);
   z+=40;
   if(l==100){strcpy(e,"N");}
   if(l==140){strcpy(e,"T");}
   if(l==180){strcpy(e,"R");}
   if(l==220){strcpy(e,"A");}
   if(l==260){strcpy(e,"N");}
   if(l==300){strcpy(e,"C");}
   if(l==340){strcpy(e,"E");}
   }
  }
 strcpy(e,"O");
 for(int l1=100,x1=120,y1=160,z1=200;l1<485;l1++,x1++)
  {
  arc(x1,y1,0,90,60);
  delay(5);
  if(l1==z1)
   {
   setcolor(2);
   outtextxy(l1,105,e);
   setcolor(14);
   z1+=40;
   if(l1==200){strcpy(e,"P");}
   if(l1==240){strcpy(e,"E");}
   if(l1==280){strcpy(e,"R");}
   if(l1==320){strcpy(e,"A");}
   if(l1==360){strcpy(e,"T");}
   if(l1==400){strcpy(e,"O");}
   if(l1==440){strcpy(e,"R");}
   }
  }
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\tOperate new\ entrance exam(y)Continue with previous one(n) :";
 cin>>cho;
 if(cho=='y')
  {
  closegraph();
  fstream cl;
  cl.open("ANDF",ios::out);
  cl.close();
  cout<<"Instructions for operating new entrance exam\n";
  ifstream p;
  p.open("Ins");
  p.seekg(0);
  while(n<5)
   {
   p.read((char*)&ins,sizeof(ins));
   puts(ins);
   n++;
   }
  cout<<"\n\tEnter name of entrance exam:";
  gets(ENTN);
  ofstream p4;
  p4.open("ENTN");
  p4.write((char*)&ENTN,sizeof(ENTN));
  cout<<"\n\tEnter date of examination(dd mm yyyy):";
  ofstream p5;
  p5.open("DATE");
  for(int t=0;t<3;t++)
   {
   cin>>date[t];
   p5<<date[t]<<"\t";
   }
  cout<<"\n\tEnter minimum qualifications of applicant of exam\n";
  ofstream p1;
  p1.open("Ins1");
  gets(ins);
  p1.write((char*)&ins,sizeof(ins));
  cout<<"\n\tEnter Syllabus\n";
  gets(ins);
  ofstream p2;
  p2.open("Ins2");
  p2.write((char*)&ins,sizeof(ins));
  cout<<"\n\tEnter other details/Enter Nill\n";
  gets(ins);
  ofstream p3;
  p3.open("Ins3");
  p3.write((char*)&ins,sizeof(ins));
  cout<<"\n\tPress Enter";
  getch();
  }
 else if(cho=='n')
  {
  cout<<"\n\tWelcome to ";
  ifstream p4;
  p4.open("ENTN");
  p4.read((char*)&ENTN,sizeof(ENTN));
  puts(ENTN);
  cout<<"\tDate of examination(dd mm yyyy):";
  ifstream p5;
  p5.open("DATE");
  for(int t1=0;t1<3;t1++)
   {
   p5>>date[t1];
   cout<<date[t1]<<" ";
   }
  cout<<"\n\tPress Enter";
  getch();
  }
 closegraph();
 }
 char rtcho()
 {return cho;}
}entrance;
class CNDT                        //Class for candidate
{
char n[60],cst[20],sch[100],addr[100],ecn[4];
float m,admt,tm;
double brdrl;
public:
void appfom()
 {
 float phy,mat,eng,chem;
 cout<<"\n\n\n\nEnter the following details\n\n1.Name :";
 gets(n);
 cout<<"\n2.School/College :";
 gets(sch);
 cout<<"\n3.Cast (General/OBC/SC/ST) :";
 gets(cst);
 cout<<"\n4.Address(House no./Nagar/Post Office/City/State)\n ";
 gets(addr);
 cout<<"\n5.Enter roll number of 12th board exam along with the year of exam\n(Eg.If 1214 is the roll number and exam was on 2007 then write 12142007)\n";
 cin>>brdrl;
 cout<<"\n6.Enter economic status(APL/BPL):";
 gets(ecn);
 cout<<"\n7.Enter marks of the following subject in your +2 board exam in percent\n";
 cout<<"\n\t\tMathematics :";
 cin>>mat;
 cout<<"\t\tPhysics :";
 cin>>phy;
 cout<<"\t\tChemistry :";
 cin>>chem;
 cout<<"\t\tEnglish :";
 cin>>eng;
m=(mat/100)*40+(phy/100)*25+(chem/100)*15+(eng/100)*10;
 admt=0.0;
 tm=0.0;
 }
 void show()
 {
 cout<<"\n1.Name :";
 puts(n);
 cout<<"\n2.School/College :";
 puts(sch);
 cout<<"\n3.Cast (General/OBC/SC/ST) :";
 puts(cst);
 cout<<"\n4.Economic status(APL/BPL):";
 puts(ecn);
 cout<<"\n5.Address(House no./Nagar/Post Office/City/State)\n ";
 puts(addr);
 }
 float rtnadmt()
 {return admt;}
 double rtnbrl()
 {return brdrl;}
 void rtnadmt(float a)
 {admt=a;}
 float rtnmrk()
 {return m;}
 void asstm(float a)
 {tm=a;}
 float rtntm()
 {return tm;}
 void shown()
 {puts(n);};
 void assttm()
 {
 if(!strcmp(cst,"OBC"))
 tm+=1;
 if(!strcmp(cst,"SC")||!strcmp(cst,"ST"))
 tm+=2;
 if(!strcmp(ecn,"BPL"))
 tm+=3;
 }
}o[20],obj[20],bj[20],rk[20],frk[20],ob;
void main()                                      //Main function
{
entrance.fnt();
int cho,check=0;
char c,inst[1000];
beg:
clrscr();
cout<<"\n\n\n\n\n\t\t1.Guide\n\t\t2.Apply for entrance exam\n\t\t3.Check for approval\n\t\t4.Check result\n\t\t5.Confidential\n\t\t6.Exit\n\n\t\tEnter your option :";
cin>>cho;
delay(100);
clrscr();
switch(cho)
 {
 case 1:gd:                                           //Guide 
	clrscr();
	cout<<"\n\n\n\n\t\t1.How to use ENTRANCE OPERATOR\n\t\t2.Minimum qualification of applicant\n\t\t3.Syllabus\n\t\t4.Other instructions\n\t\t5.Go back to main menu\n\n\t\tEnter your option :";
	cin>>c;
	switch(c)
	 {
	 case '1':clrscr();
		  int n=0;
		  ifstream pn;
		  pn.open("Ins");
		  pn.seekg(0);
		  while(n<5)
		   {
		   pn.read((char*)&inst,sizeof(inst));
		   puts(inst);
		   n++;
		   }
		  break;
	 case '2':clrscr();
		  ifstream pn1;
		  pn1.open("Ins1");
		  pn1.read((char*)&inst,sizeof(inst));
		  puts(inst);
		  break;
	 case '3':clrscr();
		  ifstream pn2;
		  pn2.open("Ins2");
		  pn2.read((char*)&inst,sizeof(inst));
		  puts(inst);
		  break;
	 case '4':clrscr();
		  ifstream pn3;
		  pn3.open("Ins3");
		  pn3.read((char*)&inst,sizeof(inst));
		  puts(inst);
		  break;
	 case '5':goto beg;
	 default:cout<<"Wrong option";
		 goto gd;
	 }
	cout<<"Press Enter to go back";
	getch();
	goto gd;
 case 2:ofstream putd;			 //Application(Complete)
	putd.open("ANDF",ios::app|ios::binary);
	int in=0;
	appl:
	o[in].appfom();
	cout<<"Application form has been completed.\n\nPress 'R' if you want to redo\nPress 'G' to go to main menu\nPress any other key to exit\n";
	cin>>c;
	if(c=='G')
	 {
	 putd.write((char*)&o[in],sizeof(o[in]));
	 in++;
	 putd.close();
	 goto beg;
	 }
	else if(c=='R')
	 {
	 clrscr();
	 goto appl;
	 }
	else
	 {
	 putd.write((char*)&o[in],sizeof(o[in]));
	 putd.close();
	 cout<<"Closing...";
	 delay(1000);
	 exit(0);
	 }
	break;
 case 3:double brol,admtn;	   //Approval
	char vrf;
	int incr=0;
	cout<<"Enter board roll number with year of applicant to be verified:";
	cin>>brol;
	ifstream src;
	src.open("ANDF",ios::binary);
	while(src)
	 {
	 src.read((char*)&obj[incr],sizeof(obj[incr]));
	 if(obj[incr].rtnbrl()==brol)
	  {
	  obj[incr].show();
	  cout<<"Press 'v' to approve this applicant for the exam ,'r' to reject:";
	  cin>>vrf;
	  ofstream app;
	  fstream admt;
	  admt.open("ADMT",ios::binary|ios::in|ios::out);
	  if(entrance.rtcho()=='y'&&check==0)
	  {
	  app.open("APP",ios::binary|ios::out);
	  check=1;
	  }
	  else
	  app.open("APP",ios::binary|ios::app);
	  if(vrf=='v')
	   {
	   admt>>admtn;
	   admtn++;
	   obj[incr].rtnadmt(admtn);
	   admt.seekp(0);
	   admt<<admtn;
	   cout<<"The admit roll number of candidate is:"<<admtn;
	   app.write((char*)&obj[incr],sizeof(obj[incr]));
	   }
	  admt.close();
	  app.close();
	  incr++;
	  break;
	  }
	 }
	src.close();
	cout<<"\nPress 'G' to go back to main window or press any other key to exit :";
	cin>>c;
	if(c=='G')
	goto beg;
	else
	exit(0);
	break;
 case 4:float ttlm[20];
	int ad=0,ls=0,optn;
	ifstream r;			 //Result
	ofstream rnk;
	r.open("Store");
	rnk.open("RnkLst",ios::out);
	while(r)
	 {
	 r.read((char*)&rk[ad],sizeof(rk[ad]));
	 ad++;
	 }
	r.close();
	for(int k=0;k<ad;k++)
	for(int h=0;h<ad;h++)
	if(rk[h].rtntm()<rk[h+1].rtntm())
	{
	ob=rk[h];
	rk[h]=rk[h+1];
	rk[h+1]=ob;
	}
	while(ls<ad)
	 {
	 rnk.write((char*)&rk[ls],sizeof(rk[ls]));
	 ls++;
	 }
	rnk.close();
	rslt:
	clrscr();
	cout<<"\n\n\t\t\tRESULT\n\t1.Show full result\n\t2.Search for individual result\n\n\tEnter your option:";
	cin>>optn;
	clrscr();
	if(optn==1)
	for(int sh=0;sh<ad-1;sh++)
	 {
	 cout<<sh+1<<".";
	 rk[sh].shown();
	 }
	if(optn==2)
	 {
	 double broln;
	 cout<<"Enter your board roll number with year:";
	 cin>>broln;
	 ifstream showr;
	 showr.open("RnkLst");
	 ls=0;
	 while(ls<ad)
	  {
	  showr.read((char*)&ob,sizeof(ob));
	  ls++;
	  if(ob.rtnbrl()==broln)
	   {
	   cout<<"Your name is ";
	   ob.shown();
	   cout<<"Your rank is:"<<ls;
	   }
	  }
	 }
	cout<<"\nPress 'G' to go back to main window\nPress'R'to check result again\nPress any other key to exit\n";
	cin>>c;
	if(c=='G')
	goto beg;
	if(c=='R')
	goto rslt;
	else
	exit(0);
	break;
 case 5:char psw[20];                   //Entering marks(Complete)
	int inr=0;
	float mark,mark1,tmrk;
	passw:
	clrscr();
	cout<<"\n\n\n\n\n\t\t\tEnter password:";
	gets(psw);
	if(!strcmp(psw,"Bjarne*Stroustrup"))
	 {
	 cout<<"\t\t\t\tPress Enter";
	 getch();
	 clrscr();
	 cout<<"Enter marks of candidates against admit numbers given below\n";
	 fstream mrk;
	 fstream str;
	 mrk.open("APP",ios::binary|ios::in);
	 str.open("Store",ios::binary|ios::out);
	 while(mrk)
	  {
	  mrk.read((char*)&bj[inr],sizeof(bj[inr]));
	  if(bj[inr].rtnadmt()!=0)
	   {
	   cout<<inr+1<<"."<<bj[inr].rtnadmt()<<":";
	   cin>>mark;
	   mark1=bj[inr].rtnmrk();
	   tmrk=mark+mark1;
	   bj[inr].asstm(tmrk);
	   bj[inr].assttm();
	   str.write((char*)&bj[inr],sizeof(bj[inr]));
	   }
	  inr++;
	  }
	 mrk.close();
	 str.close();
	 }
	else
	{
	cout<<"\n\n\t\t\tSorry wrong password";
	cout<<"\nPress 'R' to reenter password\nPress 'G' to go back to main window or press any other key to exit :";
	if(c=='R')
	goto passw;
	if(c=='G')
	goto beg;
	else
	exit(0);
	}
	cout<<"\nPress 'G' to go back to main window or press any other key to exit :";
	cin>>c;
	if(c=='R')
	goto passw;
	if(c=='G')
	goto beg;
	else
	exit(0);
	break;
 case 6:clrscr();
	cout<<"\n\n\n\n\n\t\t\t\tClosing...";
	delay(1000);
         exit(0);
 default:cout<<"\n\n\n\n\n\t\t\t\tWrong option";
	 delay(1000);
	 goto beg;
 }
}

