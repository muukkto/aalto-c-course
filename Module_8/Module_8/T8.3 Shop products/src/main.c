#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Prints the products in an array of Product elements till
 *        termination product with empty name is found. 
 * 
 * \param array The array of products.
 */
void printProducts(Product* array) {
	int i = 0;
	while(array[i].name[0] != 0) {
		printf("product: %s\tprice: %f\t in stock: %d\n",
			   array[i].name,
			   array[i].price,
			   array[i].in_stock);
		i++;
	}
}

int main() {
	// --> NOTE:: the last element has an empty name
	Product array[6] = {{"peanut butter", 1.2, 5},
						{"cookies", 12.3, 23},
						{"cereals", 3.2, 12},
						{"bread", 2.7, 12},
						{"butter", 4.2, 5},
						{"\0", 0.0, 0}};

	// sort in lexical order
	qsort(array, 5, sizeof(Product), compareAlpha);
	printf("sorted lexically:\n");
	printProducts(array);

	// search product with name
	const Product* search = findProduct(array, "cookies", compareAlpha);
	if(search) {
		printf("Found product:\n");
		printf("%s\n", search->name);
	}

	// sort products according to number of products in the stock
	qsort(array, 5, sizeof(Product), compareNum);
	printf("sorted by in stock:\n");
	printProducts(array);

	return 0;
}
