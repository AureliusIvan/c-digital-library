
// FILE *dataBUKU;
// DataBuku *node, *curr;
// dataBUKU = fopen("FileBuku.txt", "r");
// while (!feof(dataBUKU)){
// node = (DataBuku*)malloc(sizeof(DataBuku));
// node->next = NULL;
// fscanf(dataBUKU, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", node->judulBuku, node->penulis, node->tahunTerbit, node->ISBN, node->jenisBuku);
// curr = head;
// if(head == NULL){
//         head = node;
//     }
//     else{
//         while (curr->next != NULL){
//             curr = curr->next;
//         }
//         curr->next = node;
//         node->prev = curr;
//     }
// }
// fclose(dataBUKU);