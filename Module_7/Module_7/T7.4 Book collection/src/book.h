#ifndef AALTO_C_BOOK
#define AALTO_C_BOOK

// Date in numeric format

/**
 * \brief Day of a year structure
 *
 */
struct date
{
	unsigned char day;
	unsigned char month;
	int year;
};

/**
 * \brief A book data structure
 *
 */
struct book
{
	char id[10];			  //!< The identifier of the the book
	char *title;			  //!< Title of the book
	char *author;			  //!< Author of the book
	struct date release_date; //!< The release date of the book
};

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char *p_author, struct date release);

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book);

#endif
