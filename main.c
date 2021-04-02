#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct node
{
    char data[50];
    int tane;
    struct node *next;
};
struct node *first=NULL,*last=NULL;

void basa_ekle(char kelime[50],int tane)
{
   struct node *tutucu=(struct node*)malloc(sizeof(struct node));
   strcpy(tutucu->data,kelime);
   tutucu->tane=tane;

if(first==NULL){
	first=tutucu;
	last=tutucu;
	last->next=NULL;
}else{
	tutucu->next=first;
	first=tutucu;
}
}
void sona_ekle(char kelime[50],int adet)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));

    strcpy(new_node->data,kelime);
    new_node->tane=adet;

    if(first==NULL)
    {
        first = new_node;
        last = new_node;
        last->next=NULL;
    }
    else
    {
        last->next=new_node;
        last=new_node;
        last->next=NULL;
    }
}
void ortaya_ekle(char kelime[50],int tane)
{
	struct node *mid=(struct node*)malloc(sizeof(struct node));
	strcpy(mid->data,kelime);
	mid->tane=tane;
	int i=0,j;
	struct node *lL=first;
	while(lL->next!=NULL)
	{
		lL=lL->next;
		i++;
	}

   lL=first;
   for(j=0;j<=i/2-1;j++)
   {
   	lL=lL->next;
   }
   mid->next=lL->next->next;
   lL->next=mid;

}
void sirala(){
	//Silme Islemi
	int sayac=0;
	struct node *linkedList=first;
    struct node *linkedListCheck=first;
    struct node *before=linkedList,*sil;
    for(int i=0;linkedList!=NULL;i++)
	{
		for(int j=0;linkedListCheck!=NULL;j++)
		{


			if(strcmp(linkedList->data,linkedListCheck->data)==0)
			{
			sayac++;
			}

			if(sayac>1)
			{
				sil=linkedListCheck;
				linkedListCheck=before;
				linkedListCheck->next=linkedListCheck->next->next;
				free(sil);
				sayac=1;
			}
			before=linkedListCheck;
			linkedListCheck=linkedListCheck->next;

		}
		linkedListCheck=first;
		linkedList=linkedList->next;sayac=0;
	}
	linkedList=first;
//Siralama Islemi
    char tempd[50];
    while (linkedList!=last)
    {
    	linkedListCheck=first;
    	while (linkedListCheck!=last)
		{
			if(linkedListCheck->tane<linkedListCheck->next->tane)
			{
				strcpy(tempd,linkedListCheck->data);
			    int temps=linkedListCheck->tane;
			    strcpy(linkedListCheck->data,linkedListCheck->next->data);
			    linkedListCheck->tane=linkedListCheck->next->tane;
			    strcpy(linkedListCheck->next->data,tempd);
			    linkedListCheck->next->tane=temps;
			}
			linkedListCheck=linkedListCheck->next;
		}
		linkedList=linkedList->next;
    }
    linkedListCheck=first;
}
void yaz()
{
    struct node *linkedListCheck=first;
    //Yazdýrma Islemi
    for(int i=1; linkedListCheck!=NULL; i++)
    {
        printf("%d. %s:%d\n",i,linkedListCheck->data,linkedListCheck->tane);
        linkedListCheck=linkedListCheck->next;
    }

}
int ara(char kelime[50])
{
    FILE *dosya;
    dosya=fopen("metin.txt","r");
    char temp[50];
    int i=0;


        while(!feof(dosya))
        {
        fscanf(dosya,"%s",&temp);
        if(strcmp(temp,kelime)==0)
            i++;
        }
    return i;
    fclose(dosya);
    i=0;
}
void oku(){
    char kelime[50];
    char bosluk;
    FILE *dosya;
    dosya=fopen("metin.txt","r");
    if(dosya!=NULL)
    {
        while(!feof(dosya))
        {
            fscanf(dosya,"%s",&kelime);
            sona_ekle(kelime,ara(kelime));
        }
    }
    else
    {
        printf("Dosya Yok!!");
    }
    fclose(dosya);
}
int main()
{

    oku();
    sirala();
    yaz();


    return 0;
}
