#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
//#include "NameCard.h"

int main(void)
{
	List list;
	NameCard * pcard;
	ListInit(&list);

	pcard = MakeNameCard("HJ","010-1234-5678");
	LInsert(&list, pcard);
	printf("pcard : %p \n", pcard);

	pcard = MakeNameCard("DS","010-4321-5678");
	LInsert(&list, pcard);
	printf("pcard : %p \n", pcard);


	pcard = MakeNameCard("DA","010-1111-5678");
	LInsert(&list, pcard);
	printf("pcard : %p \n", pcard);

	if(LFirst(&list, &pcard))
	{
		printf("&pcard_First : %p \n", &pcard);
		printf("pcard_First : %p \n", pcard);
		if(!NameCompare(pcard, "DA"))
		{
			ShowNameCardInfo(pcard);
		}
		else {
			while(LNext(&list,&pcard))
			{
				printf("&pcard_Next : %p \n", &pcard);
				printf("pcard_Next : %p \n", pcard);
				if(!NameCompare(pcard,"DA"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}

	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "DS"))
		{
			ChangePhoneNum(pcard, "010-9999-9999");
		}
		else {
			while(LNext(&list, &pcard))
			{
				if(!NameCompare(pcard, "DS"))
				{
					ChangePhoneNum(pcard, "010-9999-9999");
					break;
				}
			}
		}
	}

	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "DA"))
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else {
			while(LNext(&list, &pcard))
			{
				if(!NameCompare(pcard, "DA"))
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	printf("total number of datas: %d \n", LCount(&list));

	if(LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while(LNext(&list, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}

	return 0;
}
