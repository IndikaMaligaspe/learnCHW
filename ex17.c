#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <string.h>


#define MAX_DATA 512
#define MAX_ROWS 100

struct  Address
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
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

void die(const char *message)
{
	if (errno){
		perror(message);
	} else {
		printf("ERROR: %s \n",message);
	}
	exit;
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s \n",addr->id, addr->name, addr->email );
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database),1,conn->file);
	if (rc != 1)
		die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error");
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
	rewind(conn->file);
	int rc = fwrite(conn->db,sizeof(struct Database),1,conn->file);

	if (rc != 1)
		die("Failed to write database.");

	//What is fflush
	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
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
		die("alrady set, delete it first.");

	addr->set = 1;
	//WARNING: bug, read the "How to break It" and fix this
	char *res = strncpy(addr->name, name,MAX_DATA);
	//demonstrate the strncpy bug
	if (!res)
		die("Name copy failed.");

	res = strncpy(addr->email,email,MAX_DATA);
	if (!res)
		die("Email copy failed");
}


int main(int argc, char *argv[]){
	return 0;
}