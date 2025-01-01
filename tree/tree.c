#include <cpm.h>
#include <util.h>
#include <stdbool.h>

#define NODE_MAX 128
#define SAYING_MAX 32
#define BUFFER_MAX 16

static char buffer[BUFFER_MAX];

// Prototypes
struct node *next_node();
char *current_saying();
char *node_lookup(struct node *n, int i);
void node_insert(struct node *n, int i, char *s);

// Binary tree implementation
struct node {
	int i;
	char *s;
	struct node *l;
	struct node *r;
};

// Allocation
struct node nodes[NODE_MAX];
char sayings[NODE_MAX * SAYING_MAX];
int node_len;

struct node *next_node() {
	nodes[node_len].i = 0;
	nodes[node_len].s = 0;
	nodes[node_len].l = 0;
	nodes[node_len].r = 0;
	return &nodes[node_len++];
}

char *current_saying() {
	return &sayings[(node_len - 1) * SAYING_MAX];
}

char *node_lookup(struct node *n, int i) {
	if (n == 0)
		return 0;
	if (i == n->i)
		return n->s;
	if (i < n->i)
		return node_lookup(n->l, i);
	if (i > n->i)
		return node_lookup(n->r, i);
}

void node_insert(struct node *n, int i, char *s) {
	if (i == n->i)
		return;
	if (i < n->i) {
		if (n->l == 0) {
			n->l = next_node();
			n->l->i = i;
			n->l->s = s;
		} else {
			node_insert(n->l, i, s);
		}
	}
	if (i > n->i) {
		if (n->r == 0) {
			n->r = next_node();
			n->r->i = i;
			n->r->s = s;
		} else {
			node_insert(n->r, i, s);
		}
	}
}

void main() {
	int i;
	struct node *root = 0;
	char *s;

	print_string("Database of numbered sayings\r\n");
	
	while (true) {
		print_string("Choose your action (add, lookup, quit): ");
		read_line(buffer, BUFFER_MAX);
		if (strings_equal(buffer, "add")) {
			print_string("Specify number: ");
			i = read_number();
			print_string("Write saying:\r\n");
			s = current_saying();
			read_line(s, SAYING_MAX);
			
			if (root == 0) {
				root = next_node();
				root->i = i;
				root->s = s;
			} else
				node_insert(root, i, current_saying());
		} else if (strings_equal(buffer, "lookup")) {
			print_string("Specify number: ");
			i = read_number();
			s = node_lookup(root, i);
			
			print_string("Saying ");
			print_number(i);
			
			if (s != 0) {
				print_string(":\r\n");
				print_string(s);
				print_string("\r\n");
			} else {
				print_string(" not found\r\n");
			}
		} else if (strings_equal(buffer, "quit")) {
			break;
		} else {
			print_string("Invalid command.\r\n");
		}
	}
}
