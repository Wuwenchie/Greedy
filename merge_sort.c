#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>  // 加入 INT_MAX
#define max_size 200 
int A[max_size];
int avail = 0; 

// 儲存數列 
void attach(int num) { 
    if (avail >= max_size) { 
        printf("Exceeded array size\n"); 
        return; 
    } 
    A[avail] = num; 
    avail++; 
} 

    
void merge(int left, int mid, int right) {
    int n1 = mid - left + 1;    // 左半部大小
    int n2 = right - mid;       // 右半部大小
    
    // 創建臨時陣列並加上哨兵值
    int L[n1 + 1], R[n2 + 1];
    
    // 複製資料到臨時陣列
    for(int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // 設定哨兵值（極大值）
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    // 合併過程
    int i = 0, j = 0;
    for(int k = left; k <= right; k++){
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int start, int finish) { 
    if(start < finish) { 
        int mid = (start + finish) / 2; 
        
        merge_sort(start, mid); 
        merge_sort(mid + 1, finish); 
        
        merge(start, mid, finish); 
    } 
}

int read_array() { 
    int num; 
    printf("Enter numbers (end with Ctrl+D or Ctrl+Z):\n");
    
    // 使用 scanf 檢查 EOF 
    while (scanf("%d", &num) != EOF) { 
        attach(num); 
        
    } 
    return avail - 1; // 返回結束位置 
} 

void print_array(int start, int finish) { 
    printf("Sorted array: "); 
    for(int i = start; i <= finish; i++) { 
        printf("%d ", A[i]); 
    } 
    printf("\n"); 
} 

int main() { 
    int start = 0; 
    int finish = read_array(); 
    if (avail > 0) { 
        // 確保有資料才排序 
        merge_sort(start, finish); 
        print_array(start, finish); 
    } else { 
        printf("No input provided.\n"); 
    } return 0; 
    
}
