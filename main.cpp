#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define z int
z waitf=0,turnf=0;
z waits=0,turns=0;
z time=0,flag;
z kf=0,ks=0;
z totalp;
void tot(int a)
{
	totalp=totalp+a;
}


z ti(z a)
{
	z i=1000-a-40;
	i=((i/100)*60)+(i%100);
	return i;
}

z ti1(int a,z b)
{
	a=a-b-40;
	if(a<0)
	return 0;
	else
	return a;
}

z cut( z a)
{
	if(a-60<0)
	return 1000+a;
	else
	{
		return 1000+100+a-60;	
	}	
}

struct st
{
	z bust;
	z ariv;
	struct st *next;
}*start,*rep;
struct ft
{
	z bust;
	z ariv;
	struct ft *next;
}*start1,*rep1;

ft* fc(z b,z a)
{
	struct ft *temp;
	temp= new struct ft;
	temp->bust=b;
	temp->ariv=a;
	temp->next=NULL;
	return temp;
}

st* sc(z b,z a)
{
	struct st *temp;
	temp= new struct st;
	temp->bust=b;
	temp->ariv=a;
	temp->next=NULL;
	return temp;
}

void ins(z b,z a)
{
	struct st *node1,*p;
	node1=sc(b,a);
	if(start == NULL)
	{
		start =node1;
		start->next=NULL;
	}
	else
	{
		p=start;
		start = node1;
		start->next=p;
	}
}
void inf(z b,z a)
{
	struct ft *node1,*p;
	node1=fc(b,a);
	if(start1 == NULL)
	{
		start1 =node1;
		start1->next=NULL;
	}
	else
	{
		p=start1;
		start1 = node1;
		start1->next=p;
	}
}
void dis()
{
	struct ft *ptr;
	ptr=start1;
	while(ptr!=NULL)
	{
		cout<<ptr->bust<<"\t and arrival time is"<<ptr->ariv<<endl;
		ptr=ptr->next;
	}
}
z main()
{
	printf("\t\tWelcome to process menagement\n");
	z p=1,facc=0,stuc=0;
	while(p)
	{
		system("cls");
		printf("1.student and 2. Faculty\n Enter your respone:- ");
		z q,b,a;
		scanf("%d",&q);
		if(q==1)
		{
			printf("Enter the bust time: ");
			scanf("%d",&b);
			printf("Enter Arival time: ");
			scanf("%d",&a);
			ins(b,a);
			stuc++;
		}
		else if(q==2)
		{
			printf("Enter the bust time: ");
			scanf("%d",&b);
			printf("Enter Arival time: ");
			scanf("%d",&a);
			inf(b,a);
			facc++;
		}
		else
		printf("choose wisely\n");
		printf("PRESS 1 TO CONTINUE else PRESS 0\t");
		scanf("%d",&p);
	}
	
	z i=0,j=0;
	z bs[stuc],as[stuc],rs[stuc],wts[stuc];
	z bf[facc],af[facc],rf[facc],wtf[facc];
	
	if(stuc)
	{
	while(start!=NULL)
	{
		bs[i]=start->bust;
		wts[i]=start->ariv;
		wts[i]=ti(wts[i]);
		rs[i]=bs[i];
		start=start->next;
		i++;
	}
	}
	if(facc)
	{
	while(start1!=NULL)
	{
		bf[j]=start1->bust;
		wtf[j]=start1->ariv;
		//wtf[j]=ti(wtf[i]);
		rf[j]=bf[j];
		start1=start1->next;
		j++;
	}}
	
	z per=(z)120/(stuc+facc);
	//clrscn();
	printf("Hello Sudesh Today You have %d process to process    \n",stuc+facc);
	printf("With %d are from student and %d from faculty         \n",stuc,facc);
	printf("So per process you will give only %d of time         \n",per);
	//sum=0;
	printf("\n\t%d %d\n",stuc,facc);
	if(facc>0 && time<120)
	{
	for(i=0;i<facc/2;i++)
	{
		swap(bf[i],bf[facc-i-1]);
		swap(rf[i],rf[facc-i-1]);
		swap(wtf[i],wtf[facc-i-1]);
	}
	for(i=0;i<facc;i++)
	{
		wtf[i]=ti(wtf[i]);
	}
	z x;
	i=0;
	m:
	x=time;
	for(z i=0;i<facc;i++)
	{
		x+=bf[i];
	}
	if(x>120)
	{
		facc--;
		printf("Faculty %d time exceed\n",facc+1);
		goto m;
	}
	
	z bff[facc],rff[facc],wtff[facc];
	for(z j=0;j<facc;j++)
	{
		bff[j]=bf[j];
		rff[j]=rf[j];
		wtff[j]=wtf[j];
	}
	
	z k=facc;
	tot(k);
	for(time=0,i=0;facc!=0;)
	{
		if(bff[i]<=per && bff[i]>0)
		{
			
			time+=bff[i];
			bff[i]=0;
			flag=1;
		}
		else if(bff[i]>0)
		{
			bff[i]-=per;
			time+=per;
		}
		if(bff[i]==0 && flag==1)
		{
			facc--;
			printf("F[%d]\t|\t%d\t|\t%d\n",i+1,time,time-rff[i]+wtff[i]);
			waitf +=time-bff[i]+wtff[i];
			turnf +=time;
			flag=0;
		}
		if(i==k-1)
		i=0;
		else
		i++;
	}
}
	z po;
	//for new faculty process.
	q:if(time<120)
	{
	z cutt = cut(time);
	printf("\nCurrent Time is %d\n",cutt);
	printf("\nAny Faculty waitng or Student waiting  press 1 for faculty or press 2 for student  \t");
	printf("\n if No process Waiting the press 3 \t");
	printf("\n To Qiut press 4");
	scanf("%d",&po);
	if(po==1)
	{
		printf("\nhow many are waiting \t");
		z op;
		scanf("%d",&op);
		int b[op],a[op];
		for(z i=0;i<op;i++)
		{
			printf("\n Enter the ARRIVAL time and BUST time %d  ",i+1);
			scanf("%d %d",&a[i],&b[i]);
			t:if(a[i]>cutt)
			{
				printf("ERROR enter the Time again\n ");
				printf("enter the corect arrival time \n");
				scanf("%d",&a[i]);
				goto t;
			}
			a[i]=ti1(cutt,a[i]);
		}
		per=(z)120/(stuc+op);
		m3:
	z x=time;
	for(z i=0;i<op;i++)
	{
		x+=b[i];
	}
	if(x>120)
	{
		op--;
		printf("F[%d] time exceed\n",op+1);
		goto m3;
	}
	z bff[op],rff[op],wtff[op];
	for(z j=0;j<op;j++)
	{
		bff[j]=b[j];
		rff[j]=b[j];
		wtff[j]=a[j];
	}
	
	z k=op;
	tot(k);
	for(i=0;op!=0;)
	{
		if(bff[i]<=per && bff[i]>0)
		{
			
			time+=bff[i];
			bff[i]=0;
			flag=1;
		}
		else if(bff[i]>0)
		{
			bff[i]-=per;
			time+=per;
		}
		if(bff[i]==0 && flag==1)
		{
			op--;
			printf("F[%d]\t|\t%d\t|\t%d\n",i+1,time,time-rff[i]+wtff[i]);
			waitf +=time-bff[i]+wtff[i];
			turnf +=time;
			flag=0;
		}
		if(i==k-1)
		i=0;
		else
		i++;
	}
	}
	else if(p==3)
	{
		if(stuc==0)
		goto final;
		else
		goto w;
	}
	else if(p==4)
	{
	printf("\n Average Waiting Time is %d     ",(waitf+waits)/totalp);
	printf("\n Average processing time is %d  ",time/totalp);
	exit(0);
	}
	else if(po==2)
	{
	z cutt = cut(time);
	printf("Current Time is %d\n",cutt);
	printf("\nAny Studnt waitng  press 1 \t");
	if(stuc==0)
	{
	z po;
	scanf("%d",&po);
	if(po==1)
	{
		printf("\nhow many are waiting \t");
		z op;
		scanf("%d",&op);
		int b[op],a[op];
		for(z i=0;i<op;i++)
		{
			printf("\n Enter the ARRIVAL time and BUST time %d  ",i+1);
			scanf("%d %d",&a[i],&b[i]);
			t1:if(a[i]>cutt)
			{
				printf("ERROR enter the Time again\n ");
				printf("enter the corect arrival time \n");
				scanf("%d",&a[i]);
				goto t1;
			}
			a[i]=ti1(cutt,a[i]);
		}
		per=(z)120/(stuc+op);
		printf("time         %d",time);
		m4:
	z x=time;
	for(z i=0;i<op;i++)
	{
		x+=b[i];
	}
	if(x>120)
	{
		op--;
		printf("S[%d] time exceed\n",op+1);
		goto m4;
	}
	z bff[op],rff[op],wtff[op];
	for(z j=0;j<op;j++)
	{
		bff[j]=b[j];
		rff[j]=b[j];
		wtff[j]=a[j];
	}
	
	z k=op;
	tot(k);
	for(i=0;op!=0;)
	{
		if(bff[i]<=per && bff[i]>0)
		{
			
			time+=bff[i];
			bff[i]=0;
			flag=1;
		}
		else if(bff[i]>0)
		{
			bff[i]-=per;
			time+=per;
		}
		if(bff[i]==0 && flag==1)
		{
			op--;
			printf("F[%d]\t|\t%d\t|\t%d\n",i+1,time,time-rff[i]+wtff[i]);
			waitf +=time-bff[i]+wtff[i];
			turnf +=time;
			flag=0;
		}
		if(i==k-1)
		i=0;
		else
		i++;
	}
	}
	}
	else
	{
	printf("WAIT \n");
	goto w;
	}
	}
	else
	{
		goto w;
	}
	}
	else
	{
		goto final;
	}
	
	
	w:if(stuc>0 && time<120)
	{
		for(i=0;i<stuc/2;i++)
	{
		swap(bs[i],bs[stuc-i-1]);
		swap(rs[i],rs[stuc-i-1]);
		swap(wts[i],wts[stuc-i-1]);
	}
	for(i=0;i<stuc;i++)
	{
		wts[i]=ti(wts[i]);
	}
	z x;
	i=0;
	m1:
	x=time;
	for(z i=0;i<stuc;i++)
	{
		x+=bs[i];
	}
	if(x>120)
	{
		stuc--;
		printf("Faculty %d time exceed\n",stuc+1);
		goto m1;
	}
	z bff[stuc],rff[stuc],wtff[stuc];
	for(z j=0;j<stuc;j++)
	{
		bff[j]=bs[j];
		rff[j]=rs[j];
		wtff[j]=wts[j];
	}
	
	z k=stuc;
	tot(k);
	for(i=0;stuc!=0;)
	{
		if(bff[i]<=per && bff[i]>0)
		{
			
			time+=bff[i];
			bff[i]=0;
			flag=1;
		}
		else if(bff[i]>0)
		{
			bff[i]-=per;
			time+=per;
		}
		if(bff[i]==0 && flag==1)
		{
			stuc--;
			printf("S[%d]\t|\t%d\t|\t%d\n",i+1,time,time-rff[i]+wtff[i]+waitf);
			waits +=time-bff[i]+wtff[i]+waitf;
			turns +=time;
			flag=0;
		}
		if(i==k-1)
		i=0;
		else
		i++;
	}
	}
	goto q;
	final:
	if(time>=120)
	{
	printf("\n Average Waiting Time is %d     ",(waitf+waits)/totalp);
	printf("\n Average processing time is %d  ",time/totalp);
	exit(0);
	}
	else
	{
		goto q;
	}
}
