#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <string.h>


#define MAX_DATA 512
#define MAX_ROWS 100


struct  Address
{
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
	int id;


};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection
{
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn);
struct Address *find_by_id(const int *id, struct Connection *conn);
struct Address *find_by_name(const char *name, struct Connection *conn);
struct Address *find_by_email(const char *email, struct Connection *conn);

void die(const char *message,struct Connection *conn)
{
	if (errno){
		perror(message);
	} else {
		printf("ERROR: %s \n",message);
	}
	Database_close(conn);
	exit(0);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s \n",addr->id, addr->name, addr->email );
}

void Database_load(struct Connection *conn)
{
	printf("TTT Loading database.. \n");
	int rc = fread(conn->db, sizeof(struct Database),1,conn->file);
	if (rc != 1)
		die("Failed to load database.",conn);
	printf("TTT Loaded database.. \n");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error",conn);
	conn->db = malloc(sizeof(struct Database));
	if (mode == 'c'){
		conn->file = fopen(filename,"w");
	} else {
		conn->file = fopen(filename, "r+");
		if (conn->file)
			Database_load(conn);
	}
	return conn;
}

void Database_close(struct Connection *conn)
{
	if (conn){
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	//what is rewind
	printf("TTT Starting to write to database... \n");
	rewind(conn->file);
	int rc = fwrite(conn->db,sizeof(struct Database),1,conn->file);

	if (rc != 1)
		die("Failed to write database.",conn);

	//What is fflush
	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.",conn);
}

void Database_create(struct Connection *conn)
{
	printf("TTT Starting to create a database... \n");
	int i = 0;
	for (i = 0; i < MAX_ROWS; i++){
		//make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		//then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email){
	struct Address *addr = &conn->db->rows[id];
	if (addr->set)
		die("alrady set, delete it first.",conn);

	addr->set = 1;
	//WARNING: bug, read the "How to break It" and fix this
	char *res = strncpy(addr->name, name,MAX_DATA);
	//demonstrate the strncpy bug
	if (!res)
		die("Name copy failed.",conn);

	res = strncpy(addr->email,email,MAX_DATA);
	if (!res)
		die("Email copy failed",conn);
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr =  &conn->db->rows[id];
	if(addr->set){
		Address_print(addr);
	} else {
		die("ID is not set",conn);
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i = 0;
	struct Database *db = conn->db;

	for ( i = 0; i < MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];

		if (cur->set){
			Address_print(cur);
		}
	}
}

void Database_find(struct Connection *conn, const char *field, const char *value)
{

	printf(" searching for field - %s , with value - %s \n",field,value);
	if  (strcmp(field,"id") == 0){
		Address_print(find_by_name(value, conn));
	}else if (strcmp(field,"name") == 0){
		Address_print(find_by_name(value, conn));
	}else if (strcmp(field,"email") == 0){
		Address_print(find_by_name(value, conn));
	}else{
		printf("Field %s not found in database \n", field);		

	}
		

}

struct Address *find_by_id(const int *id, struct Connection *conn)
{
	int i =0;
	struct Database *db = conn->db;
	for ( i = 0; i<MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];
		if ( cur->id == *id ){
			return cur;
		}
	}
	die("No recodrds found !!\n",conn);
	return NULL;
}

struct Address *find_by_name(const char *name, struct Connection *conn)
{
	int i =0;
	struct Database *db = conn->db;
	for ( i = 0; i<MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];
		if (strcmp(cur->name,name)==0){
			return cur;
		}
	}
	die("No recodrds found !!\n",conn);
	return NULL;
}

struct Address *find_by_email(const char *email, struct Connection *conn)
{
	int i =0;
	struct Database *db = conn->db;
	for ( i = 0; i<MAX_ROWS; i++){
		struct Address *cur = &db->rows[i];
		if (strcmp(cur->email,email)==0){
			return cur;
		}
	}
	die("No recodrds found !!\n",conn);
	return NULL;
}

int main(int argc, char *argv[]){
		printf("TTT Address - %ld \n",sizeof(struct Address));
		printf("TTT Database - %ld \n",sizeof(struct Database));
		printf("TTT Connection - %ld \n",sizeof(struct Connection));
		if (argc < 3)
			die("USAGE: ex17 <dbfile> <action> [action params]",NULL);

		char *test = "Hello World";
		printf("Testing ... %s \n",test);
		char *filename = argv[1];
		printf("File Name.. %s \n",filename);	
		
		char action =  (char) argv[2][0];
		printf("Action.. %c \n",action);
		printf("Connection.");
		struct Connection *conn =  Database_open(filename, action);
		int id =0;

		if ((argc > 3) && (action != 'f')) id = atoi(argv[3]);
		if (id >= MAX_ROWS) die("There is not many record.",conn);

		printf("Going into switch.. \n");
		switch (action) {
			case 'c':
				Database_create(conn);
				Database_write(conn);
				break;
			case 'g':
				if (argc !=4)
					die("Need an id to get",conn);
				Database_get(conn, id);
				break;
			case 's':
				if (argc != 6)
					die("Need id, name, email to set.",conn);
				Database_set(conn, id, argv[4], argv[5]);
				Database_write(conn);
				break;
			case 'd':
				if (argc != 4)
					die (" Need ID to delete",conn);
				Database_delete(conn, id);
				Database_write(conn);
				break;
			case 'l':
				Database_list(conn);
				break;
			case 'f':
				if (argc != 5)
					die("Need id or name or email to seearch.",conn);
				Database_find(conn, argv[3], argv[4]);
				break;
			default:
				die("Invalid action: c=creare, g=get,s=set,d=del,l=list",conn);		
		}
		Database_close(conn);
	return 0;
}