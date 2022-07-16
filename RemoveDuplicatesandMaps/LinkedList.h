#pragma once
typedef int LType;
class Node
{
public:
	LType data;
	Node* next;



	Node* GetNode()
	{
		Node* hp;
		hp = (Node*)malloc(sizeof(Node));
		hp->next = NULL;
		return hp;
	}

	Node* AddBeginning(Node* hp, LType data)
	{

		Node* tp;
		tp = GetNode();
		tp->next = hp;
		tp->data = data;
		return tp;
	}

	void AddAfter(Node* hp, LType data)
	{
		Node* tp;
		tp = GetNode();
		tp->next = hp->next;
		hp->next = tp;
		tp->data = data;
	}
	Node* DeleteFirst(Node* hp)
	{

		Node* temp;
		temp = hp;
		hp= temp->next;
		free(temp);
		return hp;
	}

	void DeleteAfter(Node* hp)
	{
		Node* temp;
		temp = hp->next;
		hp->next = temp->next;
		free(temp);

	}

	void PrintLL(Node* hp)
	{
		while (hp != NULL)
		{
			std::cout << hp->data << "->";
			hp = hp->next;
		}
		std::cout << "NULL" << std::endl;
	}
};