#include <stdio.h>
#include <stdlib.h>
#include "C_interface.h"
#include "STD.h"

int main(){
	struct Patient* head = NULL;
	reservation_Init();
	u32 stat=1;
	u32 stat_admin;
	u32 stat_user;
	u32 mode;
	u32 process;
	u8 pass;
	
	printf("\n===========================================================\n");
	printf("\n========= Welcome in Clinic Management System APP =========\n");

	
while(stat){
	stat_admin=1;
	stat_user=1;
	printf("\n===========================================================\n");
	printf("Choose mode:\n1. Admin\n2. User\n3. Exit\n");
	printf("The mode is :");
	scanf("%lu", &mode);
		switch(mode){
			case 1://admin
				pass=password();
				
				if(pass==0){
					return 0;
					}
				while(stat_admin){
					printf("\n===========================================================\n");
					printf("Choose the process:\n1. Add patient record\n2. Edit patient record\n3. reserve slot with the doctor\n4.cancel reservation\n5.Back\n\n");
					printf("The process is :");
					scanf("%lu", &process);
						switch(process){
							case 1:
								Add_Patient(&head);
								break;
							case 2:
								Edit_Patient(head);
								break;
							case 3:
								reserve_slot(head);
								break;
							case 4:
								cancel_reserve(head);
								break;
							case 5:
								stat_admin=0;
								break;
							default:
								printf("\nInvalid entry\n");
						}
		}
	break;
			case 2:				//user
			while(stat_user){
				printf("\n=================== Welcome in User Mode ==================\n");
				printf("Choose the process:\n1.View patient record\n2.View today's reservations\n3.Back\n\n");
				printf("The process is :");
				scanf("%lu", &process);
				switch(process){
					case 1:
						View_Patient(head);
						break;
					case 2:
						View_Reservations();
						break;
					case 3:
						stat_user=0;
						break;

					default:
						printf("\nInvalid entry\n");
	   }
			}
				
				break;
			case 3:				//Exit
				stat=0;
				break;
			default:
				printf("\nInvalid entry\n");
	}
}
	free_space(head);
    return 0;
}