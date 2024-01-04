#include "book.h"
#include <string.h>
#include <stdlib.h>

/**
 * \brief Initializes a book for the collection.
 *
 * \param p_book The book to be initialized.
 * \param p_id The book identifier string
 * \param p_title The book title string
 * \param p_author The book author string
 * \param release The release date of the book
 * \returns 0 if the book identifier is not valid. The identifier is invalid
 * 			  if the stated book identifier has more than 9 characters.
 * \returns 1 if the book can be initialized.
 */
int init_book(struct book* p_book,
			  const char *p_id,
			  const char *p_title,
			  const char *p_author,
			  struct date release)
{ 
	if (strlen(p_id) > 9) {
		return 0;
	}

	strcpy(p_book->id, p_id);
	char *new_title = (char*) malloc((strlen(p_title)+1) * sizeof(char));
	strcpy(new_title, p_title);
	char *new_author = (char*) malloc((strlen(p_author)+1) * sizeof(char));
	strcpy(new_author, p_author);
	(p_book->title) = new_title;
	(p_book->author) = new_author;
	(p_book->release_date) = release;

	return 1;

}

/**
 * \brief Adds a book to the collection. The collection is an array, and the
 * array should be reallocated to store the new book.
 *
 * \param collection The array of books representing the collection
 * \param size The number of books in the current collection
 * \param new_book The new book to be copied to the collection
 * \return A pointer to enlarged collection
 */
struct book *add_to_collection(struct book *collection,
							   unsigned int size,
							   struct book new_book)
{		
	struct book *new_collection = (struct book*)realloc(collection, sizeof(struct book) * (size+1));
	init_book(&new_book, new_book.id, new_book.title, new_book.author, new_book.release_date);
	new_collection[size] = new_book;

	return new_collection;
}
