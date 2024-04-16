#include <stdio.h>
#include <stdlib.h>
void look(int *requests, int total_requests, int start_head_position, char direction) {
int total_head_movements = 0;
int current_head_position = start_head_position;
int min_request = 0, max_request = 199;
int upper_limit, lower_limit;
if (direction == 'L' ) {
upper_limit = current_head_position;
lower_limit = 0;
} else {
upper_limit = max_request;
lower_limit = current_head_position;
}
printf("LOOK Schedule:\n");
while (1) {
int closest_request = -1;
int closest_distance = abs(upper_limit - lower_limit);
int closest_index = -1;
for (int i = 0; i < total_requests; i++) {
if (requests[i] >= lower_limit && requests[i] <= upper_limit) {
int distance = abs(requests[i] - current_head_position);
if (distance < closest_distance) {
closest_request = requests[i];
closest_distance = distance;
closest_index = i;
}}}
if (closest_request == -1) {
if (direction == 'L') {
direction = 'R';
upper_limit = max_request;
} else {
direction = 'L';
lower_limit = 0;
}} else {
printf("%d ", closest_request);
total_head_movements += abs(current_head_position - closest_request);
current_head_position = closest_request;
for (int i = closest_index; i < total_requests - 1; i++) {
requests[i] = requests[i + 1];
}
total_requests--;
if (direction == 'L') {
upper_limit = closest_request - 1;
} else {
lower_limit = closest_request + 1;
}}
if (total_requests == 0) {
break;
}}
printf("\nTotal head movements: %d\n", total_head_movements);
}
int main() {
int total_blocks, start_head_position;
char direction;
int requests[1000]; 
int total_requests = 0;
printf("Enter the total number of disk blocks: ");
scanf("%d", &total_blocks);
printf("Enter the disk request string (enter -1 to end): ");
while (1) {
int request;
scanf("%d", &request);
if (request == -1) {
break;
}
requests[total_requests++] = request;
}
printf("Enter the starting head position: ");
scanf("%d", &start_head_position);
printf("Enter the direction (L for left, R for right): ");
scanf(" %c", &direction);
look(requests, total_requests, start_head_position, direction);
return 0;
}
