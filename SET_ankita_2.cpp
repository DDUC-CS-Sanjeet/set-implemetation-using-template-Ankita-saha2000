#include<iostream>
#include<math.h>
using namespace std;
template< typename T>
class mySet
{
    private:
    T *Array;
    int size;

    public:
    mySet()
    {   size=0;
        Array = new T[size];
    }
    mySet (int s)
    {
        size=s;
        Array =new T[size];
        
    }
    mySet (const mySet<T> &oldset)
    {
    	size=oldset.size;
    	for(int i=0;i<size;i++)
    	{
    		Array[i]=oldset.Array[i];
		}
	}
	void removeDuplicates()
	{
		for(int i=0;i<size;i++)
        { 
        	for(int j=i+1;j<size;j++)
        	{
        		if(Array[i]==Array[j])
        		{
        			for(int k=j;k<size;k++)
        			{
        				Array[k]=Array[k+1];
        			}
					size--;
					j--;
				}
			}
		}
		
		
	}

    void setElements()
    {
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<size;i++)
            cin>>Array[i];
            this->removeDuplicates();
            this->display();
    }
    mySet<T> operator +(const mySet<T>& set2)
    {    int temparrsize=size+set2.size;
         mySet<T> temp(temparrsize);
        
        int k=0;
        for(int i=0;i<size;i++,k++)
        temp.Array[k]=Array[i];
        
        for(int j=0;j<set2.size;j++,k++)
        temp.Array[k]=set2.Array[j];
        temp.removeDuplicates();
		 return temp;
      

}
    mySet<T> operator -(const mySet<T>& set2)
    {   
      
	   	mySet<T> temp(size);
	    
        
	int flag=0,k,newsize=0;
		for(int j=0;j<size;j++)
		{
			flag=0;
			for(k =0;k<set2.size;k++)
			{
				if(this->Array[j]==set2.Array[k])
				flag=1;
			}
			if(flag==0)
			{
			  temp.Array[newsize]=this->Array[j];
			  newsize++;	
						
			}
			
		}
		temp.size=newsize;
	
		
       return temp;

    }
    mySet<T> operator *(const mySet<T>& set2)
    {  int newsize=0; 
       mySet<T> temp(newsize);
       {
       int i,j,flag=0;
 
       for(i=0;i<set2.size;i++)
        {
          for(j=0;j<size;j++)
            {
               if(set2.Array[i]==Array[j])
                {
                  temp.Array[temp.size]=set2.Array[i];
                  temp.size++;
                  break;
                } 
            }
        }
       
       }
       return temp;
   }

   
    mySet<T> operator ^(const mySet<T>& set2)
    {   
       mySet<T> temp1(size);
       mySet<T> temp2(set2.size);
       for(int i=0;i<size;i++ ){temp1.Array[i]=Array[i];}
       for(int i=0;i<set2.size;i++ ){temp2.Array[i]=set2.Array[i];}
       return ((temp1+temp2)-(temp1*temp2));
      }
    
	void powerset()
	{
		int i,j,t; 
		int sizenew =pow(2,size);
		cout<<"{{";
		for(int i=0;i<sizenew;i++)
		{
			cout<<"{";
			for(j=0;j<this->size;j++)
			{
				if(i &(1<<j))
				{
					cout<<Array[j]<<",";
			
				}
				
			}
			cout<<"\b},";
		}
		cout<<"\b}";
	}  
    const mySet<T> operator=(mySet<T> const &ob)
		{
			for(int i=0;i<ob.size;i++)
			{
				this->a[i]=ob.Array[i];
			}
			return *this;
		}  
      
    bool operator==(mySet<T> const& ob)
	{
			bool temp =false;
			int flag=0;
			if(this->size==ob.size)
			{
				for(int i=0;i<this->size;i++)
				{
					for(int j=0;j<ob.size;j++)
					{
						if(this->Array[i]==ob.Array[j])
						{
							flag++;
						}
					}
				}
				if(flag==this->size)
				{
					temp=true;
				}
			}
			return temp;
		}  
      
      void display()
      {
      	
      	cout<<"{ ";
      	for(int i=0;i<size;i++)
      	{
		  cout<<Array[i]<<" ,";
		  }
		  cout<<"\b"<<"}"<<endl;
	  }
      
      void cardinality()
      {
      	cout<<"The cardinality of the given set is::";
      	cout<<size;
	  }
     };
int main()
{  
   int ch, size1,size2,a;
   cout<<"Which datatype do you want to enter for set elements."<<endl<<"1.Int"<<endl<<"2.char"<<endl;
   cout<<"3.Double"<<endl<<"4.Float"<<endl;
   cout<<"Enter your choice::";
   cin>>ch;
   switch(ch)
   {
    case 1 :
	{
   	    cout<<"Enter the number of elements in first set"<<endl;
   	    cin>>size1;
   	    cout<<"Enter the number of elements in second set "<<endl;
   	    cin>>size2;
	    mySet<int> set1(size1);
	    mySet<int> set2(size2);
	    set1.setElements();
	    set2.setElements();
	    do{
		
	    int choice;
	    cout<<"MENU"<<endl;
	    cout<<"1.Union"<<endl;
	    cout<<"2.Set Difference"<<endl;
	    cout<<"3.Intersection"<<endl;
	    cout<<"4.Symmetric Difference"<<endl;
	    cout<<"5.Power Set"<<endl;
	    cout<<"6.Set Equality"<<endl;
	    cout<<"7.Assignment"<<endl;
	    cout<<"8.Cardinality"<<endl;
		cout<<"Enter the operation to be performed::";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					 cout<<"Union of these two sets is -";
	                 mySet<int> Union(set1+set2);
					 Union.display();
					 break;
				}
			case 2:
			    {
				    cout<<"Difference of these two sets is -";
	                mySet<int> Diff(set1-set2);
	                Diff.display();
	                break;
				}
			case 3:
			   {
			   	  cout<<"Intersection of these two sets is -";
	              mySet<int> intersct(set1*set2);
		          intersct.display();
		          break;
			   }
			case 4:
			   {
			   	  cout<<"Symetric difference of these two sets is -";
	              mySet<int> SymetricDifference(set1^set2);
		          SymetricDifference.display();
		          break;
			   }
			case 5:
			   {
			   	  cout<<"Power set of the given set is::";
	              set1.powerset();
	              break;
			   } 
			case 6:
			   {
			   	  if(set1==set2)
               					{
                    				cout<<"both sets are equal\n";
               					}
               					else
               					{
                    				cout<<"both sets are not equal\n";
               					}
								break;
				}
				
			case 7:			
			   {
								
					mySet<int>r=set1;
					mySet <int>s=set2;
					cout<<"\nassignment of set1 is:";
					r.display();
					cout<<"\nassignment of set2 is:";
					s.display();
					break;
				}
		case 8:
			    {
			    	set1.cardinality();
			    	cout<<endl;
					set2.cardinality();
			    	break;
				}
		default:
			    {
			    	cout<<"INVALID CHOICE!!";
				}								        
		}
   	    cout<<"\nDo you want to continue(y/n):";
   	    
		cin>>a;
		}while(a=='y'||a=='Y');	
	
	
	   }

	case 2:
	{
	   	cout<<"Enter the number of elements in first set"<<endl;
   	    cin>>size1;
   	    cout<<"Enter the number of elements in second set "<<endl;
   	    cin>>size2;
	    mySet<char> set1(size1);
	    mySet<char> set2(size2);
	   	set1.setElements();
	    set2.setElements();
	    int choice;
	    cout<<"MENU"<<endl;
	    cout<<"1.Union"<<endl;
	    cout<<"2.Set Difference"<<endl;
	    cout<<"3.Intersection"<<endl;
	    cout<<"4.Symmetric Difference"<<endl;
	    cout<<"5.Power Set"<<endl;
	    cout<<"6.Set Equality"<<endl;
	    cout<<"7.Assignment"<<endl;
	    cout<<"8.Cardinality"<<endl;
		cout<<"Enter the operation to be performed::";
		cin>>choice;
		do{
		switch(choice)
		{
			case 1:
				{
					 cout<<"Union of these two sets is -";
	                 mySet<char> Union(set1+set2);
					 Union.display();
					 break;
				}
			case 2:
			    {
				    cout<<"Difference of these two sets is -";
	                mySet<char> Diff(set1-set2);
	                Diff.display();
	                break;
				}
			case 3:
			   {
			   	  cout<<"Intersection of these two sets is -";
	              mySet<char> intersct(set1*set2);
		          intersct.display();
		          break;
			   }
			case 4:
			   {
			   	  cout<<"Symetric difference of these two sets is -";
	              mySet<char> SymetricDifference(set1^set2);
		          SymetricDifference.display();
		          break;
			   }
			case 5:
			   {
			   	  cout<<"Power set of the given set is::";
	              set1.powerset();
	              break;
			   }
			case 6:
			   {
			   	  if(set1==set2)
               					{
                    				cout<<"both sets are equal\n";
               					}
               					else
               					{
                    				cout<<"both sets are not equal\n";
               					}
								break;
				}
			case 7:			
			   {
								
					mySet<char> r=set1;
					mySet<char>s=set2;
					cout<<"\nassignment of set1 is:";
					r.display();
					cout<<"\nassignment of set2 is:";
					s.display();
					break;
				}
			case 8:
			    {
			    	set1.cardinality();
			    	cout<<endl;
					set2.cardinality();
			    	break;
				}
			default:
			    {
			    	cout<<"INVALID CHOICE!!";
				}				
			         
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>a;
		}while(a=='y'||a=='Y');	
   		
		
	   
	   }
	case 3:
	{
	   	cout<<"Enter the number of elements in first set::";
   	    cin>>size1;
   	    cout<<"Enter the number of elements in second set:: ";
   	    cin>>size2;
	    mySet<double> set1(size1);
	    mySet<double> set2(size2);
	   	set1.setElements();
	    set2.setElements();
	    mySet<double> Union(set1+set2);
		
	    int choice;
	    cout<<"MENU"<<endl;
	    cout<<"1.Union"<<endl;
	    cout<<"2.Set Difference"<<endl;
	    cout<<"3.Intersection"<<endl;
	    cout<<"4.Symmetric Difference"<<endl;
	    cout<<"5.Power Set"<<endl;
	    cout<<"6.Set Equality"<<endl;
	    cout<<"7.Assignment"<<endl;
	    cout<<"8.Cardinality"<<endl;
		cout<<"Enter the operation to be performed::";
		cin>>choice;
		do{
		switch(choice)
		{
			case 1:
				{
					 cout<<"Union of these two sets is -";
	                 mySet<double> Union(set1+set2);
					 Union.display();
					 break;
				}
			case 2:
			    {
				    cout<<"Difference of these two sets is -";
	                mySet<double> Diff(set1-set2);
	                Diff.display();
	                break;
				}
			case 3:
			   {
			   	  cout<<"Intersection of these two sets is -";
	              mySet<double> intersct(set1*set2);
		          intersct.display();
		          break;
			   }
			case 4:
			   {
			   	  cout<<"Symetric difference of these two sets is -";
	              mySet<double> SymetricDifference(set1^set2);
		          SymetricDifference.display();
		          break;
			   }
			case 5:
			   {
			   	  cout<<"Power set of the given set is::";
	              set1.powerset();
	              break;
			   }
			case 6:
			   {
			   	  if(set1==set2)
               					{
                    				cout<<"both sets are equal\n";
               					}
               					else
               					{
                    				cout<<"both sets are not equal\n";
               					}
								break;
				}
			case 7:			
			   {
								
					mySet<double> r=set1;
					mySet<double>s=set2;
					cout<<"\nassignment of set1 is:";
					r.display();
					cout<<"\nassignment of set2 is:";
					s.display();
					break;
				}
			case 8:
			    {
			    	set1.cardinality();
			    	cout<<endl;
					set2.cardinality();
			    	break;
				}
			default:
			    {
			    	cout<<"INVALID CHOICE!!";
				}					         
		}
   		
		cout<<"\nDo you want to continue(y/n):";
		cin>>a;
		}while(a=='y'||a=='Y');	
	   
	   }
	case 4:
	{
	   	cout<<"Enter the number of elements in first set"<<endl;
   	    cin>>size1;
   	    cout<<"Enter the number of elements in second set "<<endl;
   	    cin>>size2;
	    mySet<float> set1(size1);
	    mySet<float> set2(size2);
	   	set1.setElements();
	    set2.setElements();
	    mySet<float> Union(set1+set2);
		
	    int choice;
	    cout<<"MENU"<<endl;
	    cout<<"1.Union"<<endl;
	    cout<<"2.Set Difference"<<endl;
	    cout<<"3.Intersection"<<endl;
	    cout<<"4.Symmetric Difference"<<endl;
	    cout<<"5.Power Set"<<endl;
	    cout<<"6.Set Equality"<<endl;
	    cout<<"7.Assignment"<<endl;
	    cout<<"8.Cardinality"<<endl;
		cout<<"Enter the operation to be performed::";
		cin>>choice;
		do{
		
		switch(choice)
		{
			case 1:
				{
					 cout<<"Union of these two sets is -";
	                 mySet<float> Union(set1+set2);
					 Union.display();
					 break;
				}
			case 2:
			    {
				    cout<<"Difference of these two sets is -";
	                mySet<float> Diff(set1-set2);
	                Diff.display();
	                break;
				}
			case 3:
			   {
			   	  cout<<"Intersection of these two sets is -";
	              mySet<float> intersct(set1*set2);
		          intersct.display();
		          break;
			   }
			case 4:
			   {
			   	  cout<<"Symetric difference of these two sets is -";
	              mySet<float> SymetricDifference(set1^set2);
		          SymetricDifference.display();
		          break;
			   }
			case 5:
			   {
			   	  cout<<"Power set of the given set is::";
	              set1.powerset();
	              break;
			   }  
			case 6:
			   {
			   	  if(set1==set2)
               					{
                    				cout<<"both sets are equal\n";
               					}
               					else
               					{
                    				cout<<"both sets are not equal\n";
               					}
								break;
				}
			case 7:			
			   {
								
					mySet<float> r=set1;
					mySet<float>s=set2;
					cout<<"\nassignment of set1 is:";
					r.display();
					cout<<"\nassignment of set2 is:";
					s.display();
					break;
				}
			case 8:
			    {
			    	set1.cardinality();
			    	cout<<endl;
					set2.cardinality();
			    	break;
				}
			default:
			    {
			    	cout<<"INVALID CHOICE!!";
				}
									       
		}
		cout<<"\nDo you want to continue(y/n):";
		cin>>a;
		}while(a=='y'||a=='Y');	
   		
		
	   
   }
   	
   	
}
	return 0;
}


