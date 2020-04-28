#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
//#include <sys/resource.h>



using namespace std;

struct timespec start;
struct timespec finish;

bool pauza;
void bruteforce(int,string,int);
void ispis(string izlaz);
int entropija(string izlaz);


string sifra;
char znakovni_niz[255];



int n; // skup znakova lozinke (mala slova,velika slova,brojevi,simboli)
int ms=0,vs=0,br=0,si=0; //parametri
int MS=0,VS=0,BR=0,SI=0; //broj znakova


int main()
{
	
	
 char b;
 int  b1=0,b2=0,b3=0,b4=0,prm=0,jac=0;
 

 
izbor1:cout<<"Mala slova (Y/N):";
cin>>b;
if(b=='Y') 
 {
   b1=1;
   ms=1;
 }
 else if(b=='N') b1=0;
  else goto izbor1;



izbor2:cout<<"Velika slova (Y/N):";
cin>>b;
if(b=='Y') 
 {
   b2=2;
   vs=2;
 }
 else if(b=='N') b2=0;
  else goto izbor2;



izbor3:cout<<"Brojevi (Y/N):";
cin>>b;
if(b=='Y')
 {
   b3=4;
   br=4;
 }
 else if(b=='N') b3=0;
  else goto izbor3;


	
izbor4:cout<<"Simboli (Y/N):";
cin>>b;
if(b=='Y')
 {
   b4=8;
   si=8;
 }
 else if(b=='N') b4=0;
  else goto izbor4;
  

prm=b1+b2+b3+b4; //parametri
if (prm==0) {
	          cout<<"Krivi unos,pokusajte ponovo"<<endl<<endl;
	          goto izbor1; 
            }



	int i,x,y=0;
	switch(prm)
{
	case 1:{
		       for(x=97;x<=122;x++) 
             	{
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=25;
	            }
		break;
	}
	case 2:{
		       for(x=65;x<=90;x++) 
             	{
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=25;
		      
	            }
		break;
	}
	case 3:{
		       for(x=65;x<=122;x++) 
             	{
             	  if(x==91) x=97;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=51;
	            }
		break;
	}
	case 4:{
		       for(x=48;x<=57;x++) 
             	{
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=9;
	            }
		break;
	}
	case 5:{
		       for(x=48;x<=122;x++) 
             	{
             	  if(x==58) x=97;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=35;
	            }
		break;
	}
	case 6:{
		       for(x=48;x<=90;x++) 
             	{
             	  if(x==58) x=65;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=35;
	            }
		 break;
            
	}
	case 7:{
		       for(x=48;x<=122;x++) 
             	{
             	  if(x==58) x=65;
             	  else if(x==91) x=97;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=61;
	            }
		break;
    }
    case 8:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==48) x=58;
             	  else if(x==65) x=91;
             	  else if(x==97) x=123;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=160;
	            }
		break;
    }        
    case 9:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==48) x=58;
             	  else if(x==65) x=91;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=186;
	            }
		break;
    }                
	case 10:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==48) x=58;
             	  else if(x==97) x=123;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=186;
	            }
		break;
    }
    case 11:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==48) x=58;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=202;
	            }
		break;
    }
    case 12:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==65) x=91;
             	  else if(x==97) x=123;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=170;
	            }
		break;
    }
    case 13:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==65) x=91;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=196;
	            }
		break;
    }
     case 14:{
		       for(x=32;x<=255;x++) 
             	{
             	  if(x==97) x=123;
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=196;
	            }
		break;
    }
    case 15:{
		       for(x=32;x<=255;x++) 
             	{
		          char tmp = x;
		          znakovni_niz[y]=tmp;
		          y++;
		          n=222;
	            }
		break;
    }
    
	}


	

	
	
	string lozinka;
	unos:cout<<"Unesi lozinku (maksimalno 12 znakova):"<<endl;
	cin>>lozinka;
	
	
	if(lozinka.length()>12)
	{
	   cout<<"lozinka ima vise od 12 znakova,pokusajte opet"<<endl;
	   cout<<endl;
	   goto unos;
    }
    
    
	clock_gettime(CLOCK_REALTIME, &start);
    
    cout<<endl<<"Probijanje lozinke u tijeku..."<<endl; 

	
	 
    for(i=1;i<=12;i++)
    {
    	if(pauza) goto pauza;
    	bruteforce(i,lozinka,n);
    }
    
    pauza:system("PAUSE");
    return 0;
    
}

void bruteforce(int i,string lozinka,int n)
{
	int f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12; //f(n) predstavlja znak u lozinki pri cemu je n=indeks znaka
	
	switch(i){
		case 1:{
		    for(f1=0;f1<=n;f1++)
		         {
		         	sifra=znakovni_niz[f1];
		         	cout<< "\r" <<sifra;
		         	if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		       }
		         
		case 2:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2];
		         	cout<< "\r" <<sifra;
		         	if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
			
			
		}
		
		case 3:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3];
		         	cout<< "\r" <<sifra;
		         	if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
			
			      
	}
	    case 4:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4];
		         	cout<< "\r" <<sifra;
		         	if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
			
			      
	
}cout<<endl;
        case 5:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
			      
}
        case 6:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6];
		         	cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
			      
}
        case 7:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7];
		         	cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         	    pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
        case 8:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
			       for(f8=0;f8<=n;f8++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7]+znakovni_niz[f8];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
        case 9:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
			       for(f8=0;f8<=n;f8++)
			        for(f9=0;f9<=n;f9++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7]+znakovni_niz[f8]+znakovni_niz[f9];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
        case 10:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
			       for(f8=0;f8<=n;f8++)
			        for(f9=0;f9<=n;f9++)
			         for(f10=0;f10<=n;f10++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7]+znakovni_niz[f8]+znakovni_niz[f9]+znakovni_niz[f10];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
        case 11:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
			       for(f8=0;f8<=n;f8++)
			        for(f9=0;f9<=n;f9++)
			         for(f12=0;f10<=n;f10++)
			          for(f11=0;f11<=n;f11++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7]+znakovni_niz[f8]+znakovni_niz[f9]+znakovni_niz[f10]+znakovni_niz[f11];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
        case 12:{
			for(f1=0;f1<=n;f1++)
			 for(f2=0;f2<=n;f2++)
			  for(f3=0;f3<=n;f3++)
			   for(f4=0;f4<=n;f4++)
			    for(f5=0;f5<=n;f5++)
			     for(f6=0;f6<=n;f6++)
			      for(f7=0;f7<=n;f7++)
			       for(f8=0;f8<=n;f8++)
			        for(f9=0;f9<=n;f9++)
			         for(f10=0;f10<=n;f10++)
			          for(f11=0;f11<=n;f11++)
			           for(f12=0;f12<=n;f12++)
		         {
		         	sifra=string()+znakovni_niz[f1]+znakovni_niz[f2]+znakovni_niz[f3]+znakovni_niz[f4]+znakovni_niz[f5]+znakovni_niz[f6]+znakovni_niz[f7]+znakovni_niz[f8]+znakovni_niz[f9]+znakovni_niz[f10]+znakovni_niz[f11]+znakovni_niz[f12];
		            cout<< "\r" <<sifra;
					if(lozinka==sifra)
		         	{
		         		clock_gettime(CLOCK_REALTIME, &finish);
		         		ispis(sifra);
		         		pauza=true;
		         		goto pauza;
		         	}
		         	
		         }break;
		         
			
}
pauza: break;
}
}


void ispis(string izlaz)
{
	int i;
	int settings;
	int chars;
    unsigned long int combnum;
   

	int vrijeme =finish.tv_sec - start.tv_sec;
	
	
    
    cout<<endl;
    cout<<"LOZINKA JE PRONADENA"<<endl<<endl;
    cout<<"zaporka je: "<<izlaz<<endl;
    if(vrijeme>3600)
    {
   		cout<<"vrijeme za pronalazak zaporke je: "<<(vrijeme/3600)<<" h "<<(vrijeme/60)-60*(vrijeme/3600)<<" m "<<" i "<<(vrijeme/60.0 - vrijeme/60)*60<<" s "<<endl<<endl;
    }
    else if(vrijeme>60)
    {
    	cout<<"vrijeme za pronalazak zaporke je: "<<(vrijeme/60)<<" m "<<" i "<<(vrijeme/60.0 - vrijeme/60)*60<<" s "<<endl<<endl;
	}
	else 
    {
    
	    cout<<"vrijeme za pronalazak zaporke je: "<<vrijeme<<"s"<<endl<<endl;
	}
	


//su�elje parametara
if(ms!=0)
{

cout<<"mala slova   |X|"<<endl;
MS=26;

}
 else cout<<"mala slova   | |"<<endl;



if(vs!=0)
{

cout<<"velika slova |X|"<<endl;
VS=26;

}
 else cout<<"velika slova | |"<<endl;



if(br!=0)
{
	
cout<<"brojevi      |X|"<<endl;
BR=10;
 
}
 else cout<<"brojevi      | |"<<endl;
 


if(si!=0)
{
	
cout<<"simboli      |X|"<<endl;
SI=161;
 
}
 else cout<<"simboli      | |"<<endl;
 
 
    chars=MS+VS+BR+SI;
    combnum = pow(chars,izlaz.length());
    
    settings=ms+vs+br+si;
    
    cout<<endl<<"Jakost lozinke po parametrima: ";
    switch (settings)
    {
    	case 1: cout<<"slaba"<<endl;break;
    	case 2: cout<<" slaba"<<endl;break;
    	case 3: cout<<" dobra"<<endl;break;
    	case 4: cout<<" slaba"<<endl;break;
    	case 5: cout<<" dobra"<<endl;break;
    	case 6: cout<<" dobra"<<endl;break;
    	case 7: cout<<" jaka"<<endl;break;
    	case 8: cout<<" slaba"<<endl;break;
    	case 9: cout<<" dobra"<<endl;break;
    	case 10: cout<<" dobra"<<endl;break;
    	case 11: cout<<" jaka"<<endl;break;
    	case 12: cout<<" dobra"<<endl;break;
    	case 13: cout<<" jaka"<<endl;break;
    	case 14: cout<<" jaka"<<endl;break;
    	case 15: cout<<" vrlo jaka"<<endl;break;
    }


    


cout<<"Broj mogucih kombinacija: "<<combnum<<endl;
entropija(izlaz);
    
cout<<endl;


      
}

int entropija(string lozinka)
{
	float H=0;
	int L=0,N=0;
	int chars;
	chars=MS+VS+BR+SI;
    
	
	L=lozinka.length();
	N=chars;
	H=L*(log(N)/log(2.0));
	cout<<"entropija loznke je: "<<H<<endl;
	cout<<"jakost lozinke po entropiji je: ";
	
	if(H<=36)
	 cout<<"slaba"<<endl;
	 else if(H>36 && H<=40)
	  cout<<"dobra"<<endl;
	  else if(H>40 && H<=46)
	   cout<<"jaka"<<endl;
	   else 
	    cout<<"vrlo jaka"<<endl;
}



