#include "shop.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * \brief Writes the products in the shop into the specified binary file. 
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_binary(const char* filename, const Product* shop) {
	FILE *f = fopen(filename, "wb");
    if (!f) {
        return 1;
    }

	int len = 0;

	while (1) {
		if (strlen(shop[len].name) == 0) {
			break;
		}

		len++;
	}

	fwrite(shop, sizeof(Product), len, f);
	
	if(ferror(f)) {
		return 1;
	}

	fclose(f);
	return 0;
}

/**
 * \brief Reads the shop products from the specified binary file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 */
Product* read_binary(const char* filename) {
	FILE *f = fopen(filename, "rb");
    if (!f) {
        return NULL;
    }

	int len = 0;
	unsigned char buffer[1];

	while (1) {
		if (fread(buffer, 1, 1, f) != 1){
        	break;
    	}

		len++;	
	}

	int num_prods = len / sizeof(Product);
	Product* array = (Product*) calloc(num_prods+1, sizeof(Product));

	rewind(f);
	
	fread(array, sizeof(Product), num_prods, f);

	fclose(f);
	strcpy(array[num_prods].name, "");

	return array;
}

/**
 * \brief  Writes the shop products into a text file.
 * 
 * \details The file writes each product as follows.
 * 
 *          <product-name> <price> <in-stock>
 * 
 *       In other words, the structure fields are separated with a space, and the array 
 *       elements are separated by a newline. Because the data items are separated by a 
 *       space, the product name should not have spaces in it.
 * 
 *       The last array element (with the name of null character) should not be 
 *       written into the file.
 * 
 * \param filename The name of the file.
 * \param shop An array of products, of which last product has an empty name.
 * 
 * \returns 0 if products can be written to the file.
 * \returns 1 if an error occurs.
 */
int write_plaintext(const char* filename, const Product* shop) {
	FILE *f = fopen(filename, "w");
    if (!f) {
        return 1;
    }

	int i = 0;

	while (1) {
		if (strlen(shop[i].name) == 0) {
			break;
		}
		fprintf(f, "%s %f %d\n", shop[i].name, shop[i].price, shop[i].in_stock);
		i++;
	}

	fclose(f);
	return 0;
}

/**
 * \brief Reads the shop products from the specified text file.
 * 
 * \param filename The name of the file
 * 
 * \return  Returns a dynamically allocated array of products read from the 
 *          file in the read order. NULL if an error occurs. 
 *
 * \note You can parse each line using sscanf function.
 */
Product* read_plaintext(const char* filename) {
	FILE *f = fopen(filename, "r");
    if (!f) {
        return NULL;
    }

	Product* arr = calloc(sizeof(Product), 1);

	char str[100];
	memset(str, 0, 100);
	char name[31]; 
	memset(name, 0, 31);
	float price = 0.0;
	int in_stock = 0;

	int i = 0;

	while (1) {
		if (!fgets(str, 100, f)) {
			Product* old_arr = arr;
			arr = (Product*) calloc(sizeof(Product), i+1);
			memcpy(arr, old_arr, sizeof(Product)*i);
			strcpy(arr[i].name, "");
			free(old_arr);
			break;
		}
		sscanf(str, "%s %f %d\n", name, &price, &in_stock);
		Product* old_arr = arr;
		arr = (Product*) calloc(sizeof(Product), i+1);
		memcpy(arr, old_arr, sizeof(Product)*i);
		free(old_arr);
		strcpy(arr[i].name, name);
		arr[i].price = price;
		arr[i].in_stock = in_stock;

		i++;
		memset(str, 0, 100);
		memset(name, 0, 31);
	}

	fclose(f);
	return arr;
}
