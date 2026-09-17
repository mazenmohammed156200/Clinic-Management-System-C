#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include <stdbool.h>
#include <string.h>
#include "C_interface.h"
typedef struct {
    u8 name[50];
    u8 gender[10];
    u32 age;
    u32 ID;
} Patient_Data;


struct Patient {
    Patient_Data data;
    struct Patient* next;
};


struct Patient*  ID_search(struct Patient* head, u32 id){
    struct Patient* current = head;
    while(current != NULL){
        if(current->data.ID == id){ 
            return current;
        }
        current = current->next;
    }
	
    return NULL;
}


void Add_Patient(struct Patient** head){
    struct Patient* new = (struct Patient*)malloc(sizeof(struct Patient));
    printf("Enter patient ID: ");
    scanf("%lu", &new->data.ID);
    if(ID_search(*head, new->data.ID)){
        printf("Patient with this ID already exists.\n");
        free(new);
        return;
    }
    printf("Enter patient name: ");
    scanf("%s", new->data.name);

    printf("Enter patient gender: ");
    scanf("%s", new->data.gender);

    printf("Enter patient age: ");
    scanf("%lu", &new->data.age);

	new->next = NULL;
	
    if(*head == NULL){
        *head = new;
        
    }else{
        struct Patient* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
    }

 }


void View_Patient(struct Patient* head){
	u32 entered_id;
	if(head==NULL){
		printf("There is no patients\n");
	}else{
		printf("\nEnter the ID of patient:");
		scanf("%lu",&entered_id);
		struct Patient* current=ID_search(head,entered_id);
		if(current!=NULL){
			printf("The record of the patient with Id %lu is:\n name: %s \ngender: %s \nage: %lu \n",current->data.ID,current->data.name,current->data.gender,current->data.age);
		}else{
			printf("Id Not found");
		}
	}
	
}


u8 password(){
	u32 password=1234;
	u32 Entered_password;
	

		for(u32 i=0;i<3;i++){
			printf("Please enter the Password:");
			scanf("%lu",&Entered_password);
			if (Entered_password==password){
				printf("\n================= Welcome in Admin Mode ===================\n\n");
				return 1;
				
			}else{
				printf("WRONG Password \n Please try again\n remaining chances: %lu\n",2-i);
				if(i==2){
				return 0;
				}
			}
		}
}


void Edit_Patient(struct Patient* head){
	if(head==NULL){
		printf("\nThere is no patients to edit\n");
		return;
	}
	u32 entered_id;
	printf("\nPlease enter the Id of the patient to edit: ");
	scanf("%lu",&entered_id);
	
	struct Patient* current=ID_search(head,entered_id);
	if(current==NULL){
		printf("\nId not found\n");
		return;
		
	}
	printf("Enter patient new name: ");
    scanf("%s", current->data.name);

    printf("Enter patient new gender: ");
    scanf("%s", current->data.gender);

    printf("Enter patient new age: ");
    scanf("%lu", &current->data.age);
	
}

//===============================================

typedef struct {
	u8 time[20];
	u8 stat;
	u32 id;
}reservation;

reservation slots[5];


void reservation_Init(){

strcpy(slots[0].time,"2pm to 2:30pm");
strcpy(slots[1].time,"2:30pm to 3pm");
strcpy(slots[2].time,"3pm to 3:30pm");
strcpy(slots[3].time,"4pm to 4:30pm");
strcpy(slots[4].time,"4:30pm to 5pm");

for(u8 i=0;i<5;i++){
	slots[i].stat=0;
	slots[i].id=0;
	}
}


void reserve_slot(struct Patient* head){
	u32 entered_id;
	printf("\nEnter the id to reserve : ");
	scanf("%lu",&entered_id);
	if(ID_search(head,entered_id)==NULL){
		printf("\nthere is no patient with this id\n ");
		return;
	}
	u32 count=0;
	
	printf("Available slots :\n");
	for(u32 i=0;i<5;i++){
		
		if(slots[i].stat==0){
		printf("%lu. %s\n",i,slots[i].time);
		count++;
		}
	}
	if(count==0){
		printf("\nthere is no available slots\n");
		return;
	}
	u32 choice;
	printf("\nchoose slot to reserve:");
	scanf("%lu",&choice);
	if(choice >= 0 && choice< 5&& slots[choice].stat==0){
	slots[choice].stat=1;
	slots[choice].id=entered_id;
	}else{
		printf("\nInvalid entry\n");
		return;
	}
	printf("\nReservation done !\n");
}


void cancel_reserve(struct Patient* head){
	u32 avail=0;
	for(u32 i=0;i<5;i++){
		if(slots[i].stat==1){
			break;
		}else{
			avail++;
		}
		
	}
	if(avail==5) {
		printf("\nThere is no reservation slots is reserved to cancel\n");
		return;}
	u32 entered_id;
	printf("\nEnter the id to cancel reservation : ");
	scanf("%lu",&entered_id);
	if(ID_search(head,entered_id)==NULL){
		printf("\nthere is no patient with this id\n ");
		return;
	}
	for(u8 i=0;i<5;i++){
		if(slots[i].stat==1&&slots[i].id==entered_id){
			slots[i].stat=0;
			slots[i].id=0;
			printf("cancel reservation done\n");
			return;
		}
		
			
	}
	printf("The patient with this Id has no reservations\n");

}


void View_Reservations(){
	printf("\n==============today's reservations ==============\n");
	for(u32 i=0; i<5;i++){
		printf("%lu.%s ",i+1,slots[i].time);
		switch(slots[i].stat){
			case 0:
			printf("is available\n");
			break;
			case 1:
			printf("is reserved with id:%lu \n",slots[i].id);
			break;
		}
	}
	
}


void free_space(struct Patient* head){
	struct Patient* temp;
	while(head!=NULL){
		temp=head;
		head=head->next;
		free(temp);
		
	}
}