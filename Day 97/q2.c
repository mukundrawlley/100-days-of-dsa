#include <stdio.h>
#include <stdlib.h>

static int compareInt(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int minMeetingRooms(int** intervals, int intervalsSize) {
	if (intervalsSize == 0) return 0;

	int* start = (int*)malloc(intervalsSize * sizeof(int));
	int* end = (int*)malloc(intervalsSize * sizeof(int));

	for (int i = 0; i < intervalsSize; i++) {
		start[i] = intervals[i][0];
		end[i] = intervals[i][1];
	}

	qsort(start, intervalsSize, sizeof(int), compareInt);
	qsort(end, intervalsSize, sizeof(int), compareInt);

	int rooms = 0, endPtr = 0;
	for (int i = 0; i < intervalsSize; i++) {
		if (start[i] < end[endPtr]) rooms++;
		else endPtr++;
	}

	free(start);
	free(end);
	return rooms;
}

