template<class Element>
void replacementSelection(Element *A, int n, const char *in, const, char* out) {
	Elem min;//�����С�ѵ���Сֵ
	Elem r;//��Ŵ����뻺���������Ԫ��
	FILE *inputFile;
	FILE *outputFile;
	Buffer<Element> input;
	Buffer<Element> output;
	initFiles(inputFile, outputFile, in, out);
	initMinHeapArray(inputFile, n, A);//build heap
	MinHeap<Element> H(A, n, n);
	initInputBuffer(input, inputFile);
}