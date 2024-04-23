package com.alexis.sort;
import java.util.Random;
public class A_QuickSortDemo {
    public static void main(String[] args) {
      
        // 快速排序
        int[] arr = {2, 6, 5, 4, 7, 1, 8, 9};
        int[] arr2 = new int[10000000];
        Random r = new Random();
        // 循环得到随机数
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = r.nextInt(100000);
        }

        long time1 = System.currentTimeMillis();
        RecursionSort(arr2,0,arr2.length - 1);
        long time2 = System.currentTimeMillis();
        System.out.println(time2 - time1);

    }
    
    public static void RecursionSort(int[] arr, int minIndex, int maxIndex) {
        if (maxIndex <= minIndex) {
            return ;
        }
        int pivot = quickSort(arr,minIndex,maxIndex); // 第一轮确立基准数
        RecursionSort(arr,minIndex,pivot - 1); // 向左边排序
        RecursionSort(arr,pivot + 1,maxIndex); // 向右边排序
    }
    
    private static int quickSort(int[] arr, int minIndex, int maxIndex) {

        int pivot = minIndex;
        int star = minIndex;
        int end = maxIndex;

        while (maxIndex > minIndex) {

            while (maxIndex > minIndex && arr[maxIndex] >= arr[pivot]) {
                maxIndex--;
            }

            while (maxIndex > minIndex && arr[minIndex] <= arr[pivot]) {
                minIndex++;
            }

           swap(arr,minIndex,maxIndex);
        }

        // while 循环结束时maxIndex必然小于等于minIndex
        // 即是说maxIndex和minIndex指向了同一个元素
        // 将i索引指向的值与基准值进行交换
        // 即基准值的归为
        swap(arr,star, maxIndex);
        return minIndex;
    }

    // 交换数组的值
    private static void swap(int[] arr, int maxIndex, int minIndex) {
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
