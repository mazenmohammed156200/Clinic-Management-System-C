/**
 * @file C_interface.h
 * @brief Header file for Clinic Management System interfaces and function declarations.
 * @author Mazen Mohammed
 * @date 2026
 */

#ifndef C_INTERFACE_H_
#define C_INTERFACE_H_

#include "STD.h"

/**
 * @brief Forward declaration of the Patient structure for linear linked list.
 */
struct Patient;

/**
 * @brief Verifies the admin password with a maximum of 3 attempts.
 * 
 * Prompts the user to enter a numeric password and grants access if correct.
 * 
 * @return u8 Returns 1 if password verification is successful, 0 if all 3 attempts fail.
 */
u8 password();

/**
 * @brief Searches for a patient in the linked list using their unique ID.
 * 
 * @param head Pointer to the head node of the patient linked list.
 * @param id The unique patient ID to search for.
 * @return struct Patient* Pointer to the matching Patient node, or NULL if not found.
 */
struct Patient* ID_search(struct Patient* head, u32 id);

/**
 * @brief Displays the record details of a specific patient.
 * 
 * Prompts for an ID and outputs Name, Gender, and Age if the record exists.
 * 
 * @param head Pointer to the head node of the patient linked list.
 */
void View_Patient(struct Patient* head);

/**
 * @brief Adds a new patient record to the linked list.
 * 
 * Allocates dynamic memory for a new patient, ensures the ID is non-duplicate,
 * and appends the node to the end of the list.
 * 
 * @param head Double pointer to the head node of the patient linked list.
 */
void Add_Patient(struct Patient** head);

/**
 * @brief Modifies the personal details of an existing patient record.
 * 
 * @param head Pointer to the head node of the patient linked list.
 */
void Edit_Patient(struct Patient* head);

/**
 * @brief Initializes the clinic appointment time slots.
 * 
 * Populates predefined time slots and sets initial availability status to 0 (available).
 */
void reservation_Init();

/**
 * @brief Reserves an available doctor slot for a valid patient ID.
 * 
 * @param head Pointer to the head node of the patient linked list.
 */
void reserve_slot(struct Patient* head);

/**
 * @brief Cancels an existing doctor appointment reservation.
 * 
 * @param head Pointer to the head node of the patient linked list.
 */
void cancel_reserve(struct Patient* head);

/**
 * @brief Prints all appointment slots and their current reservation statuses.
 */
void View_Reservations();

/**
 * @brief Deallocates all dynamically allocated nodes in the patient linked list.
 * 
 * @param head Pointer to the head node of the patient linked list.
 */
void free_space(struct Patient* head);

#endif /* C_INTERFACE_H_ */