#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include <dos.h>
#include <conio.h>
int X[50][50],P[50][50];
void display(int n,int b[50][50])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}
void graphics(int n,int mul[50][50])
{
	int i=0;
	line(320,0,320,500);
	line(0,250,700,250);
	while(i!=n)
	{
		if(mul[i][1]==0)
		{
		line(mul[i][0]+320,mul[i][2]+250,mul[i+1][0]+320,mul[i+1][2]+250);
		}
		else if(mul[i][0]==0)
		{
		line(mul[i][1]+320,mul[i][2]+250,mul[i+1][1]+320,mul[i+1][2]+250);
		}
		else
		{
		line(mul[i][1]+320,mul[i][2]+250,mul[i+1][1]+320,mul[i+1][2]+250);
		}
		i++;
	}
	while(i==n)
	{
		if(mul[i][1]==0)
		{
		line(mul[i][0]+320,mul[i][2]+250,mul[0][0]+320,mul[0][2]+250);
		}
		else if(mul[i][0]==0)
		{
		line(mul[i][1]+320,mul[i][2]+250,mul[0][1]+320,mul[0][2]+250);
		}
		else
		{
		line(mul[i][1]+320,mul[i][2]+250,mul[0][1]+320,mul[0][2]+250);
		}
		i++;
	}
	getch();
}

void multi(int n, int a[50][50],int b[50][50])
{       //cleardevice();
	int mul[50][50];
	//Multipliaction of two matrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			mul[i][j]=0;
			for(int k=0;k<4;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}

	}
	delay(50);
	graphics(n,mul);
}

void projection()
{
	int ch;
	cout<<"\n1. Projection in x direction\n2. Projection in y direction\n3. Projection in z direction\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(i==j&&i!=0)
				{
				P[i][j]=1;
				}
				else
				{
				P[i][j]=0;
				}
			}
		}
		break;
		case 2:
		for(i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(i==j&&i!=1)
				{
				P[i][j]=1;
				}
				else
				{
				P[i][j]=0;
				}
			}
		}
		break;
		case 3:
		for(i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(i==j&&i!=2)
				{
				P[i][j]=1;
				}
				else
				{
				P[i][j]=0;
				}
			}
		}
		break;
	}

}

void translation(int n,int b[50][50])
{
	//P for the projection matrix;
	int T[50][50],x,y,z;
	cout<<"\nTranslation in X direction\n";
	cin>>x;
	cout<<"Translation in y direection\n";
	cin>>y;
	cout<<"Translation in z direction\n";
	cin>>z;
	for(int i=0;i<n;i++)
	{
		T[i][0]=b[i][0]+x;
		T[i][1]=b[i][1]+y;
		T[i][2]=b[i][2]+z;
		T[i][3]=b[i][3];
	}
	display(n,T);
	projection();
	delay(1500);
	cleardevice();
	multi(n,b,P);
	multi(n,T,P);
}
void scaling(int n, int b[50][50])
{

	int x_s=0,y_s=0,z_s=0;
	int S[50][50];
	cout<<"Enter the Scaling Factor in x direction: ";
	cin>>x_s;
	cout<<"Enter the Scaling Factor in y direction: ";
	cin>>y_s;
	cout<<"Enter the Scaling Factor in z direction: ";
	cin>>z_s;
	for(int i=0;i<n;i++)
	{
		S[i][0]=b[i][0]*x_s;
		S[i][1]=b[i][1]*y_s;
		S[i][2]=b[i][2]*z_s;
		S[i][3]=b[i][3];
	}
	display(n,S);
	cout<<"Original Figure is in WHITE SHADE\nScaled Figure is in RED SHADE\n";
	projection();

	delay(1500);
	cleardevice();
	multi(n,b,P);
	setcolor(RED);
	multi(n,S,P);
}
void rotation(int n, int b[50][50])
{
	int R[50][50],Rx[50][50],Ry[50][50],Rz[50][50];
	int angle;
	cout<<"Enter the angle for rotation: ";
	cin>>angle;
	angle= (angle*3.14159265)/180;
	cout<<angle<<endl;
	int a;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j)
			{
				Rx[i][j]=1;
			}
			else
			{
				Rx[i][j]=0;
			}
		}
	}
	Rx[1][1]=cos(angle);
	Rx[1][2]=sin(angle);
	Rx[2][1]=-sin(angle);
	Rx[2][2]=cos(angle);
	cout<<"Rotation matrix in X direction\n";
	display(4,Rx);

	// for rotation in y axis
	for(i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j)
			{
				Ry[i][j]=1;
			}
			else
			{
				Ry[i][j]=0;
			}
		}
	}
	Ry[0][0]=cos(angle);
	Ry[2][0]=sin(angle);
	Ry[0][2]=-sin(angle);
	Ry[2][2]=cos(angle);
	cout<<"Rotation matrix in Y direction\n";
	display(4,Ry);

	// for rotation in z axis
	for(i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j)
			{
				Rz[i][j]=1;
			}
			else
			{
				Rz[i][j]=0;
			}
		}
	}
	Rz[0][0]=cos(angle);
	Rz[1][0]=-sin(angle);
	Rz[1][1]=cos(angle);
	Rz[0][1]=sin(angle);
	cout<<"Rotation matrix in Z direction\n";
	display(4,Rz);
	cout<<"Enter:\n1.Rotation in x direction\n2. Rotation in y direction\n3. Rotation in z direction\n";
	cin>>a;
	int mul_rot[50][50];
	switch(a)
	{
	case 1:
	//Multipliaction of two matrix in x axis
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			mul_rot[i][j]=0;
			for(int k=0;k<4;k++)
			{
				mul_rot[i][j]+=b[i][k]*Rx[k][j];
			}
		}

	}
	projection();
	multi(n,b,P);
	setcolor(RED);
	display(n,mul_rot);
	delay(100);
	graphics(n,mul_rot);
       //	multi(n,mul_rot,P);

	break;

	case 2:
	//Multipliaction of two matrix in y axis
	for(i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			mul_rot[i][j]=0;
			for(int k=0;k<4;k++)
			{
				mul_rot[i][j]+=b[i][k]*Ry[k][j];
			}
		}

	}
	projection();
	multi(n,b,P);
	setcolor(RED);
	display(n,mul_rot);
	delay(100);
	graphics(n,mul_rot);
       //	multi(n,mul_rot,P);
	break;

	case 3:
	//Multipliaction of two matrix in z axis
	for(i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			mul_rot[i][j]=0;
			for(int k=0;k<4;k++)
			{
				mul_rot[i][j]+=b[i][k]*Rz[k][j];
			}
		}

	}
	projection();
	multi(n,b,P);
	setcolor(RED);
	display(n,mul_rot);
	delay(100);
	graphics(n,mul_rot);
	break;
	}


}
void reflection(int n, int b[50][50])
{
	int ref[50][50];
	int ch;
	cout<<"\n1.Reflection in x axis\n2.Reflection in y axis\n3.Reflection in z axis\n";
	cout<<"\n4.Reflection in x-y axis\n5.Reflection in y-z axis\n6.Reflection in x-z axis\n";
	cout<<"\n7Reflection in x-y-z axis\n";
	cin>>ch;
	switch(ch)
	{
		case 1://x axis
		for(int i=0;i<n;i++)
		{
		ref[i][0]=-b[i][0];
		ref[i][1]=b[i][1];
		ref[i][2]=b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 2://y axis
		for(i=0;i<n;i++)
		{
		ref[i][0]=b[i][0];
		ref[i][1]=-b[i][1];
		ref[i][2]=b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 3://z axis
		for( i=0;i<n;i++)
		{
		ref[i][0]=b[i][0];
		ref[i][1]=b[i][1];
		ref[i][2]=-b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 4://x-y axis
		for( i=0;i<n;i++)
		{
		ref[i][0]=-b[i][0];
		ref[i][1]=-b[i][1];
		ref[i][2]=b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 5: //y-z axis
		for( i=0;i<n;i++)
		{
		ref[i][0]=b[i][0];
		ref[i][1]=-b[i][1];
		ref[i][2]=-b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 6: //x-z axis
		for( i=0;i<n;i++)
		{
		ref[i][0]=-b[i][0];
		ref[i][1]=b[i][1];
		ref[i][2]=-b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
		case 7:// x-y-z axis
		for( i=0;i<n;i++)
		{
		ref[i][0]=-b[i][0];
		ref[i][1]=-b[i][1];
		ref[i][2]=-b[i][2];
		ref[i][3]=b[i][3];
		}
		break;
	}
	projection();
	delay(1500);
	cleardevice();
	multi(n,b,P);
	setcolor(RED);
	delay(100);
	multi(n,ref,P);

}
void shearing(int n,int b[50][50])
{
	int x_sh,y_sh,z_sh,Sh[50][50];
	int ch;
	cout<<"\n1. Shearing in x direction";
	cin>>x_sh;
	cout<<"\n2. Shearing in y direction";
	cin>>y_sh;
	cout<<"\n3. Shearing in z direction\n";
	cin>>z_sh;
	for(int i=0;i<n;i++)
	{
	Sh[i][0]=b[i][0]+b[i][1]+b[0][2]*x_sh;
	Sh[i][1]=b[i][0]*y_sh+b[i][1]+b[i][2];
	Sh[i][2]=b[i][0]+b[i][2]+b[i][1]*z_sh;
	Sh[i][3]=b[i][3];
	}
	projection();

	delay(1500);
	cleardevice();
	multi(n,b,P);
	setcolor(RED);
	delay(100);
	multi(n,Sh,P);


}

void main()
{
	clrscr();
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	int n;;
	cout<<"Enter the total number of vertex :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the co-ordiantes in vertex "<<i+1<<": ";
		cin>>X[i][0]>>X[i][1]>>X[i][2];
		X[i][3]=1;
	}
	display(n,X);
	int choice;
	cout<<"\n1.Translation\n2.Rotation\n3.Reflection\n4.Scaling\n5.Shearing\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		translation(n,X);
		break;
		case 2:
		rotation(n,X);
		break;
		case 3:
		reflection(n,X);
		break;
		case 4:
		scaling(n,X);
		break;
		case 5:
		shearing(n,X);
		break;
	}
	getch();
}


