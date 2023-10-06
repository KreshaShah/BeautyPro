#include<iostream.h>
#include<conio.h>
#include<string.h>
class beautyproduct
{
	int code,qty;
	char name[25],brand[20],shade[15];
	float price;
public:
	static int total_product;
	static float bill;
	void insert_product();
	void getdata();
	static int search (beautyproduct p[n], char str[30]);
	static void purchase (beautyproduct p[n]);
	static void recordoflist (beautyproduct p[n]);
	static float totalvaluation (beautyproduct p[n]);
};
int beautyproduct::total_product;
float beautyproduct::bill;

	void beautyproduct::insert_product()
	{
	cout<<"Product Name=";
	cin>>name;
	cout<<"\nBrand=";
	cin>>brand;
	cout<<"\nShade=";
	cin>>shade;
	cout<<"\nCode=";
	cin>>code;
	cout<<"\nPrice=";
	cin>>price;
	cout<<"\nQuantity=";
	cin>>qty;
	}

void beautyproduct::getdata()
{
cout<<"Here are the details of your entered product"<<endl;
cout<<"Product name="<<name<<endl;
cout<<"Brand="<<brand<<endl;
cout<<"Shade="<<shade<<endl;
cout<<"Code="<<code<<endl;
cout<<"Price="<<price<<endl;
cout<<"Quantity="<<qty<<endl;
}

	int beautyproduct::search(beautyproduct p[], char str[30])
	{
	char pname[30];
	int i;
	cout<<"Enter the name of the product you want to search"<<str<<endl;
	cin>>pname;
		for(i=0;i<total_product;i++)
		{
			if(strcmp(p[i].name,pname)==0)
			return i;
		}
		return -1;
	}
void beautyproduct::purchase(beautyproduct p[])
{
int id,pqty,pn,i;
char cname[30];
float ptotal;
cout<<"How many products do you want to purchase?"<<endl;
cin>>pn;
	for(i=0;i<pn;i++)
	{
	ptotal=0;
	id=search(p,"Purchase");
		if(id==-1)
		{
		cout<<"Product is not available."<<endl<<"Please try to buy some other product"<<endl;
		//return -1;
		}
			else
			{
			cout<<"Enter the quantity to be purchased"<<endl;
			cin>>pqty;
				if(p[id].qty-pqty<0)
				{
				cout<<"The quantity is not enough for you to buy"<<endl<<"Please try again next time"<<endl;
				}
					else
					{
					ptotal=p[id].price*pqty;
					p[id].qty=pqty;
					bill+=ptotal;
					cout<<"Product name="<<p[id].name<<endl;
					cout<<"Brand="<<p[id].brand<<endl;
					cout<<"Shade="<<p[id].shade<<endl;
					cout<<"Code="<<p[id].code<<endl;
					cout<<"Price="<<p[id].price<<endl;
					cout<<"Quantity you purchased="<<pqty<<endl;
					cout<<"Your total becomes="<<ptotal<<endl;
					}
			}
	}
if(bill>0)
{
cout<<"Enter your Name="<<endl;
cin>>cname;
cout<<"****************"<<endl;
cout<<"THANK YOU" << cname <<endl;
cout<<"Your total bill amount"<<bill<<endl;
cout<<"DO VISIT AGAIN!!!"<<endl;
cout<<"****************"<<endl;
}
	else
	{
	cout<<"****************"<<endl;
	cout<<"You were unable to purchase the beauty products"<<endl;
	cout<<"THANK YOU!!! DO VISIT AGAIN"<<endl;
	cout<<"****************"<<endl;
	}
}
	void beautyproduct::recordoflist(beautyproduct p[])
	{
	cout<<"The following beauty products are to be recorded soon"<<endl;
	cout<<"Product name="<<endl<<"Brand="<<endl<<"Shade="<<endl<<"Code="<<endl<<"Price="<<endl<<"Quantity="<<endl;
	for(int i=0;i<total_product;i++)
	{
	if(p[i].qty<=10)
	p[i].getdata();
	}
	}
float beautyproduct::totalvaluation(beautyproduct p[])
{
float total=0.0;
int i;
for(i=0;i<total_product;i++)
total+=p[i].price*p[i].qty;
return total;
}
void main()
{
clrscr();
beautyproduct p[100];
int i,n,user,choice,id,sid,eid,true;
cout<<"WELCOME TO BEAUTY PRODUCT SOFTWARE"<<endl;
cout<<"Follow the following instructions to use the software:"<<endl;
sid=0;
	while(true)
	{
	cout<<"\t\t\t***** MAIN MENU *****"<<endl;
	cout<<"Press"<<endl;
	cout<<" 1 -> ADD  NEW BEAUTY PRODUCTS"<<endl;
	cout<<" 2 -> DISPLAY ALL THE BEAUTY PRODUCTS"<<endl;
	cout<<" 3 -> SEARCH ANY BEAUTY PRODUCT"<<endl;
	cout<<" 4 -> PURCHASE ANY BEAUTY PRODUCT"<<endl;
	cout<<" 5 -> TOTAL INVESTMENT YOU MADE WHILE PURCHASING"<<endl;
	cout<<" 6 -> SOME BEAUTY PRODUCTS THAT ARE TO BE REORDERED"<<endl;
	cout<<"***PRESS ANY OTHER KEY TO ESCAPE***"<<endl;
	cout<<"Kindly enter your choice"<<endl;
	cin>>choice;
		switch(choice)
		{
		case 1:cout<<"How many new beauty products do you want to enter??"<<endl;
		       beautyproduct::total_product=beautyproduct::total_product+n;
		       for(i=sid;i<beautyproduct::total_product;i++)
		       {
		       p[i].insert_product();
		       }
		       sid=i;
		       cout<<"Total existing records are:"<<beautyproduct::total_product<<endl;
		       clrscr();
		       break;
		case 2:if(beautyproduct::total_product>0)
		       {
		       cout<<"Product name="<<endl<<"Brand="<<endl<<"Shade="<<endl<<"Code="<<endl<<"Price="<<endl<<"Quantity="<<endl;
		       for(i=0;i<beautyproduct::total_product;i++)
		       {
		       p[i].getdata();
		       }
		       }
		       else
		       {
		       cout<<"!!!WARNING!!!"<<endl;
		       cout<<"Please add some products at first"<<endl;
		       }
		       break;
		case 3:if(beautyproduct::total_product>0)
		       {
		       id=beautyproduct::search(p,"Search");
		       if(id==-1)
		       cout<<"PRODUCT NOT FOUND"<<endl;
		       else
		       {
		       cout<<"Product found!!"<<endl<<"Details are as below"<<endl;
		       cout<<"Product name="<<endl<<"Brand="<<endl<<"Shade="<<endl<<"Code="<<endl<<"Price="<<endl<<"Quantity="<<endl;
		       p[id].getdata();
		       }
		       }
		       else
		       {
		       cout<<"!!!WARNING!!!"<<endl;
		       cout<<"Please add some products at first"<<endl;
		       }
		       break;
		case 4:if(beautyproduct::total_product>0)
		       {
		       beautyproduct::bill=0;
		       beautyproduct::purchase(p);
		       }
		       else
		       {
		       cout<<"!!!WARNING!!!"<<endl;
		       cout<<"Please add some products at first"<<endl;
		       }
		       break;
		case 5:cout<<"The total valuation="<<beautyproduct::totalvaluation(p)<<endl;
		       break;
		case 6:if(beautyproduct::total_product>0)
		       {
		       beautyproduct::recordoflist(p);
		       }
		       else
		       {
		       cout<<"!!!WARNING!!!"<<endl;
		       cout<<"Please add some products at first"<<endl;
		       }
		       break;
		default:cout<<"End of the program"<<endl;
			break;
		}
		}
getch();
}

