// banker's Algorithm  
#include <stdio.h>  

int resource_request(int pid, int request[], int alloc[][3], int max[][3], int avail[], int n, int m) {
    int need[m];
    // for(int i=0; i<m; i++){
    //     printf("%d ",avail[i]);
    // }
    // printf("\n");

    // for(int i=0; i<m; i++){
    //     printf("%d ",request[i]);
    // }
    // printf("\n");
    // Calculate need matrix for the process
    for (int i = 0; i < m; i++) {
        need[i] = max[pid][i] - alloc[pid][i];
    }

    // check if the request is valid --
    for (int i = 0; i < m; i++) {
        if (request[i] > need[i]){
            printf("Bad request! exceeded max claim\n");
            return 0; // Request cannot be granted
        }
    }


    // Check if request can be granted
    for (int i = 0; i < m; i++) {
        if (request[i] > avail[i]){
            printf("Resources can't be allocated right now!\n");
            return 0; // Request cannot be granted
        }
    }

    // Simulate resource allocation to check for safety
    int temp_alloc[n][m], temp_avail[m], temp_need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp_alloc[i][j] = alloc[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        temp_alloc[pid][i] += request[i];
        temp_avail[i] = avail[i] - request[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            temp_need[i][j] = max[i][j] - temp_alloc[i][j];
        }
    }
    // Safety check
    int f[n], ans[n], ind = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 0;
    }

    int y;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (temp_need[i][j] > temp_avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        temp_avail[y] += temp_alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            printf("Request can't be granted because it puts the system in unsafe state\n");
            return 0; // Request cannot be granted as system becomes unsafe
        }
    }

    return 1; // Request can be granted
}


int is_safe(int a[][3], int ma[][3], int ava[], int n, int m){
    int alloc[5][3];
    int max[5][3];
    int avail[5];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            alloc[i][j] = a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            max[i][j] = ma[i][j];
        }
    }

    for(int i=0; i<m; i++){
        avail[i] = ava[i];
    }
    int i,j,k;
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < n; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            // printf("The following system is not safe");  
            return 0;
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d\n", ans[n - 1]);  
    }
    return 1;
}

int main()  
{  
    // P0, P1, P2, P3, P4 are the Process names here  
  
    int n, m, i, j, k;  
    n = 5;                         // Number of processes  
    m = 3;                         // Number of resources  

    // Allocation Matrix  
    int alloc[5][3] = {{0, 1, 0},  
                       {2, 0, 0},   
                       {3, 0, 2},   
                       {2, 1, 1}, 
                       {0, 0, 2}};  

    // MAX Matrix 
    int max[5][3] = {{7, 5, 3},    
                     {3, 2, 2},    
                     {9, 0, 2},   
                     {2, 2, 2},   
                     {4, 3, 3}};   
  
    // Available Resources 
    int avail[3] = {3, 3, 2};  
  
    if(is_safe(alloc,max,

    }else{
        printf("System is not in safe state");
        printf("Trying Preemption -->\n");
        int ct = 0;
        while(ct<n){
            int num_resources[5] = {0};
            for(int i=0; i<n; i++){
                int curr = 0;
                for(int j=0; j<m; j++){
                    curr += alloc[i][j];
                }
                num_resources[i] = curr;
            }
            int mx_idx = 0;
            for(int i=0; i<n; i++){
                if(num_resources[i]>num_resources[mx_idx]){
                    mx_idx = i;
                }
            }
            printf("Preempting resources from process P%d\n",mx_idx);
            for(int j=0; j<m; j++){
                avail[j] += alloc[mx_idx][j];
                alloc[mx_idx][j] = 0;
            }
            if(is_safe(alloc,max,avail,n,m)){
                break;
            }
            ct++;
        }
    }


    int pid = 1;
    int request[3] = {1, 0, 2}; // Requesting 1 unit of R1 and 2 units of R3
    if (resource_request(pid, request, alloc, max, avail, n, m)) {
        printf("Request for resources by P%d can be granted.\n", pid);
    }
    return 0;  
} 