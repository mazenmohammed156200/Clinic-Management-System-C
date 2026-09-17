/**
 * @file C_main.c
 * @brief Main application entry point for the Clinic Management System.
 * @author Mazen Mohammed
 * @date 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include "C_interface.h"
#include "STD.h"

/**
 * @brief Main execution loop driving Admin and User mode interactions.
 * 
 * @return int Standard exit code (0 on completion).
 */
int main(){
	/* Pointer to track the start of the dynamic patient linked list */
	struct Patient* head = NULL;
	
	/* Initialize the daily doctor appointment slots */
	reservation_Init();
	
	/* Main control loop flags and selection variables */
	u32 stat=1;         /**< Control flag for main program loop */
	u32 stat_admin;     /**< Control flag for admin operations loop */
	u32 stat_user;      /**< Control flag for user operations loop */
	u32 mode;           /**< User selected execution mode */
	u32 process;        /**< Sub-menu option process identifier */
	u8 pass;            /**< Password verification outcome status */
	
	printf("\n===========================================================\n");
	printf("\n========= Welcome in Clinic Management System APP =========\n");

	/* Main Application Loop */
while(stat){
	stat_admin=1;
	stat_user=1;
	printf("\n===========================================================\n");
	printf("Choose mode:\n1. Admin\n2. User\n3. Exit\n");
	printf("The mode is :");
	scanf("%lu", &mode);
		switch(mode){
			case 1://admin mode execution
				/* Authenticate Admin */
				pass=password();
				
				/* If password attempts exhausted, exit application */
				if(pass==0){
					return 0;
					}
				
				/* Admin Operations Menu Loop */
				while(stat_admin){
					printf("\n===========================================================\n");
					printf("Choose the process:\n1. Add patient record\n2. Edit patient record\n3. reserve slot with the doctor\n4.cancel reservation\n5.Back\n\n");
					printf("The process is :");
					scanf("%lu", &process);
						switch(process){
							case 1:
								/* Add new patient entry to list */
								Add_Patient(&head);
								break;
							case 2:
								/* Edit details of existing patient */
								Edit_Patient(head);
								break;
							case 3:
								/* Book doctor appointment slot */
								reserve_slot(head);
								break;
							case 4:
								/* Cancel previously booked slot */
								cancel_reserve(head);
								break;
							case 5:
								/* Return to main mode menu */
								stat_admin=0;
								break;
							default:
								printf("\nInvalid entry\n");
						}
		}
	break;
			case 2:				//user mode execution
			/* User Operations Menu Loop */
			while(stat_user){
				printf("\n=================== Welcome in User Mode ==================\n");
				printf("Choose the process:\n1.View patient record\n2.View today's reservations\n3.Back\n\n");
				printf("The process is :");
				scanf("%lu", &process);
				switch(process){
					case 1:
						/* View specific patient record */
						View_Patient(head);
						break;
					case 2:
						/* View all appointment slots */
						View_Reservations();
						break;
					case 3:
						/* Return to main mode menu */
						stat_user=0;
						break;

					default:
						printf("\nInvalid entry\n");
	   }
			}
				
				break;
			case 3:				//Exit mode execution
				/* Terminate main execution loop */
				stat=0;
				break;
			default:
				printf("\nInvalid entry\n");
	}
}
	/* Clean up dynamically allocated memory before program exit */
	free_space(head);
    return 0;
}