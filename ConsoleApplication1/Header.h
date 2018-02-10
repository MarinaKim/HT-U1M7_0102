
enum type_number { possitive, negative, all };
enum sortirovka { ubivanie, vozrastanie };

int prost(int n);
int sluch_number(type_number tn, int start, int end);
void massiv(int *a, int r, int start, int end, type_number tn);
void print_massiv(int *a, int r);
int lin_min(int*a, int r);
void sort(int*a, int r, sortirovka k);
int bin_chislo(int *a, int left, int right, int s);


