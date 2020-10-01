#include"problem.h"


int main()
{

	int *List = (int *)malloc(sizeof(int) * MAX_SIZE);
	//Call sequence 
	int length = 0;  //current length
	insert(&List, 1, &length);
	insert(&List, 2, &length);
	insert(&List, 3, &length);
	insert(&List, 4, &length);
	insert(&List, 5, &length);
	insert(&List, 6, &length);
	insert(&List, 7, &length);
	insert(&List, 8, &length);
	insert(&List, 9, &length);
	printlist(List, length);


	_delete(&List, 3, &length);
	_delete(&List, 10, &length);
	printlist(List, length);

	find(List, 3, length);
	find(List, 11, length);

	printf("%d\n", findkth(List, 7, length));
	printf("%d\n", findkth(List, 13, length));

	printf("%d\n", isEmpty(List));
	makeEmpty(&List);
	printf("%d\n", isEmpty(List));

	//free(List);
	system("pause");
	return 0;
}
