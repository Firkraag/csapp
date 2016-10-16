#define M 19

void transpose(int A[M][M]) {
	int i, j;
	
	for (i = 1; i < M; i++)
		for (j = 0; j < i; j++) {
			int t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
}
void transpose_opt(int A[M][M]) {
	int i, j;
	
	for (i = 1; i < M; i++) {
			int *A1 = (int *) A + i; // &A[0][i] 
			int *A2 = (int *) (A + i); // &A[i][0]
		for (j = 0; j < i; j++) {
            int t = *A1;
            int *ptr = A2 + j;
            *A1 = *ptr;
            *ptr = t;
            A1 += M;
		}
	}
}
