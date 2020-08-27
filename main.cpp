#include <iostream>

using namespace std;
void initialize_array(int [], int);
void print_array(const int [], int);
int * shuffle_array(const int, int);
int * createOddArray(const int [], int, int &);
int * createEvenArray(const int [], int, int &);
void array_war(int *, int, int *, int);
void sort_array(int *,int);


void initialize_array(int ray[], int value)
{
    for(int i=0;i<value;i++)
    {
        ray[i]=i;
    }
}


void print_array(const int ray[], int value)
{
    for(int i=0;i<value;i++)
    {
        cout<<ray[i]<<" ";
    }
    cout<<"\n";
}


int * shuffle_array(const int ray[], int size)
{
   int*newpointer= new int[size];
   for(int i=0;i<size;i++)
   {
       newpointer[i]=ray[i];
   }
   int x, y;
   for(x=(size-1),y=size;x>-1;x--,y--)
   {
       int rando=rand()%(y);
       int swap=newpointer[rando];  //swaps the contents of the orginal array with the contents of the random array
       newpointer[rando]=newpointer[x];
       newpointer[x]=swap; 
       
   }
   return newpointer;
}


int * createOddArray(const int ray [], int size , int &oddsize)
{
    oddsize=0;
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(ray[i] %2==1)
        {
            oddsize++;   //This counts the number of odd values that will be the number of the odd array (minus 1)
        }
    }
    int*newodd= new int[oddsize];
    for(int j=0;j<size;j++)
    {
      if(ray[j] %2==1)
      {
          newodd[count++]=ray[j];   //since the ++ are after the count, it will still start @ 0
      }
    }
    return newodd;
}

int * createEvenArray(const int ray [], int size, int &evensize)
{
    evensize=0;
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(ray[i] %2==0)
        {
            evensize++;
        }
    }
    int*neweven= new int[evensize];
    for(int j=0;j<size;j++)
    {
        if(ray[j] %2==0)
        {
            neweven[count++]=ray[j];
        }
    }
    return neweven;
}
void sort_array(int * ray, int size)    //Using bubble sort because it's easy and it works
{
    cout<<"The sorted array fight winner array is:"<<endl;
    int start=(size-1);
    int temp=0;                     
    while(start>0)
    {
        int j=0;
        for(int i=0;i<start;i++)
        {
            if(ray[i+1]<ray[i])
            {
                temp=ray[i+1];
                ray[i+1]=ray[i];
                ray[i]=temp;
                j=i;
            }
            
        }
        start=j;
    }
    for(int k=0;k<size;k++)
    {
        cout<<ray[k]<<" ";
    }
    

    cout<<"\n";
}



void array_war(int *oddray, int oddsize, int *evenray, int evensize)
{
    cout<<"The Array fight winner array is:"<<endl;
    int biggest=oddsize;
    if(evensize>oddsize)
    {
        biggest=evensize;
    }
    int wararray[biggest];
    int count=0;
    for(int i=0;i<biggest;i++)
    {
        if(oddray[i]>evenray[i])
        {
            wararray[count++]=oddray[i];
            
        }
        else 
        {
            wararray[count++]=evenray[i];
        }
    }
    for(int j=0;j<biggest;j++)
    {
        cout<<wararray[j]<<" ";
    }
    cout<<"\n";
    sort_array(wararray,biggest);
}

int main()
{
    int size;
   cout<<"Choose a number between 1 and 52"<<endl;
   cin>>size;
   while(size<1 || size>52)
   {
       cout<<"Invalid entry. Please try again."<<endl;
       cin>>size;
   }
   int array[size];
   initialize_array(array,size);    //Makes first array starting from 0 and ending in size-1
   cout<<"The inital array is:"<<endl;
   print_array(array,size); //displays first array
   initialize_array(array,size);
   int*shuffle=shuffle_array(array,size);   //since shuffle returns a pointer that points to an array, we call the shuffle function to equal to a pointer
   cout<<"The shuffled array is:"<<endl;
   print_array(shuffle,size);
   int odd,even;
   int *oddone=createOddArray(shuffle, size, odd);
   int *evenone=createEvenArray(shuffle, size, even);
   int*oddshuffle=shuffle_array(oddone,odd);
   int*evenshuffle=shuffle_array(evenone,even);
   cout<<"The odd array is:"<<endl;
   print_array(oddshuffle,odd);
   cout<<"The even array is:"<<endl;
   print_array(evenshuffle,even);
   array_war(oddshuffle,odd,evenshuffle,even);

   
    
    
    
    
    return 0;
}
