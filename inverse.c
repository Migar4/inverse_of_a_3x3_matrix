#include <stdio.h>
#include <stdlib.h>


float det2x2(float a, float b, float c, float d) {
	return ((a*d) - (b*c));
}


float det3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
	float determinent;

	determinent = (a * ((e*i) - (h*f)));
	determinent = determinent - (b * ((d*i) - (g*f)));
	determinent  = determinent + (c * ((d*h) - (g*e)));

	return determinent;
}

int main()
{
    //the input matrix
	float mat[3][3];

    //getting the elements
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			  printf("what is the value of [%d] row and [%d] col?  ", i+1, j+1);
		      scanf("%f", &mat[i][j]);
		}
	}
    //showing the matrix that was entered
	printf("\n\nThe matrix entered is as follows:\n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("     %f", mat[i][j]);
		}
		printf("\n");
	}

    //finding the determinant of the matrix (should have used pointer features but became messy real soon)
	float det = det3x3(mat[0][0], mat[0][1], mat[0][2], mat[1][0], mat[1][1], mat[1][2], mat[2][0], mat[2][1], mat[2][2]);

	printf("\n\n Determinent for the matrix is %f.\n\n", det);

    //getting the transpose of the matrix
    float transpose[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			transpose[j][i] = mat[i][j];
		}
	}

	printf("\n\n Transpose of the matrix is:\n\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("     %f", transpose[i][j]);
		}
		printf("\n");
	}

	//if the determinant is zero there is no inverse
	if (det == 0) {
		printf("\n\nSince determinant is zero there is no inverse.\n\n");
		getchar();
	}

    //getting the minor matrices and entering them in a new matrix
	float mat2x2[2][2];
	float newmat[3][3];
	float adj[3][3];
	float inverse[3][3];

	int row = 0;
	int col = 0;
	int i = 0, j = 0;
	int count = 0;

    //for each row from zero
	for (row = 0; row < 3; row++) {
	//for each column form zero
		for (col = 0; col < 3; col++) {
		//this count helps to keep track of the 2x2 current index
			count = 0;
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {

                    //if the current index of the transpose matrix is neither the current row or column of the new matrix, proceed.
					if (row != i && col != j) {
						if (count == 0) {
							mat2x2[0][0] = transpose[i][j];
						}
						else if (count == 1) {
							mat2x2[0][1] = transpose[i][j];
						}
						else if (count == 2) {
							mat2x2[1][0] = transpose[i][j];
						}
						else if (count == 3) {
							mat2x2[1][1] = transpose[i][j];
						}
						//add count after everytime the 2x2 matrix is involved
						count++;
					}


				}
			}
			//new matrix element [row][col] will be the determinant of the 2x2 matrix that was found
			newmat[row][col] = det2x2(mat2x2[0][0], mat2x2[0][1], mat2x2[1][0], mat2x2[1][1]);
		}
	}

	//finding the cofactor matrix
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {

			if ((a + b) % 2 == 1) {
				adj[a][b] = -(newmat[a][b]);
			}
			else {
				adj[a][b] = newmat[a][b];
			}
		}
	}

    //finally if the determinant is not zero the elements of the matrix of cofactors is divided by the the determinant to get the inverse
	if (det != 0) {
		printf("\n\n\n\n");
		printf("The inverse of the matrix is : \n\n");

		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				inverse[a][b] = ((adj[a][b]) / det);
				printf("     %f", inverse[a][b]);
			}
			printf("\n");
		}
	}
	getchar();
	return 0;
}
