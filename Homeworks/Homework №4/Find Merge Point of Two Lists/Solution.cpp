// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    auto* head2_dublicate = head2;
    while (head1 != nullptr)
    {
        head2 = head2_dublicate;
        while (head2 != nullptr)
        {
            if (head1 == head2)
                return head1->data;

             head2 = head2->next;
        }
        head1 = head1->next;
    }
    return NULL;

}
