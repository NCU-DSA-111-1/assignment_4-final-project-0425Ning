
int cnt;

struct History{
    int count;
    int col;
    int row;
    struct History* ptr;
};
typedef struct History history;

void show_history( history * ptr_front );
