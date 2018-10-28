#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct orders
{
	int dhaba;
	int ox,oy;
};


struct restraunt
{
	int rx,ry,size;
	struct orders order[5];
};


void swap(struct orders *a,struct orders *b)
{
	//printf("%d %d %d %d %d %d Comment 3\n",a->dhaba,a->ox,a->oy,b->dhaba,b->ox,b->oy);	
	struct orders temp;
	temp=*a;
	*a=*b;
	*b=temp;
	//printf("Comment 3\n");
	//printf("%d %d %d %d %d %d Comment 3\n",a->dhaba,a->ox,a->oy,b->dhaba,b->ox,b->oy);	
}



// arr[] is array of struct orders, min dis is overall min dis,res is array of restraunts
//temp_ans is array containing cordinates in a particular permute/branch, ans[] is final ans containing cordinates of req path
// l,r are starting and ending point for permutation, local_min is min dist in a particular permute/branch,
// sx and sy are cordinates of starting/current position,no is no of orders from a res
void permute(struct orders arr[],int *min_dis,struct restraunt res[3],int temp_ans[],int ans[],int l,int r,int local_min,int sx,int sy,int no[3],int *temp_ans_length,int elem_in_arr)

{	int i;
	printf("\nNEW PERMUTE\n");
	struct orders dummy[15];
	for(i=0;i<elem_in_arr;i++)
{	dummy[i]=arr[i];
	printf("dummy dhaba= %d  %d %d\n",dummy[i].dhaba,dummy[i].ox,dummy[i].oy);
}	
	
	printf("\nelem in array=%d\n",elem_in_arr);
	printf("l=%d r=%d local_min=%d sx=%d sy=%d\n",l,r,local_min,sx,sy);

	//printf("Enter permute\n");
	//int i;
	printf("boom %d \n",dummy[l].dhaba);
	//if(arr[l].dhaba==-1)
if(elem_in_arr>0)
{	//if(arr[l].dhaba!=0&&arr[l].dhaba!=1 &&arr[l].dhaba!=2)
	if(arr[0].dhaba==-1)
{	printf("bla %d \n",arr[l].dhaba);
	//printf("Location of delivery %d %d %d \n",arr[l].dhaba,arr[l].ox,arr[l].oy);
	if(l==r)
	{	//printf("local min dis=%d\n",*temp_ans);
		if(local_min<*min_dis)
		{	printf("SEXY  temp_ans_len=%d\n",*temp_ans_length);
			*min_dis=local_min;
			for(i=0;i<*temp_ans_length;i++)
			{ans[i]=temp_ans[i];
			printf("%d\n",ans[i]); }
		}
	}
	else
	{
		//printf("ABHI ");
		int z=*temp_ans_length;
		temp_ans[z]=arr[l].ox;
		temp_ans[z+1]=arr[l].oy;
		(*temp_ans_length) =(*temp_ans_length) +2;
		local_min+=abs(arr[l].ox-sx)+abs(arr[l].oy-sy);
		sx=arr[l].ox;
		sy=arr[l].oy;
		r--;
		//printf("%d ",elem_in_arr);
		for(i=l;i<=r;i++)
                  {
			swap(&arr[l],&arr[i]);
			
			permute(dummy,min_dis,res,temp_ans,ans,0,r,local_min,sx,sy,no,temp_ans_length,elem_in_arr);
			swap(&arr[l],&arr[i]);
                  }
		
		
	}
	
}//if condition for dhaba
// new loop if value of array 	
	else
	{
		//printf("Location of pickup %d %d %d \n",arr[l].dhaba,arr[l].ox,arr[l].oy);
		int z=*temp_ans_length;
		//printf (" z==%d\n",z); 
		temp_ans[z]=arr[l].ox;
		temp_ans[z+1]=arr[l].oy;
		(*temp_ans_length) =(*temp_ans_length)+2;
		//printf("sumit %d\n",temp_ans[z]);
		int index=arr[l].dhaba,i;
		elem_in_arr--;
		//r--;////****************************************CHECK ITS VALIDITY************************
		printf("elem = %d ",elem_in_arr);
		printf("INDEX = %d\n",index);
		for(i=0;i<no[index];i++)
		{	//printf(" hoola %d\n",i);
			//printf("Abhi %d\n",res[index].order[i].dhaba);
			printf("SRK %d\n",no[index]); 
			dummy[elem_in_arr].ox=res[index].order[i].ox;
			dummy[elem_in_arr].oy=res[index].order[i].oy;
			dummy[elem_in_arr].dhaba=-1;
			r++;
			elem_in_arr++;
			//printf("r=%d , %d\n",r,arr[elem_in_arr-1].dhaba);
		}
		//printf("%d ",elem_in_arr);	
		int k;
		//for(k=0;k<elem_in_arr;k++)printf("Location of order %d %d %d \n",arr[l].dhaba,arr[l].ox,arr[l].oy);
		local_min+=(abs(arr[l].ox-sx)+abs(arr[l].oy-sy));
		sx=arr[l].ox;
		sy=arr[l].oy;
		printf("local_min=%d\n",local_min);
		//printf("new l=%d new r=%d\n",l,r);
		for(i=l;i<=r;i++)
                  {
			swap(&arr[l],&arr[i]);
			permute(dummy,min_dis,res,temp_ans,ans,0,r,local_min,sx,sy,no,temp_ans_length,elem_in_arr);
			swap(&arr[l],&arr[i]);
                  }
		
	}
	//printf("Comment 4\n");
			
}	
//printf("\n");
}	
//void enterorder()
int main()
{
	int nr,no[3],a,b,i,j,k,l,m,sx=0,sy=0;
	struct restraunt res[3];
	//giving locations of restraunts
	res[0].rx=7;
	res[0].ry=7;
	res[1].rx=4;
	res[1].ry=7;
	res[2].rx=9;
	res[2].ry=0;
	
	
	
	//printf("Enter Number of restraunts\n");
	for(j=0;j<3;j++)
{
	printf("Enter num of orders for res %d\n",j);
	scanf("%d",&no[j]);
	res[j].size=no[j];
	//taking orders for all restraunts initially
	for(i=0;i<no[j];i++)
{
	printf("Enter x and y cordinates for order %d\n",i);
	scanf("%d%d",&a,&b);
	res[j].order[i].ox=a;
	res[j].order[i].oy=b;
	res[j].order[i].dhaba=-1;
	//stores location of order delivery point in order and dhaba=-1 denotes it is an order
}
}
	//for(i=0;i<3;i++)
	//for(j=0;j<no[i];j++)
	//printf("%d %d\n",res[i].order[j].ox,res[i].order[j].oy);
	
	printf("Orders taken\n");

	//making array that stores address of struct order
	struct orders arr[15];
	int elem_in_arr=0;
	//printf("Comment 0.1\n");
	//initiallizing first 3 array elements as restraunts.... here value of dhaba denotes restraunt number
	for(i=0;i<3;i++)
	{
	if(no[i]>0)
	{
	arr[elem_in_arr].dhaba=i;
	arr[elem_in_arr].ox=res[i].rx;
	arr[elem_in_arr].oy=res[i].ry;
	elem_in_arr++;
	}
	}
	printf("%d\n",elem_in_arr);
	for(i=0;i<elem_in_arr;i++)
	printf("%d %d %d\n",arr[i].dhaba,arr[i].ox,arr[i].oy);
	//printf("Comment 1\n");	
	//initiallizing minimum dis...possible min dis will be less than this only
	int min_dis=100000;
	int local_min=0;
	int temp_ans_length=0;
	
	//struct orders *ans[15];
	int ans[30], temp_ans[30];
	permute(arr,&min_dis,res,temp_ans,ans,0,elem_in_arr-1,local_min,sx,sy,no,&temp_ans_length,elem_in_arr);
	//printf("Comment 2\n");	
	int size=sizeof(ans)/sizeof(ans[0]);
	printf("Temp ans len=%d\n",temp_ans_length);
	for(i=0;i<temp_ans_length;i++)
	{
	printf("\n sabbey %d %d\n",ans[i],ans[i+1]);
	i++;
	}
	printf("min=%d\n",min_dis);
}

	
	
