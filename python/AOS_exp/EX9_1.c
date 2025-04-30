#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 8
#define DISK_SIZE 200

void scan(int arr[], int head, char* direction)
{
	int seek_count=0;
	int distance, cur_track;
	int left[SIZE+2],right[SIZE+2];
	int seek_sequence[SIZE+2];
	int left_size=0,right_size=0,seek_index=0;

	if(strcmp(direction, "left")==0)
	{
		left[left_size++]=0;
	}
	else if(strcmp(direction, "right")==0)
	{
	right[right_size++]=DISK_SIZE-1;
	}

	for(int i=0;i<SIZE;i++)
	{
		if(arr[i] < head)
			left[left_size]=arr[i];
	else if (arr[i] > head)
		right[right_size++]=arr[i];
	}

	for(int i=0;i<left_size-1;i++)
	{
		for(int j=i+1;j<left_size;j++)
		{
			if(left[i] > left[j])
			{
				int temp = left[i];
				left[i] = left[j];
				left[j] = temp;	
			}
		}
	}

	for(int i=0;i<right_size-1;i++)
	{
		for(int j=0;j<right_size;j++)
		{
			if(right[i] > right[j])
			{
				int temp = right[i];
				right[i] = right[j];
				right[j] = temp;	
			}
		}
	}

	int run = 2;
	while(run--)
	{
		if(strcmp(direction,"left")==0)
		{
			for(int i=left_size-1;i>= 0;i--)
			{
				cur_track=left[i];
				seek_sequence[seek_index++]=cur_track;
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
		direction = "right";
		}
		else if (strcmp(direction,"right")==0)
		{
			for(int i=0;i < right_size;i++)
			{
				cur_track = right[i];
				seek_sequence[seek_index++]=cur_track;
				distance = abs(cur_track - head);
				seek_count += distance;
				head = cur_track;
			}
			direction = "left";
		}
	}
	printf("Total number of seek opration = %d\n",seek_count);
	printf("Seek Sequence is:\n");
	for(int i=0;i<seek_index;i++)
	{
		printf("%d\n",seek_sequence[i]);
 	}
}

int main()
{
	int arr[SIZE] = {176,79,34,60,92,11,41,114};
	int head = 50;
	char direction[] = "left";
	
	scan(arr, head, direction);

	return 0;
}

