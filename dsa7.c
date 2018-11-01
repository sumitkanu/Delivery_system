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
	struct orders temp;
	temp=*a;
	*a=*b;
	*b=temp;
}



// arr[] is array of struct orders, min dis is overall min dis,res is array of restraunts
//temp_ans is array containing cordinates in a particular permute/branch, ans[] is final ans containing cordinates of req path
// l,r are starting and ending point for permutation, local_min is min dist in a particular permute/branch,
// sx and sy are cordinates of starting/current position,no is no of orders from a res
void permute(struct orders arr[],int *min_dis,struct restraunt res[3],int temp_ans[],int ans[],int l,int r,int local_min,int sx,int sy,int no[3],int temp_ans_length,int elem_in_arr)

{
	int i;
	struct orders dummy[15];
	for(i=0;i<elem_in_arr;i++)
{
	dummy[i]=arr[i];
}


if(elem_in_arr>0)

{
	if(dummy[0].dhaba==-1)

{

	if(l==r)

	{

		if(elem_in_arr==1)
		{
		int z=temp_ans_length;
		local_min=local_min+(abs(dummy[0].ox-sx)+abs(dummy[0].oy-sy));

		temp_ans[z]=dummy[0].ox;
		temp_ans[z+1]=dummy[0].oy;
		elem_in_arr--;
		(temp_ans_length) =(temp_ans_length) +2;


		sx=dummy[0].ox;
		sy=dummy[0].oy;

		}
		if(local_min<*min_dis)
		{
			*min_dis=local_min;
			for(i=0;i<temp_ans_length;i++)
			{
			ans[i]=temp_ans[i];

			 }
			return;
		}
	}

	else
	{

		int z=temp_ans_length;
		local_min+=abs(dummy[0].ox-sx)+abs(dummy[0].oy-sy);
		temp_ans[z]=dummy[0].ox;
		temp_ans[z+1]=dummy[0].oy;
		elem_in_arr--;
		sx=dummy[0].ox;
		sy=dummy[0].oy;
		for(i=0;i<elem_in_arr;i++)
		dummy[i]=dummy[i+1];
		(temp_ans_length) =(temp_ans_length) +2;




		if(elem_in_arr>0)
		for(i=0;i<elem_in_arr;i++)
                  {

			swap(&dummy[0],&dummy[i]);
			permute(dummy,min_dis,res,temp_ans,ans,l+1,r,local_min,sx,sy,no,temp_ans_length,elem_in_arr);
			swap(&dummy[0],&dummy[i]);
                  }

	}


}//if condition for dhaba
// new loop if value of array
	else
	{

		int z=temp_ans_length;
		temp_ans[z]=dummy[0].ox;
		temp_ans[z+1]=dummy[0].oy;
		local_min+=(abs(dummy[0].ox-sx)+abs(dummy[0].oy-sy));
		sx=dummy[0].ox;
		sy=dummy[0].oy;
		(temp_ans_length) =(temp_ans_length)+2;
		int index=dummy[0].dhaba,i;
		elem_in_arr--;
		for(i=0;i<elem_in_arr;i++)
		dummy[i]=dummy[i+1];


		for(i=0;i<no[index];i++)
		{
			dummy[elem_in_arr].ox=res[index].order[i].ox;
			dummy[elem_in_arr].oy=res[index].order[i].oy;
			dummy[elem_in_arr].dhaba=-1;
			r++;
			elem_in_arr++;

		}

		int k;

		for(i=0;i<elem_in_arr;i++)
                  {

			swap(&dummy[0],&dummy[i]);
			permute(dummy,min_dis,res,temp_ans,ans,l+1,r,local_min,sx,sy,no,temp_ans_length,elem_in_arr);
			swap(&dummy[0],&dummy[i]);
                  }

	}

}

}
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

	int total_locations=0;

	//printf("Enter Number of restraunts\n");
	for(j=0;j<3;j++)
{
	printf("Enter num of orders for res %d\n",j);
	scanf("%d",&no[j]);
	res[j].size=no[j];
	total_locations=total_locations+no[j];
	if(no[j]>0)
	total_locations++;
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
	//if(no[0]==0)
	{
	arr[elem_in_arr].dhaba=-1;
	arr[elem_in_arr].ox=0;
	arr[elem_in_arr].oy=0;
	elem_in_arr++;
	total_locations++;
	}
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
	//printf("Comment 1\n");
	//initiallizing minimum dis...possible min dis will be less than this only
	int min_dis=100000;
	int local_min=0;
	int temp_ans_length=0;
	printf("\nThe starting location is 0  0\n");
	for (i=0;i<3;i++)
    {
        printf("\nThe coordinates of hotel %d is %d  %d\n",i+1,res[i].rx,res[i].ry);
    }
	//struct orders *ans[15];
	int ans[30], temp_ans[30];
	permute(arr,&min_dis,res,temp_ans,ans,0,elem_in_arr-1,local_min,sx,sy,no,temp_ans_length,elem_in_arr);
	//printf("Comment 2\n");
	int size=sizeof(ans)/sizeof(ans[0]);
	printf("\ntotal_locations=%d\nMost Efficient Travelling Order:-\n",total_locations);
	for(i=0;i<total_locations*2;i++)
	{
	printf("%d %d\n",ans[i],ans[i+1]);
	i++;
	}
	printf("min travelling distance= %d units\n",min_dis);
}
