

#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





struct block{
	char flag;
	void *address;
	int size;
	int freespace;
	struct block *next;
};
struct block *head;


void heap_init (int number){
	void *heap;
	number =number*getpagesize();
	heap = mmap(NULL, number,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);
	memset(heap,'a',number);
	head= (struct block *) malloc(sizeof(struct block));
	head->freespace=number;
	head->address=heap;
	head->flag='u';
	head->size=0;
	head->next=NULL;
	
	return;
}

void *heap_alloc(int p)
{
	struct block *temp,*newBlock;

	char *t;
	long int spaceLeft,math;
	temp=head;
	while(temp->next!=NULL){
		if((temp->flag=='f')&&(temp->size>=p)) {
		temp->flag='u';
			temp->size=p;
			return temp->address;
		
		}
		spaceLeft=temp->freespace;
		if(temp->freespace<p) return NULL;
		temp=temp->next;
	}
	
	
	
		
	{	
	
		math=temp->size;
		while(((long int)temp->address+math)%16!=0){
			
			math+=1;
			if(p+math>temp->freespace) return NULL;
		}
		

		newBlock=(struct block *)malloc(sizeof(struct block)) ;
		temp->next=newBlock;
		newBlock->flag='u';
		newBlock->next=NULL;
		newBlock->freespace=temp->freespace-math;
		newBlock->size=p;
		newBlock->address=temp->address+math;
			
			
	}
	return newBlock->address; 
	}
	
	
	void  heap_free(void *pointer_to_area_to_free){
		struct block *temp,*past;
		temp=head;
		while(temp->address!=pointer_to_area_to_free){past=temp;
			temp=temp->next;}
		temp->flag='f';
		if (temp->next->flag=='f'){
			temp->size += temp->next->size;
			temp->freespace += temp->next->size;
			temp->next = temp->next->next;
		}
		if (past->flag=='f'){
			past->size+=temp->size;
			past->freespace+=past->size;
			past->next=temp->next;
		}
		
			}
		