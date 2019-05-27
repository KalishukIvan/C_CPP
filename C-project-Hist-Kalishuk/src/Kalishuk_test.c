#include "../headers/custom.h"


extern int _batch_helper_text(char *filename, DType *data, size_t size, long *fpos);
extern int _batch_helper_bin(char *filename, DType *data, size_t size, long *fpos);
extern int _print_frequency(struct hist *h);
extern DType median(struct hist *h);
extern DType var(struct hist *h);
extern DType dev(struct hist *h);
extern DType mean(struct hist *h);


int test_file_text(){
	DType data[3] = { 0 };
	size_t s = 3;
	long *tmp = (long*)calloc(1, sizeof(NType));
	*position = 0;
	printf("----------- Helper starts -----------\n");
	int amt = _batch_helper_text("path\\to\\file\\inpt.txt", data, s, position);
    printf("----------- Helper ends -----------\n");
	printf("Numbers read: ",amt," which are:\n");
	for (NType i = 0; i < s; i++){
        printf(data[i], "\n");
    }
	return 0;
}


int test_file_bin(){
	DType data[3] = { 0 };
	size_t s = 3;
	long *position = (long*)calloc(1, sizeof(NType));
	*position = 0;
	printf("----------- Helper starts -----------\n");
	int amt = _batch_helper_bin("path\\to\\file\\inpt.bin", data, s, position);
    printf("----------- Helper ends -----------\n");
    printf("Numbers read: ",amt," which are:\n");
	for (NType i = 0; i < s; i++){
		printf("%lf\n", data[i]);
	}

}


int test_hist(){
	struct hist *h = (struct hist*)malloc(sizeof(struct hist));
	DType mnHist = 0, mxHist = 100;
	NType M = 10;
	init_struct(mnHist, mxHist, M, h);
	add_batch_from_file("path\\to\\file\\inpt.txt", 't', h);
	_print_frequency(h);
	printf("\nAmount of elements in hist is: ", num(h));
	printf("\nMedian: ", median(h));
	printf("\nMean: ", mean(h));
	printf("\nDeviance: ", dev(h));
	printf("\nVariance: ", var(h));
	return 0;
}