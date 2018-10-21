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
swap(struct orders *a,struct orders *b)
{
	struct orders temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
	
	
//void enterorder()
int main()
{
	int nr,no[3],a,b,i,j,k,l,m,sx=0,sy=0;
	struct restraunt res[3];
	//giving locations of restraunts
	res[1].rx=4;
	res[1].ry=7;
	res[2].rx=9;
	res[2].ry=0;
	res[0].rx=7;
	res[0].ry=7;
	
	
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
	


	//making array that stores address of struct order
	struct orders *arr[15];
	//initiallizing first 3 array elements as restraunts.... here value of dhaba denotes restraunt number
	for(i=0;i<3;i++)
{
	arr[i]->dhaba=i;
	arr[i]->ox=res[i].rx;
	arr[i]->oy=res[i].ry;
	
}	
	//initiallizing minimum dis...possible min dis will be less than this only
	int min_dis=100000;
	int local_min=0;
	//struct orders *ans[15];
	int ans[30], temp_ans[30];
	permute(arr,&min_dis,res,temp_ans,&ans,0,3,local_min,sx,sy,no);
	int size=sizeof(ans)/sizeof(ans[0]);
	for(i=0;i<size;i++)
	{
	printf("%d %d\n",ans[i],ans[i+1]);
	i++;
	}
	
}
// arr[] is array of struct orders, min dis is overall min dis,res is array of restraunts
//temp_ans is array containing cordinates in a particular permute/branch, ans[] is final ans containing cordinates of req path
// l,r are starting and ending point for permutation, local_min is min dist in a particular permute/branch,
// sx and sy are cordinates of starting/current position,no is no of orders from a res
void permute(struct orders arr[],int *min_dis,struct restraunt res[3],int temp_ans[],int *ans[],int l,int r,int local_min,int sx,int sy,int no[3])
{
	int i;
	if(arr[l]->dhaba==-1)
{	if(l==r)
	{
		if(local_min<min_dis)
		{
			for(i=0;i<(sizeof(temp_ans)/sizeof(temp_ans[0]));i++)
			ans[i]=temp_ans[i];
		}
	}
	else
	{
		int z=sizeof(temp_ans)/sizeof(temp_ans[0]);
		temp_ans[z]=arr[l].ox;
		temp_ans[z+1]=arr[l].oy;
		local_min+=abs(arr[l]->ox-sx)+abs(arr[l]->oy-sy);
		sx=arr[l].ox;
		sy=arr[l].oy;
		for(i=l;i<=r;i++)
                  {
			swap(&arr[l],&arr[i]);
			permute(arr,&min_dis,res,temp_ans,&ans,l+1,r,local_min,sx,sy,no);
			swap(&arr[l],&arr[i]);
                  }
		
		
	}
}//if condition for dhaba
// new loop if value of array 	
	else
	{
		int z=sizeof(temp_ans)/sizeof(temp_ans[0]);
		temp_ans[z]=arr[l].ox;
		temp_ans[z+1]=arr[l].oy;

		int index=arr[l].dhaba,i;
		int size=sizeof(arr)/sizeof(arr[0]);
		for(i=0;i<no[index];i++)
		{
			arr[size+i]=res[index].order[i];
			r++;
			
			
		}
		local_min+=abs(arr[l]->ox-sx)+abs(arr[l]->oy-sy);
		sx=arr[l].ox;
		sy=arr[l].oy;
		for(i=l;i<=r;i++)
                  {
			swap(&arr[l],&arr[i]);
			permute(arr,&min_dis,res,temp_ans,&ans,l+1,r,local_min,sx,sy,no);
			swap(&arr[l],&arr[i]);
                  }
		
	}
		
}
	
	
	
	
