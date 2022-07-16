#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include "LinkedList.h"
Node* createLinkedList(Node* hp, std::vector<int> Array);
Node* removeDuplicates(Node* head)
{
	Node* temp = head;
	std::unordered_map<int, int> map;
	Node* prev = NULL;
	Node* inter = NULL;
	while (temp != NULL)
	{
		if (map.find(temp->data) != map.end()) //this means, the key is in the map
		{
			
			//temp->DeleteAfter(temp);
			inter = temp->next;
			free(temp);
			prev->next = inter;
			temp = prev->next;
	

		
		}
		else
		{
			map[temp->data]++; //this ++ will work as a frequency counter for the second int in the map
			prev = temp;
			temp = temp->next;
		}
	
	}


	return head;

}

int main(void)
{
	Node* hp=NULL;
	std::vector<int> Array = { 2,2,2,2,2};
	hp = createLinkedList(hp, Array);
	hp->PrintLL(hp);
	hp = removeDuplicates(hp);
	return 0;
}
Node* createLinkedList(Node* hp, std::vector<int> Array)
{

	Node* tp;
	hp = hp->AddBeginning(hp, Array[0]);
	tp = hp;
	for (int i = 1; i < Array.size(); i++)
	{
		tp->AddAfter(tp, Array[i]);
		tp = tp->next;
	}

	return hp;

}