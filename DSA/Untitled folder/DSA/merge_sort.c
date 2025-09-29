#include<stdio.h>
void main()
{
    int n,i,j,k,m;
    printf("Enter the size of array 1 : ");
    scanf("%d",&n);
    printf("Enter the size of array 2 : ");
    scanf("%d",&m);
    
    int arr1[n],arr2[m],arr3[n+m];

    printf("\nEnter the elements in sorted order (array 1) :");
    for(i=0;i<n;i++)
        scanf("%d",&arr1[i]);
    printf("\nEnter the elements in sorted order (array 2 ):");
    for(i=0;i<m;i++)
        scanf("%d",&arr2[i]);

    k=0,i=0,j=0;
	while(i<m && j<n)
	{
		if(arr1[i]<arr2[j])
		{
			arr3[k]=arr1[i];
			i++;
		}
		else
		{
		arr3[k]=arr2[j];
		j++;
		}
	k++;
	}

	while(i<n)
	{
		arr3[k]=arr1[i];
		i++;
		k++;
	}	
	while(j<m)
	{
		arr3[k]=arr2[j];
		j++;
		k++;
	}
	printf("the merged array are: ");
	for(k=0;k<m+n-;k++)
		printf("%d,",arr3[k]);
}