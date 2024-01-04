#include "shopfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Returns a comparison value obtained by comparing the names of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details The name field of a Product is a string.
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns 0 if a == b
 * \returns a positive number if b should be placed before a
 */
int compareAlpha(const void* a, const void* b) {
	Product* prod_a = (Product*) a;
	Product* prod_b = (Product*) b;
	
	return strcmp(prod_a->name, prod_b->name);
}

/**
 * \brief Returns a comparison value obtained by comparing in_stock of Product 
 *        objects pointed by arguments a and b.
 * 
 * \details in_stock is an integer, and the products with higher stock should be
 *          placed before the products with lower stock. 
 * 
 * \param a The first object to compare
 * \param b The second object to compare
 * 
 * \returns a negative number if a should be placed before b
 * \returns result of compareAlpha(a, b) if a == b
 * \returns a positive number if b should be placed before a
 */
int compareNum(const void* a, const void* b) {
	Product* prod_a = (Product*) a;
	Product* prod_b = (Product*) b;
	
	if (prod_a->in_stock > prod_b->in_stock) {
		return -1;
	} else if (prod_a->in_stock < prod_b->in_stock) {
		return 1;
	} else {
		return compareAlpha(a, b);
	}
}

const Product* findProduct(const Product* p_array,
						   const char* search_key,
						   int (*cmp)(const void*, const void*)) {
	/*Product* array = (Product*) p_array;*/
	/*(void)search_key;
	(void)cmp;*/
	int len = 0;

	while (1) {
		Product current = p_array[len];
		if (strlen(current.name) == 0) {
			break;
		}
		len ++;
	}

	Product* item = bsearch(search_key, p_array, len, sizeof(Product), cmp);
	return item;
}
