#include<stdio.h>
void quicksort(int array[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(array[i]<=array[pivot]&&i<last)
            i++;
         while(array[j]>array[pivot])
            j--;
         if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }

      temp=array[pivot];
      array[pivot]=array[j];
      array[j]=temp;
      quicksort(array,first,j-1);
      quicksort(array,j+1,last);

   }
}

int main(){
   int i, n, array[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&n);

   printf("Enter %d elements: ", n);
   for(i=0;i<n;i++){
      scanf("%d",&array[i]);
    }
    quicksort(array,0,n-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
      printf(" %d",array[i]);

   return 0;
}