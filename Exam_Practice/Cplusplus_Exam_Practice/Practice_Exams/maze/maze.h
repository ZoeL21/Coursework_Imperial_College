/* You are pre-supplied with the functions below. Add your own 
   function prototypes to the end of this file. */

/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

bool find_marker(char ch, char** maze, int height, int width, int& row, int& column);

bool valid_solution(const char* path, char** maze, int height, int width);

const char* find_path(char** maze,int height,int width,char start, char end);

const char* find_path_rec(char** maze,int height, int width,int row_start,int col_start,char end, char* path_so_far);

bool can_move(char** maze,int row_to_go,int col_to_go,char end);

void remove_last(char* path_so_far);

bool maze_full(char** maze,int height, int width);
