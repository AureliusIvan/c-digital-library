If node to be deleted is head node */
            if (curr == headBorrow)
                headBorrow = curr->next;

            /* Change next only if node to be deleted is NOT
               the last node */
            if (curr->next != NULL)
                curr->next->prev = curr->prev;

            /* Change prev only if node to be curreted is NOT
               the first node */
            if (curr->prev != NULL)
                curr->prev->next = curr->next;

            /* Finally, free the memory occupied by curr*/
            free(curr);