#include<iostream>
using namespace std;
#include<vector>
#define PI 3.14

class Shape {
public:
	virtual ~Shape(){}
	virtual double getArea() {return 0;}
	virtual int type(){
		return 0;
	}
};

class Parallelogram:public Shape{
protected:
	double base, side;
	double height;
public:
	Parallelogram(){base = 0; side = 0; height = 0;}
	Parallelogram(double b, double s, double h){base = b; side = s; height = h;}

	void nhap(){
		cout<<"Nhap day:"; cin>>base; cout<<endl;
		cout<<"Nhap canh ben:"; cin>>side; cout<<endl;
		cout<<"Nhap chieu cao:"; cin>>height; cout<<endl;
	}
	virtual double getArea() {return base*height;}
	virtual int type(){
		return 1;
	}
};

class Rectangle:public Parallelogram{
public:
	Rectangle(){base = 0; side = 0; height = 0;}
	
	void nhap(){
		cout<<"Nhap chieu dai:"; cin>>base; cout<<endl;
		cout<<"Nhap chieu rong:"; cin>>height; cout<<endl;
	}	
	virtual int type(){
		return 2;
	}
};

class Square:public Rectangle{
public:
	Square(){base = 0; side = 0; height = 0;}
	
	void nhap(){
		cout<<"Nhap canh:"; cin>>base; cout<<endl;
	}	
	virtual double getArea() {return base*base;}
	virtual int type(){
		return 3;
	}
};

class Ellipse:public Shape{
protected:
	double a, b;
public:
	Ellipse(){a = 0; b = 0;}

	void nhap(){
		cout<<"Nhap a:"; cin>>a; cout<<endl;
		cout<<"Nhap b:"; cin>>b; cout<<endl;
	}
	virtual double getArea() {return a*b*PI;}
	virtual int type(){
		return 4;
	}
};

class Circle:public Ellipse{
public:
	Circle(){a = 0; b = 0;}

	void nhap(){
		cout<<"Nhap ban kinh:"; cin>>a; cout<<endl;	
	}
	virtual double getArea() {return a*a*PI;}
	virtual int type(){
		return 5;
	}
};

class Triangle:public Shape{
private:
	double base, height;
public:
	Triangle(){base = 0; height = 0;}

	void nhap(){
		cout<<"Nhap day:"; cin>>base; cout<<endl;
		cout<<"Nhap chieu cao:"; cin>>height; cout<<endl;
	}
	virtual double getArea() {return base*height*0.5;}
	virtual int type(){
		return 6;
	}

};
void nhap(vector<Shape*> &ds){
	int n;
	cout<<"Ban muon nhap bao nhiu hinh: ";
	cin>>n;

	int choice;
	int a,b,c;
	for(int i=0;i<n;i++){
		cout<<"Ban muon nhap hinh gi? "<<"(1: Hinh Binh Hanh,"<<"2: Hinh Chu nhat,"<<"3: Hinh vuong,"<<"4: Ellipse,"<<"5: Hinh tron,"<<"6:Tam giac)"<<endl;
		cin>>choice; 

		if(choice==1){		
			Parallelogram* temp = new Parallelogram();
			temp->nhap();
			ds.push_back(temp);	
		}
		else if(choice==2){		
			Rectangle* temp = new Rectangle();
			temp->nhap();
			ds.push_back(temp);	
		}
		else if(choice==3){		
			Square* temp = new Square();
			temp->nhap();
			ds.push_back(temp);	
		}
		else if(choice==4){		
			Ellipse* temp = new Ellipse();
			temp->nhap();
			ds.push_back(temp);	
		}
		else if(choice==5){		
			Circle* temp = new Circle();
			temp->nhap();
			ds.push_back(temp);	
		}
		else{
			Triangle* temp = new Triangle();
			temp->nhap();
			ds.push_back(temp);	
		}
		cout<<endl;
	}
}

void tongDienTich(vector<Shape*> &ds){
	int n=ds.size();
	float sum=0;

	for(int i=0;i<n;i++){
		if(ds[i]->type()==1)
			sum += ds[i]->getArea();
		else if(ds[i]->type()==2)
			sum += ds[i]->getArea();
		else if(ds[i]->type()==3)
			sum += ds[i]->getArea();
		else if(ds[i]->type()==4)
			sum += ds[i]->getArea();
		else if(ds[i]->type()==5)
			sum += ds[i]->getArea();
		else if(ds[i]->type()==6)
			sum += ds[i]->getArea();
	}
	cout<<"Tong dien tich la:"<<sum<<endl;
}

void xoaBonho(vector<Shape*> &ds){
	int n=ds.size();
	for(int i=0;i<n;i++){
		delete ds[i];
	}
}


void main(){
	
	vector <Shape *> ds;
	nhap(ds);
	tongDienTich(ds);
	xoaBonho(ds);
	
}